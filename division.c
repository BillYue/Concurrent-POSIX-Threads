#include <stdio.h>
#include <time.h>

int main()
{
   double a,b,c;
   int i, itr, time1;
   printf("Enter a ");
   scanf("%lf",&a);   
   printf("Enter b ");
   scanf("%lf",&b); 
   struct timespec start_time, stop_time, sleep_time, res;
   int maxitr = 500000000;
   double tmp1,tmp2,tmp3,tmp4, elapsed_time_a[10], elapsed_time_s[10] ,elapsed_time_m[10], elapsed_time_d[10],time;
 
 
  // clock_getres(CLOCK_REALTIME, &res);
  // printf("The clock resolution of CLOCK %d is %d sec and %d nsec\n",
 //        CLOCK_REALTIME, res.tv_sec, res.tv_nsec);
  // a = clock_gettime(CLOCK_REALTIME, &start_time);
 // sleep_time.tv_sec = 0;
 //  sleep_time.tv_nsec = 10000000000;
  // printf("Sleep time requested is %ld sec  %ld nsec\n",
 //        sleep_time.tv_sec, sleep_time.tv_nsec);

 
 clock_gettime(CLOCK_REALTIME, &start_time);
   for(i = 0; i < maxitr; i++)
   {
      
      c = a / b;
    
   }


   clock_gettime(CLOCK_REALTIME, &stop_time);

 tmp = (stop_time.tv_sec - start_time.tv_sec)*1e9;
 tmp  += (stop_time.tv_nsec - start_time.tv_nsec);

     
      
// for(i = 0; i < maxitr; i++)
 //  {
   //   time += elapsed_time[i];
      
	//}
printf("time is %lf ns", tmp);
printf("\ntime per iteration is %lf ns", (tmp/maxitr));
   return 0;

}
