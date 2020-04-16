#include<iostream>
using namespace std;

class Date
{
public:
	// ��ȡĳ��ĳ�µ�����
	int GetMonthDay(int year, int month)
	{
		switch(month)
		{
		case 1 : 
		case 3 :
		case 5 :
		case 7 :
		case 8 :
		case 10 :
		case 12 :
			return 31;

		case 4 :
		case 6 : 
		case 9 :
		case 11 :
			return 30;

		case 2 :
			if ((year % 4 == 0 && year % 100 != 0) || (year % 400 == 0))
				return 29;
			else
				return 28;

		default:
			cout << "�������" << endl;
			return -1;
		}
	}

	// ȫȱʡ�Ĺ��캯��
	Date(int year = 0, int month = 1, int day = 1)
	{
		_year = year;
		_month = month;
		_day = day;
	}

	// �������캯��
	// d2(d1)
	Date(const Date& d)
	{
		_year = d._year;
		_month = d._month;
		_day = d._day;
	};

	// ��ֵ���������
    // d2 = d3 -> d2.operator=(&d2, d3)
	Date& operator=(const Date& d)
	{
		_year = d._year;
		_month = d._month;
		_day = d._day;

		return *this;
	}

	// ��������
	~Date()
	{
		_year = 0;
		_month = 1;
		_day = 1;
	}

	// ����+=����
	Date& operator+=(int day)
	{
		if (day <= 0)
		{
			*this -= -day;
			return *this;
		}

		_day += day;

		while (_day > GetMonthDay(_year, _month))
		{
			_day -= GetMonthDay(_year, _month);

			++_month;
			if (_month > 12)
			{
				++_year;
				_month = 1;
			}
		}

		return *this;
	}

	// ����+����
	Date operator+(int day)
	{
		Date ret(*this);

		if (day <= 0)
		{
			ret -= -day;
			return ret;
		}

		ret._day += day;

		while (ret._day > GetMonthDay(_year, _month))
		{
			ret._day -= GetMonthDay(ret._year, ret._month);

			++ret._month;
			if (ret._month > 12)
			{
				++ret._year;
				ret._month = 1;
			}
		}

		return ret;
	}

	// ����-����
	Date operator-(int day)
	{
		Date ret(*this);
		if (day < 0)
		{
			ret += -day;
			return ret;
		}


		ret._day -= day;

		while (ret._day <= 0)
		{

			--ret._month;

			if (!ret._month)
			{
				--ret._year;
				ret._month = 12;
			}

			ret._day += GetMonthDay(ret._year, ret._month);
		}

		return ret;
	}

	// ����-=����
	Date& operator-=(int day)
	{
		if (day < 0)
		{
			*this += -day;
			return *this;
		}

		_day -= day;

		while (_day <= 0)
		{

			--_month;

			if (!_month)
			{
				--_year;
				_month = 12;
			}

			_day += GetMonthDay(_year, _month);
		}

		return *this;
	}

	// ǰ��++
	Date& operator++()
	{
		*this += 1;

		return *this;
	}

	// ����++
	Date operator++(int)
	{
		Date ret(*this);
		*this += 1;

		return ret;
	}

	// ����--
	Date operator--(int)
	{
		Date ret(*this);

		*this -= 1;

		return ret;
	}

	// ǰ��--
	Date& operator--()
	{
		*this -= 1;

		return *this;
	}

	// >���������
	bool operator>(const Date& d)
	{
		if (_year > d._year)
			return true;
		else if (_year == d._year && _month > d._month)
			return true;
		else if (_year == d._year && _month == d._month && _day > d._day)
			return true;
		else
			return false;
	}

	// ==���������
	bool operator==(const Date& d)
	{
		if (_year == d._year && _month == d._month && _day == d._day)
			return true;
		else
			return false;
	}

	// >=���������
	inline bool operator >= (const Date& d)
	{
		return (*this == d) || (*this > d);
	}

	// <���������
	bool operator < (const Date& d)
	{
		return !(*this >= d);
	}

	//<=���������
	bool operator <= (const Date& d)
	{
		return !(*this > d);
	}
	// !=���������

	bool operator != (const Date& d)
	{
		return !(*this == d);
	}

	int CountDay() 
	{
		Date d1(*this);

		while (d1._month > 0)
		{
			d1._day += GetMonthDay(d1._year, d1._month);
			d1._month--;

			if (!d1._month && !d1._year)
			{
				break;
			}
			if (!d1._month)
			{
				--d1._year;
				d1._month = 12;
			}
		}
		return d1._day;
	}

	// ����-���� ��������
	int operator-(const Date& d)
	{
		Date d1(*this), d2(d);

		return d1.CountDay() - d2.CountDay();
	}
		

	void PrintDate()
	{
		cout << _year << "-" << _month << "-" << _day << endl;
	}

private:
	int _year;
	int _month;
	int _day;
};

int main()
{
	Date d1(2020, 8, 16);
	Date d2(2000, 8, 16);
	d1.PrintDate();
	d2.PrintDate();

	cout << d2 - d1 << endl;
}