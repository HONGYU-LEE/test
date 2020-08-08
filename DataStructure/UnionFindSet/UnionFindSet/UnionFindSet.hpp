#include<vector>

namespace lee
{
	class UnionFindSet
	{
	public:
		UnionFindSet(size_t size)
			: _ufs(size, -1)
		{}

		int FindRoot(int index)
		{
			//���ڵ��ֵΪ�����������Ϊ����˵�����Ǹ��ڵ㣬������
			while (_ufs[index] >= 0)
			{
				//��Ϊÿ���ڵ�洢�Լ����ڵ���±꣬�������ϼ�������
				index = _ufs[index];
			}

			return index;
		}

		bool Union(int x1, int x2)
		{
			int root1 = FindRoot(x1);
			int root2 = FindRoot(x2);

			//��������һ������
			if (root1 == root2)
			{
				return false;
			}

			//ѡ��root1��Ϊ������root2���ڼ��Ϻϲ���root1��
			_ufs[root1] += _ufs[root2];
			//����һ���ĸ��ڵ�����Ϊroot1
			_ufs[root2] = root1;

			return true;
		}

		//�󼯺ϵĸ����������ڵ�ĸ���
		size_t count() const
		{
			size_t count = 0;
			for (auto it : _ufs)
			{
				if (it < 0)
				{
					count++;
				}
			}

			return count;
		}

	private:
		std::vector<int> _ufs;
	};
};

