#include "utils.h"
#include <stdarg.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

char *strAppend(int num, ...) {
    va_list params;
    va_start(params, num);

//    char result[1024];
//    static char result[1024];
    char *result = malloc(1024);
    for (int i = 0; i < num; ++i) {
        char *content = va_arg(params, char*);
        printf("参数: %s\n", content);
        strcat(result, content);
    }
    printf("result: %s\n", result);
    return result;
}