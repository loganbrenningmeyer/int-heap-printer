#include <stdio.h>
#include <math.h>
#include <string.h>
#include <time.h>
#include <stdlib.h>

void printHeap(int *array, int size);
int getInnerSpace(int fromLeft);
int getFromLeft(int row);
void printNodes(int *array, int height, int row, int size);
void printSlashes(int height, int row, int size);
int getLength(int number);