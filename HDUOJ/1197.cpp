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
//������������ת��Ϊ10���� 12���� 16����,�����ת�����ƺ�ÿһλ�ĺ�,����ȵĻ������
int check(int i,int n){
	int s=0;
	while(i>0){
		s=s+i%n;
		i=i/n;
	}
	return s;	
}
int main()
{
	int i=2992;
	int n;
	for(i=2992;i<=9999;i++){
		if(check(i,10)==check(i,12)&&check(i,10)==check(i,16))
		printf("%d\n",i);
	}
   return 0;
}



