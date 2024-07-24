#include <stdio.h>
#define up 1
#define donw 0
int main(){
	int n; //숫자 대입 
	int ary[100][100];  //배열 
	int ax[]={-1,1}; //모서리 
	int ay[]={1,-1};//모서리  
	int x=1, y=-1; 
	int d=donw;
	int i=1;
	d=donw ;
	scanf("%d",n);
	
	for(; i<=n*n; i++)
	{
		x+=ax[d];
		y+=ax[d];
		if(d== donw){
		
		if(x<0 || y>=n){
			if(y>=n){
				y--;
				x+=2;	
			}
			else{
				
				x++;
			}
			d=up;
		}
		
		else{
		if(y<0 || x>=n){
			if(y>=n){
				x--; 
				y+=2;	
			}
			else{
				y++;
				}
				d=donw;
		}
			}
	ary[y][x]=i;
}	
}
	  for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++)
        {
            printf("%d ", ary[i][j]);
        }
        printf("\n");
    }
return 0;	
}
