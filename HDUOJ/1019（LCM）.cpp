#include<cstdio>
#include<iostream>
using namespace std;
int gcd(int a,int b)
{
	if(!b)return a;
	return gcd(b,a%b);
}
int main()
{
	int T,n,b,c;
	scanf("%d",&T);
	while(T--){
		scanf("%d%d",&n,&b);
		for(int i=1;i<n;i++){
			scanf("%d",&c);
			b=b/gcd(b,c)*c; //��������С������=��������ٳ������������Լ�� 
		}
		printf("%d\n",b);
		
	}
	return 0;
}