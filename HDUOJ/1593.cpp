/*
���⣺��������A��B��A�ڰ뾶ΪR�ĺ������ġ�B�ں��ߣ�A�ں��л�����������V1��A��B�ں�����������V2������R��V1��V2���ж�A���ﰶ���Ƿ�������B��
˼·��һ��ʼ��ΪAֱ�ӳ�B�ķ������ܣ�w�ˣ���������������AҪ�ں����ҵ����ٶȺ�B��ͬ��ͬ��Բ����ͬ��Բ��A�Ľ��ٶȴ���B�Ľ��ٶȣ�ͬ��Բ��A��B�Ľ��ٶ���ͬ��Ȼ��Aֱ�ӻ������߾�OK��~ ��ʽ��v=w*r��
*/
#include<iostream>
const double ip=3.1415926;
using namespace std;
int main()
{
	double R,r,v1,v2,sum;
	double time_0,time_e;
	while(cin>>r>>v1>>v2)
	{
		R=(v1*r)/v2;   //ͬ��Բ�� V1/R(С)=V2/r ����R(С)=(v1*r)/v2 ����Ϊ���ٶ�V=W�����ٶȣ�*R���뾶���� 
		time_0=(r-R)/v1;  //A
		time_e=(ip*r)/v2;  //���� 
		if(time_0<time_e)
		puts("Yes");
		else
		puts("No");
	}
	return 0; 
}