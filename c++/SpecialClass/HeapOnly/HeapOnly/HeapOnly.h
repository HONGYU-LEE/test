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

		//c++11,������
		HeapOnly(const HeapOnly&) = delete;
		HeapOnly& operator=(const HeapOnly&) = delete;

		/*
		c++98д��
		HeapOnly(const HeapOnly&);
		HeapOnly& operator=(const HeapOnly&);
		*/

	};
};