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
int vis[13],k,m,n;
char s[13],c[13];
bool dfs (int cur,int count)
{
	if(count==5) 
	{
		if(cur==n)return true;
		else return false;
	}
	for(int i=0;i<m;i++)
	   if(!vis[i])
	   {
	   	  vis[i]=1;
	   	  int num=s[i]-'A'+1; //�ַ���Ӧ������
			 c[k++]=s[i];
			 count++;
			 int yuanlai=cur;
			 //����ʽ�� 
			 if(count==1) cur+=num;
			 else if(count==2) cur-=num*num;
			 else if (count==3) cur+=num*num*num;
			 else if(count==4) cur-=num*num*num*num;
            else if(count==5) cur+=num*num*num*num*num;
            if(dfs(cur,count))
                return true;
                k--;
                cur=yuanlai;
                count--;
                vis[i]=0;
	   }
	   return false;
}
int main()
{
	while(scanf("%d ",&n)) //WA�˰��졣����%dҪ������һ���ո� 
	{
		k=0;
		gets(s);
		m=strlen(s);
		memset(vis,0,sizeof(vis));
		if(n==0&&strcmp(s,"END")==0)break;
		//�������Ϊ���������Ϊ�ֵ�������
		for(int i=0;i<m;i++)
		  for(int j=i+1;j<m;j++)
		      if(s[i]<s[j])
		      {
		      	char cs=s[i];
		      	s[i]=s[j];
		      	s[j]=cs;
			  }
	
	if(dfs(0,0))
	{
		c[k]='\0';
		puts(c);
	 }	
		else 
		printf("no solution\n");	  	  
		  		
	}
		
	return 0;
}