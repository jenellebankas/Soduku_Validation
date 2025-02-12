/**
 * @file functions.c
 * @author Jenelle Bankas 
 * @brief Sudoku Solution Validator 
**/

#include "define.h"

// all helper functions declared here
// grid from text file and processed in here 

// need to check for empty spaces and invalid tokens (maybe inputted as csv)

/**
* @brief opens file and carries out initial error checking
*
* @param 
* @returns
*/

int openFile(char filename[], gridInfo *funcGridInfo) {

    // Error checking for the contents of the file, this program is adapted from an example provided on: https://stackoverflow.com/questions/13566082/how-to-check-if-a-file-has-content-or-not-using-c
    
    long size;
    int allocateCheck;
    int tokenCheck;

    FILE *file = fopen(filename, "r");

    if (file == NULL) {
        printf("File does not exist\n");
        return EXIT_FILE_ERROR;
    } 
    
    fseek(file, 0, SEEK_END);
    size = ftell(file);

    
    if (size == 0) {
        printf("File is empty\n");
        fclose(file);
        return EXIT_FILE_ERROR;
    } else {
        printf("File loaded successfully\n");
        printf("\n");
        fseek(file, 0, SEEK_SET);
    }
    
    allocateCheck = allocateMaze(funcGridInfo);
    
    if (allocateCheck == EXIT_FILE_ERROR) {
        fclose(file);
        return EXIT_FILE_ERROR;
    }
    
    tokenCheck = tokeniseMaze(file, funcGridInfo);

    if (tokenCheck != 0) {
        fclose(file);
        return EXIT_FILE_ERROR;
    }
    
    fclose(file);
    return EXIT_SUCCESS;

}

/**
* @brief dynamically allocating memory for the mazeInfo struct, more specifically the maze map 
*
* @param 
* @param
* @returns 0 when file opens and data, dimensions are valid and returns 3 if memory cannot be allocated 
*/


// This program is adapted from an example provided on: https://github.com/Scsabr/comp1921-struct-pointers/blob/main/code.c 

int allocateGrid(gridInfo *funcGridInfo) {

    funcGridInfo->gridArray = malloc(9 * sizeof(char));
    for (int i = 0; i < 9; i++) {
        funcGridInfo->gridArray[i] = malloc(9 * sizeof(char));
    }

    if (!funcGridInfo->gridArray) {
        printf("Error: malloc failed\n");
        return EXIT_OTHER_ERROR;
    }

    return 0;

}


/**
* @brief check dimensions of file are correct
*
* @param file from the user 
* @return number of columns or 3 if error occurs with characters in the maze or bounds 
*/

int checkDimensions(FILE *file) {

    fseek(file, 0, SEEK_SET);

    // Idea taken from: https://stackoverflow.com/questions/2137156/finding-line-size-of-each-row-in-a-text-file#:~:text=If%20you%20already%20know%20that,strlen()%20on%20each%20substring.

    int i = 0;
    int j = 0;
    char c;

    fseek(file, 0, SEEK_SET);
    
    for (j = 0; j < 11; j++) {
        i = 0; 

        while ((c = fgetc(file)) != '\n') {
            if(c != ',')
                i++; 

            if (c == EOF) {
                i--;
                break;
            }

            int check = atoi(c);
            if (check != 0) {
                printf("Data in file is not valid\n");
                return EXIT_FILE_ERROR;
            }
        }

        if (i != ACCEPTED_DIM) {
            printf("Grid dimensions not valid\n");
            return EXIT_FILE_ERROR;
        }   
    }
    

    if (j < ACCEPTED_DIM || j > ACCEPTED_DIM) {
        printf("File dimensions not valid\n");
        return EXIT_FILE_ERROR;
    }

    return 0;
}


/**
* @brief input values for rows and columns and changes MAZEINFO instance of struct and adds to MAZEPIECE 2D array 
*
* @param file is used to be iterated over and characters put into the struct funcMazeInfo 
* @param funcGridInfo struct used to put characters into 
*
* @returns 3 if an error occurs with number of starts and ends or 0 if one does not 
*/
 

// Fgetc() taken from: https://stackoverflow.com/questions/4179671/read-in-text-file-1-character-at-a-time-using-c use this in this function

int tokeniseMaze(FILE *file, gridInfo *funcGridInfo) {

    fseek(file, 0, SEEK_SET);

    char c;
    int invalidGrid = 0;
    
    
    for (int i = 0; i < 9; i++) {
        for (int j = 0; j < 9; j++) {

            c = fgetc(file);
            
            // check if an integer 
            if (c == '\n') {
                continue;
            } else {
                funcGridInfo->gridArray[i][j] = atoi(c);  
            }
        }
    }
    
    if (invalidGrid) {
        printf("Data in file is not valid\n");
        return EXIT_FILE_ERROR;
    }
    
    return 0;

}
