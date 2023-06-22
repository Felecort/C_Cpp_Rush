#include <iostream>

using std::cout;
using std::cin;
using std::endl;

struct HolmesIV
{
    bool is_sentient;
    int sence_of_humor;
};

HolmesIV& not_dincum(){
    HolmesIV *mike = new HolmesIV();
    // mike->is_sentient
    mike->is_sentient = true;
    mike->sence_of_humor = 20;
    return (HolmesIV&)mike;
}

int main(void)
{
    
    HolmesIV &mike_ref = not_dincum();
    cout << mike_ref.is_sentient << " " << mike_ref.sence_of_humor << endl;
    
    return 0;
}