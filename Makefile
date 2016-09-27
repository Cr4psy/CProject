##Makefile

All: program.c usefulLibPerso.c fileReader.c euclideanDistance.c
	gcc -o program.out program.c usefulLibPerso.c fileReader.c euclideanDistance.c -lm
