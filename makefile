FLAGS= -g -Wall
all: sub test orig
	

sub: substitution_cipher.c
	gcc substitution_cipher.c -c $(FLAGS)

test: sub substitution_cipher_tests.c
	gcc substitution_cipher_tests.c $(FLAGS) substitution_cipher.o -o test.out

orig: sub substitution_cipher.c
	gcc substitution_cipher.c $(FLAGS) -DRUN
