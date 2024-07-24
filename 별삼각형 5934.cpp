#include <stdio.h>

int main(){
    int n;
    scanf("%d", &n);
    if(n%2==0 || n>100 || n<0){
        printf("INPUT ERROR!");
    }else {
        for(int i=1;i<=(n/2)+1;i++){
            for(int j=1;j<i;j++){
                printf(" ");
            }
            for(int j=(n/2)+1;j>=i;j--){
                printf("*");
            }
            printf("\n");
        }
        for(int i=1;i<=n/2;i++){
            for(int j=1;j<=n/2;j++){
                printf(" ");
            }
            for(int j=1;j<=i+1;j++){
                printf("*");
            }
            printf("\n");
        }
    }
    return 0;
}
