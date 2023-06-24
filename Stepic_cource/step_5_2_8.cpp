#include <cstddef> // size_t
#include <cstring>
#include <iostream>

using std::cout;
using std::cin;
using std::endl;

struct String {
	String(const char *str = ""){
        size = strlen(str);
        this->str = new char[size + 1];
        for(size_t i = 0; i < size + 1; i ++){
            this->str[i] = str[i];
        }
    }
	String(size_t n, char c);
	// ~String();

    String(const String &other);
    String &operator=(const String &other);

	void append(const String &other);


    struct Proxy {
        Proxy(char *str = "") : str(str){
        }
        size_t size;
        char *str;

        String operator[](size_t i) const {
            str[i - 1] = '\0';
            // char *new_str = new char[strlen(str)]
            // for(size_t letter; letter < i; letter++){

            return String(str);
            }
        }
    };
    Proxy operator[] (size_t i) const {
        char *str_ = new char[size - i + 1];
        for(size_t letter = i; letter < size; letter++){
            str_[letter - i] = this->str[letter];
        }
        return Proxy(str_);
    }

	size_t size;
	char *str;
};



int main(void)
{
    String s1("Hellown");
    cout << s1[5][6].str << endl;

    return 0;
}