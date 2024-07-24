#include <stdio.h>



int main(){

	int sum=0,num,n;

	scanf("%d", &n);


	for(int i=1;i<=n;i++){

		scanf("%d",&num);

		sum=sum+num;

	}

	printf("%.2lf",(float)sum/n);

}
