class Solution {
public:
	    //�ַ�����˺�ĳ��ȱض����ᳬ�����ߵĳ���֮��
        //�����һ��λ��������ǰ�ӣ������λ
        //����˼·��ʵ���ǽ��˷�дΪ���ͳ˷�,����λ�������ӵ�һ��
        /*
            ��:   12 
                x 31
                -----
                   2
                  1
                  6
                 3
                -----
                 372
        */
    string multiply(string num1, string num2) {

        int length1 = num1.size();
        int length2 = num2.size();
        string res(length1 + length2, '0');

        //�����һ��λ�ÿ�ʼ��
        for(int i = length1 - 1; i >= 0; i--)
        {
            for(int j = length2 - 1; j >= 0; j--)
            {
                int temp = (res[i + j + 1] - '0') + (num1[i] - '0') * (num2[j] - '0');
                res[i + j + 1] = temp % 10 + '0';
                //������λ
                
                res[i + j] += temp / 10;
                //��λ����һ��λ��, �����õ�+=��ԭ����һ��λ���ڲ�ͬλ����ж�ν�λ, ���ҳ�ʼ��ʱ����'\0',���ﲻ��Ҫ�ټ�
            }
        }


        for(int i = 0; i < length1 + length2; i++)
        {
            //�ҵ���Ϊ0��λ�ã����Ǹ�λ�ÿ�ʼ�Ĳ������յĽ�������Ǹ�λ�ÿ�ʼ���Ӵ�����
            if(res[i] != '0')
            {
                return res.substr(i);
            }
        }

        //���û���ҵ�����˵��������
        return "0";
    }
};
