namespace lee
{
	class HeapOnly
	{
	public:
		static HeapOnly* CreateObject()
		{
			return new HeapOnly();
		}

	private:
		HeapOnly()
		{}

		//c++11,·À¿½±´
		HeapOnly(const HeapOnly&) = delete;
		HeapOnly& operator=(const HeapOnly&) = delete;

		/*
		c++98Ð´·¨
		HeapOnly(const HeapOnly&);
		HeapOnly& operator=(const HeapOnly&);
		*/

	};
};