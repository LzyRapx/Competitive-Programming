#pragma comment(linker, "/STACK:102400000,102400000")
//#include<bits/stdc++.h>
#include <stdio.h>
#include <string.h>
#include <algorithm>
#include <iostream>
#include <cstring>
#include <vector>
#include <map>
#include <cmath>
#include <queue>
#include <set>
#include <bitset>
#include <iomanip>
#include <list>
#include <stack>
#include <utility> 
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int,int> pii;
typedef vector<int> vi;
const double eps = 1e-8;  
const int INF = 1e9+7; 
const ll inf =(1LL<<62) ;
const int MOD = 1e9 + 7;  
const ll mod = (1LL<<32);
const int N =1e6+6; 
const int M=100010;
const int maxn=200010;
#define mst(a) memset(a, 0, sizeof(a))
#define M_P(x,y) make_pair(x,y)
#define in freopen("in.txt","r",stdin) 
#define rep(i,j,k) for (int i = j; i <= k; i++)  
#define per(i,j,k) for (int i = j; i >= k; i--)  
#define lson  l , mid , rt << 1    
#define rson  mid + 1 , r , rt << 1 | 1  
const int lowbit(int x) { return x&-x; }
//const int lowbit(int x) { return ((x)&((x)^((x)-1))); } 
int read(){ int v = 0, f = 1;char c =getchar();
while( c < 48 || 57 < c ){if(c=='-') f = -1;c = getchar();}
while(48 <= c && c <= 57) v = v*10+c-48, c = getchar();
return v*f;}
int MAX[maxn<<2];

void pushup(int rt) //把当前结点的信息更新到父结点
{
	//线段树是用数组来模拟树形结构
	//对于每一个节点rt,左子节点为 2*rt (一般写作rt<<1)右子节点为 2*R+1（一般写作rt<<1|1） 
	MAX[rt] = max(MAX[rt<<1] , MAX[rt<<1|1]); 
}
void build(int l,int r,int rt)
{
	if(l==r)
	{
		scanf("%d",&MAX[rt]); return;
	}
	int mid=(l+r)>>1;
	build(lson);//递归构造左子树
	build(rson);//递归构造右子树
	pushup(rt); //更新求和 
}
void update(int p, int change, int l, int r, int rt)//单点替换 
{
	if(l==r){
		MAX[rt] = change; 
		return ;
	}
	int mid=(l+r) >> 1;
	if(p<=mid) update(p,change,lson);
	else update(p,change,rson);
	pushup(rt);
}
int query(int L,int R,int l,int r,int rt) //区间最值 
{
	if(L <= l && r <= R){
		return MAX[rt];
	}
	int mid = (l+r)>>1;
	int ans = 0;
	if(L <= mid) ans=max(ans,query(L,R,lson));
	if(R > mid) ans=max(ans,query(L,R,rson));
	return ans; 
}
int main()
{
	int n,m;
	while(~scanf("%d%d",&n,&m))
	{
		build(1,n,1);
		while(m--){
			char op[3];
			int a,b;
			scanf("%s%d%d",op,&a,&b);
			if(op[0]=='Q')printf("%d\n",query(a,b,1,n,1));
			else update(a,b,1,n,1);
		}
	}
    return 0;
}