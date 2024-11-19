#include<stdio.h>
#include<stdlib.h>
#include<math.h>

#define Max_x 2.0
#define Min_x 0.0
#define Max_y 1.0
#define mu 1.0
#define sigma 0.1

float func(float x);

int main(void)
{
                FILE*fp;
                int i,j,k,rank;
                float x,y_try,y_ref;
                int hst[201]={0};
                j=0;
                for(i=0;j<10000;i++){
                                x=(float)rand()/RAND_MAX*(Max_x-Min_x)+Min_x;
                                y_ref=func(x); /*棄却法*/
                                y_try=(float)rand()/RAND_MAX*Max_y;
                                if(y_try<=y_ref){
                                                j++;
                                                rank=(int)((x-Min_x)/0.01);
                                                if(rank >=0 && rank<201){  /*同じ幅の乱数まとめる*/
                                                        hst[rank]++;
                                                        }
                                        }
                        }
                        fp=fopen("er.dat","w");
                        for(k=0;k<201;k++){
                                        printf("hst[%d]=%d\n",k,hst[k]);
                                        fprintf(fp,"%.2f-%.2f %d\n",k*0.01,(k+1)*0.01,hst[k]);
                                }
                                fclose(fp);

                                return 0;

        }
float func(float x){
      float y;
      y=exp(-(x-mu)*(x-mu)/(2*sigma*sigma));
      return y;
        }
        
