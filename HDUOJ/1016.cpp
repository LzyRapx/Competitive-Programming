#include<iostream>       
#include<cstdlib>      
#include<cstdio> 
#include<cstring>      
#include<cmath>           
#include<string>      
#include<cstdlib>      
#include<iomanip>      
#include<vector>      
#include<list>      
#include<map>      
#include<queue>    
#include<algorithm>    
using namespace std;
int a[30],b[30];
int n,cas=0;
int prime(int x)
{
	int i;
	for(i=2;i*i<=x;i++)
	if(x%i==0)return 0;
	return 1;
}
void dfs(int x,int y)
{
	for(int i=1;i<=n;i++)
	{
		if(b[i]==0)
		{
			if(prime(x+i)==1)
			{
				b[i]=1; //��־i�ù� 
				a[y]=i;  //���� i ��ֵ 
				dfs(i,y+1); //������ 
				b[i]=0;   //û���ѵ��ͱ�־��ǰ�� i û�ù� 
			}
		}
	}
	if(y==n+1) //n+1���ǽ�����־ 
	{
		if(prime(x+1)==1) //�ж����һ���͵�һ������ 1 ����Ƿ���� 
		{
			for(int i=1;i<n;i++)
			printf("%d ",a[i]);
			printf("%d\n",a[n]);
		 } 
	}
}
int main()
{

	while(cin>>n)
	{
		printf("Case %d:\n",++cas);
		a[1]=1;
		b[1]=1;
		dfs(1,2);
		printf("\n");
	}
	return 0;
 } 