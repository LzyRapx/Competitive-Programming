#include<stdio.h>
#include<iostream>
#include<cstring>
#include<queue>
#include<algorithm>
using namespace std;
typedef long long LL; 
LL a,b;
int main()
{
    scanf("%lld",&a);
    while(a--)
    {
    	
        scanf("%d",&b);
        LL n=1;   //ÿ����һ���ʹ�S1��ʼģ�⣬�ҳ� b �ڵ�Sn�� 
        while(b>n)  //ģ�� 
        {
            b-=n;   
			n++;
        }
      //  printf("%d\n",b);
	if(b%9==0)
		printf("9\n");
	else
		printf("%lld\n",b%9);
    }
    return 0;
}
