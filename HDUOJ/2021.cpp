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
	int i,n,a[100],num;
	while(cin>>n&&n)
	{
		num=0;
		for(i=0;i<n;i++)
		{
			cin>>a[i];
			num+=a[i]/100+a[i]%100/50+a[i]%100%50/10; //3�� 
			num+=a[i]%100%50%10/5+a[i]%100%50%10%5/2;  //3�� 
			num+=a[i]%100%50%10%5%2;   //2�� 
		}
		cout<<num<<endl;
	}
	return 0;
}