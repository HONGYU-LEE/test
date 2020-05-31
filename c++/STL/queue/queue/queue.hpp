#include<deque>
#include<list>

namespace lee
{
	/*
	STL��queue�ײ��������deque����Ϊdeque��listһ������ɾ����Ч�ʶ���O��1��������deque��Ч�ʸ��ߣ���Ϊlist��һ�δ���һ��������룬������Щ�ռ�����ɢ�ֲ���.
	deque��ÿ�δ���һ���̶���С�Ŀռ䣬�������ռ�������в���ɾ����������Ч�ʸ��ߣ�������Ϊ����Ŀռ䶼��һ��һ�ε������ռ䣬�ڴ�������ʸ���
	*/
	template<class T, class Container = std::deque<T>>
	class queue
	{
	public:
		void push(const T& val)
		{
			_con.push_back(val);
		}

		void pop()
		{
			_con.pop_front();
		}

		T& front()
		{
			return _con.front();
		}

		const T& front() const
		{
			return _con.front();
		}

		T& back()
		{
			return _con.back();
		}

		const T& back() const
		{
			return _con.back();
		}

		size_t size() const
		{
			return _con.size();
		}

		bool empty() const
		{
			return _con.empty();
		}

	private:
		Container _con;
	};
}
