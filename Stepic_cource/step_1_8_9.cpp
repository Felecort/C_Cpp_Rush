#include <iostream>

using namespace std;

int main(void)
{
    int tests = 0;
    int a, b;
    cin >> tests;
    for (int i = 0; i < tests; i++){
        cin >> a >> b;
        cout << (a + b);
    }
    return 0;
}