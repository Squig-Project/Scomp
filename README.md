# Scomp
Scomp(SquigCompress) is a compression library made in pure C with zlib.

## Requirements
To build Scomp, you have to own a Linux machine, this project has not been tested for the Windows platform. Make sure you have installed zlib, gnu compiler collection v12.2.0, and the GNU binutils.

## Compiling
To compile Scomp, run the ``./build.sh`` script. To clean up the bin folder, run the ``./clean.sh`` script.

## License
Scomp goes by the Zlib license, for more information read LICENSE.txt.

## Examples
```c
#include"scomp.h"

int main(void)
{
  char buffer[14] = "Hello, World!";

  unsigned long compressed_size;
  // both functions writes the data to an output file, specified in the out_file argument.
  char *compressed_data = compress_data(buffer, "compressed.scomp", &compressed_size);
  decompress_data(compressed_data, "decompressed.txt", compressed_size);
  return 0;
}
```
