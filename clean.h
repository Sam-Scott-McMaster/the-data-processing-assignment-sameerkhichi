/*
Name: Sameer Khichi
MacID: khichis
Student Number: 400518172
*/
float** read_data(int* rows, int* cols);
float** clean_delete(float** data, int rows, int cols, int* manipulated_rows);
void clean_impute(float** data, int rows, int cols);
void output_data(float** data, int rows, int cols);
void free_memory(float** data, int rows);