#	$NetBSD$

if [ "X$1" = "X-d" ]; then
	SHELLCMD=cat
	shift
else
	SHELLCMD="sh -e"
fi

( while [ "X$1" != "X" ]; do
	cat $1
	shift
done ) | awk -f ${NETBSDSRCDIR}/distrib/common/list2sh.awk | ${SHELLCMD}
