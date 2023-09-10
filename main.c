#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void get_size(int *rows_count, int *columns_count);
void fill_matrix_random(int *arr, int rows_count, int columns_count);
void print_matrix(int *arr, int rows_count, int columns_count);
int* mul_matrix(int *matrix1, int *matrix2, int n, int m);
int one_thread_func(int *matr1, int *matr2, int len);
int* get_column(int *matrix, int n, int m, int number);
void print_array(int *array, int len);
int get_entropy();


int main() {
    int rows_number, columns_number;
    get_size(&rows_number, &columns_number);

    int matrix1[rows_number][columns_number];
    int matrix2[rows_number][columns_number];
    fill_matrix_random(matrix1, rows_number, columns_number);
    print_matrix(matrix1, rows_number, columns_number);
    fill_matrix_random(matrix2, rows_number, columns_number);
    print_matrix(matrix2, rows_number, columns_number);
    int* mmm;
    mmm = mul_matrix(matrix1, matrix2, rows_number, columns_number);
    print_matrix(mmm, rows_number, columns_number);
    return 0;
}

void get_size(int *rows_count, int *columns_count) {
    scanf("%d %d", rows_count, columns_count);
}

void fill_matrix_random(int *arr, int rows_count, int columns_count) {
    int seed;
    seed = get_entropy();
    srand(seed);
    for (int i = 0; i < rows_count * columns_count; i++) {
        arr[i] = rand() & 1;
    }
}

void print_matrix(int *arr, int rows_count, int columns_count) {
    printf("--------\n");
    for (int i = 0; i < rows_count * columns_count; i++) {
        if ((i != 0) && (i % columns_count == 0))
            printf("\n");
        printf("%d ", arr[i]);
    }
    printf("\n--------\n");
}

int* mul_matrix(int *matrix1, int *matrix2, int n, int m) {
    int* result_matrix;
    result_matrix = malloc(n * m * sizeof(int));
    for (int i = 0; i < n*m; i++) {

//        printf("string (%d): ", i / m);
//        print_array(&matrix1[(i / m) * m], m);
//        printf("column (%d): ", i % m);
//        print_array(get_column(matrix2, n, m, i % m), m);
//        printf("%d", one_thread_func(&matrix1[(i / m) * m], get_column(matrix2, n, m, i % m),
//                        m));
//        printf("\n\n");

        result_matrix[i] = one_thread_func(&matrix1[(i / m) * m], get_column(matrix2, n, m, i % m),
                                           m);
    }
    return result_matrix;
}

int one_thread_func(int *matr1, int *matr2, int len) {

//    print_array(matr1, len);
//    print_array(matr2, len);
//    printf("\n");

    int result = 0;
    for (int i = 0; i < len; i++)
        result += matr1[i] * matr2[i];
    return result;
}

int* get_column(int *matrix, int n, int m, int number) {
    int* column;
    column = malloc(n * sizeof(int));
    for (int i = 0; i < n; i++) {
        column[i] = matrix[number + i*m];
    }
    return column;
}

void print_array(int *arr, int len) {
    for (int i = 0; i < len; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int get_entropy() {
    int seed, start, finish;
    start = (int) clock();
    finish = (int) clock();
    seed = finish - start;
    return seed % 512;
}