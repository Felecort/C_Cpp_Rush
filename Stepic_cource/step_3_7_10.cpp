#include <cstddef> // size_t
#include <cstring> // strlen, strcpy
#include <iostream>

using std::cout;
using std::cin;
using std::endl;

struct String {
	String(const char *str = "");
	String(size_t n, char c);
	~String();


    /* Реализуйте конструктор копирования */
	// String(const String &other)
	// void append(const String &other);
    String &operator=(const String &other){
        if (this != &other){ 
            delete [] str;
            size = other.size;
            str = new char[size + 1];
            for(int i = 0; i <= size; i++){
                str[i] = other.str[i];
            }
        }
        return *this;
    }

	size_t size;
	char *str;
};

int main(void)
{
    

    return 0;
}