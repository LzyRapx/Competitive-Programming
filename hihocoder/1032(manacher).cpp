#include<iostream>
#include<string>
#include<algorithm>
using namespace std;
static string afterProcessStr(1000002*2,'#');//Ԥ�ȷ����ڴ沢���г�ʼ��
int preprocess(string &str)//Ԥ����ʱ��ֻҪ������λ�õġ�#���滻�˾ͺã�
{
    //string afterProcessStr="#";
    for(int i=0;i<str.size();++i)
    {
        afterProcessStr [2*i+1]= str[i];
    }
    return str.size()*2+1;
    //afterProcessStr.clear();
}
int maxpalindrome(string &str)
{
   int  sizeStr=preprocess(str);
  // cout<<afterProcessStr<<endl;
   int maxEdge=0,center=0;
   int *p=new int[sizeStr]();
   int ans=0;
   for(int i=1;i<sizeStr;++i)
   {
       p[i]=(maxEdge>i)?min(maxEdge-i,p[2*center-i]):0;
       while(i-1-p[i]>=0&&i+1+p[i]<sizeStr&&afterProcessStr[i+1+p[i]]==afterProcessStr[i-1-p[i]])
          ++p[i];
          if(i+p[i]>maxEdge)
          {
              center=i;
              maxEdge=i+p[i];
          }
          if(p[i]>ans)
           ans=p[i];
   }
    return ans;
}
int main()
{
    int tn;
    cin>>tn;
    string str;
    str.reserve(1000002);
    int ans,tmp;
    for(int ye=0;ye<tn;++ye)
    {
        cin>>str;
        cout<<maxpalindrome(str)<<endl;
    }

}
