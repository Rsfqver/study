#include <stdio.h>
#include <string.h>

int main()
{
    char a[26] = {0}; // 26개의 알파벳 대문자에 대한 배열
    char num;
    
    while (1)
    {
        scanf(" %c", &num); // 공백을 추가하여 개행문자와 공백을 무시함
        
        if (num >= 'A' && num <= 'Z') // A에서 Z 사이의 대문자 확인
        {
            a[num - 'A']++; // 올바른 인덱스를 사용하여 카운트
        }
        else
        {
            // 입력 종료 처리
            break;
        }
    }
    
    for (int i = 0; i < 26; i++)
    {
        if (a[i] != 0)
        {
            printf("%c : %d\n", i + 'A', a[i]); // 대문자로 출력
        }
    }
    
    return 0;
}

