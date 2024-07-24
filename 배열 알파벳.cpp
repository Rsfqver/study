#include <stdio.h>

int main(void){
	
	char array[26];
	for(int i=0,b='Z'; i<26; i++,b--){
		array[i]=(char)b;
		
		printf("%c ",array[i]);
	}
	return 0;	
}
