#include <stdio.h>

#include <stdio.h>
int main(void) {
    int h, w; //height, width
    scanf("%d %d", &h, &w); //입력을 받는다.
    for (int i = 0; i < h; i++) {
        for (int j = 1; j <= w; j++) { //for문 두개를 중첩시켜 2차원 배열 형태의 숫자를 출력한다.
            printf("%d ", i * w + j);
        }
        printf("\n", i * w + h); //한 줄 출력이 끝날 때 마다 줄바꿈을 해 준다.
    }
    return 0;
}


