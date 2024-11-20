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
    float** data = malloc(*rows *sizeof(float*));
    if(!data){
        fprintf(stderr, "Error allocating memory");
        exit(EXIT_FAILURE);
    }


    if( scanf("%d,%d", rows, cols) != 2 ){
        fprintf(stderr, "There was an error checking row and column sizes. \n");
    }


    for(int i = 0; i < *rows; i++){

        //allocating memory for the rows using malloc
        data[i] = malloc(*cols *sizeof(float));
        
    }

    for(int i = 0; i < *rows; i++){
        for(int j = 0; j < *cols; j++){
            if(scanf("%f", &data[i][j]) != 1){
                data[i][j] = NAN;
            }
        }
    }
}


float** clean_delete(float** data, int rows, int cols, int* manipulated_rows){

}

void clean_impute(float** data, int rows, int cols){

}

void output_data(float** data, int rows, int cols){

}
