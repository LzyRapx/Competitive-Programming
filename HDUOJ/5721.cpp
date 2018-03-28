#include<iostream>
#include<stdio.h>
#include<cstring>
#include<algorithm>
typedef long long LL;
using namespace std;
const LL Max =1LL<<60;
//��άƽ������n���� ������:��ÿ������ʧһ�ε�����£�ʣ�������������Ծ��룬����͡�
//ƽ��������:����
struct point
{
	LL x,y;
};
point p[100010]; //���鿪С��TLE 
int t[1000010];  //���鿪С��TLE 
LL min(LL a,LL b)
{
	return a>b?b:a;
}

int cmp (const point &a,const point &b) //�Ե��x�������� 
{
	if(a.x==b.x)return a.y<b.y;
	return a.x>b.x;
}

int cmpy(const int &a,const int &b) //�Ե��y�������� 
{
	return p[a].y<p[b].y;
} 
LL dis(point a,point b)   //����ľ��� 
{
	return ((a.x-b.x)*(a.x-b.x)+(a.y-b.y)*(a.y-b.y));
 } 
 
LL myabs(LL x)
{
	return x<0?-x:x;
 } 

struct node 
{
	LL res;
	int x,y;
	node (){}
	node (LL res,int x,int y):res(res),x(x),y(y){}
};
LL sqr(LL x)
{
	return x*x;
 } 
 node solve(int left,int right)//���Σ��ݹ� 
 {
 	LL x=Max; 
 	if(left==right)return node(x,0,0);
 	if(left==right+1)return node(dis(p[left],p[right]),left,right);
 	int mid=(left+right)>>1; //����м�� 
 	node dl=solve(left,mid);
 	node dr=solve(mid+1,right);
 	if(dl.res>dr.res)
 	dl=dr;
 	//���м�2dl��ȵĲ��ֵĵ����������� 
 	int i,j,k;
 	k=0;
 	for(i=left;i<=right;i++) 
 	{
 		if(sqr(p[i].x-p[i+1].x)<dl.res)
 		t[k++]=i;
	 }
	 sort(t,t+k,cmpy); //���µ�������ɨ��
	 for(i=0;i<k;i++) 
	 {
	 	for(j=i+1;j<k&&sqr(p[t[j]].y-p[t[i]].y)<dl.res;j++)
	 	{
	 		LL d3 =dis(p[t[i]],p[t[j]]);
	 		if(dl.res>d3)
	 		{
	 			dl =node(d3,t[i],t[j]);
			 }
		 }
	 }
	 return dl;
 }
 int main()
 {
 	int T;
 	cin>>T;
 	int n;
 	while(T--)
 	{
 		cin>>n;
 		int x,y;
 		for(int i=1;i<=n;i++)
 		{
 			scanf("%d%d",&x,&y);
 			p[i].x =x; p[i].y =y;
		 }
		 sort(p+1,p+n+1,cmp);
		node r=solve(1,n);
		LL res =r.res*(n-2);
		point tmp =p[r.x];
		p[r.x].x=1e9;
		p[r.x].y=1e9;
		res+=solve(1,n).res;
		p[r.x]=tmp;
		p[r.y].x=1e9;
		res+=solve(1,n).res;
		cout<<res<<endl;
	 }
	 return 0;
 }