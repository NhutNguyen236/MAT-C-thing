#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <stdbool.h>
#include <string.h>

float gs(int s){
	// Tinh s%6
	float gs;
	int smod6 = s%6;
	switch(smod6){
		case 0:
			return gs = s/2;
			break;
		case 1:
			return gs = 2*s;
			break;
		case 2:
			return gs = pow(-(s%9),3)/5;
			break;
		case 3:
			return gs = pow(-(s%30),2) + 3 * s;
			break;
		case 4:
			return gs = -s;
			break;
		case 5:
			return gs = -(s % 5 + 5 + 1) * (s % 5 + 5) / 2;
			break;
	}
}

int main(void){
	int s = 100;
	
	printf("%f",giong(s));
	
	return 0;
}
