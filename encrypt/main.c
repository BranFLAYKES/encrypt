	//
	//  main.c
	//  encrypt
	//
	//  Created by Brandon Figueredo on 5/1/17.
	//  Copyright © 2017 Brandon Figueredo. All rights reserved.
	//

#include <stdio.h>
#include <stdlib.h>
#include <strings.h>

//unsigned char
typedef unsigned  char Byte;

//prototype
void displayBits(Byte value, unsigned long length, FILE * output);

int main(int argc,  const char * argv[]) {
	
    //declare file pointers/variables
	FILE * fp = NULL;
	FILE * output = NULL;
	Byte * txtFile = (Byte*)malloc(sizeof(Byte));
    Byte result;
	int i = 0;
	unsigned long length = 0;
	
	if (argc > 1)
	{
        //open files
		fp = fopen(argv[1], "r+");
		output = fopen(argv[2], "w+");
	 
		if (output == NULL || fp == NULL)
		{
			puts("File failed to open!");
			exit(1);
		}
	}
    
    //store each character
    while (!feof(fp))
    {
        *(txtFile + i) = fgetc(fp);
        i++;
    }
    
    //make length the size of file
    length = strlen((char*)txtFile);
    
    puts("Original Text\n-----------------------------------------------");
    
    for (int a = 0; a < length; a++)
    {
        printf("%c", *(txtFile + a));
    }
    puts("Shifted Binary\t\t1's Complement Of Shift\n");
    
    for (int a = 0; a < length; a++)
    {
        //manipulate bits with bitwise OR and set the value equal to result
        result = ( *(txtFile + a) << 2) | (*(txtFile + a) >> (6));

        //print binary of shifted bits
        for (int s= 7; s >= 0; --s)
        {
            putchar( (result & (1 << s)) ? '1' : '0' );
        }
        //calls function that prints final value in bits
        printf("%s", "------->");
        displayBits(~result, length, output);
        puts("");
    }

    //close files
    fclose(fp);
    fclose(output);
    free(txtFile);

	return 0;
}

//display complement of shifted bits
void displayBits(Byte value, unsigned long length, FILE * output)
{
    //output char to file
	fprintf(output, "%c", value);
	
    //print binary of complemented value
	for (int c = 7; c >= 0; --c) {
			putchar(value & (1 << c) ? '1' : '0');
			
		}
}




