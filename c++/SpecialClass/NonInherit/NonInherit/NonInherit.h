namespace lee
{
	//c++98д��
	class NonInherit
	{
	public:
		static NonInherit CreateObject()
		{
			return NonInherit();
		}
	private:
		//���캯��˽�л��������޷����ù��캯���������޷��̳�
		NonInherit()
		{}
	};

	/*
	c++11д��

	class NonInherit final
	{

	};
	*/
};