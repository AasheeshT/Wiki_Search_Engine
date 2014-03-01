l=${#2}
lastchr=${2#${2%?}}
temp=""
if [ "$lastchr" == "/" ]; then
	temp="$2posting_201101144"
else
	temp="$2/posting_201101144"

fi
java Parser $1 > $temp
