#include <stdio.h>


int main(void){
int a;//�ڷ� �Է� ������

int title ;
int sum;
double ave;

scanf("%d",&a);

while(1)
{
    if(a==0){
	printf("�Էµ� �ڷ��� ����=%d\n",title);
	printf("�Էµ� �ڷ��� �հ�=%d\n",sum);
	printf("�Էµ� �ڷ��� ���=%.2f\n",ave);
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
