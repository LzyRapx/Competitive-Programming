/*
dp[i][j][k]�У�i��ʾa���е�i��Ԫ�أ�j��ʾb���еĵ�j��Ԫ�أ�
a[i]==0ʱ��kΪ��i~n����ƥ���Ԫ�������ֵ
a[i]==1ʱ��kΪ��i~n����ƥ���Ԫ������Сֵ
*/
#include<bits/stdc++.h>
#define lson l,m,rt<<1
#define rson m+1,r,rt<<1|1
using namespace std;
const int mod = 1e9 + 7;
const int MX = 500 + 5;
int a[25], b[MX];
int dp[25][MX][MX];
int n, m;
void add(int &x, int y)
{
    x += y;
    if(x >= mod) x -= mod;
    if(x < 0) x += mod;
}
struct BITree	//��״��������Ż���n*m^2*log(m)
{ 
    int sum[MX];
    int lowbit(int x)
    {
        return x & (-x);
    }
    void update(int x, int v)
    {
        while(x)
        {
            add(sum[x], v);
            x -= lowbit(x);
        }
    }
    int query(int x)
    {
        if(x == 0) return 0;
        int ret = 0;
        while(x <= m) {
            add(ret, sum[x]);
            x += lowbit(x);
        }
        return ret;
    }
    void clear()
    {
        memset(sum, 0, sizeof(sum));
    }
} tree[25][MX]; //aƥ�䵽��i����b��ǰ��һ����j

/*
��Ŀ������12 13 23 ��3��
412 125 ��2��
*/
int main()
{
    while(~scanf("%d%d", &n, &m))
    {
        for(int i = 1; i <= n; i++) scanf("%d", &a[i]);
        for(int i = 1; i <= m; i++) scanf("%d", &b[i]);
        memset(dp, 0, sizeof(dp));
        for(int i = 1; i <= n; i++)
            for(int j = 1; j <= m; j++)
                tree[i][j].clear();
        /*
        ��ʼ���Ǹ��ѵ㣬���a[1]==1����ôҪ���½�Ϊ��Сֵ1
        ���a[1]==0����ôҪ���½�Ϊ���ֵm
        if(a[1]==1) t[1][1].update(m,1);
        else t[1][m].update(m,1);
        */
        for(int i=1;i<=m;i++) 
        {
            if(a[1]==1)
            {
            	dp[1][i][1]=1;
            }
            else {
            	dp[1][i][m]=1;
            }
        	
        }
        for(int i = 2; i <= n; i++)
		{
            for(int j = 1; j <= m; j++)
            {
                for(int k = 1; k <= m; k++)
                {
                    dp[i][j][k] = tree[i][k].query(b[j]);
                }
                
                if(i==1) continue;
                
                for(int k = 1; k <= m; k++)
                {
                    if(dp[i - 1][j][k] == 0) continue;
                    int L = b[j], R = k;
                    if(a[i - 1] == 1) swap(L, R);
                    if(L > R) continue;
                    if(a[i] == 0)
                    {
                        tree[i][R].update(R, dp[i - 1][j][k]);
                        tree[i][R].update(L - 1, -dp[i - 1][j][k]);
                    } 
                    else
                    {
                        tree[i][L].update(R, dp[i - 1][j][k]);
                        tree[i][L].update(L - 1, -dp[i - 1][j][k]);
                    }
                }
            }
        }
        int ans = 0;
        for(int j = 1; j <= m; j++)
        {
            for(int k = 1; k <= m; k++)
            {
                add(ans , dp[n][j][k]);
            }
        }
        printf("%d\n", ans);
    }
    return 0;
}