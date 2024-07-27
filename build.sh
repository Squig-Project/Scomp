if [ ! -d "bin" ]; then
    mkdir "bin"
    echo "Run the build script again."
else
    pushd "bin"

    gcc -c ../src/scomp.c -o scomp.o -lz -Wall -Wextra -Werror
    ar rcs libscomp.a scomp.o

    rm scomp.o
    popd
fi
