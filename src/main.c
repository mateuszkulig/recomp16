#include "stdio.h"
#include "disassemblerTest.h"
#include "byteReader.h"
#include "disassembler.h"
#include "stdint.h"
#include "stdlib.h"

int main(int argc, char **argv) {
    // dissasemblerTest();
    FILE *input;
    // char **bytes;
    input = fopen("opsys/loader", "r");
    // bytes = readBytes(input, 100);
    // printf("%s", assembleString(bytes, 100));

    uint8_t *code = malloc(4);
    code[3] = '\0';
    for (int i=0; i<3; ++i) {
        code[i] = fgetc(input);
    }

    disassembleCode(code, 3);

    fclose(input);
    return 0;
}