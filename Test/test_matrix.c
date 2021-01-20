#include <stdio.h>
#include <stdlib.h>

int main(void){
	float matrix[6][6] = {
	{0, -0.05,-0.1,-0.15,-0.2,-0.25},
	{0.005, 0,-0.005,-0.1,-0.15,-0.2},
	{0.1, 0.05, 0, -0.005, -0.1, -0.15},
	{0.15, 0.1, 0.005, 0, -0.005, -0.1},
	{0.2, 0.15, 0.1, 0.005, 0, -0.005},
	{0.25, 0.2, 0.15, 0.1, 0.005, 0},
	};
	
	// index to each row and col
	int i, j;
	
	for(i=0; i < 6; i++){
		for(j=0; j < 6; j++){
			printf("%f", matrix[i][j]);
			
			// Line break for each row
			if(j == 5){
				printf("\n");
			}
		}
	}
	
	// If s = 88 so s % 6 = 4 and t is Shower so qt will be 0.1
	printf("%f",matrix[1][4]);
	return 0; 
}
