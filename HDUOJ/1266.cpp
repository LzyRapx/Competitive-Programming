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

int main(){
	int t;
	char s[117];
	scanf("%d",&t);
	while(t--)
	{
		scanf("%s",&s);
		int k=0;
	    int len = strlen(s);
		if(s[0]=='-')
		printf("-");
		int flag=0;
		for(int i=len-1;i>=0;i--) //�ַ����������
		{
			if(s[i]=='0'&&flag==0)  //β��Ϊ0ʱ��־Ϊ0
			k++;
			else if(s[i]=='-')
			continue;
			else
			{
				flag=1;  //�м�ĵ�0����־
				printf("%c",s[i]);
				
			}
		}
		for(int i=0;i<k;i++)
		  printf("0");
		  printf("\n");
	}
  return 0;
}