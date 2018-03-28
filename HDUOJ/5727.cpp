#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>
#include <string>
#include <cstdlib>
#include <vector>
#include <set>
#include <map>
using namespace std;
vector<int>e[10];
int mp[10][10];
int linker[10];
int vis[10];
int pos[10];
//����2*n�ű�ʯ������n������ʯ��n������ʯ��
//��������������������������ڣ����������ϣ�Χ��һ������,��������m��x,y��
//��ʾ�������ʯx������ʯy����һ������ʯ�ͻ���Ӱ�죬
//�����������ʯ��Ӱ������������� 
int dfs(int u)
{
    for (int i=0; i<e[u].size(); i++)
    {
        int v=e[u][i];
        if (!vis[v])
        {
            vis[v]=1;
            if (linker[v]==-1||dfs(linker[v]))
            {
                linker[v]=u;
                return 1;
            }
        }
    }
    return 0;
}
int main()
{
    int n,m,ans;
    while (scanf ("%d%d",&n,&m)!=EOF)
    {
        memset(mp,0,sizeof(mp));
        while (m--)
        {
            int t1,t2;
            scanf ("%d%d",&t1,&t2);
            mp[t1][t2]=1;
        }
        if (n==0)
        {
            printf ("0\n");
        }
        else
        {
            ans=10;
            for (int i=1; i<=n; i++)
                pos[i]=i;
            do
            {
                for (int i=1; i<=n; i++) e[i].clear();
                for (int i=1; i<=n; i++)	//�ӱ�,i�����ۣ���
                {
                    int u=pos[i];
                    int v;
                    if (i==n) v=pos[1];
                    else v=pos[i+1];
                    for (int j=1;j<=n;j++)	//����ÿһ��������
                    {
                        if (mp[j][u]||mp[j][v]) continue;//��������ͻ
                        e[j].push_back(i);	//�����������
                    }
                }
                int temp=0;
                memset(linker,-1,sizeof(linker));
                
                for (int i=1; i<=n; i++)//���������ƥ��
                {
                    memset(vis,0,sizeof(vis));
                    if (dfs(i)) temp++;
                }
                ans=min(ans,n-temp);
                if (ans==0) break;
            }while(next_permutation(pos+2,pos+n+1));
            printf ("%d\n",ans);
        }
    }
    return 0;
}