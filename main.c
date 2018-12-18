#include <stdio.h>
#include <math.h>
#include <sys/types.h>
#include <unistd.h>
#include <stdlib.h>
#include <stddef.h>
#include <sys/sysinfo.h>
#include <time.h>
#include <sys/wait.h>
#include <sched.h>

/* 
 *	The SCHED_BATCH is supported since Linux 2.6.16
 */
#define SCHED_BATCH 3 

#define PARENT_PRIORITY	 	5	
#define HIGH_PRIORITY		4
#define MIDDLE_PRIORITY		3
#define LOW_PRIORITY		2

void show_sched() {
    switch( sched_getscheduler(getpid()) ) {
        case SCHED_OTHER :
            printf("The current scheduler is SCHED_OTHER.\n");
            break;
        case SCHED_BATCH :
            printf("The current scheduler is SCHED_BATCH.\n");
            break;
        case SCHED_FIFO  :
            printf("The current scheduler is SCHED_FIFO.\n");
            break;
    }    
}

int main(int argc, char *argv[]) {
    int count = 0;
    int n_filhos = 10;
    int sched_type = 0;
    pid_t pai = getpid();
    clock_t begin_pai = clock();

    if(strcmp(argv[1],"OTHER")==0) {
        sched_type = SCHED_OTHER;
    } else if(strcmp(argv[1],"BATCH")==0) {
        sched_type = SCHED_BATCH;
    } else if(strcmp(argv[1],"FIFO")==0) {
        sched_type = SCHED_FIFO;
    } 

    printf("--------- Beginning of test ---------\n");
    show_sched();

	/*
	 * The following structure is used to set a processes priority
	 */
  	struct sched_param param;
    //#pragma GCC diagnostic ignored "-Wunused-but-set-variable"
	
	/*
	 * Set the scheduler to the Round Robin scheduler
	 */
	param.sched_priority = 0;
	if( sched_setscheduler( pai, sched_type, &param ) == -1 ) {
		printf("error setting scheduler ... are you root?\n");
        printf("--------- Ending of test ------------\n\n");
		exit(1);
	}

	//printf("Parent prio = %d\n", getpriority(PRIO_PROCESS, 0));
	//sched_getparam(0, &param); 
	//printf("Parent sched prio = %d\n", param.sched_priority);
    show_sched();


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
        printf("--------- Ending of test ------------\n\n");
    }
   

    return 0;
}