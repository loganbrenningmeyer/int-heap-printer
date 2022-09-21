#include "printHeap.h"

int getLength(int number) {
    char numStr[11];
    sprintf(numStr, "%d", number);
    //printf("%ld", strlen(numStr));
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
    //initialize spaces leftmost node away from left
    int fromLeft = 5;
    for (int i = 0; i < height-2; i++) {
        fromLeft = fromLeft*2 + 2;
    }
    for (int i = 0; i < height; i++) {
        printNodes(array, height, height-i, size);
        printSlashes(height, height-i, size);
    }
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
            printf(" "); //one space
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

/*
Row 4:
- From Left: 26
- Between Children: 27
- Between Inner Pairs:
- Between Outer Pairs:
- Lines to: 13

Row 3:
- From Left: 12
- Between Children: 13
- Between Inner Pairs: 27
- Between Outer Pairs: 
- Lines to: 6

Row 2:
- From Left: 5
- Between Children: 5
- Between Inner Pairs: 13
- Between Outer Pairs: 13
- Lines to: 2

Row 1:
- From Left: 2
- Between Children: 3
- Between Inner Pairs: 5
- Between Outer Pairs: 7
- Lines to: 1

Row 0:
- From Left: 0
- Between Children: 0
- Between Inner Pairs: 3
- Between Outer Pairs: 1
- Lines to: 
                                                            54  5*8 + 2*(4+2) + 2

                          4[0]                                 26  5*4 + 2*2 + 2
                         / \                                       
                        /   \                                   
                       /     \                    
                      /       \                   
                     /         \    
                    /           \
                   /             \
                  /               \
                 /                 \
                /                   \
               /                     \
              /                       \                
             /                         \
            3[1]                        3[2]                   12  5*2 + 2
           / \                         / \                    
          /   \                       /   \
         /     \                     /     \
        /       \                   /       \
       /         \                 /         \
      /           \               /           \
     2[3]          2[4]          2[5]          2[6]            5  5*1 + 0
    / \           / \           / \           / \ 
   /   \         /   \         /   \         /   \
  1[7]  1[8]    1[9]  1[10]   1[11] 1[12]   1[13] 1[14]        2
 / \   / \     / \   / \     / \   / \     / \   / \
0[15]0 0   0   0   0 0   0   0   0 0   0   0   0 0   0       0 

  5  11    25            53

  1  2     3             4

  1 2 6 13 27

                                                                                         
                                                      5                                       
                                                     / \                       
                                                    /   \                    
                                                   /     \                   
                                                  /       \    
                                                 /         \
                                                /           \
                                               /             \
                                              /               \
                                             /                 \
                                            /                   \
                                           /                     \                
                                          /                       \
                                         /                         \
                                        /                           \
                                       /                             \
                                      /                               \
                                     /                                 \
                                    /                                   \
                                   /                                     \
                                  /                                       \
                                 /                                         \
                                /                                           \
                               /                                             \
                              /                                               \
                             /                                                 \
                            /                                                   \ 
                           /                                                     \
                          4                                                       4
                         / \                                                     / \                                                                                           
                        /   \                                                   /   \                      
                       /     \                                                 /     \                  
                      /       \                                               /       \                     
                     /         \                                             /         \ 
                    /           \                                           /           \
                   /             \                                         /             \
                  /               \                                       /               \
                 /                 \                                     /                 \
                /                   \                                   /                   \
               /                     \                                 /                     \
              /                       \                               /                       \              
             /                         \                             /                         \
            3                           3                           3                           3         
           / \                         / \                         / \                         / \                    
          /   \                       /   \                       /   \                       /   \
         /     \                     /     \                     /     \                     /     \
        /       \                   /       \                   /       \                   /       \
       /         \                 /         \                 /         \                 /         \
      /           \               /           \               /           \               /           \
     2             2             2             2             2             2             2             2
    / \           / \           / \           / \           / \           / \           / \           / \ 
   /   \         /   \         /   \         /   \         /   \         /   \         /   \         /   \
  1     1       1     1       1     1       1     1       1     1       1     1       1     1       1     1
 / \   / \     / \   / \     / \   / \     / \   / \     / \   / \     / \   / \     / \   / \     / \   / \
0   0 0   0   0   0 0   0   0   0 0   0   0   0 0   0   0   0 0   0   0   0 0   0   0   0 0   0   0   0 0   0    

  5  11    25            53

  1  2     3             4  */