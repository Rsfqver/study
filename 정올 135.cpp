#include<stdio.h>

int main(){
	int n=0;
	int m=0;
	int sum=0;
	int cout=0;
	double avg=0;
	
	scanf("%d %d", &n,&m);

		if(n>m){
		
	for(int i=m; i<=n; i++){
	if(i%3==0 || i%5==0){
		sum+=i;
		cout ++;
	}
	}
	}
		else
	{
		for(int i=n; i<=m; i++){
			if(i%3==0 || i%5==0){
			sum+=i;
			cout ++;
			}	
		}
	}
	avg=(double)sum/cout;
	printf("sum : %d\n",sum);
	printf("avg : %.1f",avg);
	
	return 0;
}
