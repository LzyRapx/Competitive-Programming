#include<stdio.h>
#include<iostream>
//���Ǹ�������double�� ���� A B 
// ������һ��int ��  i  ����  i*A��i*B֮��ֻ��һ����
//Ҳ������Ŀ�е�ACMER  ����i���������student ....
using namespace std;
int main()
{
	ios::sync_with_stdio(false);
	double 	p,q,a,b;
	int t,i,x,y;
	scanf("%d",&t);
	while(t--){
		scanf("%lf%lf",&p,&q);
		for(i=1;;i++)
		{
			a=p*i/100;
			b=q*i/100;
			x=int(a);
			y=int(b);
			if(x<a&&x+1==y)break;
			}
			printf("%d\n",i);
		}

	return 0;
}