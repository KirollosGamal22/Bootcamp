Cflags=-Wl,-Map=main.map,--cref
sum.exe: main.o func1.o func2.o
	gcc -o sum.exe main.o func1.o func2.o
	gcc $^ --output $@ $(Cflags)
main.o: main.c func1.h func2.h
	gcc -c main.c
func1.o: func1.h func1.c
	gcc -c func1.c
func2.o: func2.h func2.c
	gcc -c func2.c	
Clean: 
	del *.o sum.exe
