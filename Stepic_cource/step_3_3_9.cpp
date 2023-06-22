#include <cstddef> // size_t
#include <cstring> // strlen, strcpy
#include <iostream>

using std::cout;
using std::cin;
using std::endl;


struct String {

    /* Реализуйте этот конструктор */
	String(const char *str = ""){
        size = strlen(str);
        this->str = new char[size + 1];
        strcpy(this->str, str);
    }
    String(size_t n, char c){
        size = n;
        this->str = new char[size + 1];
        for(unsigned i = 0; i < size; i++){
            this->str[i] = c;
        }
        this->str[size] = '\0';
    }

    ~String(){
        delete [] str;
    }

	size_t size;
	char *str;

    void append(String &other){
        char *tmp_str = new char[this->size + other.size + 1];
        for(unsigned i = 0; i < size; i++){
            tmp_str[i] = str[i];
        }
        for(unsigned i = size; i < (size + other.size); i++){
            tmp_str[i] = other.str[i - size];
        }
        tmp_str[size + other.size] = '\0';
        delete []str;
        str = tmp_str;
        size += other.size;
    }

};

int main(void)
{
    String s1("Hello,");
    String s2("world");
    s1.append(s2);
    cout << s1.str << "| len: " << s1.size <<endl;

    return 0;
}