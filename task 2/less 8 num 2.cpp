#include <iostream>

class Fraction
{
private:
    int numerator_;
    int denominator_;

public:
    Fraction(int numerator, int denominator) : numerator_(numerator), denominator_(denominator) {}

    Fraction operator+(const Fraction& other) const
    {
        return Fraction(numerator_ * other.denominator_ + other.numerator_ * denominator_, denominator_ * other.denominator_);
    }

    Fraction operator-(const Fraction& other) const
    {
        return Fraction(numerator_ * other.denominator_ - other.numerator_ * denominator_, denominator_ * other.denominator_);
    }

    Fraction operator*(const Fraction& other) const
    {
        return Fraction(numerator_ * other.numerator_, denominator_ * other.denominator_);
    }

    Fraction operator/(const Fraction& other) const
    {
        return Fraction(numerator_ * other.denominator_, denominator_ * other.numerator_);
    }

    Fraction operator-() const
    {
        return Fraction(-numerator_, denominator_);
    }

    Fraction& operator++()
    {
        numerator_ += denominator_;
        return *this;
    }

    Fraction& operator--()
    {
        numerator_ -= denominator_;
        return *this;
    }

    Fraction operator++(int)
    {
        Fraction temp(*this);
        ++(*this);
        return temp;
    }

    Fraction operator--(int)
    {
        Fraction temp(*this);
        --(*this);
        return temp;
    }

    bool operator==(const Fraction& other) const
    {
        return (numerator_ == other.numerator_ && denominator_ == other.denominator_);
    }

    bool operator!=(const Fraction& other) const
    {
        return !(*this == other);
    }

    bool operator<(const Fraction& other) const
    {
        return (numerator_ * other.denominator_ < other.numerator_ * denominator_);
    }

    bool operator>(const Fraction& other) const
    {
        return (numerator_ * other.denominator_ > other.numerator_ * denominator_);
    }

    bool operator<=(const Fraction& other) const
    {
        return (*this < other || *this == other);
    }

    bool operator>=(const Fraction& other) const
    {
        return (*this > other || *this == other);
    }

    void display() const
    {
        std::cout << numerator_ << "/" << denominator_;
    }
    friend std::ostream& operator<<(std::ostream& out, const Fraction& frac);
};

std::ostream& operator<<(std::ostream& out, const Fraction& frac)
{
    out << frac.numerator_ << "/" << frac.denominator_;
    return out;
}

int main()
{
    setlocale(LC_ALL, "ru");
    int num1, den1, num2, den2;

    std::cout << "Введите числитель дроби 1: ";
    std::cin >> num1;
    std::cout << "Введите знаменатель дроби 1: ";
    std::cin >> den1;

    std::cout << "Введите числитель дроби 2: ";
    std::cin >> num2;
    std::cout << "Введите знаменатель дроби 2: ";
    std::cin >> den2;

    Fraction f1(num1, den1);
    Fraction f2(num2, den2);

    Fraction add = f1 + f2;
    Fraction sub = f1 - f2;
    Fraction mul = f1 * f2;
    Fraction div = f1 / f2;

    std::cout << std::endl;
    std::cout << f1 << " + " << f2 << " = " << add << std::endl;
    std::cout << f1 << " - " << f2 << " = " << sub << std::endl;
    std::cout << f1 << " * " << f2 << " = " << mul << std::endl;
    std::cout << f1 << " / " << f2 << " = " << div << std::endl;

    Fraction temp = f1;
    std::cout << "++" << f1 << " = " << ++f1 << std::endl;
    std::cout << "Значение дроби 1 = " << f1 << std::endl;

    std::cout << f1 << "-- * " << f2 << " = " << (temp-- * f2) << std::endl;
    std::cout << "Значение дроби 1 = " << temp << std::endl;

    return 0;
}