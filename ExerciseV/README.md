

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
Convolutional Neural Networks are implemented as matrix multiplications. Therefore, the multiplication of matrices can be accelerated through hardware optimizations such as systolic arrays since they allow operand reuse in two dimensions, and data movements locally. The advantage of systolic arrays lies on the fact that the operand movements are local, from PE to PE inside the chip, which increase the computation density, reduces the latency, improves the enery eficiency, and makes simpler the control. Since the PE are always fetching and processing data, then another advantage is the higher throughputs. 

- How is the ISA of a matrix multiplicator using systolic arrays?
The basic ISA of a matrix multiplication using systolic arrays are composed by instruction of 3 addresses written in two data word. For instance a simple addition operation can be written as follows:

``` bash
add    op0, op1, dest
```
The processor is composed by registers such as the communication register, arithmetic units for addition and multiplication, and shifters. When the processor gets that instruction, then decodes the addresses of the two operands, op0 and op1. Then, it extracts the  operands from the register file and execute the operation of addition and writes the resulting value to the destination register, and continues with the next instruction. The paralellization comes at the bit level by fetching and processing data every 16 clock cycles, assuming that in every clock cycle only one bit can be processed. 