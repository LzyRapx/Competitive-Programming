#include<stdio.h>
#include<iostream>
#include<string.h>
#include<algorithm> 
using namespace std;
typedef long long LL;
const int mod =998244353;
const int N=100005;
int b[N];
int c[N];
LL dp[N];
//����:;���� 1 - n �е�������ɵ�n���ȶѣ�����ǰ i ���ȶѵ����ֵ��C[i],��Сֵ��B[i]
//����֪����n�ѹȶ�ǰ����ǰ׺�����ֵ����Сֵ,����Щ�ȶ��ܹ��ж�������ɷ�ʽ?
//���:����,�ų���5�ֲ����ܵ����,1.b[i]>b[i-1] 2,c[i]<c[i-1] 3,b[i]>c[i] 4.c[1]!=b[1] 5.b[i],c[i] < 1 || > n ,
//Ȼ�����,�����ǰ�������µ� b[i]���� c[i] ��ôdp[i] = dp[i-1] ��
//�����ǰ b[i-1] = b[i] && c[i-1] = c[i] ����ô���ǿ����� [b[i],c[i]]����ѡһ����,
//�������ڹȶ��ǻ�����ͬ��,����ÿ�����ǵ�ѡ������,
//Ū������������һ�µ�ǰ�Ѿ�ѡ�˶�����,����֮��𰸼�Ϊ dp[i] = dp[i-1]*(c[i]-b[i]+1-num)
int main()
{
    int t;
    scanf("%d",&t);
    while(t--)
    {
    	int n;
    	scanf("%d",&n);
    	int Min=999999;
    	int Max=-1;
    	int flag=1;
    	for(int i=1;i<=n;i++)
    	{
    		scanf("%d",&b[i]);
    		if(b[i]>Min) flag=0;
    		if(b[i]<1||b[i]>n) flag=0;
    		Min=min(Min,b[i]);
		}
		for(int i=1;i<=n;i++)
		{
			scanf("%d",&c[i]);
			if(c[i]<Max)flag=0;
			if(c[i]<1||c[i]>n) flag=0;
			if(c[i]<b[i]) flag=0;
			Max=max(Max,c[i]);
			
		}
		if(!flag||c[1]!=b[1]) puts("0"); //ǰ 1���������Сֵһ����� ������������� 
		else
		{
			memset(dp,0,sizeof(dp));
			dp[1]=1;
			int num=1;
			for(int i=2;i<=n;i++) //dp���� 
			{
				if(c[i]==c[i-1]&&b[i]==b[i-1]&&b[i]!=c[i])
				{
					dp[i]=dp[i-1]*(c[i]-b[i]+1-num)%mod;
				}
				else if( b[i]<b[i-1]&&c[i-1]==c[i] || b[i]==b[i-1]&&c[i-1]<c[i] )
				{
						//dp[i] = dp[i-1]+1;
						dp[i]=dp[i-1];
				}
					num++; //�Ѿ�ѡ�˶�����
			}
		  printf("%I64d\n",dp[n]);
		}
	}
    return 0;
}