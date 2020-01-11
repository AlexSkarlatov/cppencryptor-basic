#pragma once


#include "p3header.h"
#include <stdio.h>
#define _CRT_SECURE_NO_WARNINGS


#include <ctype.h>        
#include <stdio.h>        
#include <stdlib.h>       
#include <time.h>         
#include <string.h>

//prototypes
//method 1
/*this method will take the file pointer and input character by  character into an array using a char 
file point*/
void getInputMessage(FILE *, char *);

//method 2
/* this method will implement the rotation alogrithm using char array pointer, an array pointer to the
integer key array that holds the key, and the length of the key array is passed by copy to reset it when necessary
code is implemented to account for overwrapping and for when it is not a an alphabetical character*/
void encrypt(char *, int *, int);

//method 3
/*this method will implement the rotation algorithm necessary to decrypt the message operating like encrypt but in 
reverse. parameyers passed are the same as encrypt e.g. a msg character array, a key integer array, and length of
the key integer array*/
void decrypt(char *, int *, int);

//method 4
/*this method will output a formal report to a file using a given character array, the characters will be 
written character by charactyer until the reach '\0' character to a given file pointer*/
void output(char *, FILE *);
