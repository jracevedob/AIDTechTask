# AIDTechTask #

This repository contains the solution to five exercises used during the recruiting process at 
AID GmbH for the position of Compute Platform Engineer. Therefore, you find here descriptions and explanations about the current hardware trends employed as acceleration engines for autonomous driving at the level 4/5. Additionally, a block diagram design is provided to integrate the software stack for a self-driving car into its central compute platform.

Finally, besides to the merely descriptive content of some of those exercises, the reader will find several ***software code pieces*** implemented mainly in C. Those programs will implement matrix multiplication operations using SIMD (Single Instruction Multiple Data) instructions, and systolic arrays, which are based on the principle of MISD(Multiple Instructions Single Data).

## Setup description ##

All the exercises were implemented on a machine with the X86 architecture, running a virtual machine with Ubuntu 18.04.1 on top of it. The code was compiled using the GCC compiler version 7.4.0.

## Table of contents ##

The development of each exercise is encapsulated on different directories to maintain the development organized and to grant an easy understanding for the reader.

__Hardware acceleration engines__ [[Exercise I](https://github.com/jracevedob/AIDTechTask/tree/master/ExerciseI)]