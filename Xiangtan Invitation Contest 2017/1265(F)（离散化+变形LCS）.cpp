/*
���⣺��������A����n��������һ����m��
��һ��X����{x1,x2,x3}��x1,x2,x3����[1,m]�����ڵ�����

�裺f(k)��ʾ�������е������������Ϊk��

������X��A����f(0),f(1),f(2),f(3)��X���ж����֡�

˼·��f(0)���󡣼����n��������m��Χ�ڵĲ�ͬ��������Ϊcnt��Ȼ�����(m-cnt)^3���ɡ�

��n������<=m��������ɢ����

Ҫ��f(1),f(2),f(3);
f(3)��X�����ڵ���һ����n�����л�á�
f(2)��X�����ڵ�����������Դ��һ������������n�����л�ã�Ȼ��Longest Common SubsequenceΪ2��
��һ��������������n�����л�ã�Ȼ��Longest Common SubsequenceΪ2������һ����<=m�Ĳ�����n���������л�á�
f(1)��X�����ڵ�����������Դ��һ����3������n�����л�ã�Ȼ��Longest Common SubsequenceΪ1��
��һ������������n�����л�ã�Ȼ��Longest Common SubsequenceΪ1������һ������<=m�Ĳ�����n���������л�á�
��һ��������һ����n�����л�ã�Ȼ��Longest Common SubsequenceΪ1�����������<=m�Ĳ�����n���������л�á�

�裺cnt��ʾn������<=m������kind��ʾn������<=m�Ĳ�ͬ�������ࡣm-kind��ʾ������n����������������

ö��x1,x2,x3ȫ��n������ɵ�X���У�����xi��ö�����е�n������

��Щ���а���f(3),f(2)��һ����Դ��f(1)��һ����Դ������������㷽����һ���ǳ����Longest Common Subsequence ��dp�󷨣�������ʱ�临�Ӷ�ΪO(N^4);
���õ������ǣ�Ԥ����next[i][j]��ʾi���λ���ұߵ�һ�γ���j�������λ�á���ô����O(1)�ж�X���е�Longest Common SubsequenceΪk�������Ǹ��µ�f(k)�С�
flag[a[i]][a[j]][a[k]]��ʾ������п���ƥ������LCS��ȡ��ֵ�����������㼴�ɡ�

ʣ��Ҫ��f(2)�ĵڶ�����Դ,f(1)�ĵڶ�����Դ�͵�������Դ��
f(2)�ڶ�����Դ�����ֿ���(x1,x2),(x2,x3),(x1,x3)λ�ã�Longest Common SubsequenceΪ2����һ��λ��Ϊm-kind��ȡ�� ��ʵ�������һ���ġ�f(2) += 3*Q(cnt)*(m-kind);
Q(cnt)��ʾcnt�������ҵ���A���е�Longest Common SubsequenceΪ2����������������ö������λ�ã�ͬ����˵�ķ�����

f(1)�ڶ�����Դ�����ֿ���(x1,x2),(x2,x3),(x1,x3)λ��,����Longest Common SubsequenceΪ1������һ��λ�ô�m-kind��ȡ�� f(1) += 3*P(cnt)*(m-kind);
f(1)��������Դ�����ֿ���x1,x2,x3λ����ͬ����������λ��Ϊm-kind��ȡ��f(1) += 3*kind*(m-kind)*(m-kind);


˼����ΪʲôҪ��next[i][j]��ʾi���λ���ұߵ�һ�γ���j�������λ�á�������ֱ��next[i][j]��ʾj������Ƿ���i���ұߡ�
���裺 2 2
��ôö�ٳ���2 2 2. ����ú����������壬��ô�𰸾���3�ˡ�ʵ����ֻ����2.
*/

#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef pair<int,int> P;
const int maxn = 1e5+100;
int flag[202][202][202];
int sign[202][202];
int mark[1000005];
int n, m;
int cnt , kind;
LL f[4];
int a[202], z;
int Next[202][202];

set<int> se;

void NextInit()
{
    for(int i = 0; i < z; i++)
	{
        for(int j = i+1; j < z; j++)
		{
            if(Next[i][a[j]]==-1)
			{
                Next[i][a[j]] = j;
            }
        }
    }
}
void lisan()
{
    int cnt = 1;
    set<int>::iterator it;
    for(it = se.begin(); it!=se.end(); it++)
	{
        mark[*it] = cnt;
        cnt++;
    }
    for(int i = 0; i < z; i++)
	{
        a[i] = mark[a[i]];
    }
}

