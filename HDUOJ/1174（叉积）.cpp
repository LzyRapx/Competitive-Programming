#include<iostream>
#include<cstdlib>
#include<cstdio>
#include<cmath>
#include<cstring>
#include<string>
#include<cstdlib>
#include<algorithm>
///typedef long long LL;
using namespace std;
//��˹�ʽ������AB�������AC��ģ�ٳ�������AC��ģ����B��AC�ľ��룻   
double chacheng(double x1,double y1,double z1,double x2,double y2,double z2)  
{  
    double a, b, c; 
	//��ǹ�ķ��������뾯�����������ߵ�'��� ' 
    a = y1*z2-z1*y2;  
    b = x1*z2-z1*x2;  
    c = x1*y2-y1*x2;  
    return sqrt((a*a+b*b+c*c))/sqrt((x2*x2+y2*y2+z2*z2));  
}  
int main()
{
    int T;  
    double h1,r1,x1,y1,z1;  
    double h2,r2,x2,y2,z2,x3,y3,z3;  
    double a,b,c,dis;  
    cin>>T;    
    while(T--)  
    {  
        cin>>h1>>r1>>x1>>y1>>z1;  
        cin>>h2>>r2>>x2>>y2>>z2>>x3>>y3>>z3;    //(x3,y3,z3)ǹͷ��ָ����ķ������
          
        z1 += h1-r1;					//����ͷ��Z������  
        z2 += h2*0.9-r2;				//����ͷ��Z������  
     
     //����ͷ���뾯��ͷ���������� 
        a=x1-x2;						 
        b=y1-y2;  
        c=z1-z2;  

        dis = chacheng(a,b,c,x3,y3,z3);  
        if(dis<=r1&&(a*x3+b*y3+c*z3)>0)  //(a*x3+b*y3+c*z3)>0��Ϊ���жϷ�ͽ�ǲ����ھ�������  
            cout<<"YES"<<endl;  
        else  
            cout<<"NO"<<endl;
    } 
   return 0;
}


