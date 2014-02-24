#Christine Malong: Tin2x
#Gregory Tacker: gctacker

#makefile

header = common.h     #declare header variables
files = main.c print.c #declare .c file variables

#name of program to build
default: lister 

#build files into .o file before making executable
lister.o: $(files) $(header)
	gcc $(files) -o lister.o

#build files into executable
lister: lister.o
	gcc $(files) -o lister


