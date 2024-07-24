#include <stdio.h>

int main(void)
{
    double a=0;
	double b=0;
	int l;
    char c=0;
    
    scanf("%lf %lf %c",&a,&b,&c);
    
    l=(a*1000+5)/10;
    a=l/100;
    l=(b*1000+5)/10;
    b=l/100;
    
    
    printf("%.2f\r\n%.2f\r\n%c",a,b,c);

    return 0;
}
