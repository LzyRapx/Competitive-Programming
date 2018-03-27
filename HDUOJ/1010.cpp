#include<iostream>       
#include<cstdlib>      
#include<cstdio>      
#include<cmath>      
#include<cstring>      
#include<string>      
#include<cstdlib>      
#include<iomanip>      
#include<vector>      
#include<list>      
#include<map>      
#include<queue>    
#include<algorithm>      
using namespace std;
int n,m,ex,ey,t;
bool success;
char maze[10][10]; 
/*
 stx ---->��ʼx����
 sty ---->��ʼy����
 dt  ---->����ʱ��
*/
void dfs(int stx,int sty,int dt )
{
 
    if(stx<=0||stx>n||sty<=0||sty>m)     
	               return ;
	if(stx==ex&&sty==ey&&dt==t)
	        success=true;
	if(success) return ;
   int temp=(t-dt)-abs(ex-stx)-abs(ey-sty);
	if(temp<0||temp&1)   //��ż��֦
		return ;
		
/*
   0 1 0 1 0 1 0 1 0
   1 0 1 0 1 0 1 0 1
   0 1 0 1 0 1 0 1 0
   1 0 1 0 1 0 1 0 1
   0 1 0 1 0 1 0 1 0
   1 0 1 0 1 0 1 0 1
   0 1 0 1 0 1 0 1 0
   1 0 1 0 1 0 1 0 1 
 �����Ǵ�o ��ʼ���Ǵ�1��ʼ��
 ���� 0--->1 ����1--->0 ����������
  0-->0 , 1--->1 ����ż����
*/
   //���������ҵ�����
   if(maze[stx][sty+1]!='X')   //��������
   {
	   maze[stx][sty+1]='X'; 
	   dfs(stx,sty+1,dt+1);
	   maze[stx][sty+1]='.';
   }
   
   if(maze[stx+1][sty]!='X')   //��������
    {
	    maze[stx+1][sty]='X';  
	   dfs(stx+1,sty,dt+1);
	    maze[stx+1][sty]='.';
    }
   if(maze[stx][sty-1]!='X')   //��������
   {
	    maze[stx][sty-1]='X';  
	   dfs(stx,sty-1,dt+1);
	    maze[stx][sty-1]='.';
   }
  if(maze[stx-1][sty]!='X')   //��������
   {
	    maze[stx-1][sty]='X';  
	    dfs(stx-1,sty,dt+1);
	    maze[stx-1][sty]='.';
   }
  return ;
}

int main()
{
	int stx,sty,wall;
  while(scanf("%d%d%d",&n,&m,&t),n+m+t)
  {
	  getchar();
	  wall=0;    //ͳ���ϰ���ĸ���
   for(int i=1;i<=n;i++)
   {
	   for(int j=1;j<=m;j++)
	   {
		   scanf("%c",&maze[i][j]);
		   if(maze[i][j]=='S')
		   {
			   stx=i;     // ��ע��ʼ��x���λ��
			   sty=j;     // ��ע��ʼ��y���λ��
		   }
		   else
			if(maze[i][j]=='D')
			{
               ex=i;    // ��ע������x���λ��
			   ey=j;    // ��ע������y���λ��
			}
			else if(maze[i][j]=='X')
			{
               wall++;
			}
	   }
	   getchar();
   }
    success=false;
    maze[stx][sty]='X'; //��ס���
    if( n*m-wall<=t )  //��Ϊֻ����tʱ��door�Ŵ�
        printf("NO\n");
    else 
	{
		dfs(stx,sty,0);
		if(success)
			printf("YES\n");
		else
			printf("NO\n");
	}
  }
  return 0;
}
 

