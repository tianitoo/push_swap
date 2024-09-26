
# **push_swap** - A Sorting Algorithm Project
## Overview

**push_swap** is a project from the 42 Network curriculum that focuses on creating a sorting algorithm using a stack data structure. The goal is to sort a list of integers with the least number of operations possible, demonstrating a deep understanding of data structures, algorithms, and optimization techniques.
## Table of Contents

- [Overview](#overview)
- [Function Prototypes](#function-prototypes)
- [Project Structure](#project-structure)
- [How It Works](#how-it-works)
- [Compilation and Usage](#compilation-and-usage)
## Function Prototypes

```c
void push_swap(int argc, char **argv);
```

- **Parameters**:
  - `argc`: The number of command-line arguments.
  - `argv`: The array of command-line arguments, which are the integers to be sorted.
  
- **Return**:
  - This function does not return a value; it sorts the integers in place.


- **main.c**: The entry point of the program, handling input and output.
- **stack_operations.c**: Functions to perform operations on the stack (push, pop, swap, etc.).
- **sorting_algorithms.c**: Implementation of the sorting algorithms.
- **utils.c**: Utility functions for various tasks, such as error handling and input validation.
- **push_swap.h**: The header file containing function prototypes and necessary definitions.
- **Makefile**: Used for compiling the project.

## How It Works

The **push_swap** algorithm employs a stack-based approach to sort integers using a series of predefined operations:
- **Push (pa/pb)**: Move the top element from one stack to another.
- **Swap (sa/sb)**: Swap the top two elements of a stack.
- **Rotate (ra/rb)**: Move the top element of a stack to the bottom.
- **Reverse Rotate (rra/rrb)**: Move the bottom element of a stack to the top.

The sorting logic involves analyzing the current state of the stacks and applying the above operations in a way that minimizes the total number of operations. The project requires students to implement efficient sorting algorithms and optimize their implementation to handle larger data sets.

## Compilation and Usage

You can compile the project using the provided **Makefile**. To generate the object files and the final program, run the following commands:

```bash
# Compile the program
make

# Clean up object files
make clean

# Clean everything (object files and binary)
make fclean

# Recompile everything
make re
