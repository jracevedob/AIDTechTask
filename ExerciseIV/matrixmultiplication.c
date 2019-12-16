#include <stdio.h>
#include <string.h>
#include <x86intrin.h>
#include <omp.h>

/* Matrix dimensions configurations */
#define N 1024
#define M 2048
#define K 512


void mm_nomultithreading(float *matrixA, float *matrixB, float *result) {
    /* Conventional nested loop for matrix multiplication */
    for(int i=0; i<N; i++) {
        for(int k=0; k<K; k++) {
            for(int j=0; j<M; j++) {
                result[i*M+j] += matrixA[i*M+k]*matrixB[k*M+j];
            }
        }
    }
}

void mm_multithreading(float *matrixA, float *matrixB, float *result) {
    /* Conventional nested loop for matrix multiplication with parallel construct enabled */
    #pragma omp parallel for
    for(int i=0; i<N; i++) {
        for(int k=0; k<K; k++) {
            for(int j=0; j<M; j++) {
                result[i*M+j] += matrixA[i*M+k]*matrixB[k*M+j];
            }
        }
    }
}   

void mm_multithreading_SIMD(float *matrixA, float *matrixB, float *result) {
   /* */
    #pragma omp parallel for
    for(int i=0; i<N; i++) {
        for(int k=0; k<K; k++) {
            __m128 broadcast_matrixA = _mm_set1_ps(matrixA[i*M+k]);
            for(int j=0; j<M; j+=4) {
                __m128 broadcast_result = _mm_load_ps(&result[i*M+j]);
                __m128 broadcast_matrixB = _mm_load_ps(&matrixB[k*M+j]);
                broadcast_result = _mm_add_ps(_mm_mul_ps(broadcast_matrixA,broadcast_matrixB),broadcast_result);
                _mm_store_ps(&result[i*M+j], broadcast_result);
            }
        }
    }
}

int main(int argc, char* argv[]) {

    /* Input matrix definition*/
    float *matrixA = _mm_malloc(N*M * sizeof *matrixA, 64);
    float *matrixB = _mm_malloc(M*K * sizeof *matrixB, 64);

    /* Resulting matrix definition */
    float *result_nmult = _mm_malloc(N*K * sizeof *result_nmult, 64);
    float *result_mult  = _mm_malloc(N*K * sizeof *result_mult, 64);
    float *result_mult_simd = _mm_malloc(N*K * sizeof *result_mult_simd, 64);

    /* Matrix initialization*/
    for(int i=0; i<N*M; i++) matrixA[i] = i % 10;
    for(int i=0; i<M*K; i++) matrixB[i] = i % 10;
    //memset(matrixA, 0, N*M * sizeof *matrixA);
    //memset(matrixB, 0, M*K * sizeof *matrixB);
    memset(result_nmult, 0, N*K * sizeof *result_nmult);
    memset(result_mult , 0, N*K * sizeof *result_mult);
    memset(result_mult_simd, 0, N*K * sizeof *result_mult_simd);
    double dtime;

    /* Processing and benchmarking*/
    
    dtime = -omp_get_wtime();
    mm_nomultithreading(matrixA,matrixB,result_nmult);
    dtime += omp_get_wtime();
    printf("Execution time NO multithreading: %f\n", dtime);
    
    
    dtime = -omp_get_wtime();
    mm_multithreading(matrixA,matrixB,result_mult);
    dtime += omp_get_wtime();
    printf("Execution time multithreading: %f\n", dtime);
    
    dtime = -omp_get_wtime();
    mm_multithreading_SIMD(matrixA,matrixB,result_mult_simd);
    dtime += omp_get_wtime();
    printf("Execution time multithreading and SIMD : %f\n", dtime);
  
    /*Error flags*/ 
    if(memcmp(result_nmult,result_mult, N*K*sizeof *result_nmult) != 0)
	printf("Error: Memory content mismatch\n");
    
    if(memcmp(result_nmult,result_mult_simd, N*K*sizeof *result_nmult) != 0)
 	printf("Error: Memory content mismatch\n");

    return 0;
}
