#include <iostream>
using std::cin;
using std::cout;

#define BUFFER_SIZE 8 

char *resize(const char *str, unsigned size, unsigned new_size)
{
	char *new_str = new char[new_size];
    size = (size > new_size) ? new_size : size;
    for (unsigned i = 0; i < size; i++){
        new_str[i] = str[i];
    }
    delete [] str;
    return new_str;
}


char *getline()
{
    char * str = new char [BUFFER_SIZE];
    unsigned counter = 0;
    unsigned buffer_size = BUFFER_SIZE;

    char tmp;
    // cin >> tmp;
    while (cin.get(tmp) && tmp != '\n'){
        if (counter < (buffer_size - 1)){
            str[counter] = tmp;
            counter++;
        } else {
            buffer_size *= 2;
            str = resize(str, counter, buffer_size);
            str[counter] = tmp;
            counter++;
        }
        // cin >> tmp;
    }
    str[counter] = '\0';
    return str;
}

int main(void)
{

    char *arr = getline();
    cout << arr;
}