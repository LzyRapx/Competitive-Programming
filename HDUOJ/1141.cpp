#include<iostream>
#include<stdio.h>
#include<algorithm>
#include<math.h>
using namespace std;
//��n! < 2^bit����n������bitΪ�����λ��, �� n��
//���߶�����log(1) + log(2) +...+ log(n) < bit* log(2)��
int main()
{
	int n; int bit;
	while(~scanf("%d",&n),n)
	{
		int time=(n-1960)/10;
		bit=pow(2.0,1.0*(time+2));
	 double sum=0; int i=1;
    while(1)
    {
		sum+= log10(i*1.0);	
		if(sum>bit*log10(2.0))
		 break;
		i+=1;
	
   }
		printf("%d\n",i-1);
	}
	return 0;
}