## \file compile.sh
#
# This script file comtains the commands for building the engine from scratch
# The order of compilations has to be maintained. Unrequired compilations can be commented

## This will compile the odsautil library
gcc -g -o ../Build/odsautil -c ../Code/odsautil.c
## This will compile the odsaoutputmap library
gcc -g -o ../Build/odsaoutputmap -c ../Code/odsaoutputmap.c
## This will compile the odsatransform library
gcc -g -o ../Build/odsatransform -c ../Code/odsatransform.c
## This will compile the odsa library test suite
gcc -o ../Build/Testodsa ../Build/odsaoutputmap ../Build/odsatransform ../Build/odsautil ../Test/Testodsa.c
## This will compile the Forward transform test suite
gcc -o ../Build/Transform ../Build/odsaoutputmap ../Build/odsatransform ../Build/odsautil ../Test/Transform.c
## This will compile the Reverse transform test suite
gcc -o ../Build/ReverseTransform ../Build/odsaoutputmap ../Build/odsatransform ../Build/odsautil ../Test/ReverseTransform.c
## This will run the engine once the compilation is done. This can be uncommented only when its
# required to run the engine after making changes in the source and see the working in one go
# Ie intented for developement purpose
sh test.sh
