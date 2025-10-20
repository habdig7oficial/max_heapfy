#include "stdio.h"
#include "math.h"
#include "stdbool.h"

void max_heapfy(int *vec, int i){
    bool parity = (i % 2) == 0;
    int index = (int)i / 2 + (parity? -1 : 0);
    int index_brother = i + (parity ? -1 : 1);
    printf("Root: vec[%d] = %d\n", index, vec[index]);
    printf("Leaf: vec[%d] = %d\n", i, vec[i]);
    printf("Brother: vec[%d] = %d\n", index_brother, vec[index_brother]);
    printf("\n");
}

void print_vec(int *vec, int len){
    printf("[");
    for (int i = 0; i < len; i++){
        printf("%d, ", vec[i]);
    }
    printf("]\n");
}

int main(){
    int vec[] = {2,14,6,8,5,4,3,1,7,9,6,10,17,20,12,19};
    print_vec(vec, sizeof(vec) / sizeof(int));

    for(int i = sizeof(vec) / sizeof(int) - 1; i > 0; i--){
        max_heapfy(vec, i);
    }
}