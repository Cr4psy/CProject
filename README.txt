README.txt

SUB-FUNCTION :
The program is divided in several sub-function. These functions can be found in different .c files :
- fileReader.c : is a function that reads the value of a file and convert into a 2D matrix. Each data in the file have to be number, the column separation are tabs and a new line has to be set with a line feed  The data file is build in a way that each row represent a vector which can have any dimensions. The limitation for the number of vector is 1000, but can be expended.
- euclideanDistance.c : computes the euclidean distance of two vectors of any dimensions as long as their dimensions are identical.
- usefulLibPerso.c : contains multi-functions that are used for several purposes. For instance, strToInt convert a string number into an array. randomNumberGenerator gives a random number in a define range. The last function, extractRow, returns a selected row from a 2D array.


MAIN :
The main function is divided in chapter, each chapter realise a specific tasks that are described below :
    1. Reads the value given through the terminal (m), only one value is accepted and it has to be a number.
    2. Extracts the data from the data file and convert to a 2D matrix called D.
    3. Creates a new matrix P, composed of m different points of the matrix D.
    4. Compute the euclidean distance between each value of P and D.
    5. Select the points Di closer of Pi and compute the average, this value is written in Pi.
    6. Compare the new calculated value of the matrix P with the old one. If there is a difference return to chapter 4.
    7. If there is no improvement, the iteration is stopped and the centroid are returned.


HEADER :
The header file contains all the functions initialisations, as well as the declaration of the different libraries needed.


MAKEFILE :
The make file allows to compile the program with the function "make" in the terminal, it includes all the files needed.

Anthony Clerc
2016-09-27
