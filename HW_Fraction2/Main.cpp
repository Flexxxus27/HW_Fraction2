#include <iostream>


template <typename T>
class Fraction
{
public:

	Fraction() : Num_(0), Denum_(1) {};
	Fraction(T num, T denum)
	{
		if (denum == 0)
		{
			throw - 1;
		}
		Num_ = num;
		Denum_ = denum;
	}

	//доступ к полям
	T GetNum()const { return Num_; }
	T GetDenum()const { return Denum_; }

	//Метод изменения полей
	T SetNum(T num) { Num_ = num; }
	T SetDenum(T denum) { Denum_ = denum; }

	//конструктор целого числа 

	explicit Fraction(int num) : Num_(num), Denum_(1) {};

	//Операторы математики

	Fraction operator+(const Fraction& other)
	{
		T num = Num_ * other.Denum_ - other.Num_ * Denum_;
		T denum = Denum_ * other.Denum_;
		return Fraction(num, denum);
	}

	Fraction operator-(const Fraction& other)
	{
		T num = Num_ * other.Denum_ - other.Num_ * Denum_;
		T denum = Denum_ * other.Denum_;
		return Fraction(num, denum);
	}

	Fraction operator /(const Fraction& other)
	{
		T num = Num_ * other.Denum_;
		T denum = Denum_ * other.Num_;
		return Fraction(num, denum);
	}
	Fraction operator *(const Fraction& other)
	{
		T num = Num_ * other.Num_;
		T denum = Denum_ * other.Denum_;
		return Fraction(num, denum);
	}
	Fraction operator +()
	{
		return Fraction(Num_, Denum_);
	}
	Fraction operator -()
	{
		return Fraction(-Num_, Denum_);
	}
	Fraction& operator ++()
	{
		Num_ += Denum_;
		return*this;
	}
	Fraction& operator --()
	{
		Num_ = Num_ - Denum_;
		return*this;
	}

	//Работа с потоками

	friend std::ostream& operator<<(std::ostream& os, const Fraction<T>& fraction) {
		os << fraction.Num_ << '/' << fraction.Denum_;
		return os;
	}

	friend std::istream& operator>>(std::istream& is, Fraction<T>& fraction) {
		is >> fraction.Num_ >> fraction.Denum_;
		return is;

	}
	//Предикаты
	bool CorrectFr()
	{
		if (Denum_ > Num_)
			return true;
		else
			return false;
	}
	bool InCorrectFr()
	{
		if (Num_ > Denum_)
			return true;
		else
			return false;
	}
	bool IntFr()
	{
		if (Num_ == Denum_)
			return true;
		else
			return false;
	}

	//Данные из дроби

	int FullPart()
	{
		int num = Num_ / Denum_;
		return num;
	}
	void FractionPart()
	{
		int num = Num_ % Denum_;
		std::cout << num << '/' << Denum_;
	}
	void Reverse()
	{
		std::swap(Num_, Denum_);
		std::cout << Num_ << '/' << Denum_;
	}


private:
	T Num_;
	T Denum_;
};



int main() {
	setlocale(0, "");
	
	Fraction<int> F1;
	Fraction<int> F2;

	std::cout << "Введдите дробь 1 -> ";
	std::cin >> F1;
	std::cout << F1;
	std::cout << std::endl;

	std::cout << "Введдите дробь 2 -> ";
	std::cin >> F2;
	std::cout << F2;
	std::cout << std::endl;

	Fraction<int> Sum = F1 + F2;
	std::cout << "Сумма = " << Sum;
	std::cout << std::endl;

	return 0;
}