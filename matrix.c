#include <stdio.h>
#include <math.h>
#include <sys/mman.h>
#include <pthread.h>
#include <malloc.h>
#include <stdlib.h>
#define NTHREADS 10000 

pthread_mutex_t job_queue_mutex = PTHREAD_MUTEX_INITIALIZER;
int j,i,x,y,x,matrix1[20][20],matrix2[20][20],matrix3[20][20];
/* for(j=0; j<3; j++){
        for(i=0; i<3; i++){
        printf("Please enter [%d] [%d]", j,i);
        scanf("%d", &matrix[j][i]); */
	
	
   

struct thread_info {
   int maxitr,i,j;
   int m1[20][20];
   int m2[20][20];
   int m3[20][20];

};

typedef struct thread_info thread_info_t;



void *func(void *arg)
{


thread_info_t *info;
pthread_mutex_lock(&job_queue_mutex);
info = (thread_info_t *)arg;
 for(i=0; i<18; i++){
        for(j=0; j<16; j++){

          
          matrix1[i][j]=i+j;  
          info->m1[i][j] = matrix1[i][j];
          
         
}
}
pthread_mutex_unlock(&job_queue_mutex);
pthread_mutex_lock(&job_queue_mutex);
 for(x=0; x<=16; x++){
        for(y=0; y<=18; y++){
         
    
          matrix2[x][y]=x+2*y;  
          info->m2[x][y] = matrix1[x][y];
       //   printf("i = %d j=%d num=%d \n", x,y,matrix2[x][y]);
}
}
pthread_mutex_unlock(&job_queue_mutex);
;
//  info->v[0][0] = matrix1[0][0];
 // info->m1[0][1] = matrix1[0][1];
  
/*
int matrix[3][3],i,j;

 for(j=0; j<3; j++){
   for(i=0; i<3; i++){
        printf("Please enter [%d] [%d]", j,i);
        scanf("%d", &matrix[j][i]);
	
	
   }
}
*/
  

   


}

/*int computeC(int c1, int c2)
{

int c = c1*c2;
return c;

}*/

int main(void)
{

typedef struct thread_info thread_info_t;
int j1,j2,i1,i2,matrix[3][3];

pthread_t thread[3][3];
thread_info_t info[3][3];

/*
for(j1=0; j1<3; j++){
        for(i1=0; i1<3; i++){
if (pthread_create(&thread[j1][i1], NULL, &func, &info[j1][i1]) != 0) {
           printf("Error in creating thread 1\n");
           exit(1);
          }
}
}

   pthread_join(thread[0][0], NULL);
   printf("1 %lf", info[0][0].v1);
*/

 // printf("compute c = %d", computeC(2,2));;

//int x1,y1;

 //for(x1=0; x1<=16; x1++){
   //     for(y1=0; y1<=18; y1++){
      
    
     //     pthread_create(&thread[x1][y1], NULL, &func, &info[x1][y1]);
     //     pthread_join(thread[x1][y1], NULL);
       //  printf("0-0  %d \n", info[x1][y1].m1[x1][y1]);
       //   printf("i = %d j=%d num=%d \n", x,y,matrix2[x][y]); 
}
}



pthread_create(&thread[0][0], NULL, &func, &info[0][0]);
pthread_create(&thread[0][1], NULL, &func, &info[0][1]);
pthread_create(&thread[0][2], NULL, &func, &info[0][2]);
pthread_create(&thread[0][3], NULL, &func, &info[0][3]);
         
pthread_create(&thread[1][0], NULL, &func, &info[0][0]);
pthread_create(&thread[1][1], NULL, &func, &info[0][1]);
pthread_create(&thread[1][2], NULL, &func, &info[0][2]);
         
pthread_create(&thread[1][3], NULL, &func, &info[0][3]);
pthread_create(&thread[2][0], NULL, &func, &info[0][0]);
pthread_create(&thread[2][1], NULL, &func, &info[0][1]);
pthread_create(&thread[2][2], NULL, &func, &info[0][2]);
         
pthread_create(&thread[2][3], NULL, &func, &info[0][3]);
pthread_create(&thread[3][0], NULL, &func, &info[0][0]);
pthread_create(&thread[3][1], NULL, &func, &info[0][1]);
pthread_create(&thread[3][2], NULL, &func, &info[0][2]);
         
pthread_create(&thread[3][3], NULL, &func, &info[0][3]);

   pthread_join(&thread[4][0], NULL);
   printf("0-0  %d \n", info[0][0].m1[0][0]);
  
   pthread_join(&thread[0][1], NULL);
   printf("0-1  %d \n", info[0][1].m1[0][1]);

   pthread_join(&thread[0][2], NULL);
   printf("0-2  %d \n", info[0][2].m1[0][2]);
  
   pthread_join(&thread[0][3], NULL);
   printf("0-3  %d \n", info[0][3].m1[0][3]);
 
   

/*
if (pthread_create(&thread1, NULL, &func, &info4) != 0) {
           printf("Error in creating thread 4\n");
           exit(1);
          }
   pthread_join(thread4, NULL);
   printf("4", info1.v4);
*/

pthread_exit(NULL);

/
}
