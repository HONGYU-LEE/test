namespace lee
{
	//c++98写法
	class NonInherit
	{
	public:
		static NonInherit CreateObject()
		{
			return NonInherit();
		}
	private:
		//构造函数私有化，子类无法调用构造函数，所以无法继承
		NonInherit()
		{}
	};

	/*
	c++11写法

	class NonInherit final
	{

	};
	*/
};