int cal(int i,int j,int k)//O(1)��ѯ 
{
    if(Next[i][a[j]]==j&&Next[j][a[k]]==k) return 3;
    if(Next[i][a[j]]==j) return 2;
    if(Next[j][a[k]]==k) return 2;
    if(Next[i][a[k]]==k) return 2;
    return 1;
}
/*
f(3)��X�����ڵ���һ����n�����л�á�

f(2)�� X�����ڵ�����������Դ��һ������������n�����л�ã�Ȼ�� LCSΪ2��
��һ��������������n�����л�ã�Ȼ��LCSΪ2������һ����<=m�Ĳ�����n���������л�á�

f(1)��X�����ڵ�����������Դ��һ����3������n�����л�ã�Ȼ�� LCSΪ 1��
��һ������������ n�����л�ã�Ȼ�� LCS Ϊ 1������һ������<=m�Ĳ�����n���������л�á�
��һ��������һ���� n�����л�ã�Ȼ�� LCS Ϊ 1�����������<=m�Ĳ�����n���������л�á�
*/
void solve()
{
	//�����n��������m��Χ�ڵĲ�ͬ��������Ϊcnt��Ȼ�����(m-cnt)^3��Ϊ f(0)�� 
	
    kind = se.size();//n������<=m�Ĳ�ͬ��������
    cnt = z;
    LL temp = m-kind;//������n��������������
    f[0] = 1LL*temp*temp*temp;
    
    //ö������ѭ���������С�
   
	//flag[a[i]][a[j]][a[k]]��ʾ������п���ƥ������LCS��ȡ��ֵ�����������㼴�ɡ�
	
	//��������n�����л�� 
    for(int i = 0; i < z; i++)
	{
        for(int j = 0; j < z; j++)
		{
            for(int k = 0; k < z; k++)
			{
                int len = cal(i,j,k);
                flag[a[i]][a[j]][a[k]] = max(flag[a[i]][a[j]][a[k]],len);
            }
        }
    }

    se.clear();//���ԭ��û����ɢ������
    
    for(int i = 0; i < z; i++)
	{
        se.insert(a[i]);
    }
    
    set<int>::iterator it, it1, it2;
    for(it = se.begin(); it!=se.end(); it++)
	{
        for(it1 = se.begin(); it1!=se.end(); it1++)
		{
            for(it2 = se.begin(); it2!=se.end(); it2++)
			{
                f[flag[*it][*it1][*it2]]++;
            }
        }

    }

    //ö������ѭ��.
    int cnt2, cnt1;
    for(int i = 0; i < z; i++)
	{
        for(int j = 0; j < z; j++)
		{
            int len;
            if(Next[i][a[j]]==j)
			{
				len = 2;
			}
            else
            {
            	len = 1;
			}
		
            sign[a[i]][a[j]]= max(sign[a[i]][a[j]],len);
        }
    }
    cnt1 = cnt2 = 0;
    for(it = se.begin(); it!=se.end(); it++)
	{
        for(it1 = se.begin(); it1!=se.end(); it1++)
		{
            if(sign[*it][*it1]==2)//LCSΪ 2 ���������� 
			{
                cnt2++;
            }
			else cnt1++;
        }
    }

    f[2] += 1LL*3*cnt2*(m-kind);
    f[1] += 1LL*3*cnt1*(m-kind);
    ///f(1)��������Դ;
    f[1] += 1LL*3*kind*(m-kind)*(m-kind);
}
int main()
{
    while(~scanf("%d%d",&n,&m))
    {
        z = 0;
        for(int i = 0; i < n; i++) {
            scanf("%d",&a[z]);
            if(a[z]<=m) z++;//n������<=m����
        }
        memset(f, 0, sizeof f);
   		memset(Next, -1, sizeof Next);
    	memset(flag, 0, sizeof flag);
    	memset(sign, 0, sizeof sign);
    	se.clear();
        for(int i = 0; i < z; i++)
		{
            se.insert(a[i]);
        }
        lisan();//��n������<=m��������ɢ����
		//Ԥ����next[i][j]��ʾi���λ���ұߵ�һ�γ���j�������λ�á�
		//��ô����O(1)�ж�X���е�Longest Common SubsequenceΪk�������Ǹ��µ�f(k)�С� 
        NextInit();
        solve();
        printf("%I64d %I64d %I64d %I64d\n",f[0], f[1], f[2], f[3]);
    }
    return 0;
}