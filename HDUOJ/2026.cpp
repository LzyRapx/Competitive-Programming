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
	int i;
	char a[100];
	while(gets(a))
	{
		for(i=0;i<strlen(a);++i)
		{
            if(i==0) 
        //���ַ������мӼ���ֱ�Ӷ�Ӧ��Ӧ��ĸ��a��ascii��Ϊ97��A��ascii��Ϊ65����32��
			a[0]=a[0]-32; 
			if(a[i]==' ')
			a[i+1]=a[i+1]-32;
			cout<<a[i];
		}
		cout<<endl;
	}
	return 0;
}