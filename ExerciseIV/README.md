
For this exercise was implemented an algorithm of matrix multiplication using matrices of different sizes. The code is a C program which compares the execution time of the matrix multiplication operation using nested loops without multithreading, nested loops with multithreading, and finally a matrix multiplication using multithreading and SIngle Input Multiple Data (SIMD) instructions. The computing platform for this exercise was the following:

```bash
Architektur:                   x86_64
CPU Operationsmodus:           32-bit, 64-bit
Byte-Reihenfolge:              Little Endian
CPU(s):                        8
Liste der Online-CPU(s):       0-7
Thread(s) pro Kern:            2
Kern(e) pro Socket:            4
Sockel:                        1
NUMA-Knoten:                   1
Anbieterkennung:               GenuineIntel
Prozessorfamilie:              6
Modell:                        94
Modellname:                    Intel(R) Core(TM) i7-6700T CPU @ 2.80GHz
Stepping:                      3
CPU MHz:                       900.034
Maximale Taktfrequenz der CPU: 3600,0000
Minimale Taktfrequenz der CPU: 800,0000
BogoMIPS:                      5616.00
Virtualisierung:               VT-x
L1d Cache:                     32K
L1i Cache:                     32K
L2 Cache:                      256K
L3 Cache:                      8192K
NUMA-Knoten0 CPU(s):           0-7

```

In order to compile the program, please run the following command:

```bash
gcc -std=c99 -O3 -fopenmp -mfpmath=sse -msse2 -Wall matrixmultiplication.c
```

Then, the resulting file can be executed with the following command:

```bash
./a.out
```
In this case, the name of the executable was not provided, but the user can assign a name for this executable according to his/her preferences. 

When the programm is executed in the mentioned computing platform, the following results were obtained:

| Acceleration Metodology | Execution time (s) |
| ----------------------- | -------------- |
| Nested loop without hiperthreading       | 0,244176 |
| Nested loop with hiperthreading          | 0,053835 |
| Nested loop with hiperthreading and SIMD | 0,045866 |

The matrix sizes used for this implementation were 1024x2048 and 2048x512. Then, the resulting matrix has a dimension of 1024x512.

Questions:
- Absolute performance calculation: In order to calculate the absolute performance the number of total operations must be considered. The total number of operations for a matrix multiplication of different dimensions is given by N*K(M(M-1)), where the matrix A has a dimension NxM, and the matrix B has a dimension of MxK. Then the absolute performance is the relationship between the number of operation and the exection time of the multiplications.

| Acceleration Metodology | Absolute  performance in FLOPS |
| ----------------------- | -------------- |
| Nested loop without hiperthreading       | 9e+12 |
| Nested loop with hiperthreading          | 4e+13 |
| Nested loop with hiperthreading and SIMD | 4.8+13|

- Performance limitation factors: 