# push_swap
A 42 school project about sorting data with a limited amount of operations and using two stacks.

## Details
push_swap is made for unix systems. Compile with make, and run with "./push_swap *insert any amount of numbers*". The numbers should not repeat and be within the range of an integer.
After providing the program with correct input, it will print out operations which would sort the array of numbers. The opeartions include:
* pa - push the first element of stack a to the top of stack b
* pb - push the first element of stack b to the top of stack a
* sa - swap the first two elements of stack a
* sb - swap the first two elements of stack b
* ss - sa and sb at the same time
* ra - put the first element of stack a to the bottom of stack a
* rb - put the first element of stack b to the bottom of stack b
* rr - ra and rb at the same time
* rra - put the last element of stack a to the top of stack a
* rrb - put the last element of stack b to the top of stack b
* rrr - rra and rrb at the same time

## Checker
Compile with 'make bonus'. Run with "./checker *insert any amount of numbers*". Afterwards the program will wait for standard input - operations which should be performed on the stack of numbers.
If after applying those operations the stack would be sorted - print out "OK", else print out "KO".

## Main concepts learned:
* Algorithm complexity
* Radix sort
* Bitwise operations
