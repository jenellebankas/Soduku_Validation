/**
 * @file functions.c
 * @author Jenelle Bankas 
 * @brief Sudoku Solution Validator 
**/

#include "define.h"
#include "fileIO.h"

// all helper functions declared here

/**
* @brief 
*
* @param 
* @returns
*/

// setup threads here to check the rows and columns 

int threadDef(){

    // initialising thread 
    pthread_t thread_id;
    pthread_create(&thread_id, NULL, checkInt, NULL);
    pthread_join(thread_id, NULL);

    return 0;
}

/**
* @brief 
*
* @param 
* @returns
*/

// function for checking if all values found 
// using flags to check if values 1-9 are present 
// make current val be to check and re
// do by column with 9 threads 

int* checkInt(gridInfo *grid, int startIndex){

    int validNum = {1, 2, 3, 4, 5, 6, 7, 8, 9};
    int i = 0;
    int count = 0;

    // for loop through validNum and for every value in row/column check if present
    // need count 
    int isValid = 0;
    return 0;
}