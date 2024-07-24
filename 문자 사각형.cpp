#include <stdio.h>

int main(){

int s=0;
int mat[30][100];  
    while(1){
    scanf("%d",&s);

    if(s<0|| s>100){
        printf("INPUT ERROR!\n");
	}else{
    break;
}

	for(int i=0; i<s; i++){
		for(int j=0; j<s; i++){
			if(j%2)//È¦¼ö 
		mat[i][j]=(char)('A'+i+j*s);
		else 
		mat[s-i-1]j]=(char)('A'+i+j*s);
		//	printf("%c","A"+i+j);
		}
	}

}
return 0;

}
