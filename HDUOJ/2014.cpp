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
	int n,a[100],s;  //�����Ϊdouble�����
//error: invalid operands of types 'double' and 'double [100]' to binary 'operator+'
	while(cin>>n)
	{
		s=0;
		for(int i=0;i<n;i++)
		{
			cin>>a[i];
			s+=a[i];
		}
        sort(a,n+a);
	    //cout<<fixed<<setprecision(2)<<(double)(s-a[0]-a[n-1])/(n-2)<<endl;
	    printf("%.2lf\n",(double)(s-a[0]-a[n-1])/(n-2));
	   
	}
	return 0;
}