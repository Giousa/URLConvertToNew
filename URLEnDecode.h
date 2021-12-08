#ifndef URLCONVERTTONEW_URLENDECODE_H
#define URLCONVERTTONEW_URLENDECODE_H

#include <string.h>

#define BURSIZE 2048

int hex2dec(char c);

char dec2hex(short int c);

void urlEncode(char url[]);

void urlDecode(char url[]);

#endif //URLCONVERTTONEW_URLENDECODE_H
