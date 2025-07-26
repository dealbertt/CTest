#include <stdio.h>
#include <ctest.h>

int add(int a, int b){
    return a + b;
}

int main(){
    assertEqualsFloat(3, 4);
    assertNotEqualsFloat(3, 4);
    assertEqualsInt(4, add(2, 2));

    return 0;
}
