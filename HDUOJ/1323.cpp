#include<iostream>
#include<cstdlib>
#include<cstdio>
#include<cmath>
#include<cstring>
#include<string>
#include<cstdlib>
#include<algorithm>
typedef long long LL;
using namespace std;
int main()
{
	int a[110],num=1,i,j;
	while(~scanf("%d",&a[num]),a[num])
	{
		num++;
	}
	printf("PERFECTION OUTPUT\n");
	for(i=1;i<num;i++)  //i���õ���num����Ϊ����������Ϊ0 
	{
		int sum=0;
		for(j=1;j<=a[i]/2;j++)
		{
			if(a[i]%j==0)     //����ȸ���С�����й�Լ��������8��1,2,4,��ʱΪDEFICIENT
			{
				sum+=j;
			}
		} 
		if(sum==a[i])
		printf("%5d  PERFECT\n",a[i]);
		else if(sum>a[i])
		printf("%5d  ABUNDANT\n",a[i]);
		else 
		printf("%5d  DEFICIENT\n",a[i]);
	}
	printf("END OF OUTPUT\n");
	return 0;

}