#include "../include/assert.h"
void doAssert(bool expr, const sourceLocation *loc, const char *expression){
    if(!expr){
        printf("Failed\n");
    }else{
        printf("Success\n");
    }
}
