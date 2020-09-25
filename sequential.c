#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <pthread.h>

struct thread_info {
   int maxitr;
   double exec_time,exec_time_1,exec_time_2,exec_time_3,exec_time_4;
};

typedef struct thread_info thread_info_t;

void *func(void *arg)
{
   struct timespec time_1, time_2;
   double exec_time,exec_time_1,exec_time_2,exec_time_3,exec_time_4;
   thread_info_t *info;
   int i, maxitr;
   volatile double a, b, c;

   info = (thread_info_t *)arg;
   maxitr = info->maxitr;

   b = 2.3; c = 4.5;
   exec_time = 0.0;
   exec_time_1 = 0.0;
   exec_time_2 = 0.0;
   exec_time_3 = 0.0;
   exec_time_4 = 0.0;
// Block for add
   clock_gettime(CLOCK_REALTIME, &time_1);

   for (i = 0; i < maxitr ; i++) {
         a = b+c;
   }
         
   clock_gettime(CLOCK_REALTIME, &time_2);

   exec_time_1 = (time_2.tv_sec - time_1.tv_sec)*1e9;
   exec_time_1 = exec_time_1 + (time_2.tv_nsec - time_1.tv_nsec);

   info->exec_time_1 = exec_time_1/maxitr;
//

// Block for sub
   clock_gettime(CLOCK_REALTIME, &time_1);

   for (i = 0; i < maxitr ; i++) {
         a = b-c;
   }
         
   clock_gettime(CLOCK_REALTIME, &time_2);

   exec_time_2 = (time_2.tv_sec - time_1.tv_sec)*1e9;
   exec_time_2 = exec_time_2 + (time_2.tv_nsec - time_1.tv_nsec);

   info->exec_time_2 = exec_time_2/maxitr;
//

// Block for mul
   clock_gettime(CLOCK_REALTIME, &time_1);

   for (i = 0; i < maxitr ; i++) {
         a = b*c;
   }
         
   clock_gettime(CLOCK_REALTIME, &time_2);

   exec_time_3 = (time_2.tv_sec - time_1.tv_sec)*1e9;
   exec_time_3 = exec_time_3 + (time_2.tv_nsec - time_1.tv_nsec);

   info->exec_time_3 = exec_time_3/maxitr;
//

// Block for div
   clock_gettime(CLOCK_REALTIME, &time_1);

   for (i = 0; i < maxitr ; i++) {
         a = b/c;
   }
         
   clock_gettime(CLOCK_REALTIME, &time_2);

   exec_time_4 = (time_2.tv_sec - time_1.tv_sec)*1e9;
   exec_time_4 = exec_time_4 + (time_2.tv_nsec - time_1.tv_nsec);

   info->exec_time_4 = exec_time_4/maxitr;
//

   pthread_exit(NULL);
   
}

int main(void)
{
   pthread_t thread1,thread2,thread3,thread4;
   thread_info_t info1,info2,info3,info4;
   double maxitr;

   maxitr = 5.0e8;

   info1.maxitr = (int)maxitr;

   if (pthread_create(&thread1, NULL, &func, &info1) != 0) {
           printf("Error in creating thread 1\n");
           exit(1);
   }

   pthread_join(thread1, NULL);
   printf("Time division thread1(add) = %lf ns\n", info1.exec_time_1);

if (pthread_create(&thread2, NULL, &func, &info2) != 0) {
           printf("Error in creating thread 2\n");
           exit(1);
   }

   pthread_join(thread2, NULL);
   printf("Time division for thread2(sub) = %lf ns\n", info1.exec_time_2);

if (pthread_create(&thread3, NULL, &func, &info3) != 0) {
           printf("Error in creating thread 3\n");
           exit(1);
   }

   pthread_join(thread3, NULL);
   printf("Time division for thread3(mul) = %lf ns\n", info1.exec_time_3);

if (pthread_create(&thread4, NULL, &func, &info4) != 0) {
           printf("Error in creating thread 4\n");
           exit(1);
   }

   pthread_join(thread4, NULL);

   printf("Time division for thread4 = %lf ns\n", info1.exec_time_4);
   pthread_exit(NULL);
   
//
   
  

   
   

   

//





}
