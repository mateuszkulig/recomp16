#include "stdio.h"
#include "stdlib.h"
#include "stdint.h"

char *hexToText(uint8_t hex) {
    char hexChars[16] = "0123456789ABCDEF";
    char *output = malloc(4);
    output[0] = '\\';
    output[1] = 'x';
    output[2] = hexChars[hex/16];
    output[3] = hexChars[hex - (hex/16)*16];    // dividing int cuts the remainder
    // printf("%c%c%c%c\n", output[0], output[1], output[2], output[3]);
    
    return output;
}

char **readBytes(FILE *input, int n) {
    char    **bytes = malloc((sizeof(char*))*n);
    uint8_t charBuffer;
    char    *hexBuffer;
    for (int i=0; i<n; ++i) {
        bytes[i] = malloc(4);
        charBuffer = fgetc(input);
        hexBuffer = hexToText(charBuffer);
        for (int j=0; j<4; ++j) {
            bytes[i][j] = hexBuffer[j];
        }
        free(hexBuffer);
    }
    return bytes;
}

char *assembleString(char **bytes, int len) {
    char *byteString = malloc((len*4) + 1);
    int counter = 0;
    for (int i=0; i<len; ++i) {
        for (int j=0; j<4; ++j) {
            byteString[counter] = bytes[i][j];
            counter++;
        }
    }
    byteString[counter] = '\0';

    return byteString;
}

