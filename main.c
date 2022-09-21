#include "heapsort.h"
#include "printHeap.h"
#include <stdlib.h>
#include <time.h>

void printHeap(int *array, int size);

int main(void) {
    srand(time(NULL));
    int size = rand() % 64;

    int array[size];
    for (int i = 0; i < size; i++) {
        array[i] = rand() % 101 - 50;
    }

    printf("unsorted array: ");
    for (int i = 0; i < size; i++) {
        printf("%d ", array[i]);
    }
    printf("\n\n");
    //Print unsorted heap
    printHeap(array, size);
    //Sort heap
    heapsort(array, size);

    printf("\nsorted array: ");
    for (int i = 0; i < size; i++) {
        printf("%d ", array[i]);
    }
    printf("\n\n");
    //Print sorted heap
    printHeap(array, size);

    printf("\n");
}
