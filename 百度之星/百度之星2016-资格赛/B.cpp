/*
 WA�İ汾....
 nԽ��ͳ�������int64��....
 */
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
LL dp[210];
int main()
{
     int n;
     dp[1]=1;
     dp[2]=2;
     for(int i=3;i<=201;i++)
     {
     	dp[i]=dp[i-1]+dp[i-2];   
     }
     while(~scanf("%d",&n))
     {
     	if(n==0)printf("\n"); //�Ӱ�
     	else
		printf("%I64d\n",dp[n]);
     }
	return 0;
}


//java�汾��AC

import java.util.Scanner;
import java.math.BigInteger;
public class Main {
    public static BigInteger[]dp=new BigInteger[205];
    public static void main(String[] args) {     
        Scanner cin=new Scanner(System.in);      
        Init();
        while(cin.hasNext())
        {
            int n=cin.nextInt();
            if(n>=1&&n<=200)
            {
                System.out.print(dp[n]);
            }
            System.out.println();  //��n=0ʱ���������,�Ӱ�
        }
        
        
    }
    public static void Init()
    {
        dp[1]=new BigInteger("1");
        dp[2]=new BigInteger("2");
        for(int i=3;i<=201;i++)
        {
            dp[i]=dp[i-1].add(dp[i-2]);
        }
    }

}