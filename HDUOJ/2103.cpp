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
int main()
{
    int t, n, m, temp, flag;
    int a[35];
    long long b[35], ans;
    b[0] = 0;
    b[1] = 10000;
    for(int i = 2; i <= 30; i++)
        b[i] = 2 * b[i - 1];
    scanf("%d", &t);
    while(t--)
    {
        ans = 0;
        flag = 0;
        scanf("%d%d", &m ,&n);
        for(int i = 1; i <= n; i++)
            scanf("%d", &a[i]);
        for(int i = 1; i <= m; i++)//���������ķ�Χ�ڳ����к������ڸ��к�֮�����������С����Ҫ�շ�
        {
            if(a[i] == 1)
            {
                temp = i;
                for(int i = 0; i <= n - temp; i++)
                    ans += b[i];
                    flag = 1;//��ʾ���������ķ�Χ�ڳ����к�
                    break;
            }
        }
        if(flag == 1)
            printf("%lld RMB\n", ans);
        else//���������ķ�Χ�ڲ������к����򿴿��Ƿ�����ÿ������С����������Ů����Ҫ�շ�
        {
            for(int i = 0; i <= n - m; i++)
                ans += b[i];
            printf("%lld RMB\n", ans);
        }
    }
    return 0;
}