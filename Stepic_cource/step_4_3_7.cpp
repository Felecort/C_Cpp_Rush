#include <iostream>

using std::cout;
using std::cin;
using std::endl;


struct Expression
{
    virtual double evaluate() const = 0;
    virtual ~Expression(){}
};

struct Number : Expression
{
    Number(double value)
        : value(value)
    {}
    
    double evaluate() const {return value;}

private:
    double value;
};

struct BinaryOperation : Expression
{
    /*
      Здесь op это один из 4 символов: '+', '-', '*' или '/', соответствующих операциям,
      которые вам нужно реализовать.
     */
     ~BinaryOperation() {
         delete left;
         delete right;
     }
    BinaryOperation(Expression const * left, char op, Expression const * right)
        : left(left), op(op), right(right)
    {}
     double evaluate() const {
        switch (op) {
            case '+':
                return  (left->evaluate() + right->evaluate());
            case '-': 
                return  (left->evaluate() - right->evaluate());
            case '*': 
                return  (left->evaluate() * right->evaluate());
            case '/': 
                return  (left->evaluate() / right->evaluate());
            default: return 0.0;
        }
    
     }
private:
    Expression const * left;
    char op;
    Expression const * right;
};


int main(){
    // сначала создаём объекты для подвыражения 4.5 * 5
    Expression * sube = new BinaryOperation(new Number(4.5), '*', new Number(5));
    // потом используем его в выражении для +
    Expression * expr = new BinaryOperation(new Number(3), '+', sube);

    // вычисляем и выводим результат: 25.5
    std::cout << expr->evaluate() << std::endl;

    // тут освобождаются *все* выделенные объекты
    // (например, sube будет правым операндом expr, поэтому его удалять не нужно)
    delete expr;
    return  0;
}