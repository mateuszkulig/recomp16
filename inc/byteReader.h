#include "stdio.h"
#include "stdint.h"

// convert hex to char* containing hex in format "\xhh"
char *hexToText(uint8_t hex);

// read n bytes from file from input
char **readBytes(FILE *input, int n);

// create string containing all of bytes together
char *assembleString(char **bytes, int len);
