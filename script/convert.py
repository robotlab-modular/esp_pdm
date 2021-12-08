

print('convert')
lines = []
with open('script/sin.hex') as in_f:
    lines = in_f.readlines()

    
with open('sinus.h','w') as out_f:
   
    out_f.write('const int16_t sinus[] = {\n')

    i=0
    for line in lines:
        out_f.write('0x')
        out_f.write(line.rstrip())
        out_f.write(', ')
        i += 1
        if (i % 8 == 0):
            out_f.write('\n')
    out_f.write('};\n')
  

print('done !')
