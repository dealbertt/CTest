#include <stdio.h>
#include "../include/ctest.h"

int sum(int a, int b){
    return a + b;
}

bool assertEqual(int expected, int (*funcPointer)(int, int), int a, int b){
    int result = funcPointer(a, b);
    if(expected == result){
        printf("Yay it works, equal!\n");
        return true;
    }else{
        printf("Not really equal man!\n");
        return false;
    }
}

int main(){
    assertEqual(4, sumTest, 3, 2);
}
