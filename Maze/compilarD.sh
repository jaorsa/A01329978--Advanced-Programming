gcc -Wall -fPIC -c 01_static_library.c
gcc -shared -o liboperations.so 01_static_library.o
gcc -o dynamic 03_static\&dynamic.o liboperations.so

echo $LD_LIBRARY_PATH
export LD_LIBRARY_PATH=.
./dynamic
