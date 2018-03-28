#pragma comment(linker, "/STACK:102400000,102400000")
#include <cstdio>
#include <iostream>
#include <cstdlib>
#include <cstring>
#include <algorithm>
#include <cmath>
#include <cctype>
#include <map>
#include <set>
#include <queue>
#include <bitset>
#include <string>
using namespace std;
typedef pair<int,int> Pii;
typedef long long LL;
typedef unsigned long long ULL;
typedef double DBL;
typedef long double LDBL;
const int maxn=1e4+10;
//const int maxn=10;

char A[maxn], B[maxn];
bitset<maxn> posA[26], posB[26], 
Ap[maxn], Bp[maxn], ans, tem, pre[maxn];
/*
����һ�� bitset����Ԥ����� 26����ĸ�� A��B���ķֲ� 
Ap[i][j]��ʾ A������Ϊ i��ǰ׺���� B���� jλ���ҵ�ƥ�� Bp
ͬ��Bp[i][j]Ϊ B������Ϊ i��ǰ׺���� A���� jλ��ƥ��
������ A����ö�ٺ�׺��ʼ��λ�� i�����ö����Լ� Bp���ж� 
A���� iλ�ÿ�ʼ����Զ���� B����ƥ�䵽ʲôλ�� 
Ȼ��� Ap[i-1]����Щλ��ȡ��������λһ�£� 
���ܵõ��� iλ�ò��ܶԴ𰸵���Щλ����ɹ��ף� 
���򵽴��ϼ���
*/
int main()
{
    #ifdef LOCAL
    freopen("in.txt", "r", stdin);
//    freopen("out.txt", "w", stdout);
    #endif

    for(int i=1; i<maxn; i++) pre[i] = pre[i-1].set(i-1);
    while(~scanf(" %s %s", A, B))
    {
        int N=strlen(A);
        for(int i=0; i<26; i++) posA[i].reset(), posB[i].reset();

        for(int i=0; i<N; i++)
        {
            posA[A[i]-'a'][i] = 1;
            posB[B[i]-'a'][i] = 1;
        }

        Ap[0] = posB[A[0]-'a'];
        Bp[0] = posA[B[0]-'a'];
        for(int i=1; i<N; i++) Bp[i] = Bp[i-1] & (posA[B[i]-'a']>>i);

        ans.reset(); tem.reset();
        bool all = A[0]==B[0];
        if(all) ans[0]=1;
        for(int i=1; i<N; i++)
        {
            Ap[i] = Ap[i-1] & (posB[A[i]-'a']>>i);
            int l=0, r=N-1;
            while(l<r)
            {
                int mid=(l+r+1)>>1;
                if(!Bp[mid][i]) r=mid-1;
                else l=mid;
            }
            all &= A[i]==B[i];
            if(all) ans[i]=1;
            if(l==0 && A[i] != B[0]) continue;
            ans |= (Ap[i-1]&pre[l+1]) << (i-1);
        }
        for(int i=0; i<N; i++) putchar(ans[i]+'0');
        puts("");
    }
    return 0;
}