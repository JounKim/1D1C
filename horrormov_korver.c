#include <stdio.h>
#include <cs50.h>
#include <string.h>
#include <unistd.h>
#include <stdlib.h>

/*

메모리 초기화 => memset
메모리 복사 => memcpy
메모리 이동 => memmove
메모리 비교 => memcmp

All work and no play makes Jack a dull boy
'Heeeere's Johnny!!!!'

*/

int n;
int m;

char mom[4] = {"MOM"};
char son[4] = {"SON"};
char *bates;

void compare(int result);
// void check(int z);

int main(void){

    //게임을 시작할까 말까
    printf("역시 더울 때는 공포영화지\n");
    printf("play? -> yes: y / no: n\n");
    char answer;
    scanf("%c", &answer);
    printf("\n");

    if (answer == 'y'){
        printf("It's Alive! It's ALIVE!!!!\n\n");
        sleep(1);
    }else{
        printf("We belong dead.\n\n");
        return 1;
    }


    //***************샤이닝으로 익히고*******************//
    char jack[43] = {"All work and no play makes Jack a dull boy"};
    char johnny[43] = {"*********'Heeeere's Johnny!!!!'***********"};

    // printf("jack: %s\n", jack);
    // printf("johnny: %s\n", johnny);
    // printf("%lu\n", strlen(jack));

    ////////  메모리 초기화
    char *shining = malloc(strlen(jack));

    memcpy(shining, jack, strlen(jack));
    printf("%s\n", shining);

    // for (int q = 0; q < strlen(jack); q++){
    //     shining[q] = jack[q];
    // }
    // printf("%s\n", shining);

    for (int w=0; w<5; w++){
        memset(shining+w, johnny[w],1);
        printf("%s\n", shining);
        sleep(1);
    }

    // for (int w = 0; w < strlen(jack); w++){
        //     memset(shining+w, johnny[w], 1);
        //     printf("%s\n", shining);
        //     sleep(1);
        // while (w>=5){
    for(int e = 0; e<strlen(jack); e++){
        memset(shining+(e+5), johnny[e+5], 1);
        memset(shining+e, jack[e], 1);
        printf("%s\n", shining);
        sleep(1);
        // }
    }

    // for(int r = 0; r<strlen(shining); r++){
    //     memmove(shining+r,jack,strlen(shining));
    //     printf("%s\n", shining);
    // }

    printf("%s\n\n", johnny);

    free(shining);
    // }


    //******************싸이코로 실습*********************//
    int result;
    int count = 1;

    bates = malloc(strlen(son)*10);

    printf("STAGE 1\n");
    sleep(1);

    printf("<BATES HOTEL에 오신 걸 환영합니다>\n");

    for(int c = 0, l = strlen(son) * 10; c<l; c++){
        bates[c] = son[c % 3];
    }
    printf("%s\n\n", bates);

    //첫 번째 살인
    printf("몇호실에서 묵으시렵니까?\n");
    printf("숫자만 입력하세요 (1 ~ 10) : ");
    scanf("%i", &n);
    // check(n);
    printf("\n");
    sleep(1);

    for (int j = 3 * (n-1); j < 3*n; j++){
        memset(bates+j,  mom[j%3], 1);
    }
    printf("%s\n", bates);
    printf("꺄아아아아아악!!!!!\n");
    sleep(1);
    printf("당신은 살해당했습니다...\n\n");
    sleep(1);


    //////// 메모리 복사, 이동, 비교 ( MOM < SON )
    printf("STAGE 2\n");
    printf("탐정으로 플레이어 전환\n");
    printf("범인을 피해 호텔을 잘 살펴보세요\n\n");
    printf("%s\n", bates);
    for(;;){
        printf("탐색할 호실을 입력하세요 (1 ~ 10) : ");
        scanf("%i", &m);
        // check(m);
        printf("\n");

        result = memcmp(bates+(3*(n-1)), bates+(3*(m-1)), 3);

        //Debug용
        // printf("%s\n", bates);
        // printf("bates[3*(n-1)]: %c, bates[3*(m-1)]: %c\n", bates[3*(n-1)], bates[3*(m-1)]);
        // printf("%i\n\n", result);

        if (result == 0){
            printf("당신: 아니 당신은?!\n");
            printf("범인이 당신을 발견하고 공격했습니다.\n");
            printf("당신은 공격을 받고 사망하고 말았습니다.\n\n");
            break;
        }else{
            printf("아들: 내가 여기 들어오지 말라고 했잖아! 당장 나가지 못해!?\n");
            printf("(이크, 쫓겨났네...)\n\n");
            memmove(bates+(3*(m-1)),mom,3);
            printf("%s\n", bates);
            // memcpy(bates+(3*(m-1)),mom,3);
            // ref에 나오는 설명과 다르게
            // printf("%s\n", bates);
            for(int f = 0; f<10;f++){
                if (bates[3*f] == 'M'){
                    count ++;
                }
            }
            // printf("%i\n\n",count);

            if(count == 55){
                printf("Well, a boy's best friend is his mother.\n\n");
                printf("축하합니다. 죽지 않고 범인을 잡았군요.\n");
                printf("하지만 아들의 인격체가 결국 엄마의 인격체에게 잠식당해 버렸답니다.\n");
                printf("끝\n\n");
                return 0;
            }
            continue;
        }
        // compare(result);
        // if (bates)
    }



    //////// 메모리 비교
    // char *string1 = get_string("word1: ");
    // printf("string1: %s\n", string1);
    // char *string2 = get_string("word2: ");
    // printf("string2: %s\n", string2);

    // result = memcmp(string1, string2, 3);
    // compare(result);

}

// void compare(int result){
//     switch(result){
//         case 0:
//             printf("범인이 당신을 발견하고 공격했습니다.\n");
//             printf("당신은 공격을 받고 사망하고 말았습니다.\n\n");
//             break;
//         case 1:
//             printf("after is smaller than previous\n");
//             break;
//         case -1:
//             printf("아들: 내가 여기 들어오지 말라고 했잖아!\n");
//             printf("아들: 당장 나가지 못해!?\n");
//             memmove(bates+(3*m),mom,3);
//             continue;
//     }
// }

// void check(int z){
//     if( z>=1 && z<=10){
//         continue;
//     }else{
//         printf("그런 방은 없습니다. 다시 선택해주세요.\n");
//     }
// }
//-> 이 부분은 다시 방을 선택하시오. 로 돌아가도록 하는 방법이 현재 없기 때문에
//    안됨.

/*

reference:

https://dojang.io/mod/page/view.php?id=285
https://blog.naver.com/sharonichoya/220508334439
http://blog.naver.com/PostView.nhn?blogId=sharonichoya&logNo=220510332768

*/
