#!/bin/bash

for (( c=510; c<=22710; c+=222 ))
do  
   ./lab1-seq $c >> ./res-gcc/gcc-seq.txt
   ./lab1-par-1 $c >> ./res-gcc/gcc-par-1.txt
   ./lab1-par-4 $c >> ./res-gcc/gcc-par-4.txt
   ./lab1-par-16 $c >> ./res-gcc/gcc-par-16.txt
   ./lab1-par-20 $c >> ./res-gcc/gcc-par-20.txt
done
