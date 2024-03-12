//#include <stdio.h>

#ifndef COMPRESS_H
#define COMPRESS_H

void compress(FILE* inputFile, FILE* outputFile);
void decompress(FILE* inputFile, FILE* outputFile);
unsigned int invertBinary(unsigned int num);
int decimalToBinary(int num);
void printBinary(unsigned int binary, FILE* file);
int binaryToDecimal(int binary);


#endif