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
	int t; int a,b,c;
	cin>>t;
	while(t--)
	{
		cin>>a>>b>>c;
//���к����ʱ����������Դ�7�ֵ���֮��7�����ɷŻ�����,����һ����8�� 
/*�ص㣬����˹ŵ�˵Ĺ���ÿ�δ�����������Դ�һ�β��򣬲�����������·Ż����ϣ���û�к���ʱ��ֻ�ܴ���򲻹���ʱ�����ܷŻ�����*/
/*���Դ�������֮���7����÷����Ϊ8*/
		if(a>6)b=b+(a-6)*8+2+3+4+5+6+7;
		else 
		 for(int i=7;a>0;--i,--a) b+=i;
		 if(b>=c)printf("Yes\n");
		 else printf("No\n");
	}
    return 0;
}