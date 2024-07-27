#ifndef SCOMP_H
#define SCOMP_H

char* compress_data(char *input, const char *out_file, unsigned long *compressed_size);
void decompress_data(char *input, const char *out_file, unsigned long compressed_size);

#endif // SCOMP_H
