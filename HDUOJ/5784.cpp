#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
using namespace std;
#define ll long long
/*
ֱ��ͳ����������ν����ѣ���������ķ��棬ͳ��ֱ�������Ρ��۽������Ρ�ƽ�������Ρ�
����ö�������ε�һ���˵�A�����������������Ϊ��һ�ؼ��֣�����Ϊ�ڶ��ؼ�������
Ȼ��ʹ������ָ�룬����O��n����ɨ�衣
��������Ϊ�� i ָ��ָ�������εĵڶ����˵�B��
���ǿ��Լ���ͨ��ƽ�ƺ���ת����A������ƽ��ֱ������ϵ��ԭ�㣬��B������x���������
��ô������AB��ɶ۽ǻ�ֱ�ǵĵ�����������޻���y�ᡣ
�� j ָ��ָ���һ�����ڿ��������ǵ����ĵ㣬
��kָ���j + 1 ��ʼɨ�������һ��������ɶ۽ǵĵ㣬Ȼ��ͳ�ƶԴ𰸵Ĺ��ס�
֮�� i ָ�� +1������ɨ�衣
*/
const double eps=1e-8;
struct Point{
    ll x,y;
    int f;//��������һ������
    friend Point operator-(Point aa,Point bb){
        return (Point){aa.x-bb.x,aa.y-bb.y};
    }
}a[2005],b[2005];
Point S;
int n,m;
//��� 
inline ll cross(Point a,Point b,Point c){
    return (b.x-a.x)*(c.y-a.y)-(b.y-a.y)*(c.x-a.x);
}
inline int cal(Point a)//��������
{
    if(a.x>0&&a.y==0) return 1;
    if(a.x>0&&a.y>0) return 1;
    if(a.x==0&&a.y>0) return 2;
    if(a.x<0&&a.y>0) return 2;
    if(a.x<0&&a.y==0) return 3;
    if(a.x<0&&a.y<0) return 3;
    if(a.x==0&&a.y<0) return 4;
    if(a.x>0&&a.y<0) return 4;
}
inline bool cmp(const Point a,const Point b)//�Ȱ����������ٰ���������
{
    if(a.f<b.f) return true;
    if(a.f>b.f) return false;
    ll temp=cross(S,a,b);//���˲������������ 
    if(temp>0) return true;
    else return false;
}
inline bool ok(Point a,Point b,Point c)
{
    ll temp=(b.x-a.x)*(c.x-a.x)+(b.y-a.y)*(c.y-a.y);
    if(temp>0) return true;
    else return false;
}

int main()
{
    while(scanf("%d",&n)!=EOF)
    {
        for(int i=1; i<=n; i++){
            scanf("%I64d%I64d",&a[i].x,&a[i].y);
        }
        ll sum=0;//ͳ�Ƴ�����������ε����������εĸ���
        for(int p=1; p<=n; p++)//ö�������ε�һ������
        {
            S=a[p];
            m=0;
            for(int j=1; j<=n; j++){
                if(j!=p) b[++m]=a[j];
            }
            for(int i=1; i<=m; i++) b[i].f=cal(b[i]-S);
            sort(b+1,b+m+1,cmp);//��������
            //two pointers
            int i=1,j=1,k=1;
            while(ok(S,b[i],b[j])&&cross(S,b[i],b[j])>=0&&j<=m) j++;
            if(j==m+1) continue;
            j--;k=j+1;
            while(i<=m){
                if(!ok(S,b[i],b[k])){
                    while(!ok(S,b[i],b[k+1])&&k<m) k++;
                    sum+=k-j;
                }
                i++;
                if(j<i) j=i;
                while(ok(S,b[i],b[j+1])&&cross(S,b[i],b[j+1])>0&&j<m) j++;
                if(k<=j) k=j+1;
                if(k>m) break;
            }
        }
        ll ans=1ll*n*(n-1)*(n-2)/6;
        ans-=sum;
        //cout<<ans<<" "<<sum<<endl;
        printf("%I64d\n",ans);
    }
}
