/**
 * @file define.h
 * @author Jenelle Bankas 
 * @brief Sudoku Solution Validator 
**/

#ifndef DEFINES_FILE
#define DEFINES_FILE

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include <pthread.h>
#include <unistd.h>


// Defines for max and min permitted dimensions
#define ACCEPTED_DIM 9

// Defines for the required autograder exit codes
#define EXIT_SUCCESS 0
#define EXIT_ARG_ERROR 1
#define EXIT_FILE_ERROR 2
#define EXIT_OTHER_ERROR 2

// define constants here 

// defining data type for storing thread information
typedef struct {
    int row;
    int column;
} parameters;

// defining data type for storing grid info
typedef struct {
    int **gridArray;
    int rowDim;
    int colDim;
} gridInfo;

#endif