#include<stdio.h>
#include<stdlib.h>

int main(void)
{
      FILE*fp;

      int i,rnd;
      float x;
      int hst[10]={0};

      
      for(i=0;i<10000;i++){      /*乱数10000個生成*/
                      rnd=rand();
                      x=(float)rnd/RAND_MAX;　　/*生成したものを0.0~1.0に収める*/
                      
                      int zone=(int)(x*10);　　/*分類*/
                      if(zone>=0&&zone<10){
                      hst[zone]++;
                              }
              }

              fp=fopen("qa.dat","w");
              for(i=0;i<10;i++){
                              printf("hst[&d]=%d\n",i,hst[i]);
                              fprintf(fp,"%.1f-%.1f %d\n",i*0.1,(i+1)*0.1,hst[i]);
                      }
                      fclose(fp);

                      return 0;

        }

