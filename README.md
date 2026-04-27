# M06-Programming-Assignment-2-

## Description

This program implements a B-Tree insert function in C++. The user enters a minimum degree, inserts integer values, and displays the structure of the B-Tree.

A B-Tree stores values in sorted order. When a node becomes full, the program splits the node to keep the tree balanced.

## Inputs

- Minimum degree of the B-Tree
- Integer values to insert
- Menu choices (1, 2, or 3)

## Outputs

- Confirmation when values are inserted
- Display of the B-Tree structure
- Error message for invalid menu choices

## How to Compile & Run

g++ main.cpp BTree.cpp -o btree

./btree

## Program Testing

I have included 3 screenshots:
- Program start (entering degree)
- Inserting values (including invalid input example)
- Displaying the B-Tree
- Example values used: 10, 20, 5, 6, 12
