#include <iostream>

using std::cout;
using std::cin;
using std::endl;


template <typename Type,
          typename SizeT=size_t,
          typename CRet=Type>
struct Array{
    explicit Array(SizeT size=10) : data_(new Type[size]), size_(size)
    {}
    ~Array(){delete [] data_;}
    
    SizeT size() const {return size_;}
    
    CRet operator[](SizeT i) const {
        return data_[i];
    }
    Type &operator[](SizeT i) {
        return data_[i];
    }

private:
    Type *data_;
    SizeT size_;
};


int main(void)
{
    
    Array<int> ai(10);
    Array<float> af(20);
    Array<Array<int>, size_t, Array<int> const&> da(30);

    
    return 0;
}