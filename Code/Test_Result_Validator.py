## @file Test_Result_Validator.py
#
#  This script file has will validat whether the decompressed data is same that of the compressed data.
fi = open('../Test/TestInput.txt','rb')
linesi = []
for line in fi:
    linesi.append(line.strip())
fi.close()
fi = open('../Test/TestOutput.txt','rb')
lineso = []
for line in fi:
    lineso.append(line.strip())
fi.close()
flag = False
if len(lineso[0]) == len(linesi[0]):
    for x in xrange(0, len(lineso[0])):
        if lineso[0][x] != linesi[0][x]:
            print lineso[0][x], linesi[0][x]
            flag = True
else :
    flag = True
if not flag:
    print "The uncomressed data validated successfully"
else :
    print "Error while uncompressing the data"
