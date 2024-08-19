#include<stdio.h>
int main()
{
	int n, temp;
	scanf("%d",&n);
	int score[n] = {0,};
	for(int i=0; i<n; i++){
		scanf("%d",&score[i]);
	}
	for(int i=0; i<n - 1; i++){
		for(int j=0; j<n -1; j++){
			if(!(score[j] > score[j+1])){
			temp = score[j];
			score[j] = score[j+1];
			score[j+1] = temp;
			}
		}
	}
	for(int i=0; i<n; i++)
	printf("%d\n",score[i]);
}
