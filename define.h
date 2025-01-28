/**
 * @file functionIO.h
 * @author Jenelle Bankas 
 * @brief Sudoku Solution Validator 
**/

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include <pthread.h>
#include <unistd.h>

// define constants here 

// defining data type for storing thread information
typedef struct {
    int row;
    int column;
} parameters;

// defining data type for storing grid info
typedef struct {
    
} grid;