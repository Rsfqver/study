#include <stdio.h>

#include <stdio.h>
int main(void) {
    int h, w; //height, width
    scanf("%d %d", &h, &w); //�Է��� �޴´�.
    for (int i = 0; i < h; i++) {
        for (int j = 1; j <= w; j++) { //for�� �ΰ��� ��ø���� 2���� �迭 ������ ���ڸ� ����Ѵ�.
            printf("%d ", i * w + j);
        }
        printf("\n", i * w + h); //�� �� ����� ���� �� ���� �ٹٲ��� �� �ش�.
    }
    return 0;
}


