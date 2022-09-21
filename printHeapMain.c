#include "printHeap.h"

void printHeap(int *array, int size);

int main(void) {
    //Create heap array of random size [1,63]
    srand(time(NULL));
    int size = rand() % 63 + 1;
    int heap[size];

    //Sets each element to a random int [-99,99] and prints array
    printf("array: [");
    for (int i = 0; i < size; i++) {
        heap[i] = rand() % 199 - 99;
        if (i != size-1) {
            printf("%d, ", heap[i]);
        } else {
            printf("%d]\n\n", heap[i]);
        }
    }

    printHeap(heap, size);
}