#include<bits/stdc++.h>
using namespace std;

int main()
{
	int n,m,L;
	int l,r,t,b;
	scanf("%d%d%d",&n,&m,&L);
	scanf("%d%d%d%d",&l,&r,&t,&b);
	if(L>=2*(m*n)) //���԰�ȫ���ض�Ȧ�� 
	{
		printf("%d\n",m*n-(r-l)*(b-t));
	}
	else
	{
		int ll,rr,tt,bb;
		ll = l; rr = r; tt = t; bb = b;
		if(l+r<=m) //С������ 
		{
			ll=m-r;
			rr=m-l;
		}
		if(t+b<=n)  //С������ 
		{
			bb=n-t;
			tt=n-b;
		}
		int ans=0;
		for(int i=1;i<= L/2 && i<=m; i++) //����ö�ټӱ� 
		{
			for(int j=1;j<=L/2-i && j<=n; j++) 
			{
				if (i <= ll || j <= tt)  //Ȧ����û��ˮ�� 
                ans = ans > i*j ? ans : i*j;  
            else if (i > ll && i <= rr && j > tt && j <= bb)  //Ȧ������һ���� 
                ans = ans > i*j - (i - ll)*(j - tt) ? ans : i*j - (i - ll)*(j - tt);  
            else if (i >= rr&&j >= tt)  //Ȧ������ȫ��ˮ�� 
                ans = ans > i*j - (r - l)*(b - t) ? ans : i*j - (r - l)*(b - t);  
            else  
                continue; 
			}
		}
		printf("%d\n",ans);
	 } 
	return 0;
 } 