#include"p3header.h"
#define _CRT_SECURE_NO_WARNINGS
//#include <stdio.h>

//method 1
/*this method will take the file pointer and input character by  character into an array using a char
file point*/
void getInputMessage(FILE *fp1, char *msg)
{
	//initialize variables
	char *cpointer;
	int i = 0;
	cpointer = msg;
	//step 1 input the file character by character into a character array
			//will have to iterate over array
	*cpointer = getc(fp1);
	cpointer++;
	for (;i < 5000 && !feof(fp1);i++, cpointer++)
	{
		
		*cpointer = getc(fp1);
	}
	*cpointer = '\0';
			//then assign values to the indices
}
//method 2
/* this method will implement the rotation alogrithm using char array pointer, an array pointer to the
integer key array that holds the key, and the length of the key array is passed by copy to reset it when necessary
code is implemented to account for overwrapping and for when it is not a an alphabetical character*/
//pass it a string, pass it a key array,int key size
void encrypt(char *msg, int *keyArray, int keySize)
{
	printf("entering encrypt method----------------------\n");
	char *cp;
	char temp;
	int *ip, i = 0;
	ip = &keyArray[0];
	cp = msg ;
//	putchar(*cp);
	for (;*cp != '\0'; cp++)
	{
	//	putchar(*cp);
		//reset condition found
		if (i >= keySize)
		{
			//printf("here  ");
			ip = &keyArray[0];//error occurs here,,,, why?
			i = 0;
		}
		//do encryption here
		//*cp = (char)(*cp + *ip);
		//str[i] =(char) (str[i] + x[j]);
		if (isupper(*cp) && isalpha(*cp ))
		{
			if ((char)(*cp + *ip) > 'Z')
			{
				//temp = *cp;
				*cp = (char)(*cp + *ip) - 26;
				//printf("%c changed to %c by number %d", *cp,temp,*ip);
			}
			else if ((char) (*cp + *ip) < 'A')
			{
				//temp = *cp;
				*cp = (char)(*cp + *ip) + 26;
				//printf("%c changed to %c by number %d", *cp,temp,*ip);

			}
			else
			{
				//temp = *cp;
				*cp = (char)(*cp + *ip);
				//printf("%c changed to %c by number %d", *cp,temp,*ip);
			}
			i++;//incr i in both clause
			ip++;
		}
		//else isLower(*cp)
		else if(islower(*cp))
		{
			if ((char) (*cp + *ip) > 'z')
			{
				//temp = *cp;
				*cp = (char)(*cp + *ip) - 26;
				//printf("%c changed to %c by number %d", *cp,temp,*ip);
			}
			else if ((char)(*cp + *ip) < 'a')
			{
				//temp = *cp;
				*cp = (char)(*cp + *ip) + 26;
				//printf("%s changed to %s by number %d", *cp,temp,*ip);
			}
			else
			{
				 //temp = cp;
				*cp = (char)(*cp + *ip);
				//printf("%s changed to %s by number %d", (char)*cp,(char)*temp,*ip);
			}
			i++;//incr i in both clause
			ip++;
		}
		//putchar(*cp);
		//increment array
		//if is not letter/character....decrement array
		if ( !isalpha(*cp) )
		{
		}
	}
	printf("exiting encrypt method-------------------------------\n");
}

//method 3
/*this method will implement the rotation algorithm necessary to decrypt the message operating like encrypt but in
reverse. parameters passed are the same as encrypt e.g. a msg character array, a key integer array, and length of
the key integer array*/
void decrypt(char *msg, int *keyArray, int keySize)
{
	printf("entering decrypt method----------------------\n");
	char *cp,temp;
	int *ip, i = 0;
	ip = &keyArray[0];
	cp = msg;
	for (; *cp != '\0'; cp++)//will always increment cp to process next character in msg
	{
		temp = *cp;
		//reset condition found
		if (i >= keySize)
		{
			i = 0;
			ip = &keyArray[0];
		}
		//do decryption here
		if (isupper(*cp))
		{
			if ((char)*cp - *ip > 'Z')
			{
				//char temp = *cp;
				*cp = (char)(*cp - *ip) + 26;
				//printf("%s changed to %s by number %d", *cp,temp,*ip);
			}
			else if ((char)*cp - *ip < 'A')
			{
				//char temp = *cp;
				*cp = (char)(*cp - *ip) - 26;
				//printf("%s changed to %s by number %d", *cp,temp,*ip);
			}
			else
			{
				//char temp = *cp;
				*cp = (char)(*cp - *ip);
				//printf("%s changed to %s by number %d", *cp,temp,*ip);
			}
			ip++;
			i++;
		}
		//else isLower(*cp)
		else if(islower(*cp) && isalpha(*cp))
		{
			//test for wrapping conditions
			if ((char)(*cp - *ip) > 'z')
			{
				//char temp = *cp;
				// check to see if it will end up above 'z'
				*cp = (char)(*cp - *ip) - 26;
				//printf("%s changed to %s by number %d", *cp,temp,*ip);
			}
			else if ((char)(*cp - *ip) < 'a')
			{
				//char temp = *cp;
				//check to see if it will end up below 'a'
				*cp = (char)(*cp - *ip) + 26;
				//printf("%s changed to %s by number %d", *cp,temp,*ip);
			}
			else
			{
				//char temp = *cp;
				*cp = (char)(*cp - *ip);
				//printf("%c changed to %c by number %d", *cp,temp,*ip);
			}
			ip++;
			i++;
		}
		//increment number array
		//ip++;
		//i++;
		//if is not letter/character....decrement array
		if (!isalpha(*cp))
		{
			//ip--;
			//i--;
		}
	}
	printf("exiting decrypt method----------------------\n");
}


//method 4
/*this method will output a formal report to a file using a given character array, the characters will be
written character by charactyer(using putchar to console and putc to file) until they reach the '\0' character of a given file pointer*/
//receives msg, and File pointer as parameter
void output(char *msg, FILE *fp2)
{
	printf("entering output method------\n");
	char *cp;
	cp = msg;
	putc(*cp,fp2);
	putchar(--*cp);
	cp++;
	while (*cp != '\0')
	{
		putchar(*cp);//wil put to console
		putc(*cp, fp2);//will put message to file
		cp++;//will increment cp to th3en next index in array
	}
	printf("exiting output method------\n");
}



