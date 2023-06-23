
#include <iostream>

using std::cout;
using std::cin;
using std::endl;

struct Cls {
    Cls(char c, double d, int i) : c(c), d(d), i(i)
    {};
    private:
        char c;
        double d;
        int i;
};

struct Cls2 {
    Cls2(char c, double d, int i) : c(c), d(d), i(i)
    {};
    public:
        char c;
        double d;
        int i;
};
// Эта функция должна предоставить доступ к полю c объекта cls.
// Обратите внимание, что возвращается ссылка на char, т. е.
// доступ предоставляется на чтение и запись.
char &get_c(Cls &cls) {
    Cls2 *cls2 = (Cls2 *)(&cls);
    return cls2->c;
}

double &get_d(Cls &cls) {
    Cls2 *cls2 = (Cls2 *)(&cls);
    return cls2->d;
}

int &get_i(Cls &cls) {
    Cls2 *cls2 = (Cls2 *)(&cls);
    return cls2->i;
}

int main(void)
{
    Cls cls(100, 2.5, INT32_MAX);
    char ch;
    ch = get_c(cls);
    cout << sizeof(cls) << endl;
    cout << ch << endl;

    return 0;

}


