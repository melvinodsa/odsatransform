## @file Test_Transform.py
#
#  This script file has simple implementation the forward odsa transform algorithm

## transform function
#
# transform function is run iteratively by main function to transform the entire input data
def transform(input_text):
    LP = 0
    LL = input_text[0]
    output_map_jump = []
    output_map_letter = [input_text[0]]
    output_map_index = [0]
    last_buffer_length = 1
    jump_count = 0
    just_appened = False
    for letter in input_text[1:]:
        if letter < LL :
            output_map_jump = output_map_jump + [letter, LP+1]
            jump_count += 1
            if not letter in output_map_letter:
                index = 0
                flag = False
                for item in output_map_letter[:len(output_map_letter)]:
                    if item > letter and flag == False:
                        index = output_map_letter.index(item)
                        flag = True
                    elif flag == True:
                        output_map_index[output_map_letter.index(item)] += 1
                output_map_letter = output_map_letter[:index] + [letter] + output_map_letter[index:]
                output_map_index = output_map_index[:index] + [output_map_index[index]] + output_map_index[index:]
                output_map_index[index+1] += 1
            else :
                for x in xrange(output_map_letter.index(letter)+1, len(output_map_letter)):
                    output_map_index[x] += 1
        else :
            if not letter in output_map_letter:
              output_map_letter = output_map_letter + [letter]
              output_map_index = output_map_index + [output_map_index[len(output_map_index)-1]+last_buffer_length]
              last_buffer_length = 1
            else :
              if output_map_letter.index(letter) == len(output_map_letter)-1:
                  last_buffer_length += 1
              else :
                  for x in xrange(output_map_letter.index(letter)+1, len(output_map_letter)):
                      output_map_index[x] += 1

        LP += 1
        LL = output_map_letter[len(output_map_letter)-1]
        if jump_count >= 3:
            f = open('../Test/Transform.kt','a')
            for x in xrange(0, len(output_map_letter)):
                f.write(output_map_letter[x]+" ")
            f.write('\n')
            for x in xrange(0, len(output_map_letter)):
                f.write(str(output_map_index[x])+" ")
            f.write(str(output_map_index[len(output_map_index)-1]+last_buffer_length))
            f.write('\n')
            for l in xrange((len(output_map_jump)-2),-1,-2):
                f.write(output_map_jump[l]+" ")
            f.write('\n')
            for l in xrange((len(output_map_jump)-1),0,-2):
                f.write(str(output_map_jump[l])+" ")
            f.write('\n')
            f.close()
            just_appened = True
            input_text = input_text[LP+1:]
            return output_map_letter, output_map_index, output_map_jump, input_text, just_appened, last_buffer_length
    input_text = []
    return output_map_letter, output_map_index, output_map_jump, input_text, just_appened, last_buffer_length

fo = open('../Test/TestInput.txt','rb')
lines = []
for line in fo:
    lines.append(line.strip())
fo.close()
f = open('../Test/Transform.kt','wb')
f.write("")
f.close()
input_text = lines[0]
just_appened = False
while len(input_text) > 0:
    output_map_letter, output_map_index, output_map_jump, input_text, just_appened, last_buffer_length = transform(input_text)

if not just_appened :
    f = open('../Test/Transform.kt','a')
    for x in xrange(0, len(output_map_letter)):
        f.write(output_map_letter[x]+" ")
    f.write('\n')
    for x in xrange(0, len(output_map_letter)):
        f.write(str(output_map_index[x])+" ")
    f.write(str(output_map_index[len(output_map_index)-1]+last_buffer_length))
    f.write('\n')
    for l in xrange((len(output_map_jump)-2),-1,-2):
        f.write(output_map_jump[l]+" ")
    f.write('\n')
    for l in xrange((len(output_map_jump)-1),0,-2):
        f.write(str(output_map_jump[l])+" ")
    f.close()
