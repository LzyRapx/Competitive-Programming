#include<stdio.h>
#include<math.h>
#include<iostream>
#define PI acos(-1.0)
#define g  9.87

int main()
{
	double v,m,a;
	double H2=0.5; int H1=3;
	while(~scanf("%lf%lf%lf",&v,&m,&a))
	{
		double Vx=v*cos(a*PI/180); //ˮƽ�ٶ� 
		double Vy=v*sin(a*PI/180);  //��ֱ�ٶ� 
		double x,t1,t2,t;
		if(Vy*Vy/(2*g)>H2)		//�µó����컨�塣������ 
		{   
	        double t1=2*(Vy-sqrt(Vy*Vy-2*H2*g))/g; //�����컨��ʱ������������ 
            double t2=(sqrt(Vy*Vy+2*g*H1)-Vy)/g; // ���� 
            t=t1+t2;  
		}
		else   //�²����컨�� 
        {
            t=2*Vy/g+(sqrt(Vy*Vy+2*g*H1)-Vy)/g;
        }
        x=t*Vx; 
		printf("%.3lf\n",x);
	}
	return 0;
}