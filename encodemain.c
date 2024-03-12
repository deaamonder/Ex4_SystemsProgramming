#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "compress.h"
    
int main(int argc, char *argv[]) {
    if (argc != 4) {
        fprintf(stderr, "Usage: %s <input_file> -c/-d <output_file>\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    FILE *inputFile = fopen(argv[1], "r");
    if (inputFile == NULL) {
        fprintf(stderr, "Error opening input file: %s\n", argv[1]);
        exit(EXIT_FAILURE);
    }

    FILE *outputFile = fopen(argv[3], "wb");
    if (outputFile == NULL) {
        fclose(inputFile);
        fprintf(stderr, "Error opening output file: %s\n", argv[3]);
        exit(EXIT_FAILURE);
    }

    if (strcmp(argv[2], "-c") == 0) {
        // Compress the file
        compress(inputFile, outputFile);
        printf("File compressed successfully!\n");
    } else if (strcmp(argv[2], "-d") == 0) {
        // Decompress the file
        decompress(inputFile, outputFile);
        printf("File decompressed successfully!\n");
    } else {
        fprintf(stderr, "Invalid option: %s\n", argv[2]);
        fclose(inputFile);
        fclose(outputFile);
        exit(EXIT_FAILURE);
    }

    fclose(inputFile);
    fclose(outputFile);

    return 0;
}