#include <stdio.h>
#include <string.h>
#include <x86intrin.h>
#include <omp.h>

/* Matrix dimensions configurations */

/* Golden Matrix sizes*/
#define MATRIX_SIZE 4
#define MAX_MATRIX_SIZE 16


void nestedmatrixmultiplication(int *matrixA, int *matrixB, int *result) {
 /* Conventional nested loop for matrix multiplication */
    for(int i=0; i<MATRIX_SIZE; i++) {
        for(int k=0; k<MATRIX_SIZE; k++) {
            for(int j=0; j<MATRIX_SIZE; j++) {
                result[i*MATRIX_SIZE+j] += matrixA[i*MATRIX_SIZE+k]*matrixB[k*MATRIX_SIZE+j];
            }
        }
    }
}

void mm_systolicarray(const int *matrixA, const int *matrixB, int *result) {
    
    /* Auxiliar varibles for matrix decomposition*/
    int i,j,k, pos = 0;

    /* Internal matrices declaration */
    int internalA[MATRIX_SIZE][MATRIX_SIZE];
    int internalB[MATRIX_SIZE][MATRIX_SIZE];
    int internalresult[MATRIX_SIZE][MATRIX_SIZE];

    memset(internalresult, 0, MATRIX_SIZE*MATRIX_SIZE);

    
    /*PEs fill out using matrix A*/
    for (pos = 0, i = 0, j = 0; pos < MATRIX_SIZE*MATRIX_SIZE; pos++, j++) {
        if (j == MAX_MATRIX_SIZE) {
            i++;
            j = 0;
        }
        internalA[i][j] = matrixA[pos];
    }

    /*PEs fill out using matrix B*/
    for (pos = 0, i = 0, j = 0; pos < MATRIX_SIZE*MATRIX_SIZE; pos++, j++) {
        if (j == MAX_MATRIX_SIZE) {
            i++;
            j = 0;
        }
        internalB[i][j] = matrixB[pos];
    }

   
     for (k = 0; k < MAX_MATRIX_SIZE; k++) {
        for (i = 0; i < MATRIX_SIZE; i++) {
            for (j = 0; j < MATRIX_SIZE; j++) {
                int last;
                if(k == 0){
		  last = 0;
                }else{
                  last = internalresult[i][j];
                }

                int a_aux, b_aux;
                if(i < MATRIX_SIZE && k < MATRIX_SIZE){
			a_aux = internalA[i][k];
		} else {
			a_aux= 0;
                }

                if(k < MATRIX_SIZE && j < MATRIX_SIZE){
			b_aux = internalB[k][j];
		} else {
			b_aux= 0;
                }
               
                internalresult[i][j] = last + (a_aux*b_aux);
            }
        }
    }

    for (pos = 0, i = 0, j = 0; pos < MATRIX_SIZE*MATRIX_SIZE; pos++, j++) {
        if (j == MAX_MATRIX_SIZE) {
            i++;
            j = 0;
        }
        result[pos] = internalresult[i][j];
    }
    
    
}   



int main(int argc, char* argv[]) {

    /* Time variable */
    double dtime;

    /* Input matrix definition*/
    int *matrixA = _mm_malloc(MATRIX_SIZE*MATRIX_SIZE * sizeof *matrixA, 4);
    int *matrixB = _mm_malloc(MATRIX_SIZE*MATRIX_SIZE * sizeof *matrixB, 4);

    /* Resulting matrix definition */
    int *result_nmult = _mm_malloc(MATRIX_SIZE*MATRIX_SIZE * sizeof *result_nmult, 4);
    int *result_systolicarray = _mm_malloc(MATRIX_SIZE*MATRIX_SIZE * sizeof *result_nmult, 4);

    /* Matrices's initialization */
    for(int i=0; i<MATRIX_SIZE*MATRIX_SIZE; i++) matrixA[i] = i % 10;
    for(int i=0; i<MATRIX_SIZE*MATRIX_SIZE; i++) matrixB[i] = i % 10;
    memset(result_nmult, 0, MATRIX_SIZE*MATRIX_SIZE * sizeof *result_nmult);
    memset(result_systolicarray, 0, MATRIX_SIZE*MATRIX_SIZE * sizeof *result_systolicarray);
    

    dtime = -omp_get_wtime();
    nestedmatrixmultiplication(matrixA,matrixB,result_nmult);
    dtime += omp_get_wtime();
    printf("Execution time NO multithreading: %f\n", dtime);

    dtime = -omp_get_wtime();
    mm_systolicarray(matrixA,matrixB,result_systolicarray );
    dtime += omp_get_wtime();
    printf("Execution time systolic: %f\n", dtime);


    return 0;
}
