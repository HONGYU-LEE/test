namespace lee
{
	class StackOnly
	{
	public:
		static StackOnly CreateObject()
		{
			return StackOnly();
		}
	private:
		StackOnly()
		{}

		/*
		�÷�����ȱ�ݣ���Ȼ��ֹ��ջ�Ͽ��ٿռ䣬���������ھ�̬������
		void* operator new(size_t size) = delete;
		void operator delete(void* p) = delete;
		*/
	};	
};