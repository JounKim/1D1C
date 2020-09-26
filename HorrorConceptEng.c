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
 
    //Starting with Frankenstein//
    printf("Yes a nice horror for the hot summer!\n");
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
 
 
    //***************Practicing with SHINING*******************//
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
 
 
    //******************Practice 2 with Psycho*********************//
    int result;
    int count = 1;
 
    bates = malloc(strlen(son)*10);
 
    printf("STAGE 1\n");
    sleep(1);
 
    printf("<Welcome to the BATES HOTEL>\n");
 
    for(int c = 0, l = strlen(son) * 10; c<l; c++){
        bates[c] = son[c % 3];
    }
    printf("%s\n\n", bates);
 
    //First Murder
    printf("What room do you want to stay?\n");
    printf("Enter Number (1 ~ 10) : ");
    scanf("%i", &n);
    // check(n);
    printf("\n");
    sleep(1);
 
    for (int j = 3 * (n-1); j < 3*n; j++){
        memset(bates+j,  mom[j%3], 1);
    }
    printf("%s\n", bates);
    printf("Ahhhhhhhhhhhhhhhhhhh!!!!!\n");
    sleep(1);
    printf("You are murdered...\n\n");
    sleep(1);
 
 
    //////// 메모리 복사, 이동, 비교 ( MOM < SON )
    printf("STAGE 2\n");
    printf("Player change to the detective\n");
    printf("Investigate the rooms avoiding the murderer.\n\n");
    printf("%s\n", bates);
    for(;;){
        printf("Enter number of room to investigate (1 ~ 10) : ");
        scanf("%i", &m);
        // check(m);
        printf("\n");
 
        result = memcmp(bates+(3*(n-1)), bates+(3*(m-1)), 3);
 
        //Debug
        // printf("%s\n", bates);
        // printf("bates[3*(n-1)]: %c, bates[3*(m-1)]: %c\n", bates[3*(n-1)], bates[3*(m-1)]);
        // printf("%i\n\n", result);
 
        if (result == 0){
            printf("You: What you?!\n");
            printf("The murderer found you.\n");
            printf("You are attacted and got killed.\n\n");
            break;
        }else{
            printf("Son: I told you to stay out of this room! Get OUT!!\n");
            printf("(Yikes, got kicked out...)\n\n");
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
                printf("Congratulations. You found the murderer without getting killed.\n");
                printf("But the son's consciousness is eaten up by his mothers subconscious.\n");
                printf("The End\n\n");
                return 0;
            }
            continue;
        }
        // compare(result);
        // if (bates)
    }
 }
 
 
    //////// 메모리 비교
    // char *string1 = get_string("word1: ");
    // printf("string1: %s\n", string1);
    // char *string2 = get_string("word2: ");
    // printf("string2: %s\n", string2);
 
    // result = memcmp(string1, string2, 3);
    // compare(result);
 
 
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
