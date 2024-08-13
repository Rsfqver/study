#include <stdio.h>
#include <stdlib.h>
#include "IntStack.h"

/*--- ���� �ʱ�ȭ ---*/
int Initialize(IntStack *s, int max)
{
    s->ptr = 0;
    if ((s->stk = (int*)calloc(max, sizeof(int))) == NULL) {
        s->max = 0;                     // �迭 ������ ����
        return -1;
    }
    s->max = max;
    return 0;
}

/*--- ���ÿ� �����͸� Ǫ�� ---*/
int Push(IntStack *s, int x)
{
    if (s->ptr >= s->max)               // ������ ���� ��
         return -1;
    s->stk[s->ptr++] = x;
    return 0;
}

/*--- ���ÿ��� �����͸� �� ---*/
int Pop(IntStack *s, int *x)
{
    if (s->ptr <= 0)                    // ������ ��� ����
        return -1;
    *x = s->stk[--s->ptr];
    return 0;
}

/*--- ���ÿ��� �����͸� ��ũ ---*/
int Peek(const IntStack *s, int *x)
{
    if (s->ptr <= 0)                    // ������ ��� ����
        return -1;
    *x = s->stk[s->ptr - 1];
    return 0;
}

/*--- ������ ���� ---*/
void Clear(IntStack *s)
{
    s->ptr = 0;
}

/*--- ������ �ִ� �뷮 ---*/
int Capacity(const IntStack *s)
{
    return s->max;
}

/*--- ���ÿ� ���� ������ ���� ---*/
int Size(const IntStack *s)
{
    return s->ptr;
}

/*--- ������ ��� �ִ°�? ---*/
int IsEmpty(const IntStack *s)
{
    return s->ptr <= 0;
}

/*--- ������ ���� á�°�? ---*/
int IsFull(const IntStack *s)
{
    return s->ptr >= s->max;
}

/*--- ���ÿ��� �˻� ---*/
int Search(const IntStack *s, int x)
{
    for (int i = s->ptr - 1; i >= 0; i--)   // ���������� �Ʒ��� ���� �˻�
        if (s->stk[i] == x)
            return i;       // �˻� ����
    return -1;              // �˻� ����
}

/*--- ��� ������ ��� ---*/
void Print(const IntStack *s)
{
    for (int i = 0; i < s->ptr; i++)        // �Ʒ����� ���� ��ĵ
        printf("%d ", s->stk[i]);
    putchar('\n');
}

/*--- ���� ���� ---*/
void Terminate(IntStack *s)
{
    if (s->stk != NULL)
        free(s->stk);       // �迭 ����
    s->max = s->ptr = 0;
}

int main(void)
{
    IntStack s;
    if (Initialize(&s, 64) == -1) {
        puts("���� �ʱ�ȭ�� �����߽��ϴ�.");
        return 1;
    }

    while (1) {
        int menu, x;
        printf("���� ������ ����: %d / %d\n", Size(&s), Capacity(&s));
        printf("(1)Ǫ�� (2)�� (3)��ũ (4)��� (0)����: ");
        scanf("%d", &menu);

        if (menu == 0) break;
        switch (menu) {
         case 1: /*--- Ǫ�� ---*/
                 printf("������: ");
                 scanf("%d", &x);
                 if (Push(&s, x) == -1)
                    puts("\a����: Ǫ�ÿ� �����߽��ϴ�.");
                 break;

         case 2: /*--- �� ---*/
                 if (Pop(&s, &x) == -1)
                    puts("\a����: �˿� �����߽��ϴ�.");
                 else
                    printf("���� �����ʹ� %d�Դϴ�.\n", x);
                 break;

         case 3: /*--- ��ũ ---*/
                 if (Peek(&s, &x) == -1)
                    puts("\a����: ��ũ�� �����߽��ϴ�.");
                 else
                    printf("��ũ�� �����ʹ� %d�Դϴ�.\n", x);
                 break;

         case 4: /*--- ��� ---*/
                 Print(&s);
                 break;
        }
    }
    Terminate(&s);
    return 0;
}

