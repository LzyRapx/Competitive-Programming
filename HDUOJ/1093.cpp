#include<stdio.h>
int main (void)
{
    int n, i;
    scanf("%d",&n);
    while (n--)                                       //Ҫ���������
    {
        {
            int s;
            s = 0;
            scanf("%d",&i);
            while(i--)                       //Ҫ��������ָ���
            {
                int a;
                scanf("%d",&a);
                s = s+a;                 //һ�ζ�ȡһ������Ȼ���ۼ�
            }
            printf("%d\n",s);
        }
    }
    return 0;
}