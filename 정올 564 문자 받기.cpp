#include <stdio.h>
#include <string.h>

int main()
{
    char a[26] = {0}; // 26���� ���ĺ� �빮�ڿ� ���� �迭
    char num;
    
    while (1)
    {
        scanf(" %c", &num); // ������ �߰��Ͽ� ���๮�ڿ� ������ ������
        
        if (num >= 'A' && num <= 'Z') // A���� Z ������ �빮�� Ȯ��
        {
            a[num - 'A']++; // �ùٸ� �ε����� ����Ͽ� ī��Ʈ
        }
        else
        {
            // �Է� ���� ó��
            break;
        }
    }
    
    for (int i = 0; i < 26; i++)
    {
        if (a[i] != 0)
        {
            printf("%c : %d\n", i + 'A', a[i]); // �빮�ڷ� ���
        }
    }
    
    return 0;
}

