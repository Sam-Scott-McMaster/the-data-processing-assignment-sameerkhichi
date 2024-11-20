/*
Name: Sameer Khichi
MacID: khichis
Student Number: 400518172
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "clean.h"


int main(int argc, char* argv[]){

    //variable library
    int rows;
    int manipulated_rows;
    int cols;
    float** data;
    bool dFlagChecker = false;

    //checking if the -d flag is used
    if( (argc == 2) && (strcmp(argv[1], "-d") == 0) ){
        dFlagChecker = true;
    }

    //reading the data as a 2D array
    data = read_data(&rows, &cols);

    //handling if no data is given
    if(!data){
        fprintf(stderr, "No data given");
        exit(EXIT_FAILURE);
    }

    //calling the appropriate function if the -d flag is used or not
    if(dFlagChecker){
        
        data = clean_delete(data, rows, cols, &manipulated_rows);
        //for the row counter as # of rows will change after some are deleted
        rows = manipulated_rows;

    }
    else{
        clean_impute(data, rows, cols);
    }

    //output the data with the correct format
    output_data(data, rows, cols);

    //freeing the allocated memory after the program has finished
    free_memory(data, rows);

    return EXIT_SUCCESS;
}