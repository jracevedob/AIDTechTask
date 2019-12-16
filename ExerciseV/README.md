

In this directory is presented the design of a matrix multiplication algorithm using systolic arrays. The code is a C program which is composed of a fully nested loop implementation, and an implementation using systolic arrays by using Processing Elements(PE) of a dimension 4x4. The hardware architere used for this implementation is the following:

```bash
Architektur:             x86_64
CPU Operationsmodus:     32-bit, 64-bit
Byte-Reihenfolge:        Little Endian
CPU(s):                  2
Liste der Online-CPU(s): 0,1
Thread(s) pro Kern:      1
Kern(e) pro Socket:      1
Sockel:                  2
NUMA-Knoten:             1
Anbieterkennung:         GenuineIntel
Prozessorfamilie:        6
Modell:                  142
Modellname:              Intel(R) Core(TM) i7-7600U CPU @ 2.80GHz
Stepping:                9
CPU MHz:                 2903.998
BogoMIPS:                5807.99
Hypervisor-Anbieter:     VMware
Virtualisierungstyp:     voll
L1d Cache:               32K
L1i Cache:               32K
L2 Cache:                256K
L3 Cache:                4096K
NUMA-Knoten0 CPU(s):     0,1
```

 In order to compile the program, please run the following command:
```bash
$ gcc -std=c99 -O3 -fopenmp  -Wall matrixmultiplication.c
```

Then, the resulting file can be executed with the following command:
```bash
./a.out
```

Questions:
- How can matrix multiplication with systolic arrays be used for CNN?



- How is the ISA of a matrix multiplicator using systolic arrays?
