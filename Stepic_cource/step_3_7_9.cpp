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
	String(const String &other){
        String *new_str = new String(other.str);
        new_str->size = other.size;
    }

	// void append(const String &other);

	size_t size;
	char *str;
};

int main(void)
{
    

    return 0;
}