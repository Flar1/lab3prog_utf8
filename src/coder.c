#include <stdio.h>
#include <inttypes.h>
#include "coder.h"
int encode(uint32_t code_point, CodeUnit *code_unit)
{
    if (code_point < 0x80)
    {
        code_unit -> length = 1;
        code_unit -> code[0] = code_point;
    }
    else if (code_point <0x800)
    {
        code_unit ->length = 2;
        code_unit ->code[0] = 0xc0 | (code_point >> 6);
        code_unit ->code[1] = 0x80 | (code_point & 0x3f);

    }
    else if( code_point < 0x10000)
    {
        code_unit -> length = 3;
        code_unit ->code[0] = 0xe0 | (code_point >> 12);
        code_unit ->code[1] = 0x80 | ((code_point >> 6) & 0x3f);
        code_unit ->code[2] = 0x80 | (code_point & 0x3f); 
    }
    else if (code_point < 0x200000)
    {
        code_unit ->length = 4;
        code_unit ->code[0] = 0xf0 | (code_point >> 18);
        code_unit ->code[1] = 0x80 | ((code_point >> 12)& 0x3f);
        code_unit ->code[2] = 0x80 | ((code_point >> 6)&0x3f);
        code_unit ->code[3] = 0x80 | (code_point & 0x3f);
    }
}
int write_code_unit(FILE *out, const CodeUnit *code_unit)
{
    int result = fwrite(code_unit -> code,1,code_unit ->length , out);
    return result;
}