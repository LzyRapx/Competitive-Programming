#include <iostream>
#include<stdio.h>
using namespace std;
#include<cmath>
//��Ϊn=i*j+i+j+1-1=(i+1)(j+1)-1;
//n+1=(i+1)(j+1); 
//����sqrt(n+1)>=(i+1) 
int main()
{
    ios::sync_with_stdio(false);
    long long n;
    int t;
    cin>>t;
    while(t--)
    {

    	cin>>n;
    	int num;
    	int sum=0;
    	num=sqrt(n+1);
    	for(int i=1;i<num;i++)
    	{
    		if((n+1)%(i+1)==0)  //����(j+1)Ϊ���� 
    		sum++;
		}
	cout<<sum<<endl;
	}
    return 0;
}

