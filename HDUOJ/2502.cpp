#include<iostream>   
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
const int maxn=100;
int m[10005];
//nλ�Ķ���������2^��n-1����
//s=2^(n-1)(ÿ���ĵ�һλ��1)+2^��n-1��*(1/2)*(n-1)(ʣ�µ�n-1λÿλ��һ�뼸����1��Ȼ���2^��n-1������������
int main()
{
  	
	int t,i;
	cin>>t;
	while(t--)
	{
		int n;
		double s;
		cin>>n;
		s=pow(2,n-1)+pow(2,n-1)*(n-1)/2; 
		int ans=s;  //ע��ת��Ϊint 
		cout<<ans<<endl;
	}
	return 0;
 } 