#include <stdio.h>

int main (void){
	
	int a;
    int b;
	 scanf("%d%d",&a,&b);
	 if(a>b){
	  printf("입력받은 수 중 큰 수는 %d이고 작은 수는 %d입니다.",a,b);
		}		
     else{
      printf("입력받은 수 중 큰 수는 %d이고 작은 수는 %d입니다.",b,a);  
 
     }
 
     return 0;
}
