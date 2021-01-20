//============================================================================
// Name        : maiantiem.c
// Author      : Nguyen Quoc Thuan
// Version     : 1.1
//============================================================================
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <stdbool.h>
#include <string.h>

/**********************************************************************
 * Ham: read_File
 * Sinh vien can hoan chinh ham doc_File de thuc hien viec doc gia tri file input.inp
**********************************************************************/
// Doc File
int doc_File(int *hp, int *d, int *s, char t[], char input[])
{
	FILE *f;
	
	// tinh trang doc file
	int read_status = 1;
	
	f = fopen(input,"r");
	if(f == NULL){
		read_status = 0;
	}
	else{
		rewind(f);
	
		fscanf(f ,"%d %d %d %s", hp, d, s, t);

		fclose(f);	
	}
	return read_status;
}

/**********************************************************************
 * Ham: ghi_File
 * Sinh vien can hoan chinh ham ghi_file de thuc hien viec ghi ket qua p vao file output.out tai thu muc lam viec
**********************************************************************/
// Ghi File
void ghi_File(float p, char output[], int read_status)
{
	FILE *fb;
	
	fb = fopen(output,"w");
	
	// xet gia tri p khi loi doc file
	if(read_status == 0 ){
		p = -1;
		fprintf(fb, "%d", (int)p);
		exit(1);
	}
	// Loc gia tri p theo de bai
	else{
		if(p <= 0.0){
			p = 0;
			fprintf(fb, "%d", (int)p);
		}
		else{
			if(p >= 1.0){
				p = 1;
				fprintf(fb, "%d", (int)p);
			}
			else{
				// .3 khac 3. rat nhieu
				fprintf(fb, "%.3g", p);
			}
		}
	}
	
	
	//printf("%d\n",p);
	
	fclose(fb);
}

/**********************************************************************
 * Name: main
 * Target: Implements your application
 **********************************************************************/
// Kiem tra so perfect square
bool isPerfectSquare(int n){
	int s = sqrt(n);
	return (s*s == n);
}
// Kiem tra so fib - tra ve 0 neu ko la so fib, 1 neu la so fib
int Fibonacci(int ds){
    // mac dinh ds ko la so fib
	int fibtus = 0;
    if(isPerfectSquare(5*pow(ds,2) + 4) == true || isPerfectSquare(5*pow(ds,2) - 4) == true){
    	fibtus = 1;
	}
	else{
		fibtus = 0;
	}
    return fibtus;
}

// Ham kiem tra so prime, return 1 neu la so prime, 0 neu ko la so prime
int checkPrime(int hp){
	int flag = 0, i, m = 0, status = 0;
	m = hp/2;
	
	// neu hp la 1 thi no ko phai prime cung chang la gi het
	if(hp == 1){
		flag = 1;
	}
	else{
		for(i=2; i <= m; i++){
			if(hp % i == 0){
				flag = 1;
				break;
			}
		}	
	}	
	
	if(flag == 0){
		status = 1;
	}
	else{
		status = 0;
	}
	
	return status;
}

// Ham tinh g(s) dua vao bang cho san 
// Chinh kieu gia tri cua gs sang int
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
			return gs = -pow((s%30),2) + 3 * s;
			break;
		case 4:
			return gs = -s;
			break;
		case 5:
			return gs = -(s % 5 + 5 + 1) * (s % 5 + 5) / 2;
			break;
	}
}

// Ham tinh qt dua vao bang co san
// Ap dung ma tran trong so de lay gia tri
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

// Ham nay dung de convert gia tri s va t ra so int i va j de hop voi ma tran o ham pt
// Input: smod6, va chuoi t
// Output: Array chua 2 chi so i j tuong ung trong ma tran pt
int * ij_converter(int smod6, char t[]){
	static int ij[2];
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
	ij[0] = i;
	ij[1] = j;
	
	return ij;
}

/*
	- d > 800: f(d,s,t) = (-d * s)/1000
*/

