l=${#1}
lastchr=${1#${1%?}}
temp=""
if [ "$lastchr" == "/" ]; then
	temp="$1posting_201101144"
else
	temp="$1/posting_201101144"

fi
java query $temp
