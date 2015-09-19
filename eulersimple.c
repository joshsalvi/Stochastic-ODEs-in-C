/* Euler for a set of first order differential equations */

#include <stdio.h>
#include <math.h>
#define dist 0.2               /* stepsize in t*/
#define MAX 1.0                /* max for t */
int N=1;
void euler(double x, double y[], double step); /* Euler function */

double f(double x, double y[], int i);          /* function for derivatives */

main()
{
double t, y[N];
int j;

y[0]=1.0;                                       /* initial condition */

 
for (j=0; j*dist<=MAX ;j++)                     /* time loop */
{
   t=j*dist;
   printf("j =  %d,t = %f y[0] = %f\n", j,t, y[0]);
   euler(t, y, dist);

}

}

void euler(double x, double y[], double step)
{
double  s[N];      /* for euler */
int i;
{
for (i=0;i<N;i++)
 {     s[i]=step*f(x, y, i);
}
}

{
for (i=0;i<N;i++) 
     y[i]+=s[i];
}
}
double  f(double x, double y[], int i)
{
      return(x-y[0]);                 /* derivative of first equation */
}