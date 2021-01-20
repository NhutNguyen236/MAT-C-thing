#include <stdio.h>
#include <conio.h>
#include <stdlib.h>

float pt(int i, int j){	
	float pt;
	
	// bang
	float qt_table[6][6] = {
		{0, -0.05,-0.1,-0.15,-0.2,-0.25},
		{0.005, 0,-0.005,-0.1,-0.15,-0.2},
		{0.1, 0.05, 0, -0.005, -0.1, -0.15},
		{0.15, 0.1, 0.005, 0, -0.005, -0.1},
		{0.2, 0.15, 0.1, 0.005, 0, -0.005},
		{0.25, 0.2, 0.15, 0.1, 0.005, 0},
	};
	
	pt = qt_table[i][j];
	return pt;
}

int main(void){
	int s = 88;
	char t[100] = "Shower";
	printf("%s", t);
	int smod6 = s%6;
	
	int i, j;
	// Get j out of smod6 to pass to qt(i,j)
	switch(smod6){
		case 5:
			j = 0;
			break;
		case 4:
			j = 1;
			break;
		case 0:
			j = 2;
			break;
		case 1:
			j = 3;
			break;
		case 2:
			j = 4;
			break;
		case 3:
			j = 5;
			break;
	}
	
	// Get i out of string t to pass to qt(i,j)
	// case handle lower and uppercase - flood, FLood, fLoOd 
	if(strcmp(t,"Flood") == 0){
		i = 0;
	}
	else{
		if(strcmp(t,"Storm") == 0){
			i = 1;
		}
		else{
			if(strcmp(t,"Rain")== 0){
				i = 2;
			}
			else{
				if(strcmp(t,"Shower")== 0){
					i = 3;
				}
				else{
					if(strcmp(t,"Drizzle")== 0){
						i = 4;
					}
					else{
						if(strcmp(t,"Cloudy")== 0){
							i = 5;
						}
					}
				}
			}
		}
	}
	
	printf("%d %d\n",i,j);
	printf("%f",pt(i,j));
}
