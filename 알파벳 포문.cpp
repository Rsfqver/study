#include <stdio.h>


int main(void){
int a;//자료 입력 받을것

int title ;
int sum;
double ave;

scanf("%d",&a);

while(1)
{
    if(a==0){
	printf("입력된 자료의 개수=%d\n",title);
	printf("입력된 자료의 합계=%d\n",sum);
	printf("입력된 자료의 평균=%.2f\n",ave);
}

    	else{
    	title++;
   		sum+=a;
    	ave=sum/title;
 }
 scanf("%d",&a);

}
return 0;
}
