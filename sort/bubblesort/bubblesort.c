#include <stdio.h>
#include <stdlib.h>

int main (){
    int array[10];
    printf("Insert 10 numbers:\n");
    for (int i=0; i<10; i++){
        scanf("%d", &array[i]);
    }

    // Bubble sort algorithm
    for (int i=0; i<9; i++){
        for (int j=0; j<9-i; j++){
            if (array[j]>array[j+1]){
                int temp = array[j];
                array[j] = array[j+1];
                array[j+1] = temp;
            }
        }
    }

    printf("Sorted array in ascending order:\n");
    for (int i=0; i<10; i++){
        printf("%d ", array[i]);
    }
    return 0;
}