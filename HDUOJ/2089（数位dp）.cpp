#include<bits/stdc++.h>
#include<stdio.h>
#include<string.h>
#include<iostream>
#include<algorithm>
using namespace std;
int dp[10][10];
int digit[10];
void init()
{
    //ʮλ�Ӹ�λdp����λ��ʮλdp��ǧλ�Ӱ�λdp
    dp[0][0]=1;
    for(int i=1;i<=7;i++) //λ�� 
    {
        for(int j=0;j<10;j++)//ö�ٵ�iλ���ϵ����֡�
        {
            for(int k=0;k<10;k++)//ö�ٵ�i-1λ�ϵ����֡�
            {
                if(!(j==6&&k==2)&&j!=4)//��������
                dp[i][j]+=dp[i-1][k];
            }
        }
    }
}
int cal_length(int n) //���㳤�� 
{
    int cont=0;
    while(n)
    {
        cont++;
        n/=10;
    }
    return cont;
}

int cal_digit(int n,int len) //�����λ�ϵ����� 
{
    memset(digit,0,sizeof(digit));
    for(int i=1;i<=len;i++)
    {
        digit[i]=n%10;
        n/=10;
    }
}
int solve(int n) //����[0,n)���������ĸ���
{
     int ans=0;
     int len=cal_length(n);
     cal_digit(n,len);
     for(int i=len;i>=1;i--)//�����λ��ʼö��
     {
         for(int j=0;j<digit[i];j++)
         {
             if(!(j==2&&digit[i+1]==6)&&j!=4)
             {
                 ans+=dp[i][j]; // ����������answer 
             }
         }
        if(digit[i]==4 || (digit[i]==2 && digit[i+1]==6))//��iλ�Ѿ���������������iλ�Ժ󶼲�������������������ѭ��
            break ;
     }
     return ans; //�������ս�� 
}
int main()
{
    init();
    int n,m;
    while(~scanf("%d%d",&n,&m))
    {
        if(n==0&&m==0)break;
        printf("%d\n",solve(m+1)-solve(n));
    }
}
