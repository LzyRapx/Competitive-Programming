#include<iostream>
#include<stdio.h >
#include<string>
#include<algorithm>
using namespace std;
string a[110];
int main()
{
	string s1,s2;
	int t,n,i,j,mini,min,k,max;
	cin>>t;
	while(t--)
	{
		max = 0; min = 200;
		cin>>n;
		for(i=0; i<n; i++)
		{
			cin>>a[i];
			if(a[i].size() < min)
			{
				min = a[i].size();
				mini = i;
			}
		}
		for(i=0; i<a[mini].size(); i++)
		{
			for(j=1; j<=a[mini].size() - i; j++)
			{
				s1 = a[mini].substr(i,j); //���ش�i��ʼ�� j ���ַ���ɵ��ַ���
				s2 = s1;
				reverse(s2.begin(),s2.end());
				for(k=0; k<n; k++)
				{
					//��0��ʼ�����ַ���s1��s2 �ڵ�ǰ���е�λ�ã����ҳɹ�ʱ��������λ�ã�ʧ�ܷ���string::npos��ֵ
					if(a[k].find(s1,0) == string::npos && a[k].find(s2,0) == string::npos)  
						break;
				}
				
				if(k == n && j > max)
					max = j;
			}
		}
		
		cout<<max<<endl;
	}
	return 0;
}


-------------------------
#include <iostream>
#include<stdio.h>
#include <algorithm>
using namespace std;
string str[110]; 
int t;
int cmp(const string& a, const string& b){
	return a.length()<b.length();
}
//string substr(int pos = 0,int n = npos) const;  ���ش�pos��ʼ��n���ַ���ɵ��ַ���

int dfs(string now,string reve,int len)
{
	for(int i=1;i<t;i++)
	{
		int sign=0;
		for(int j=0;j+len<=str[i].length();j++)
		{
			string sub=str[i].substr(j,len);  //���ش�j��ʼ ,����Ϊlen���Ӵ�
			
			if(sub==now||sub==reve) 
			{
				sign=1;break; //�ҵ��ͼ�����
			}
		}
		if(!sign)
			return 0; //����ֱ���˳�
	}
	return len;
}
int main(){
	int n;
	cin>>n;
	while(n--){
		cin>>t;
		for(int i=0;i<t;i++)
			cin>>str[i];
		sort(str,str+t,cmp);
		int len=str[0].length();
		int max=0;
		for(int i=len;i>=1;i--)
		{
			for(int j=0;j+i<=len;j++)
			{
				string now=str[0].substr(j,i); //�ش� j��ʼ�� i���ַ���ɵ��ַ���
				string reve=now;
				reverse(reve.begin(),reve.end());
				//��д�ķ�ת�ַ���,����һ��Ч����ͬ 
				//for(int k=now.length()-1;k>=0;k--) 
				//	rev+=now[k];
				//cout<<rev<<endl;
				int maxn=dfs(now,reve,i);
				if(maxn>max)
					max=maxn;
			}
		}
		cout<<max<<endl;
	}
	return 0;
}