// Ham tinh xac suat p
float p_value(int hp, int d, int s, char t[]){
	// Tinh 2 gia tri P1 va P2
	int P1, P2;
	// Lay gia tri P1
	// Neu hp la 1 so prime
	if(checkPrime(hp) == 1){
		P1 = 1000;
		P2 = (hp + s) % 1000;
	}
	// Neu hp ko la 1 so prime
	else{
		if(checkPrime(hp) == 0){
			P1 = hp;
			P2 = (hp + d) % 100;
		}
	}
	// Xac suat p can output
	float p;
	// Ham fdst
	float fdst;
	//Tinh s mod 6 de truyen tham so cho ham converter
	int smod6 = s % 6;
	// Khoi tao 2 bien i j
	int i, j;
	// Convert s va t sang index cua ma tran
	i = ij_converter(smod6,t)[0];
	j = ij_converter(smod6,t)[1];
	
	printf("\n hp la %d \t d la %d \t s la %d \t t la %s \t P1 la %d \t P2 la %d", hp, d, s, t, P1, P2);
	// Tinh f(dst)
	// th1: d < 200
	int ds = d + s;
	if(d < 200){
		if(Fibonacci(ds) == 1){
			// tinh theo th2
			// Vung nhieu ran
			if(d >= 200 && d < 300){
				float rc;
				rc = ((float)d + (float)P1 + (float)P2)/1000;
				// Kiem tra xs bi ran can
				// MAT tu vong
				if(rc > 0.8){
					return p = 0;
				}
				// MAT bi giam hp
				else{
					// Tu 0.8 den 0.6
					if(rc>=0.60 && rc<=0.80){
						hp = hp - 50;
						fdst = (40.0 - abs(d - 500.0) / (20.0) + gs(s)) * (1.0 + pt(i, j));
						// Tinh lai P1 va P2
						if(checkPrime(hp) == 1){
							P1 = 1000;
							P2 = (hp + s) % 1000;
						}
						// Neu hp ko la 1 so prime
						else{
							if(checkPrime(hp) == 0){
								P1 = hp;
								P2 = (hp + d) % 100;
							}
						}
						return p = (P1 + P2 * fdst)/(1000 + abs(P2 * fdst));
					}
					// Tu 0.6 den 0.4
					if(rc >= 0.4 && rc < 0.6){
						hp = hp - 30;
						fdst = (40.0 - abs(d - 500.0) / (20.0) + gs(s)) * (1.0 + pt(i, j));
						// Tinh lai P1 va P2
						if(checkPrime(hp) == 1){
							P1 = 1000;
							P2 = (hp + s) % 1000;
						}
						// Neu hp ko la 1 so prime
						else{
							if(checkPrime(hp) == 0){
								P1 = hp;
								P2 = (hp + d) % 100;
							}
						}
						return p = (P1 + P2 * fdst)/(1000 + abs(P2 * fdst)); 
					}
					// Tu 0.4 den 0.2
					if(rc >= 0.2 && rc < 0.4){
						hp = hp - 20;
						fdst = (40.0 - abs(d - 500.0) / (20.0) + gs(s)) * (1.0 + pt(i, j));
						// Tinh lai P1 va P2
						if(checkPrime(hp) == 1){
							P1 = 1000;
							P2 = (hp + s) % 1000;
						}
						// Neu hp ko la 1 so prime
						else{
							if(checkPrime(hp) == 0){
								P1 = hp;
								P2 = (hp + d) % 100;
							}
						}
						return p = (P1 + P2 * fdst)/(1000 + abs(P2 * fdst)); 
					}
					// Tu 0 den 0.2
					if(rc >= 0.0 && rc < 0.2){
						fdst = (40.0 - abs(d - 500.0) / (20.0) + gs(s)) * (1.0 + pt(i, j));
						return p = (P1 + P2 * fdst)/(1000 + abs(P2 * fdst)); 
					}
				}
			}
			// Vung nay ko co ran
			else{
				//printf("\ngs la %f \t pt la %f \t i la %d \t j la %d \t smod6 la %d", gs(s), pt(i, j), i, j, smod6);
				fdst = (40.0 - abs(d - 500.0) / (20.0) + gs(s)) * (1.0 + pt(i, j));
				p = (P1 + P2 * fdst)/(1000 + abs(P2 * fdst));
				//printf("\n%.3f",p);
				return p = (P1 + P2 * fdst)/(1000 + abs(P2 * fdst)); 
			}
		}
		else{
			fdst = 0;
			return p = (P1 + P2 * fdst)/(1000 + abs(P2 * fdst));
		}	
	}
	
	// th2: 200 <= d <= 800
	else{
		if(d >= 200 && d <= 800){
			// Vung nhieu ran
			if(d >= 200 && d < 300){
				float rc;
				rc = ((float)d + (float)P1 + (float)P2)/1000;
				// Kiem tra xs bi ran can
				// MAT tu vong
				if(rc > 0.8){
					return p = 0;
				}
				// MAT bi giam hp
				else{
					// Tu 0.8 den 0.6
					if(rc>=0.60 && rc<=0.80){
						hp = hp - 50;
						fdst = (40.0 - abs(d - 500.0) / (20.0) + gs(s)) * (1.0 + pt(i, j));
						// Tinh lai P1 va P2
						if(checkPrime(hp) == 1){
							P1 = 1000;
							P2 = (hp + s) % 1000;
						}
						// Neu hp ko la 1 so prime
						else{
							if(checkPrime(hp) == 0){
								P1 = hp;
								P2 = (hp + d) % 100;
							}
						}
						return p = (P1 + P2 * fdst)/(1000 + abs(P2 * fdst));
					}
					// Tu 0.6 den 0.4
					if(rc >= 0.4 && rc < 0.6){
						hp = hp - 30;
						fdst = (40.0 - abs(d - 500.0) / (20.0) + gs(s)) * (1.0 + pt(i, j));
						// Tinh lai P1 va P2
						if(checkPrime(hp) == 1){
							P1 = 1000;
							P2 = (hp + s) % 1000;
						}
						// Neu hp ko la 1 so prime
						else{
							if(checkPrime(hp) == 0){
								P1 = hp;
								P2 = (hp + d) % 100;
							}
						}
						return p = (P1 + P2 * fdst)/(1000 + abs(P2 * fdst)); 
					}
					// Tu 0.4 den 0.2
					if(rc >= 0.2 && rc < 0.4){
						hp = hp - 20;
						fdst = (40.0 - abs(d - 500.0) / (20.0) + gs(s)) * (1.0 + pt(i, j));
						// Tinh lai P1 va P2
						if(checkPrime(hp) == 1){
							P1 = 1000;
							P2 = (hp + s) % 1000;
						}
						// Neu hp ko la 1 so prime
						else{
							if(checkPrime(hp) == 0){
								P1 = hp;
								P2 = (hp + d) % 100;
							}
						}
						return p = (P1 + P2 * fdst)/(1000 + abs(P2 * fdst)); 
					}
					// Tu 0 den 0.2
					if(rc >= 0.0 && rc < 0.2){
						fdst = (40.0 - abs(d - 500.0) / (20.0) + gs(s)) * (1.0 + pt(i, j));
						return p = (P1 + P2 * fdst)/(1000 + abs(P2 * fdst)); 
					}
				}
			}
			// Vung nay ko co ran
			else{
				//printf("\ngs la %f \t pt la %f \t i la %d \t j la %d \t smod6 la %d", gs(s), pt(i, j), i, j, smod6);
				fdst = (40.0 - abs(d - 500.0) / (20.0) + gs(s)) * (1.0 + pt(i, j));
				p = (P1 + P2 * fdst)/(1000 + abs(P2 * fdst));
				//printf("\n%.3f",p);
				return p = (P1 + P2 * fdst)/(1000 + abs(P2 * fdst)); 
			}
		}
		
		// th3: d > 800 - vi tri gan bo bien
		else{
			if(d > 800){
				//printf("here");
				fdst = (-(float)d * (float)s)/1000;
				return p = ((float)P1 + (float)P2 * fdst)/(1000 + abs((float)P2 * fdst)); 
			}
		}
	}
}

int main(int argc, char *argv[]){
	int hp = 0, d = 0, s = 0;
	char t[100];
	float p = -1;
	
	// gia tri read_file de xet th file bi loi
	int read_status = doc_File(&hp, &d, &s, t, argv[1];
	
	doc_File(&hp, &d, &s, t, argv[1]);
	//printf("%d", doc_File(&hp, &d, &s, t, argv[1]));
	
	p = p_value(hp,d,s,t);

	ghi_File(p,"output.out", read_status);
	
	return 2020;
}
