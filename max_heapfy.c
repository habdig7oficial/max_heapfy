#include "stdio.h"
#include "math.h"
#include "stdbool.h"

void print_vec(int *vec, int len){
    printf("[");
    for (int i = 0; i < len; i++){
        printf("%d, ", vec[i]);
    }
    printf("]\n"); 
}

void max_heapfy(int *vec, int i, int len){
    bool parity = (i % 2) == 0;
    int index_father = (int)i / 2 + (parity? -1 : 0);
    int index_brother = i + (parity ? -1 : 1);
    printf("Root: vec[%d] = %d\n", index_father, vec[index_father]);
    printf("Leaf: vec[%d] = %d\n", i, vec[i]);
    printf("Brother: vec[%d] = %d\n", index_brother, vec[index_brother]);
    printf("\n");

    if(index_brother >= len){
        return;
    }
    int max_child = (vec[i] >= vec[index_brother])? i : index_brother;
    if(vec[max_child] > vec[index_father]){
        int aux = vec[index_father];
        vec[index_father] = vec[max_child];
        vec[max_child] = aux;
    }

    print_vec(vec, len);
}

int main(){
    int vec[] = {2,14,6,8,5,4,3,1,7,9,6,10,17,20,12,19};
    int len = sizeof(vec) / sizeof(int);
    print_vec(vec, len);

    for(int i = len - 1; i > 0; i -= 2){
        max_heapfy(vec, i, len);
    }
}