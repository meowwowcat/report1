#include<stdio.h>
#include<math.h>
#include<stdlib.h>

#define Max_x 2.0
#define Min_x -2.0
#define Max_y 1.0
#define mu 0.0
#define sigma 0.5
#define g 9.8
#define dt 0.001
#define OUTPUT 100

float func(float x);
float gen_error();

int main()
{  
   FILE*fp;
   fp=fopen("u.dat","w");
   int i,j,output_counter;
   float t,x,y,vx,vy,error;

   x=10; y=5;
   vx=4; vy=6;

   fprintf(fp,"%8.3f %8.3f %8.3f %8.3f 0.000\n",t,x,y,y);

   output_counter=0;

   for(t=0;t<=2;t+=dt){
                   error=gen_error();
                   printf("%8.3f %8.3f %8.3f %8.3f\n",t,x,y+error,error);
                   if(output_counter==OUTPUT){
                                   fprintf(fp,"%8.3f %8.3f %8.3f %8.3f %8.3f\n",t,x,y,y+error,error);
                                   output_counter=0;
                           }
                           output_counter++;

                           vy=vy-g*dt;
                           x=x+vx*dt;
                           y=y+vy*dt;
           }
           fclose(fp);
           return 0;
        }
float func(float x){
                float y;
                y=exp(-(x-mu)*(x-mu)/(2*sigma*sigma));
                return y;
        }

        float gen_error(){
                        float x_rnd,y_try,y_ref;
                        while(1){  
                                x_rnd=Min_x+(float)rand()/RAND_MAX*(Max_x-Min_x);
                                y_try=(float)rand()/RAND_MAX*Max_y;
                                y_ref=func(x_rnd);
                                if(y_try<=y_ref){
                                                return x_rnd;
                                        }
                                }
                }
