#include <iostream>
#include <cstdio>
#include<algorithm>
using namespace std;
int main()
{
	int i;
	int n;
	int temp;
	int a;
	while(scanf("%d",&n)!=EOF && n!=0)
	{
		temp=0;
		while(n--)
		{
			scanf("%d",&a);
			temp = a ^ temp;  //���������ص���
	    }
	    cout<<temp<<endl;
	}
	return 0;
}