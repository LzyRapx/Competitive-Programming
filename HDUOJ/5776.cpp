#include<bits/stdc++.h>
using namespace std;
int n,m;
int a[100010];
bool vis[100010];
int main()
{
	int t;
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d%d",&n,&m);
		memset(vis,0,sizeof(vis));
		int sum=0;
		vis[0]=1;
		bool flag=0;
		for(int i=1;i <= n;i++)
		{
			scanf("%d",&a[i]);
			sum=(sum+a[i])%m;
			if(vis[sum])
			{
				flag=1;
			}
		//���������������ͬ��������ӵ�����һ���п�ģ m �� 
			vis[sum] = 1; 
		}
		puts(flag ?"YES" : "NO");
		
	}
	return 0;
}