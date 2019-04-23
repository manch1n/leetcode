#!C:\Program Files\Git\git-bash.exe
#author: manch1n
#date:2019-4-16
#discription: for auto push the exercises in leetcode.
#realease: 1.1


date=`date +%Y%m%d`
branch=${1}
suffix=${2}
[ "$#" -ne 2 ]&&echo "usage:$0 branch file.suffix"&&exit 0

git add *.${suffix}
if [ $? -ne 0 ];
then
    echo "add add file(s) failed."&&exit 1
fi

git commit -m"${date}"
if [ $? -ne 0 ]
then 
    echo "commit failed."&&exit 1
fi

git push origin ${branch}
if [ $? -ne 0 ]
then
    echo "push failed."&&exit 1
fi

echo "/******auto push complete*****/.\n"
exit 0
