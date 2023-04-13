#include <stdio.h>
#include <inttypes.h>
#include "command.h"
#include "coder.h"
int encode_file(const char *in_file_name, const char *out_file_name)
{
    FILE *in;
    FILE *out;

    in = fopen(in_file_name,"r");

    if (!in)
    {
        return -1;
    }

    out = fopen(out_file_name,"wb");
    
    if (!out)
    {
        return -1;
    }
    uint32_t code_point;
    fscanf(in,"%" SCNx32,&code_point);
    printf("%" PRIx32,code_point);

    CodeUnit code_unit;
    encode(code_point, &code_unit);
    return 0;
}
int decode_file(const char *in_file_name, const char *out_file_name)
{
    FILE *in;
    FILE *out;

    in = fopen(in_file_name,"r");

    if (!in)
    {
        return -1;
    }

    out = fopen(out_file_name,"wb");
    
    if (!out)
    {
        return -1;
    }
}