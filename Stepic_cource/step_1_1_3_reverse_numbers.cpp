#include <iostream>

using namespace std;

void get_num(){
    int value;
    cin >> value;
    if (value == 0) return;
    get_num();
    cout << value << " ";
}

int main()
{
    get_num();
	return 0;
}