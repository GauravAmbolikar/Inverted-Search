# Inverted Search

## Description

Inverted Search is a C-based project that creates an inverted index from multiple text files. It stores each word along with the files in which the word occurs and the number of times it appears in each file.

The project uses a hash table to store words and linked lists to maintain file names and word counts.

## Features

- Read and validate multiple `.txt` files
- Create an inverted database using a hash table
- Store words according to their first character
- Store the number of files containing each word
- Store the word count for each file
- Search for a word in the database
- Display the complete database
- Update the database by adding a new text file
- Save the database to a file
- Overwrite an existing database file

## Technologies Used

- C
- Hash Table
- Singly Linked List
- Structures
- Pointers
- Dynamic Memory Allocation
- File Handling
- String Handling
- Makefile
- GCC

## Compilation

Compile the project using Makefile:

```bash
make