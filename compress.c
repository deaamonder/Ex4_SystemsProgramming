#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "compress.h"

void compress(FILE* inputFile, FILE* outputFile){
    if(inputFile == NULL || outputFile == NULL){
        printf("inputfile or outputfile is null");
        exit(1);
    }

    int digit;
    while(fscanf(inputFile,"%1d",&digit) == 1){ 
        printBinary(invertBinary(decimalToBinary(digit)),outputFile);
    }
}

void decompress(FILE* inputFile, FILE* outputFile){
    if(inputFile == NULL || outputFile == NULL){
        printf("inputfile or outputfile is null");
        exit(1);
    }
    int binary;
    while(fscanf(inputFile,"%04d",&binary) == 1){
        fprintf(outputFile,"%1d \n",binaryToDecimal(binary));
    }
}

int decimalToBinary(int num) {
    int binary = 0;

    // Calculate 4-bit binary representation
    for (int i = 0; i <= 3; i++) {
        binary |= ((num % 2) << i);
        num /= 2;
    }

    return binary;
}

unsigned int invertBinary(unsigned int binary) {
    unsigned int inverted = ~binary;
    return inverted ;  // Mask to keep only 4 bits
}

void printBinary(unsigned int binary, FILE* file) {
    for (int i = 0; i <= 3; i++) {
        fprintf(file,"%d", (binary >> i) & 1);
    }

    fprintf(file,"\n");
}

int binaryToDecimal(int binary) {
    int decimal = 0;
    int bit;

    for (int i = 0; i <= 3; i++) {
        bit = binary % 10;
        decimal += bit * (2^i);
        binary /= 10;
    }

    return decimal;
}