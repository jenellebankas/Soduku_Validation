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

void threadDef(){

    // declaring parameters struct 
    parameters *data = (parameters*) malloc(sizeof(parameters));
    data->row = 1;
    data->column = 1;

    // initialising threads
    // will re-factor this at some point 

    pthread_t thread1, thread2, thread3, thread4, thread5, thread6, thread7, thread8, thread9;

    pthread_create(&thread1, NULL, checkInt, data);
    pthread_create(&thread2, NULL, checkInt, data);
    pthread_create(&thread3, NULL, checkInt, data);
    pthread_create(&thread4, NULL, checkInt, data);
    pthread_create(&thread5, NULL, checkInt, data);
    pthread_create(&thread6, NULL, checkInt, data);
    pthread_create(&thread7, NULL, checkInt, data);
    pthread_create(&thread8, NULL, checkInt, data);
    pthread_create(&thread9, NULL, checkInt, data);

    pthread_join(thread1, NULL);
    pthread_join(thread2, NULL);
    pthread_join(thread3, NULL);
    pthread_join(thread4, NULL);
    pthread_join(thread5, NULL);
    pthread_join(thread6, NULL);
    pthread_join(thread7, NULL);
    pthread_join(thread8, NULL);
    pthread_join(thread9, NULL);
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