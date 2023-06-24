#include <iostream>

struct Rational {
    Rational(int numerator = 0, int denominator = 1) : numerator_(numerator), denominator_(denominator) {};

    void add(Rational rational) {
        numerator_ = numerator_ * rational.denominator_ + rational.numerator_ * denominator_;
        denominator_ *= rational.denominator_;
    }

    void sub(Rational rational) {
        numerator_ = numerator_ * rational.denominator_ - rational.numerator_ * denominator_;
        denominator_ *= rational.denominator_;
    }

    void mul(Rational rational) {
        numerator_ *= rational.numerator_;
        denominator_ *= rational.denominator_;
    }

    void div(Rational rational) {
        numerator_ *= rational.denominator_;
        denominator_ *= rational.numerator_;
    }

    void neg() {
        numerator_ = -numerator_;
    }

    void inv() {}

    double to_double() const {
        return numerator_ / (double) denominator_;
    }
    Rational & operator+=(const Rational & rational) { 
        this->add(rational);            
        return *this; 
    }
    Rational & operator+=(int d)                      { 
        this->add(Rational(d));         
        return *this; 
    }
    
    Rational & operator-=(const Rational & rational) { 
        this->sub(rational);    
        return *this; 
    }
    Rational & operator-=(int d)                      { 
        this->sub(Rational(d)); 
        return *this; 
    }
    
    Rational & operator*=(const Rational & rational) { 
        this->mul(rational);
        return *this; 
    }
    Rational & operator*=(int d)                     { 
        this->mul(Rational(d)); 
        return *this; 
    }
    
    Rational & operator/=(const Rational & rational) { 
        this->div(rational);    
        return *this; 
    }
    Rational & operator/=(int d)                     { 
        this->div(Rational(d)); 
        return *this; 
    }
 
    Rational operator-() const { Rational r(this->numerator_, this->denominator_); r.neg(); return r; }
    Rational operator+() const { Rational r(this->numerator_, this->denominator_);          return r; }

    int get_numer() const {
        return this->numerator_;
    }
    int get_denom() const {
        return this->denominator_;
    }

    operator double() const {
        return to_double();
    }

private:
    int numerator_;
    int denominator_;
};

Rational operator+(Rational num_1, Rational const &num_2){
    return num_1 += num_2;
}
Rational operator-(Rational num_1, Rational const &num_2){
    return num_1 -= num_2;
}
Rational operator*(Rational num_1, Rational const &num_2){
    return num_1 *= num_2;
}
Rational operator/(Rational num_1, Rational const &num_2){
    return num_1 /= num_2;
}

bool operator==(Rational const &a, Rational const &b){
    int a_ = a.get_numer() * b.get_denom();
    int b_ = b.get_numer() * a.get_denom();
    return (a_ == b_);
}
bool operator!=(Rational const &a, Rational const &b){
    return !(a == b);
}

bool operator<(Rational const &a, Rational const &b){
    int a_ = a.get_numer() * b.get_denom();
    int b_ = b.get_numer() * a.get_denom();
    return (a_ < b_);
}
bool operator>(Rational const &a, Rational const &b){
    return (b < a);
}
bool operator<=(Rational const &a, Rational const &b){
    return !(b < a);
}
bool operator>=(Rational const &a, Rational const &b){
    return !(a < b);
}
int main(){
    // Rational r1(3, 7);
    // Rational r2(2, 5);
    // Rational r3 = r1 + r2;
    // Rational r4 = r1 + 5;
    // Rational r5 = 5 + r1;
    std::cout << 39 / 7 << std::endl;
    std::cout << 39 % 7 << std::endl;
}
// Rational R1(x, y); 
// Rational R2(x2, y2); 
//  Rational R3 = R1 +R2; 
// 2. Полуграбли №2: 
// Авторы курса хотят, чтобы работал код:
// int x; Rational R1; 
// Rational R2 = x + R1;
// Rational R3 = R1 + x;