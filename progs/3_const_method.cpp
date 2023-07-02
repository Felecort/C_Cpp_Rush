#include <iostream>

using std::cout;
using std::cin;
using std::endl;

void f()
{

}

struct SomeStruct{
    SomeStruct(int year) : year_(year)
    {}

    void foo(int a) const {
        a++;
        cout << year_ << " " << a << endl;
    }

private:
    int year_;
};

int main(void)
{
    SomeStruct s{12};
    s.foo(34);

    int *val_ptr = new int{1'000'000'000};
    int &ref_var = *val_ptr;
    cout << ref_var << endl;
    cout << sizeof(int) << endl;
    delete val_ptr;
    return 0;
}