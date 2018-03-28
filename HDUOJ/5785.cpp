#include<bits/stdc++.h>
using namespace std;
const int mod=1e9+7;
const int maxn=1e7;
char str[maxn];
int n,L;
int p[maxn];
char s[maxn];
/*
data[1]��ʾ�Ե�ǰ��Ϊ�ұ߽�����л��Ĵ������ĵĺ͵�������
data[2]��ʾ�Ե�ǰ��Ϊ�ұ߽�����л��Ĵ��ĸ�����
data[3]��ʾ�Ե�ǰ��Ϊ��߽�����л��Ĵ������ĵĺ͵�������
data[4]��ʾ�Ե�ǰ��Ϊ��߽�����л��Ĵ��ĸ�����
*/
int data[5][2000100];
//manacherԤ���� 
void init()
{
	memset(data,0,sizeof(data));
	n=strlen(s);
	str[0]='@';
	str[1]='#';
	for(int i=0;i<n;i++){
		str[i*2+2]=s[i];
		str[i*2+3]='#'; 
	}
	L=n*2+2; 
	str[L]=0; 
}
//manacher 
void manacher()
{
	int mx=0;
	int id;
	for(int i=1;i<L;i++)
	{
		if(mx>i)
		{
			p[i]=min(p[2*id-i],mx-i); //mx-iд��p[id]+id-iҲ�� 
		}
		else p[i]=1;
		while(str[i+p[i]]==str[i-p[i]])  
            p[i]++;  
            
            if(p[i]+i>mx)  
      	   	{  
           	 	mx=p[i]+i;  
            	id=i;  
       	}  
	}
}
// 
void add(int op,int l,int r,int num)
{
    if (l>r) return ;
    data[op][l] += num;
    data[op][l] %= mod;

    data[op][r+1] -= num;
    data[op][r+1] %= mod;
}
int main()
{
	while(~scanf("%s",s))
	{
		init();
		manacher();
		for(int i=L-1;i>=1;--i) //�ұ� 
		{
			add(1,i-p[i]+1,i,i); //data[1] 
			add(2,i-p[i]+1,i,1); //data[2] 
		}
		for (int i=1;i<L;i++)   //��� 
        {
            add(3,i,i+p[i]-1,i); //data[3] 
            add(4,i,i+p[i]-1,1);  //data[4] 
        }
        for (int i=1;i<L;i++)
        {
            for (int j=1;j<=4;j++)
            {
                data[j][i]+=data[j][i-1];
                data[j][i]=(mod+data[j][i])%mod;
            }
        }

        int ans=0;
        for (int i=2;i<L-2;i+=2)
        {
            int aa,bb;
            aa=((data[1][i+2]-(long long)data[2][i+2]*((i+2)/2))%mod+mod)%mod;
            bb=((data[3][i]-(long long)data[4][i]*(i/2))%mod+mod)%mod;
            ans+=((long long)aa*(long long)bb)%mod;
            ans%=mod;
           // printf ("i=%d\n",i/2);
           // printf ("%lld\n",((long long)aa*(long long)bb)%mod);
        }
        printf ("%d\n",ans);
	}
	return 0;
 } 