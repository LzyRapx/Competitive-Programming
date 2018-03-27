#include<iostream>
#include<algorithm>
#include<stdio.h>
#include<string.h>
using namespace std;
#define ll long long
char str[1010];
struct point
{
    double x,y;
}p[1010];
double cross(point a,point b,point c)//������
{
    return (b.x-a.x)*(c.y-a.y)-(b.y-a.y)*(c.x-a.x);
}
int main()
{
    int n;
    while(scanf("%d",&n)&&n)
    {
        for(int i=0;i<n;i++)
        {
            scanf("%lf%lf",&p[i].x,&p[i].y);
        }
        p[n++]=p[0];
        p[n++]=p[1];
        bool ans=true;
        for(int i=2;i<n;i++)
        {
            if(cross(p[i-2],p[i-1],p[i])<0) //С��0���Ƕȴ���180�� 
            {
                ans=false;
                break;
            }
        }
        if(ans) puts("convex");//��͹��
        else puts("concave");//����͹��
    }
    return 0;
}
