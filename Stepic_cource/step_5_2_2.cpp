#include <iostream>

using std::cout;
using std::cin;
using std::endl;

struct Rational
{
    Rational(int numerator = 0, int denominator = 1)
    : numerator_(numerator), denominator_(denominator)
    {};

    void add(Rational rational);
    void sub(Rational rational);
    void mul(Rational rational);
    void div(Rational rational);

    void neg();
    void inv();
    double to_double() const {
        return numerator_ / denominator_;
    };

    Rational operator-() const{
        return Rational(this->numerator_ * -1, this->denominator_);
    }
    Rational operator+() const{
        return Rational(this->numerator_, this->denominator_);
    }

    Rational & operator+=(Rational const &number){
        int new_denom = this->denominator_ * number.denominator_;
        int new_numer = (this->numerator_ * number.denominator_) + (number.numerator_ * this->denominator_);
        this->denominator_ = new_denom;
        this->numerator_ = new_numer;
        return *this;
    }
    Rational & operator+=(int &number){
        (*this)+=(Rational(number, 1));
        return *this;
    }

    Rational &operator-=(Rational const &number){
        -(*this);
        (*this)+=(number);
        this->numerator_*=-1;
        return *this;
    }
    Rational &operator-=(int &number){
        (*this)-=(Rational(number, 1));
        return *this;
    }

    Rational &operator*=(Rational const &number){
        this->denominator_*=number.denominator_;
        this->numerator_*=number.numerator_;
        return *this;
    }
    Rational &operator*=(int &number){
        (*this)*=(Rational(number, 1));
        return *this;
    }

    Rational &operator/=(Rational const &number){
        (*this)*=Rational(number.denominator_, number.numerator_);
        return *this;
    }
    Rational &operator/=(int &number){
        (*this)*=Rational(1, number);
        return *this;
    }

private:
    int numerator_;
    int denominator_;
};


int main(void)
{
    Rational r1(3, 7);
    Rational r2(2, 5);
    r1 /= r2;
    r1 /= 7;
    return 0;
}