#include<iostream>  
#include<memory.h>  
#include<cstdlib>  
#include<cstdio>  
#include<cmath>  
#include<cstring>  
#include<string>  
#include<cstdlib>  
#include<iomanip>  
#include<vector>  
#include<list>  
#include<map>  
#include<algorithm>  
typedef long long LL;  
using namespace std; 
const int maxn=3000;

int main()
{
    LL a,b,c;
    while(cin>>a>>b>>c)
    {
    	if((a+b)==c||(a+c)==b||(b+c)==a)//�� �ͼ� 
				cout<<"oh,lucky!"<<endl;
				else if((a*b)==c||(a*c)==b||(b*c)==a)//�˺ͳ� 
				cout<<"oh,lucky!"<<endl;
				//������ע�������ĳ�����һ������ʡȥС�� 
				else if((b&&(a%b==c||c%b==a))||(c&&(a%c==b||b%c==a))||(a&&(b%a==c||c%a==b)))
				cout<<"oh,lucky!"<<endl;
				else
				cout<<"what a pity!"<<endl;
    }
    return 0;
}
