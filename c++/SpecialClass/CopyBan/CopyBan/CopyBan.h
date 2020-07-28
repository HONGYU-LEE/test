namespace lee
{
	class CopyBan
	{
	public:
	private:
		/*
		c++98Ð´·¨
		CopyBan(const CopyBan&);
		CopyBan& operator=(const CopyBan&);
		*/
		//c++11Ð´·¨
		CopyBan(const CopyBan&) = delete;
		CopyBan& operator=(const CopyBan&) = delete;
	};
};