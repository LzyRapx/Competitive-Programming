#include<iostream>
#include<stdio.h>
#include<cmath>
#include<algorithm>
using namespace std;
int x[15],num[15]={0};
int sum;
int n;
int check (int k)
{
	for(int i=1;i<k;i++)
	{
		//��֦�����ж��Ƿ������������,i��ʾ�ʺ����ڵ�������x[i]��ʾ���ڵ�������
		//����ǰ���Ǹ����������ж������ʺ��Ƿ��ڶԽ�����,���������ж��Ƿ���ͬһ���ϡ�
		//��������Ҫ�жϣ���Ϊ���Ǳ����i�ʹ����������
		if(abs(k-i)==abs(x[k]-x[i])||x[k]==x[i])
		return 0;
	}
	return 1;
}
void dfs(int a)
{
	if(a>n)q
	{
		sum++;
	}
	else for(int i=1;i<=n;i++)
	{
		x[a]=i; //�� a���ʺ�ŵ����� i 
		if(check(a))  
		{
			dfs(a+1);
		}
	}
}

int main()
{ 
	int N;
	for(int i=0;i<=10;i++)
	{
		n=i; //��ʾ�����ʺ�
		sum=0;  //ÿ�ζ����� 
		dfs(1); //ÿ�δӵ�һ���ʺ�ʼ 
		num[i]=sum;  //�洢���� 
		
	}
	
	while(~scanf("%d",&N)&&N)
	{
		printf("%d\n",num[N]);
	}
	return 0;
}