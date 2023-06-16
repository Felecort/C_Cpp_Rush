#include <iostream>
using namespace std;

int main()
{
    char c = '\0';
    char prev_c = '\0';
    while (cin.get(c)) {
        if ((c == '\n') || (c == '\0')){
            return 0;
        }
        if ((prev_c != ' ') || (c != ' ')){
            cout << c;
        }
        prev_c = c;
    }
	return 0;
}