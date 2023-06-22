

template <typename T>
T add(T x, T y, T z){
    return x + y + z;
}

int main(void)
{
    unsigned char c = add(2, 3, 4);
    int a = add(1, 2, 3);
    double b = add(2.4, 2.2, 5.5);   
    long double d = add(2.4, 2.2, 5.5);   
    
    return 0;
}