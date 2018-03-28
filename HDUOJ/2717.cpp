#include<stdio.h>
#include<string.h>
#include<iostream>
#include<algorithm>
#include<queue>
using namespace std;
const int MAX=100000+10;
int vis[MAX*2];   //���� 2 �ͻ� RE 
int time[MAX*2];
int n,k;

void bfs(int a)
{
	int next;
	int start;
	queue<int>q;
	vis[a]=1;
	time[a]=0;
	
	q.push(a); //�����ڵ� a ��� 
	while(!q.empty())
	{
		start=q.front(); //ȡ����Ԫ�� 
		q.pop();
		for(int i=0;i<3;i++)
		{
			if(i==0)
			{
				next=start+1;
			}
			else if(i==1)  // д��if������������ 
			{
				next=start-1;
			}
			else 
			{
				next=start*2; 
			}
			if(!vis[next] && next <=MAX && next >= 0) //���û�з��ʹ�,��û��Խ��,���,time+1 
			{
				vis[next] = 1;
				q.push(next);
				time[next] = time[start] + 1; 
			}
            if(next==k)
            {
            	printf("%d\n",time[next]);
            	return ;
			}
		}
	}
}

int main()
{
	
	while(~scanf("%d %d",&n,&k))
	{
		memset(vis,0,sizeof(vis));
		memset(time,0,sizeof(time));
		if(n==k)puts("0");
		else bfs(n);
	}
	return 0;
}