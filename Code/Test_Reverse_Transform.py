## @file Test_Reverse_Transform.py
#
#  This script file has simple implementation the reverse odsa transform algorithm

## reverse_jumps function
#
# make reverse jumps to the elloborateed output
def reverse_jumps(letter, index, input_text):
    output = input_text
    for x in xrange(0, len(letter)):
        output = output[:output.index(letter[x])] + output[output.index(letter[x])+1:]
        output = output[:index[x]]+[letter[x]]+output[index[x]:]
    return output

## elloborate function
#
# ellobrate the output text from the letter output map
def elloborate(letter, index):
    output = []
    for x in xrange(0, len(letter)):
        for y in xrange(index[x],index[x+1]):
            output += letter[x]
    return output

#main program
fo = open('../Test/Transform.kt','rb')
lines = []
for line in fo:
    lines.append(line.strip())
fo.close()
fo = open('../Test/TestOutput.txt','wb')
fo.write('')
fo.close()
inSize = 0
outSize = 0
len_letter_map = 0
for x in xrange(0,len(lines)/4):
    letter_map = lines[4*x].split(' ')
    index_map = map(int, lines[4*x+1].split(' '))
    letter_transform = lines[4*x+2].split(' ')
    index_transform = map(int, lines[4*x+3].split(' '))
    output = elloborate(letter_map, index_map)
    output = reverse_jumps(letter_transform, index_transform, output)
    fo = open('../Test/TestOutput.txt','a')
    fo.write(''.join(output))
    fo.close()
    inSize += len(output)
    outSize += len(letter_map)+len(letter_transform)+len(index_map)+len(index_transform)
    len_letter_map += len(letter_map)
    if x == (len(lines)/4)-1 and not len(lines)%4 == 0:
        letter_map = lines[4*(x+1)].split(' ')
        index_map = map(int, lines[4*(x+1)+1].split(' '))
        output = elloborate(letter_map, index_map)
        fo = open('../Test/TestOutput.txt','a')
        fo.write(''.join(output))
        fo.close()
        inSize += len(output)
        outSize += len(letter_map)+len(letter_transform)+len(index_map)+len(index_transform)
        len_letter_map += len(letter_map)
print 'Input size =', inSize, ' bytes.'
print 'Output size =', outSize, ' bytes.'
print 'Actual file size =', ((outSize*2)+len_letter_map+4), ' bytes'
print 'Efficency =', (100 - (outSize)*100/inSize), '%'
print 'Actual efficency =', (100 - ((outSize*2)+len_letter_map+4)*100/inSize), '%'
