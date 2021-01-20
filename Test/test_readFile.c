#include <stdio.h>
#include <stdlib.h>

//Fix
void doc_File(int *hp, int *d, int *s, char t[]){
	
	FILE *f;
	
	f = fopen("input1.inp","r");
	if(f == NULL){
		printf("404: Not found");
	}
	else{
		rewind(f);
	
		fscanf(f ,"%d %d %d %s", hp, d, s, t);
		
		printf("hp is %d", *hp);
		printf("\td is %d", *d);
		printf("\ts is %d", *s);
		printf("\tt is %s", t);
		
		fclose(f);	
	}
	return ;
}

int main(void){
	int hello = 0; 
	int d = 100; 
	int s = 0; 
	char t[100];
	
	doc_File(&hello, &d, &s, t);
	printf("\n%d", d);

	return 0;
}
