#include<iostream>
#include<cstdlib>
#include<cstdio>
#include<cmath>
#include<cstring>
#include<string>
#include<cstdlib>
#include<iomanip>
#include<algorithm>
typedef long long LL;
using namespace std;

int main()
{
	int n,i,s;
	char a[100];
	cin>>n;
	getchar(); //ע�������getchar
	while(n--)
	{
		s=0;
		gets(a);
		for(i=0;i<strlen(a);++i)
		{
			if(a[i]<0)
			s++;
		}
	//���ֵ�ascii��Ϊ��ֵ�����Һ���Ϊ�����ֽڣ����Գ��Զ���
		cout<<s/2<<endl;
     } 
    return 0;
}