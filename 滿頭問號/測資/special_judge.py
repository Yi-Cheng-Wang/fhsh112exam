import sys
from itertools import zip_longest

result = {"$JUDGE_RESULT":"", "$LINECOUNT":"","$USEROUT":"","$SYSTEMOUT":"","$MESSAGE":""}

def cnt(s:str):
    n = 0
    copy = 0
    for i in s:
        if i == 'A':
            n += 1
        if i == 'D':
            n -= 1
        if i == 'C':
            copy = n
        if i == 'V':
            n += copy
    return n

def main(argv):
    if len(argv) != 3:
        print ('special.py [inputfile] [ansfile] [outputfile]')
        sys.exit(2)

    infile = open(argv[0], 'r', encoding='UTF-8')
    ansfile = open(argv[1], 'r', encoding='UTF-8')
    outfile = open(argv[2], 'r', encoding='UTF-8')

    for index, (iin, out, ans) in enumerate(zip_longest(infile.readlines(), outfile.readlines(), ansfile.readlines()), 1):
        if ans is None :
            result["$JUDGE_RESULT"] = "OLE"
            result["$LINECOUNT"]= str(index)
            result["$USEROUT"]=out.strip()
            result["$MESSAGE"]="OLE"
            return
        if out is None :
            result["$JUDGE_RESULT"]="WA"
            result["$LINECOUNT"]=str(index)
            result["$MESSAGE"]="WA"
            return
        if len(out.strip()) > len(ans.strip()) or str(cnt(out.strip())) != iin.strip():
            result["$JUDGE_RESULT"]="WA"
            result["$LINECOUNT"]=str(index)
            result["$USEROUT"]=out.strip()
            result["$SYSTEMOUT"]=ans.strip()
            result["$MESSAGE"]="You are wrong!"
            return
    result["$JUDGE_RESULT"]="AC"

if __name__ == "__main__":
    main(sys.argv[1:])
    for key in result:
        print(key+"="+result[key])