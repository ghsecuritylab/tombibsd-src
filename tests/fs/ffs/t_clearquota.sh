# $NetBSD$ 
#
#  Copyright (c) 2011 Manuel Bouyer
#  All rights reserved.
# 
#  Redistribution and use in source and binary forms, with or without
#  modification, are permitted provided that the following conditions
#  are met:
#  1. Redistributions of source code must retain the above copyright
#     notice, this list of conditions and the following disclaimer.
#  2. Redistributions in binary form must reproduce the above copyright
#     notice, this list of conditions and the following disclaimer in the
#     documentation and/or other materials provided with the distribution.
# 
#  THIS SOFTWARE IS PROVIDED BY THE NETBSD FOUNDATION, INC. AND CONTRIBUTORS
#  ``AS IS'' AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED
#  TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR
#  PURPOSE ARE DISCLAIMED.  IN NO EVENT SHALL THE FOUNDATION OR CONTRIBUTORS
#  BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR
#  CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF
#  SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS
#  INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN
#  CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)
#  ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE
#  POSSIBILITY OF SUCH DAMAGE.
#

for e in le be; do
  for v in 1 2; do
    for q in "user" "group"; do
      test_case_root clear_${e}_${v}_${q} clear_quota \
	 "clear quota with ${q} enabled" -b ${e} ${v} ${q}
    done
    test_case_root clear_${e}_${v}_"both" clear_quota \
	 "clear quota with both enabled" -b ${e} ${v} "both"
    test_case_root clear_${e}_${v}_"both_log" clear_quota \
	 "clear quota for new id with both enabled, WAPBL" -bl ${e} ${v} "both"
  done
done

clear_quota()
{
	create_ffs_server $*
	local q=$4
	local expect
	local fail
	local id=1

	case ${q} in
	user)
		expect=u
		fail=g
		;;
	group)
		expect=g
		fail=u
		;;
	both)
		expect="u g"
		fail=""
		;;
	*)
		atf_fail "wrong quota type"
		;;
	esac

#set and check the expected quota
	for q in ${expect} ; do
		atf_check -s exit:0 \
		   env LD_PRELOAD=/usr/lib/librumphijack.so RUMPHIJACK=vfs=getvfsstat,blanket=/mnt edquota -$q -s10k/20 -h40M/50k \
		   -t 2W/3D ${id}
		atf_check -s exit:0 \
-o "match:/mnt        0       10    40960  2weeks       0      20   51200   3days" \
-o "match:Disk quotas for .*: $" \
		    env LD_PRELOAD=/usr/lib/librumphijack.so RUMPHIJACK=vfs=getvfsstat,blanket=/mnt quota -${q} -v ${id}
	done
#now clear the quotas
	for q in ${expect} ; do
		atf_check -s exit:0 \
		   env LD_PRELOAD=/usr/lib/librumphijack.so RUMPHIJACK=vfs=getvfsstat,blanket=/mnt edquota -$q -c ${id}
	done;

#check that we do not get positive reply for any quota type
	for q in u g ; do
		atf_check -s exit:0 -o "not-match:/mnt" \
		    -o "not-match:Disk quotas for .*: $" \
		    -o "match:Disk quotas for .*: none$" \
		    env LD_PRELOAD=/usr/lib/librumphijack.so RUMPHIJACK=vfs=getvfsstat,blanket=/mnt quota -${q} -v ${id}
	done
	rump_quota_shutdown
}
