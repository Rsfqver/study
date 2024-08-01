#include<stdio.h>
#include<windows.h>

int main()
{
	int i=0;
	for(i=0; i<=100; i++)
	
	printf("\r%3d%%\n",i);
	fflush(stdout);
	Sleep(10000000);
	
	return 0;
}
