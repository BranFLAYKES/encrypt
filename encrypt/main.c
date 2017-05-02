	//
	//  main.c
	//  encrypt
	//
	//  Created by Brandon Figueredo on 5/1/17.
	//  Copyright © 2017 Brandon Figueredo. All rights reserved.
	//

#include <stdio.h>
#include <stdlib.h>


int main(int argc,  const char * argv[]) {
	
	FILE * fp;
	fp = fopen("hamlet.txt", "r+");
	
	
	if (argc > 1)
	{
		
		if (fp == NULL)
		{
			puts("File failed to open!");
			exit(1);
		}
		
		char * txtFile = (char*)malloc(sizeof(char));
		int i = 0;
		
		while (!feof(fp))
		{
			fgets(txtFile, sizeof(fp), fp);
			*(txtFile + i) = fputs(txtFile, fp);
			printf("%c", *(txtFile) );
		}
		
		
	}
	
	
	return 0;
}
/*
 void readFile(char * txtFile, FILE * fp)
 {
	
	for (int i = 0; i < sizeof(txtFile); i++) {
 fseek(fp, 8, SEEK_SET);
	}
 }
 */
