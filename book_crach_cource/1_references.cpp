#include <iostream>
#include <vector>

using std::cout;
using std::cin;
using std::endl;

struct HolmesIV
{
    bool is_sentient;
    int sence_of_humor;
};

HolmesIV& not_dincum() {
    HolmesIV *mike = new HolmesIV;
    mike->is_sentient = true;
    mike->sence_of_humor = 20;
    return *mike;
}

int main() {
    HolmesIV& holmes = not_dincum();
    cout << holmes.is_sentient << " " << holmes.sence_of_humor << endl;
    delete &holmes; // Remember to delete the dynamically allocated object
    return 0;
}