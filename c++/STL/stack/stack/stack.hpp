#include<vector>
#include<deque>

namespace lee
{
	/*
		STL�ײ��е�����ѡ�����deque����Ϊdeque�Ǽ���������ռ䣬��ÿ�β���ʱ���ݶ���ֱ���ڲ���ĵط�ֱ�Ӳ���һƬ�̶���С�Ŀռ䣬
		�����ͱ�֤���߼��ϵ����ԣ�����Ҫ�������ݡ���vectorÿ�����ݣ�����Ҫ�����¿ռ䣬����ԭ���ݣ�����ԭ�ռ䣬���ҿ��Ŀռ���ԭ���ݵ�1.5����2������ͬ�汾��
		vector����Ч�ʲ���deque�ߣ��ռ��������Ҳ���ߣ�������ݻᵼ�¿ռ����Ƭ��

	*/
	template<class T, class Container = std::deque<T>>
	class stack
	{
	public:
		void push(const T& val)
		{
			_con.push_back(val);
		}

		void pop()
		{
			_con.pop_back();
		}

		T& top() 
		{
			return _con.back();
		}

		const T& top() const
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
