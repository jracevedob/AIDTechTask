# AIDTechTask #

This repository contains the solution to five exercises used during the recruiting process at 
AID GmbH for the position of Compute Platform Engineer. Therefore, you find here descriptions and explanations about the current hardware trends employed as acceleration engines for autonomous driving at the level 4/5. Additionally, a block diagram design is provided to integrate the software stack for a self-driving car into its central compute platform.

Finally, besides to the merely descriptive content of some of those exercises, the reader will find several ***software code pieces*** implemented mainly in C. Those programs will implement matrix multiplication operations using SIMD (Single Instruction Multiple Data) instructions, and systolic arrays, which are based on the principle of MISD(Multiple Instructions Single Data).

## Setup description ##

All the exercises were implemented on a machine with the X86 architecture, running a virtual machine with GNU/Ubuntu 18.04.1 LTS (Bionic Beaver) on top of it. The code was compiled using the GCC compiler version 7.4.0.

## Table of contents ##

The development of each exercise is encapsulated on different directories to maintain the development organized and to grant an easy understanding for the reader.

- __Exercise I__ [[Hardware acceleration engines](https://github.com/jracevedob/AIDTechTask/tree/master/ExerciseI)]
- __Exercise II__ [[Block diagram desgin](https://github.com/jracevedob/AIDTechTask/tree/master/ExerciseII)]
- __Exercise III__ [[GPU multicore multithreading](https://github.com/jracevedob/AIDTechTask/tree/master/ExerciseIII)]
- __Exercise IV__ [[Implementation matrix multiplication with SIMD instructions](https://github.com/jracevedob/AIDTechTask/tree/master/ExerciseIV)]
- __Exercise V__ [[Implementation matrix multiplication with systolic arrays](https://github.com/jracevedob/AIDTechTask/tree/master/ExerciseV)]


## Installation and support
In each repository, the reader will find a README file in which is described where the descriptions are located or how to execute the software implementations. In order to clone this respository with git, the reader just have to select a directory where to clone the code, i.e, $TOP_DIR. For instance:

```bash
$ cd $TOP_DIR
$ git clone https://github.com/jracevedob/AIDTechTask AIDTechTask
```

Since this is private repository, the access to it will be granted only to members of the staff of AID GmbH.

## Known issues
All the software implementation were vastly tested and until its release not errors were detected.
