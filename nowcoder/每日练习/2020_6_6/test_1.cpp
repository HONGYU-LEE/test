/*
��Ҫ��
https://www.nowcoder.com/practice/1183548cd48446b38da501e58d5944eb?tpId=85&&tqId=29840&rp=1&ru=/activity/oj&qru=/ta/2017test/question-ranking
����С����һ��W*H��������ӣ�������б��Ϊ0~H-1��������б��Ϊ0~W-1��ÿ������������Է�һ�鵰�⣬�������鵰���ŷ����þ��벻�ܵ���2��
����������������(x1,y1),(x2,y2)��ŷ����þ���Ϊ:
( (x1-x2) * (x1-x2) + (y1-y2) * (y1-y2) ) ������ƽ����
С����֪�������ԷŶ��ٿ鵰������������
*/ 
/*
	���ȳ�ʼ����־�������λ��Ϊ1��˵�����Էŵ��⣬Ϊ0����
	���Ź۲칫ʽ������ŷ����þ�����ʵ���Ǻ�����֮���ƽ������������֮�͵�ƽ���ٿ�����
	���Լ����Ƶ�����ŷ����þ���Ϊ2ʱ��˵����������ֻ����һ���в�ֵ����һ����ͬ�����Ҳ�ֵֻ��Ϊ2
	���磺(0, 0) �� (2, 0) (0, 2) 
*/
 


#include<iostream>
#include<vector>

using namespace std;
int main()
{
	size_t row, col;

	while (cin >> row >> col)
	{
		size_t res = 0;
        //���ȳ�ʼ����־�������λ��Ϊ1��˵�����Էŵ��⣬Ϊ0����
		vector<vector<int>> flag(row, vector<int>(col, 1));

		for (size_t i = 0; i < row; i++)
		{
			for (size_t j = 0; j < col; j++)
			{
				//���Ϊ1��˵�����Դ�� 
				if (flag[i][j] == 1)
				{
					res++;
					//�ж϶�Ӧλ�� 
					if (i + 2 < row)
					{
						flag[i + 2][j] = 0;
					}

					if(j + 2 < col)
					{
						flag[i][j + 2] = 0;
					}
				}
			}
		}
		cout << res << endl;
	}
	return 0;
}
