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
#include <math.h>


typedef unsigned  char Byte;

void readFile(Byte* txtFile, FILE * output, unsigned long length,  const char * a);
void displayBits(Byte value, unsigned long length, FILE * output);

int main(int argc,  const char * argv[]) {
	
	FILE * fp;
	FILE * output;
	Byte * txtFile = (Byte*)malloc(sizeof(Byte));
	int i = 0;
	unsigned long length = 0;
	
	if (argc > 1)
	{
		fp = fopen(argv[1], "r+");
		output = fopen(argv[2], "w+");
	 
		if (output == NULL || fp == NULL)
		{
			puts("File failed to open!");
			exit(1);
		}
		
		while ( !feof(fp))
		{
		
			*(txtFile + i) = fgetc(fp);
			i++;
		}
		
		
		
		length = strlen((char*)txtFile);
		
			//don't really need this to print
		/*
		for (int a = 0; a < length; a++)
		{
			printf("%c", *(txtFile + a));
		}
		 */
		
		readFile(txtFile, output, length, argv[2]);
		
		fclose(fp);
		
	}
	
	free(txtFile);
	
	
	return 0;
}

 void readFile(Byte * txtFile, FILE * output, unsigned long length, const char * a)
 {
	
	 unsigned int mask = 1 << 31;
	 unsigned int c;
	 Byte result = '\0';
/*
	//print characters in binary
	 for (int a = 0; a < length; a++)
	 {
		
		 c = *(txtFile + a) << 24;
		
		for (int i = 0; i < 8; i++)
		 {
			putchar( c & mask ? '1' : '0');
			c <<= 1;
		}
		 puts("\n\n");
	}
*/
	
		 //relocate bits
	 for (int a = 0; a < length; a++)
	 {
		 
		 for (int s= 7; s >= 0; --s)
		 {
			 result = *(txtFile + a) * (Byte)pow(2, 2);
			 putchar( (result & (1 << s)) ? '1' : '0' );
		 }
		 printf("%s", "------->");
		 displayBits(~result, length, output);
		 puts("");
	 }
	 fclose(output);
 }
	 
void displayBits(Byte value, unsigned long length, FILE * output)
{
	Byte mask = 1 << 7;
	Byte fill[8 * length];
	unsigned int x = 0;
	
	for (int c = 0; c < 8; ++c) {
			putchar(value & mask ? '1' : '0');
			value <<= 1;
			
		}
	
	if (<#condition#>) {
		<#statements#>
	}

}


