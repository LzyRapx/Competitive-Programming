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
int main()
{
	char a,b,c;
	while(cin>>a>>b>>c){
		if(a>b){
			swap(a,b);
		}
		//ע������ѽ��WA��һ�Ρ����� 
		if(b>c){
		swap(b,c);	    
		if(a>b)
			swap(a,b);
		}
		printf("%c %c %c\n",a,b,c);
	} 
	return 0;

}

