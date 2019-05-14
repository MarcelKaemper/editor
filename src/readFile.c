#include <stdio.h>
#include <stdlib.h>

void readFile(){

	FILE *fp = fopen("test", "r");
	FILE *fp2 = fopen("copy", "w");
	char ch;

	while((ch = fgetc(fp)) != EOF){
		printf("%c", ch);	
		fprintf(fp2, "%c", ch);
	}

}


