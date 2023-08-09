#/bin/bash
path=$1
files=$(ls $path )
for filename in $files
do
   # echo $filename
   sed -i 's/#RVTEST_RV64U/\#RVTEST_RV64U/' $filename
   sed -i 's/#RVTEST_CODE_BEGIN/\#RVTEST_CODE_BEGIN/' $filename
done
