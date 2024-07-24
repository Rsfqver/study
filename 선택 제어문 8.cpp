#include <stdio.h>

int main (void){

int a;

printf("1.삽입\n");
printf("2.수정\n");
printf("3.삭제\n");

printf("숫자를 선택하세요");
scanf("%d",&a);

if(a==1){
   printf("삽입을 선택하셨습니다."); 
}
else if(a==2){
   printf("수정을 선택하셨습니다."); 
}

else if (a==3){
   printf("삭제를 선택하셨습니다."); 
}

return 0;
}
