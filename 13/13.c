#include<stdio.h>
#include<math.h>

#define g 9.8 /*gravitation acc  (m/s^2)*/
#define dt 0.1

int main(void){
        float x0,y0,vx0,vy0; /*初期条件(m,m/s)*/
        float x,y,t,vx,vy; /*位置(m)，速度8(m/s)時刻(s)*/
        float delx,dely,delvx,delvy; 

        x0=10; y0=5;
        vx0=4; vy0=6; /*初期条件の値*/

        FILE*fp;   /*ファイルポインタの宣言*/
        fp=fopen("ik.dat","w");
        for(t=0;t<2.0;t=t+dt){
                        vx=vx0;
                        delvx=0;
                        vy=vy0-g*t;
                        delvy=vy-g*dt;
                        x=x0+vx*t;
                        delx=x+vx*dt;
                        y=y0+vy*t-1/2*g*t*t;
                        dely=y+vy*dt-g*t*dt;
                        printf("%8.3f,%8.3f,%8.3f\n",t,x,y);
                        fprintf(fp,"%8.3f,%8.3f,%8.3f\n",t,x,y);
                }
    fclose(fp);
    return 0;
}

