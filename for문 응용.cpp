#include <stdio.h>

int main(void)
{
	int i,j;
    int s,e;
    for(;;){
    scanf("%d %d",&s,&e);

    if(s<2|| s>9 || e<2 || e>9){
        printf("INPUT ERROR!\n");
}   else{
    break;
}
}

for(int j=1; j<10; j++){
	if(s>e){
		for(int i=s; i>=e; i--){
			printf("%d*%d=%2d   ",i,j,i*j);
		}
	}else{
		for(int i=s; i<=e; i++){
				printf("%d*%d=%2d   ",i,j,i*j);
		}
	}
	printf("\n");
	
	
}
return 0;
}
