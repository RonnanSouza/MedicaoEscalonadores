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

void get_scheduler(pid_t pid) {
    
    int p_id = (int) pid;
    char command[100];

    char *command_pattern = "chrt -p "; //getting value from a function
    sprintf(command, "%s%d", command_pattern, p_id ); 
    system(command);
}


void set_scheduler(pid_t pid, int sched_type) {

    int p_id = (int) pid;
    char command[100];
    char *command_pattern;

    switch( sched_type ) {
        case SCHED_OTHER :
            command_pattern = "sudo chrt --other -p 0 "; // SCHED_OTHER scheduling policy
            break;
        case SCHED_BATCH :
            command_pattern = "sudo chrt --batch -p 0 "; // SCHED_BATCH scheduling policy       
            break;
        case SCHED_FIFO  :
            command_pattern = "sudo chrt --fifo -p 1 "; // SCHED_FIFO scheduling policy
            break;
    } 
    sprintf(command, "%s%d", command_pattern, p_id ); 
    system(command);   
}

void main(int argc, char *argv[]) {
	
	char *p;							 // convert to int
	long aux = strtol(argv[2], &p, 10); // convert to int
    int n_filhos = aux;
    int count = 0;
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

    set_scheduler(pai, sched_type);

    while (count < n_filhos){
        if (getpid() == pai){
            pid_t filho = fork();
            if (filho == 0){
                clock_t begin = clock();
                for (int i = 0; i < 999999; i++){
                    for (int j = 0; j < 1000; j++){
                        rand();
                    }
                }
                clock_t end = clock();

                double time_spent = (double)(end - begin) / CLOCKS_PER_SEC;
                double time_begin = (double)(begin) / CLOCKS_PER_SEC;
                double time_end = (double)(end) / CLOCKS_PER_SEC;            
                printf("%f %f %f %d %d PROCESSO_%d %s\n", time_spent, time_begin, time_end, n_filhos, (count+1), (count+1), argv[1]);
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
        //printf("total: %f\n", time_spent);
    }
   

    exit(1);
}