## String literal vs Char array

String literals are immutable. Char arrays are mutable.

It is possible to check using the utility `objdump` (available on Linux) that strings literals reside in BSS segment, which is read-only, as static global variables, while char arrays are saved into the heap.