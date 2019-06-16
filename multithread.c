#define _GNU_SOURCE
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <pthread.h>
#include <sched.h>
void fun2(char buff[]){
	char array =0;
}
void *myfun(void * CPUNum)
{
    cpu_set_t mask;
   //cpu_set_t get;
    char buf[256];
    int i;
    int j;
    int num = sysconf(_SC_NPROCESSORS_CONF);
    printf("system has %d processor(s)\n", num);
    for (i = 0; i < num*20; i++) {
        //CPU_ZERO(&mask);
        //CPU_SET(3, &mask);
       //if (pthread_setaffinity_np(pthread_self(), sizeof(mask), &mask) < 0) {
       //     fprintf(stderr, "set thread affinity failed\n");
      // }
        //CPU_ZERO(&get);
        //if (pthread_getaffinity_np(pthread_self(), sizeof(get), &get) < 0) {
        //    fprintf(stderr, "get thread affinity failed\n");
       // }
       // for (j = 0; j < num; j++) {
       //     if (CPU_ISSET(j, &get)) {
       //         printf("thread %d is running in processor %d\n", (int)pthread_self(), j);
       //     }
       // }
        j = 0;
        while (j++ < 100000000) {
		char buf2[256];
		fun2(buf2);
            //memset(buf, 0, sizeof(buf));
		if(j%100000==0){
		//usleep(*(int *)CPUNum);
		}
        }
	usleep(*(int *)CPUNum);
    }
   // pthread_exit(NULL);
}
void *MyFun0(void *arg){
	while(1){
		usleep(1);
	}	
}
int main(int argc, char *argv[])
{
	
    pthread_t tid[16];
	int num=2;
    if (pthread_create(&tid[0], NULL,&myfun,(void *)&num) != 0) {
        fprintf(stderr, "thread create failed\n");
        return -1;
	}
    pthread_t tid2;
	int num2=3;
    if (pthread_create(&tid[1], NULL,&myfun,(void *)&num2) != 0) {
        fprintf(stderr, "thread create failed\n");
        return -1;
    }
    pthread_t tid0;
        int num0=1;
    if (pthread_create(&tid[2], NULL,&myfun,(void *)&num2) != 0) {
        fprintf(stderr, "thread create failed\n");
        return -1;
    }
	int i=3;
    for(;i<16;i++){
	pthread_create(&tid[i], NULL,&MyFun0,(void *)&num2);
	}
    for( i=0;i<16;i++){
	pthread_join(tid[i],NULL);	
}
    //pthread_join(tid1, NULL);
    //pthread_join(tid, NULL);
    //pthread_join(tid0, NULL);
    return 0;
};
