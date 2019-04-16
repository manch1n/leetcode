#!C:\Program Files\Git\git-bash.exe
#author: manch1n
#date:2019-4-16
#discription: for auto push the exercises in leetcode.
#realease: 1.0


date=`date +%Y%m%d`
branch=${1}
suffix=${2}
[ "$#" -lt 2 ]&&echo "please select a branch and the file suffix"&&exit 0
git add *.${suffix}
git commit -m\'${date}\'
git push origin ${branch}
