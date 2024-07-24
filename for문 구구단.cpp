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


if(s < e){
    for(int i = s;i <= e;i++){
        for(int j = 1;j <= 3;j++){
        printf("%d * %d = %2d   " , i , j , j * i);
        }
        printf("\n");
        for(int j = 4;j <= 6;j++){
        printf("%d * %d = %2d   " , i , j , j * i);
        }
        printf("\n");
        for(int j = 7;j <= 9;j++){
        printf("%d * %d = %2d   " , i , j , j * i);
        }
        printf("\n\n");
        }
        }else{
        for(int i = s;i >= e;i--){
        for(int j = 1;j <= 3;j++){
            printf("%d * %d = %2d   " , i , j , j * i);
            }
            printf("\n");
            for(int j = 4;j <= 6;j++){
            printf("%d * %d = %2d   " , i , j , j * i);
            }
            printf("\n");
            for(int j = 7;j <= 9;j++){
            printf("%d * %d = %2d   " , i , j , j * i);
            }
            printf("\n\n");
        }
        }
        return 0;
    }
