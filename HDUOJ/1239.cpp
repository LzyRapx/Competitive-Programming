#include<stdio.h>
#include<math.h>
using namespace std;
int prime(int n)
{
    if(n<=1)
    return 0;
    if(n==2)
    return 1;
    for(int i=2;i<n;i++)
    {
        if(n%i==0)
        {
            return 0;
        }
    }
    return 1;
}
//Ҫ��2����(������Ϊp,q)��p,q��Ϊ������p*q<=m;a/b <= p/q <= 1;c.���������������������p,q�г˻�����һ��p,q
int main()
{
	int m,a,b;
	while(~scanf("%d %d %d",&m,&a,&b))
    {
    	if(m==0&&a==0&&b==0)break;
        float score =1.0*a/b;
        int i;
        int j;
        for(i=m;i>=4;--i)
        {
            if(!prime(i))   //i���������� 
            for(j=2;j<=sqrt(i*1.0);j++)
            {
                if(i%j==0)
                {
                    if(prime(j)&&prime(i/j)&&(score<=j*1.0/(i/j))&&(j*1.0/(i/j)<=1)) //�������Ӷ�Ҫ������ 
                    {
                      goto A;
                      
                    }
                }
            }
        }
       A:printf("%d %d\n",j,i/j);
    }
	return 0;
}