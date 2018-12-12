#include <stdio.h>
#include <math.h>
#include <sys/types.h>
#include <unistd.h>
#include <stdlib.h>
#include <stddef.h>
#include <time.h>
#include <sys/sysinfo.h>
#include <sys/wait.h>

int main(void){
    int count = 0;
    int n_filhos = 10;
    pid_t pai = getpid();
    clock_t begin_pai = clock();
    // printf("Pai, pid: %d\n",pai);
    while (count < n_filhos){
        if (getpid() == pai){
            pid_t filho = fork();
            if (filho == 0){
                // printf("Filho %d, pid: %d\n",count, getpid());
                clock_t begin = clock();
                for (int i = 0; i < 999999; i++){
                    for (int j = 0; j < 1000; j++){
                        rand();
                    }
                }
                clock_t end = clock();
                double time_spent = (double)(end - begin) / CLOCKS_PER_SEC;
                printf("time: %f\n", time_spent);
                break;
            }
            
        }
        count++;
    }
    for (int i = 0; i < n_filhos; i++){
        wait(NULL);
    }
    if (getpid() == pai){
        clock_t end_pai = clock();
        double time_spent = (double)(end_pai - begin_pai) / CLOCKS_PER_SEC;
        printf("total: %f\n", time_spent);
    }
    
    return 0;
}

// int main(void){
//     clock_t begin = clock();

//     for (int i = 0; i < 999999; i++){
//         for (int j = 0; j < 1000; j++){
//             rand();
//             // sqrt(r);
//         }
//     }

//     clock_t end = clock();

//     double time_spent = (double)(end - begin) / CLOCKS_PER_SEC;

//     printf("time: %f\n", time_spent);

//     return 0;
// }