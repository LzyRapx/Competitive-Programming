#include<iostream>
#include<cstdlib>
#include<cstdio>
#include<cmath>
#include<cstring>
#include<string>
#include<cstdlib>
#include<iomanip>
#include<algorithm>
#include<time.h>
typedef long long LL;
using namespace std;

int main()
{
	int t;
    string s0,s1;
	int n;
	LL s[50]={0};
	s[1]=1;
	for(int i=2;i<50;i++)
	{
		s[i]=s[i-1]+s[i-2];
	}
	cin>>t;
	while(t--)
	{
		cin>>s0>>s1>>n;
		LL ch1[26]={0};
		LL ch2[26]={0};
		
		for(int i=0;i<s0.size();i++)
		{
			ch1[s0[i]-'a']++;    //�ַ�ת�������� 
		}
		for(int i=0;i<s1.size();i++)
		{
			ch2[s1[i]-'a']++;   //�ַ�ת�������� 
		}
		
		if(n==0)
		{
			for(int i=0;i<26;i++)
			{
				cout<<(char)('a'+i)<<":"<<ch1[i]<<endl;   //n=0ʱ��ֻ�����һ�� 
			}
			cout<<endl; continue;
		}
		for(int i=0;i<26;i++)
		{
			cout<<(char)('a'+i)<<":"<<s[n-1]*ch1[i]+s[n]*ch2[i]<<endl; //�ۼӵ���n-1���͵�n�� 
		}
		cout<<endl;
	}
	
    return 0;

}