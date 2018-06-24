class Solution {
public:
    int findNthDigit(int n) {
        if(n <= 9) return n;
        int bits = 1; // ��ǰλ��
        
        long long num = 9; // ע�⣺long long
        
        // ��λ��
        while(n > bits * num)
        {
            n -= bits * num;
            bits++;
            num *= 10;
        }
        int nth = (n - 1) / bits; // �ڼ���
        int wei = (n - 1) % bits; // �ڼ�λ
        
        //  ��ԭ����
        int number = pow(10, bits - 1) + nth;
        
        string s =  to_string(number);
        // cout << s << endl;
        // cout << wei << endl;
        int ans = s[wei] - '0';
        return ans;
    }
};
/*
����һ��λ���͹���
* ��λ����1-9��һ��9��,����9������
* 2λ����10-99,һ��90��������180������
* 3λ����100-999��һ��900��������2700������
* 4λ����1000-9999��һ��9000��������36000������
* �Դ����ƣ�
* �����Ϳ������ȶ�λ���Ǽ�λ�������ҵ����Ӧ������.
*/