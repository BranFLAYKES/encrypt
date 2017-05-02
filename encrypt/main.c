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

typedef unsigned  char Byte;

void readFile(Byte* txtFile, FILE * output, unsigned long length,  const char * a);

int main(int argc,  const char * argv[]) {
	
	FILE * fp = NULL;
	FILE * output = NULL;
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
	
	}
	
	length = strlen((char*)txtFile);
	for (int a = 0; a < length; a++) {
		printf("%c", *(txtFile + a));
	}
	
	readFile(txtFile, output, length, argv[2]);
	
	free(txtFile);
	fclose(output);
	fclose(fp);
	return 0;
}

 void readFile(Byte * txtFile, FILE * output, unsigned long length, const char * a)
 {
	
	 unsigned int mask = 1 << 31;
	 //unsigned char mask = 0x80;
	 unsigned int c;
	 unsigned char * storeBytes;
	
	 for (int a = 0; a < length; a++)
	 {
		
		 c = *(txtFile + a) << 24;
		 
		 for (int i = 0; i < 8; i++)
		 {
			 storeBytes[a] = putchar( c & mask ? '1' : '0');
			 c <<= 1;
		 }
		 
		 
		 
		
		 fprintf(output, "%s", storeBytes);
		
		 puts("\n\n");
	 }
	 
	 
}

