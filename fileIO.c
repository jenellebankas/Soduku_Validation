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
* @brief 
*
* @param 
* @returns
*/

int openFile(char filename[], MazeInfo *funcMazeInfo, MazePiece *funcMazePiece) {


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
    

    // Calls checkDimensions() function before proceding to ensure that time is not wasted

    int rowLength = checkRowDimensions(file);
    if (rowLength == EXIT_MAZE_ERROR) {
        return EXIT_MAZE_ERROR;
    }

    int colLength = checkColDimensions(file, rowLength);
    if (colLength == EXIT_MAZE_ERROR) {
        fclose(file);
        return EXIT_MAZE_ERROR;
    }

    funcMazeInfo->rowDimension = rowLength;
    funcMazeInfo->colDimension = colLength;

    allocateCheck = allocateMaze(funcMazeInfo, funcMazePiece);
    
    if (allocateCheck == EXIT_MAZE_ERROR) {
        fclose(file);
        return EXIT_MAZE_ERROR;
    }
    
    tokenCheck = tokeniseMaze(file, funcMazeInfo);


    if (tokenCheck != 0) {
        fclose(file);
        return EXIT_MAZE_ERROR;
    }
    
    fclose(file);
    return EXIT_SUCCESS;

}

/**
* @brief dynamically allocating memory for the mazeInfo struct, more specifically the maze map 
*
* @param funcMazeInfo declared in main() and memory allocated in the function
* @param funcMazePiece declared in main() and used for memory allocation for maze struct 
* @returns 0 when file opens and data, dimensions are valid and returns 3 if memory cannot be allocated 
*/


// This program is adapted from an example provided on: https://github.com/Scsabr/comp1921-struct-pointers/blob/main/code.c 

int allocateMaze(MazeInfo *funcMazeInfo, MazePiece *funcMazePiece) {

    funcMazeInfo->mazeMap = malloc(funcMazeInfo->rowDimension * sizeof(MazePiece));
    for (int i = 0; i < funcMazeInfo->rowDimension; i++) {
        funcMazeInfo->mazeMap[i] = malloc(funcMazeInfo->colDimension * sizeof(MazePiece));
    }

    if (!funcMazeInfo->mazeMap) {
        printf("Error: malloc failed\n");
        return EXIT_OTHER_ERROR;
    }

    return 0;
}
