# Push_swap

## Description

Push_swap is a 42 School project that involves sorting data on a stack, with a limited set of instructions, using the lowest possible number of actions. To make this happen, you will have at your disposal a set of integer values, two stacks (Stack A and Stack B), and a set of instructions to manipulate both stacks.

This implementation uses a modified Turk algorithm to sort the numbers efficiently.

## Algorithm

The sorting strategy implemented in this project is based on the Turk algorithm. The process involves:

1.  Pushing the first two numbers from Stack A to Stack B.
2.  Calculating the minimum and maximum numbers in Stack B.
3.  Identifying the "cheapest" number in Stack A (the one requiring the fewest operations to be pushed to the correct position in Stack B).
4.  Pushing the cheapest number to Stack B, updating the min/max values.
5.  Repeating the process until Stack A is empty.
6.  Pushing everything back from Stack B to Stack A in the correct order.

## Installation

To compile the project, run:

```bash
make
```

This will generate the `push_swap` executable.

## Usage

Run the program with a list of integers as arguments:

```bash
./push_swap <list_of_integers>
```

Example:

```bash
./push_swap 2 1 3 6 5 8
```

The program will output the list of operations needed to sort the numbers.

## Operations

The allowed operations are:

*   **sa** (swap a): Swap the first 2 elements at the top of stack a.
*   **sb** (swap b): Swap the first 2 elements at the top of stack b.
*   **ss**: sa and sb at the same time.
*   **pa** (push a): Take the first element at the top of b and put it at the top of a.
*   **pb** (push b): Take the first element at the top of a and put it at the top of b.
*   **ra** (rotate a): Shift up all elements of stack a by 1. The first element becomes the last one.
*   **rb** (rotate b): Shift up all elements of stack b by 1. The first element becomes the last one.
*   **rr**: ra and rb at the same time.
*   **rra** (reverse rotate a): Shift down all elements of stack a by 1. The last element becomes the first one.
*   **rrb** (reverse rotate b): Shift down all elements of stack b by 1. The last element becomes the first one.
*   **rrr**: rra and rrb at the same time.
