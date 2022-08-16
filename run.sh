# added by GBR in 2022/07/28
# command to run this.sh file:
# 0. should be in the or-project file  give permissions, just need once 
# 1. chmod a+x run.sh
# 2. ./run.sh run

cmake -B cmake-build

cd cmake-build 

make

cd test

./runAppTest 
# ./runAllTest
# ./runProverTest