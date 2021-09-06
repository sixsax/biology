CC = gcc
CFLAGS = -g -Wall
RM = find

all = biologist

biology: biologist.o ribosome.o nucleobase.o nucleotide.o codon.o lib/list.o
	$(CC) $(CFLAGS) -o biology biologist.o ribosome.o nucleobase.o nucleotide.o codon.o lib/list.o

biologist: biologist.o
	$(CC) $(CFLAGS) -o biologist.o

codon.o: codon.c codon.h nucleotide.c nucleotide.h
	$(CC) $(CFLAGS) -c codon.c

nucleotide.o: nucleotide.c nucleotide.h nucleobase.c nucleobase.h
	$(CC) $(CFLAGS) -c nucleotide.c

nucleobase.o: nucleobase.c nucleobase.h
	$(CC) $(CFLAGS) -c nucleobase.c

ribosome.o: ribosome.c ribosome.h
	$(CC) $(CFLAGS) -c ribosome.c

#lib
lib/lib.o: lib/list.c lib/list.h
	$(CC) $(CFLAGS) -c lib/list.c -o lib/list.o
#end lib

clean:
	$(RM) . -name "*.gch" -delete -o -name "*.o" -delete -o -name "biology" -delete
