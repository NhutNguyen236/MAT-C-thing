#include<stdio.h>


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

int main(){
	// input manually 
	printf("%d\t",checkPrime(657));
	return 0;
}
	
