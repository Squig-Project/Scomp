#include<zlib.h>
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include"scomp.h"

char* compress_data(char *input, const char *out_file, unsigned long *compressed_size) 
{
    *compressed_size = compressBound(strlen(input) + 1);

    char *compressed_data = (char *)malloc(*compressed_size);
    if (compressed_data == NULL) { perror("malloc"); return NULL; }

    int res = compress((Bytef *)compressed_data, compressed_size, (Bytef *)input, strlen(input) + 1);
    if (res != Z_OK) 
    { 
        fprintf(stderr, "Compression failed\n"); 
        free(compressed_data); 
        return NULL; 
    }

    FILE *file = fopen(out_file, "wb");
    if (file == NULL) { perror("fopen"); return NULL; }

    fwrite(compressed_data, 1, *compressed_size, file);
    fclose(file);
    return compressed_data;
}

void decompress_data(char *input, const char *out_file, unsigned long compressed_size) 
{
    unsigned long uncompressed_size = 1024; // just in case

    char *uncompressed_data = (char *)malloc(uncompressed_size);
    if (uncompressed_data == NULL) { perror("malloc"); return; }

    int res = uncompress((Bytef *)uncompressed_data, &uncompressed_size, (Bytef *)input, compressed_size);
    if (res == Z_BUF_ERROR) 
    {
        free(uncompressed_data);
        uncompressed_size *= 2;
        uncompressed_data = (char *)malloc(uncompressed_size);
        if (uncompressed_data == NULL) { perror("malloc"); return; }

        res = uncompress((Bytef *)uncompressed_data, &uncompressed_size, (Bytef *)input, compressed_size);
    }
    if (res != Z_OK) 
    { 
        fprintf(stderr, "Decompression failed\n"); 
        free(uncompressed_data);
        return; 
    }

    FILE *file = fopen(out_file, "w");
    if (file == NULL) { perror("fopen"); return; }

    fwrite(uncompressed_data, 1, uncompressed_size, file);
    fclose(file);
    free(uncompressed_data);
}
