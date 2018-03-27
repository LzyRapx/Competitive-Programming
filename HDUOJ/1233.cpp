#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
#include<algorithm>
#define N 110
#define INF 0x7ffffff
using namespace std;
int n;
int dist[N],map[N][N],isvisited[N];
int prim(){
         int i,j,min,pos;
         int sum=0;
         memset(isvisited,false,sizeof(isvisited));
         //��ʼ��
         for(i=1;i<=n;i++){
                   dist[i]=map[1][i];
         } 
        //��1��ʼ
         isvisited[1]=true;
         dist[1]=65535;
         //�ҵ�Ȩֵ��С�㲢��¼��λ��
         for(i=1;i<n;i++){
                   min=65535;
                   for(j=1;j<=n;j++){
                            if(!isvisited[j] && dist[j]<min){
                                     min=dist[j];
                                     pos=j;
                            }
                   }        
                   sum+=dist[pos]; //����Ȩֵ
                   isvisited[pos]=true; 
                   //����Ȩֵ
                  for(j=1;j<=n;j++){
                            if(!isvisited[j] && dist[j]>map[pos][j]){

                                     dist[j]=map[pos][j];
                            }
                  }
         }        
         return sum;
}
int main()
{
    while(~scanf("%d",&n)&&n)
    {
        for(int i=1;i<=n;i++)
            for(int j=1;j<=n;j++)
                map[i][j]=INF;
        int m=n*(n-1)/2;
        for(int i=0;i<m;i++)
        {
            int u,v,t;
            scanf("%d%d%d",&u,&v,&t);
            if(map[u][v]>t) 
			 map[u][v]=map[v][u]=t;
        }
        cout<<prim()<<endl;
    }
}
