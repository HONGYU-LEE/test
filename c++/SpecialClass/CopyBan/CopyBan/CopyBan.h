namespace lee
{
	class CopyBan
	{
	public:
	private:
		/*
		c++98д��
		CopyBan(const CopyBan&);
		CopyBan& operator=(const CopyBan&);
		*/
		//c++11д��
		CopyBan(const CopyBan&) = delete;
		CopyBan& operator=(const CopyBan&) = delete;
	};
};