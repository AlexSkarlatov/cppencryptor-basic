/*
by: Alexander Skarlatov
program description: This program will take a file, input the file character by character into a char array
using pointers, then encrypt the array using a rotation cipher, then output the array to fp2 encrypted-file
,then it will de encrypt the char array and output the result to fp3 unencrypted-file
*/


//problem is definitely the DEcrypt ,Method*****************
/* WHAT NEEDS WORK---------------------
the input mehthod needs some woprk i guess
*/


#define _CRT_SECURE_NO_WARNINGS
//output method must use putcher(*cp) to go to console and not printf(*) 
#include <stdio.h>

#include "p3header.h"
void main()
{
	//initialize variables
	FILE *fp1, *fp2, *fp3;
	int keySize = 10;
	char  msg[5000]; 
	int key[] = { 5 , 2 , -1 , 2 , -3 , 2 , -4 , -2, 6 , 4 };
	char filename[55],holder[55];
	printf("please input filename\n");
	scanf("%s", filename);

	fp1 = fopen(filename, "r");
	fp2 = fopen("encrypted-message-1", "w");
	fp3 = fopen("unencrypted-m-1", "w");
	//method 1
	//call inputMethod()
	getInputMessage(fp1, msg);//input works
	//method2
	//call encrypt()
	output(msg, fp2);

	encrypt( msg, key, keySize);
	//put encrypted to file
	output(msg, fp2);
	
	
	
	
	
	
	
	//method 3
	//call decrypt method
    decrypt(msg, key, keySize);
	//method 4
	//call output() method
	output(msg, fp3);
	fclose(fp1);
	fclose(fp2);
	fclose(fp3);
	printf("please hold here\n");
	scanf("%s", holder);
}

