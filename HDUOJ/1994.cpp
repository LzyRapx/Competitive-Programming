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
    double y,q,e,f,g;
    cin>>t;
    while(t--)
    { 
	 //Y-����ı���<=100000,
     //Q-�Ѵ�����<=365,
	 //e-��������,
	 //f-��������
	 //g-��ߺ�Ķ�������.
      cin>>y>>q>>e>>f>>g;
       cout<<y*(1+e/100*q/365)*(1+g/100)<<endl;
       cout<<y*(1+f/100*(q+365)/365)<<endl;
    }

	return 0;
} 