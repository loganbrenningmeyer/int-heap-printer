# C Int Heap Printer

Prints int arrays as heaps with nodes connected by / \\ 

Large arrays make nice fractals

Works best with 2-digit numbers in the range (-100, 100]
  - Lots of 3-digit numbers can bunch together at the leaf nodes and be hard to differentiate
    - Negative 2-digit numbers technically take up 3 spaces. However, negative leaf nodes are formatted so that branches always point to their negative sign (-) or first digit. That way, numbers in the range (-100, 100] are always properly formatted and distinguishable at leaf nodes


Examples:

array = [11, 5, -6] represented as a heap:
```
  11
 / \
5  -6
```

array = [-5, 21, -25, 22, 10, -5, 21, -15, -1]
```
            -5
           / \
          /   \
         /     \
        /       \
       /         \
      /           \
     21            -25
    / \           / \
   /   \         /   \
  22    10      -5    21
 / \
-15-1
```

array = [-11, 1, -21, -14, 8, 8, -18, -19, -23, 7, -24, -20, 10, -20, -24, -19, 11, -7, -12, -20, 8, -4, 
        14, -22, 0, 11, -2, -6, 16, 10, 20, -20, -15, -2, 16, -8, 6, -3, -1, 8, 3, 25, 14, 13, -21, -11, 
        -7, 16, 7, 6, -5, 15, 2, -17, 18, -24, -7, 15, 20, -16, -1, -12, 14]
```        
                                                      -11
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
                          1                                                       -21
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
            -14                         8                           8                           -18
           / \                         / \                         / \                         / \
          /   \                       /   \                       /   \                       /   \
         /     \                     /     \                     /     \                     /     \
        /       \                   /       \                   /       \                   /       \
       /         \                 /         \                 /         \                 /         \
      /           \               /           \               /           \               /           \
     -19           -23           7             -24           -20           10            -20           -24
    / \           / \           / \           / \           / \           / \           / \           / \
   /   \         /   \         /   \         /   \         /   \         /   \         /   \         /   \
  -19   11      -7    -12     -20   8       -4    14      -22   0       11    -2      -6    16      10    20
 / \   / \     / \   / \     / \   / \     / \   / \     / \   / \     / \   / \     / \   / \     / \   / \
-20-15-2  16 -8   6 -3 -1   8   3 25  14  13 -21-11-7   16  7 6  -5   15  2 -17 18 -24 -7 15  20 -16 -1 -12 14
```

