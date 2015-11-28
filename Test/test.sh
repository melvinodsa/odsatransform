## \file test.sh
#
# This script file comtains the commands for testing/ running the engine

cd ../Build

## Running the python scripts
#
## Forward odsa Transform
#python ../Code/Test_Transform.py

## Reverse odsa Transform
#python ../Code/Test_Reverse_Transform.py

## FValidating the results
#python ../Code/Test_Result_Validator.py

# Running the odsa engine written in C
#
## Forward transform test suite
./Transform ../Test/TestInput.txt ../Test/TestTransform.kt

## Forward transform test suite memory check with valgrind
#valgrind -v ./Transform ../Test/TestInput.txt ../Test/TestTransform.kt

## Reverse transform test suite
./ReverseTransform ../Test/TestTransform.kt ../Test/TestOutput.txt ../Test/TestStatus.txt

## Reverse transform test suite memory check with valgrind
#valgrind -v ./ReverseTransform ../Test/TestTransform.kt ../Test/TestOutput.txt ../Test/TestStatus.txt

## Odsa library test suite
#./Testodsa ../Test/TestTransform.kt

## FValidating the results
python ../Code/Test_Result_Validator.py
