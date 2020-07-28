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
		该方法有缺陷，虽然禁止了栈上开辟空间，但还可以在静态区开辟
		void* operator new(size_t size) = delete;
		void operator delete(void* p) = delete;
		*/
	};	
};