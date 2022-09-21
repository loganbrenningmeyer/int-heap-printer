#include "printHeap.h"

int getLength(int number) {
    char numStr[11];
    sprintf(numStr, "%d", number);
    return strlen(numStr);
}

int getInnerSpace(int fromLeft) {
    return fromLeft*2 + 3;
}

int getFromLeft(int row) {
    if (row == 1) return 2;
    int fromLeft = 5;
    for (int i = 0; i < row-2; i++) {
        fromLeft = fromLeft*2 + 2;
    }
    return fromLeft;
}

void printHeap(int *array, int size) {
    //height of heap (0...n = height)
    int height = (int)log2((double)size);
    //Print non-leaf nodes
    for (int i = 0; i < height; i++) {
        printNodes(array, height, height-i, size);
        printSlashes(height, height-i, size);
    }
    //Print leaf nodes
    printNodes(array, height, 0, size);
}

//array[(int)pow(2, height - row) - 1 + i] way to index array through row
void printNodes(int *array, int height, int row, int size) {
    int spaceWidth = 0;

    if (row != 0) printf("%*c", getFromLeft(row), ' ');
    for (int i = 0; i < pow(2, height - row); i++) {    
        //if not all leaf nodes full, break
        if ((int)pow(2, height - row) - 1 + i >= size) break;
        printf("%d", array[(int)pow(2, height - row) - 1 + i]);
        if (i != (int)pow(2, height - row) - 1) {
            //For row 1 (second to bottom row)
            //Even rows (0, 2,...2n) are spaced by 5 minus the length of the previous value exceeding 1, odd rows spaced by 7
            if (row == 1) {
                if (i % 2 == 0) {
                    spaceWidth += 5 - (getLength(array[(int)pow(2, height - row) - 1 + i]) - 1);
                    if (spaceWidth > 0) printf("%*c", spaceWidth, ' ');
                    spaceWidth = 0;
                    continue;
                } else {
                    spaceWidth += 7 - (getLength(array[(int)pow(2, height - row) - 1 + i]) - 1);
                    if (spaceWidth > 0) printf("%*c", spaceWidth, ' ');
                    spaceWidth = 0;
                    continue;
                }
            //For row 0 (bottom row)
            //Because values are placed so closely together, have to do a bit of formatting magic to prevent
            //odd numbers/3-digit numbers from pushing elements out of their spot
            //Space between numbers boils down to their default spacing (1 or 3) minus the element's length exceeding 1
            //If the previous element was negative/3-digit and shifted back, add one to the next space
            } else if (row == 0) {
                int nextSpace = 0;

                if ((i - 1) % 4 == 0) {
                    spaceWidth += 1 - (getLength(array[(int)pow(2, height - row) + i - 1]) - 1);
                    //Check if next value is negative, if there's room to make room then add a space
                    if ((array[(int)pow(2, height - row) + i] < 0 || array[(int)pow(2, height - row) + i] >= 100) && spaceWidth - 1 > 0) {
                        spaceWidth--;
                        nextSpace = 1;
                    }
                    if (spaceWidth > 0) printf("%*c", spaceWidth, ' ');
                    spaceWidth = nextSpace;
                    continue;
                } else {
                    spaceWidth += 3 - (getLength(array[(int)pow(2, height - row) + i - 1]) - 1);
                    //Check if next value is negative, if there's room to make room then add a space
                    if ((array[(int)pow(2, height - row) + i] < 0 || array[(int)pow(2, height - row) + i] >= 100) && spaceWidth > 0) {
                        spaceWidth--;
                        nextSpace = 1;
                    }
                    if (spaceWidth > 0) printf("%*c", spaceWidth, ' ');
                    spaceWidth = nextSpace;
                    continue;
                }
            }
            printf("%*c", getInnerSpace(getFromLeft(row)) - (getLength(array[(int)pow(2, height - row) - 1 + i]) - 1), ' ');
        }
    }
    printf("\n");
}

void printSlashes(int height, int row, int size) {
    if (row == 1) {
        if (height > 1) {
            int count = 0;
            printf(" ");
            for (int i = pow(2, height) - 1; i < size; i++) {
                if (count % 2 == 0) {
                    printf("/ ");
                } else {
                    if ((count + 1) % 4 == 0) {
                        printf("\\     ");
                    } else {
                        printf("\\   ");
                    }
                }
                count++;
            }
            printf("\n");
            return;
        } else {
            printf(" ");
            printf("/ \\");
            printf("\n");
            return;
        }
    }

    for (int i = 1; i <= getFromLeft(row)/2; i++) {
        printf("%*c", getFromLeft(row)-i, ' ');
        printf("/");
        printf("%*c", 2*(i-1) + 1, ' '); 
        printf("\\");
        for (int j = 0; j < pow(2, height-row)-1; j++) {
            printf("%*c", getFromLeft(row+1) + 1 - i*2, ' '); 
            printf("/");
            printf("%*c", 2*(i-1) + 1, ' '); 
            printf("\\");
        }
        printf("\n");
    }
}