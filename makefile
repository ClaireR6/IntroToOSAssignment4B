a.exe : Assignment4PartB.o
	gcc Assignment4PartB.o

Assignment4.o : Assignment4PartB.c
	gcc -c Assignment4PartB.c

clean : 
	rm a.exe
	rm Assignment4PartB.o


