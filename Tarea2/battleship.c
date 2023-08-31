#include <stdio.h>
#include <stdlib.h>

int random_int(){
    return rand()% 3+1;
}

int main(){
    int i = 0;
    for(i; i<10;i++){
        int random_value=random_int();
        printf("Random:%d\n",random_value);
    }
}