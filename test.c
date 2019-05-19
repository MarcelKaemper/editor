#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char ** argv){

	char *str;
	char *c;

	int size = 1;

	str = (char *) malloc(size);

	for(int i = 0; i<6; i++){
		c = (char *) malloc(1);
		scanf("%s", c);
		strcat(str,c);
		size+=1;
		str = (char *) realloc(str, size);
		free(c);
	}
	printf("%s", str);

	free(str);

	return 0;

}
