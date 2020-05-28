cat words.txt |tr -s ' ' '\n' | sort | uniq -c|sort -k1nr|awk '{print$2" "$1}'
