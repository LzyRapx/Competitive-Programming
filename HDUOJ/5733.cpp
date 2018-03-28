#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
#define eps 1e-8
#define zero(x) (((x)>0?(x):-(x))<eps)
//�����ĸ���ά�ĵ㣬�����ĸ��������һ�������壬���������������ĺͰ뾶�����ܾ����O O O O��
//�����ĵ��Ƿ��棬�������޽⡣Ȼ������Բ�����꣬Ȼ�����Բ�ĵ�����һ��ľ���
struct point3
{
    double x,y,z;
};
struct line3
{
    point3 a,b;
};
struct plane3
{
    point3 a,b,c;
};

//������ U x V
point3 xmult(point3 u,point3 v)
{
    point3 ret;
    ret.x=u.y*v.z-v.y*u.z;
    ret.y=u.z*v.x-u.x*v.z;
    ret.z=u.x*v.y-u.y*v.x;
    return ret;
}
//���� ��� U . V
double dmult(point3 u,point3 v)
{
    return u.x*v.x+u.y*v.y+u.z*v.z;
}
//ʸ���� U - V
point3 subt(point3 u,point3 v)
{
    point3 ret;
    ret.x=u.x-v.x;
    ret.y=u.y-v.y;
    ret.z=u.z-v.z;
    return ret;
}
//ȡƽ�淨����
point3 pvec(plane3 s)
{
    return xmult(subt(s.a,s.b),subt(s.b,s.c));
}

point3 pvec(point3 s1,point3 s2,point3 s3)
{
    return xmult(subt(s1,s2),subt(s2,s3));
}
//�������
double dis(point3 p1,point3 p2)
{
    return sqrt((p1.x-p2.x)*(p1.x-p2.x)+(p1.y-p2.y)*(p1.y-p2.y)+(p1.z-p2.z)*(p1.z-p2.z));
}
//������С
double vlen(point3 p)
{
    return sqrt(p.x*p.x+p.y*p.y+p.z*p.z);
}
//�ж��Ƿ��� 
int dots_onplane(point3 a,point3 b,point3 c,point3 d)
{
    return zero(dmult(pvec(a,b,c),subt(d,a)));
}

//�㵽ƽ�����
double ptoplane(point3 p,point3 s1,point3 s2,point3 s3)
{
    return fabs(dmult(pvec(s1,s2,s3),subt(p,s1)))/vlen(pvec(s1,s2,s3));
}
//���׹�ʽ��С��ʹ�ã���Ȼ���Ծ��� 
double Area(point3 a,point3 b,point3 c)
{
    double ab=dis(a,b),bc=dis(b,c),ac=dis(a,c);
    double p=(ab+bc+ac)/2;
    return sqrt(p* (p-ab) * (p-bc)*(p-ac));
}

int main()
{
    point3 p[5];
    while(~scanf("%lf%lf%lf",&p[1].x,&p[1].y,&p[1].z))
    {
        for(int i=2;i<=4;i++) scanf("%lf%lf%lf",&p[i].x,&p[i].y,&p[i].z);
        if(dots_onplane(p[1],p[2],p[3],p[4])) { printf("O O O O\n"); continue; }
        double Sabc=Area(p[1],p[2],p[3]);
        double Sabd=Area(p[1],p[2],p[4]);
        double Sacd=Area(p[1],p[3],p[4]);
        double Sbcd=Area(p[2],p[3],p[4]);
        double S=Sabc+Sabd+Sacd+Sbcd;
        point3 heart;
        heart.x=( Sabc*p[4].x+Sabd*p[3].x + Sacd*p[2].x+Sbcd*p[1].x)/S;
        heart.y=( Sabc*p[4].y+Sabd*p[3].y + Sacd*p[2].y+Sbcd*p[1].y)/S;
        heart.z=( Sabc*p[4].z+Sabd*p[3].z + Sacd*p[2].z+Sbcd*p[1].z)/S;
        //������������ߺͰ뾶
        printf("%.4lf %.4lf %.4lf %.4lf\n",heart.x,heart.y,heart.z,ptoplane(heart,p[1],p[2],p[3]));
    }
    return 0;
}