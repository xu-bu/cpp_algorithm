//
// Created by test on 2022/7/7.
//
#include <stdio.h>

int main(){
    typedef struct hmac{
        struct subData{
            int num;
        }sub;
    }parent;
    parent p={};
    printf("%d",parent.sub.num);
}
