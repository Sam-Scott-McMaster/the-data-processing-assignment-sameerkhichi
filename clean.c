/*
Name: Sameer Khichi
MacID: khichis
Student Number: 400518172
*/
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "clean.h"


float** read_data(int* rows, int* cols){

    
    //malloc is a function that assigns memeory from allocated space
    //this block of code will check if there was any problems doing so and will be in every function
    float** data = malloc(*rows * sizeof(float*));
    if(!data){
        fprintf(stderr, "Error allocating memory");
        exit(EXIT_FAILURE);
    }


    if( scanf("%d,%d", rows, cols) != 2 ){
        fprintf(stderr, "There was an error checking row and column sizes. \n");
    }


    for(int i = 0; i < *rows; i++){

        //allocating memory for the rows using malloc
        data[i] = malloc(*cols * sizeof(float));
        
    }

    //processes the 2D array
    for(int i = 0; i < *rows; i++){
        for(int j = 0; j < *cols; j++){
            //if scanf doesnt return that it read a value (float) successfully it assigns it to NAN
            if(scanf("%f", &data[i][j]) != 1){
                data[i][j] = NAN;
            }
        }
    }
    return data;
}


float** clean_delete(float** data, int rows, int cols, int* manipulated_rows){

    //pointer keeping track of the rows checked for NAN
    *manipulated_rows = 0;

    //allocate memory for a new array which is a copy of the original
    //again this just checks if memory was allocated right
    float** manipulated_data = malloc(rows * sizeof(float*));
    if(!manipulated_data){
        fprintf(stderr, "Error allocating memory");
        exit(EXIT_FAILURE);
    }

    for(int i = 0; i < rows; i++){
        bool hasNAN = false;

        //a check to see if the column has a NAN value
        for(int j = 0; j < cols; j++){
            if(isnan(data[i][j])){
                hasNAN = true;
                break;
            }
        }

        //if the row didnt have any NAN values and allocate the copy of the original array space accordingly
        if(!hasNAN){
            manipulated_data[*manipulated_rows] = malloc(cols * sizeof(float));
            for(int j = 0; j < cols; j++){
                manipulated_data[*manipulated_rows][j] = data[i][j];
            }
            (*manipulated_rows)++;
        }

        //resizes a block of memory using realloc that was allocated using malloc
        //perameter: previous allocated memory array, new memory size block calculation respectively
        manipulated_data = realloc(manipulated_data, (*manipulated_rows) *sizeof(float*));
        
        return manipulated_data; //returns this array

    }
}

void clean_impute(float** data, int rows, int cols){

}

void output_data(float** data, int rows, int cols){

}
