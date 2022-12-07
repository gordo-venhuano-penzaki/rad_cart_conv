#!/bin/bash


gcc -x c -c -fgnu-tm -g -O0 utils.h -o utils.o -lm
gcc -x c -g -O0 rad_cart_conv.c -o tests -lm

