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
* @brief checks each column of integers to see if all expected values appear
*
* @param grid
* @returns
*/

int* checkIntCol(gridInfo *grid, parameters *index){

    int i = index->column;
    int isValid = 0;
    
    for(int c = 1; c<=9; c++){
        for(i; i<=9; i++){
            if(grid->gridArray[index->row][i] == c){
                isValid = 1;
                continue;
                isValid = 0;
            }
        }
    }

    if(isValid){
        return 0;
    } else {
        return 1;
    }
}

/*
* @brief checks each row of integers to see if all expected values appear
*
* @param grid
* @returns
*/


int* checkIntRow(gridInfo *grid, parameters *index){

    int i = index->row;
    int isValid = 0;
    
    for(int c = 1; c<=9; c++){
        for(i; i<=9; i++){
            if(grid->gridArray[i][index->column] == c){
                isValid = 1;
                continue;
                isValid = 0;
            }
        }
    }

    if(isValid){
        return 0;
    } else {
        return 1;
    }
}