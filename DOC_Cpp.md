# Memory allocation  
`new` for single value and `new []` for arrays  
`delete` for single value and `delete []` for arrays  

`int (*)m = new int (5)`  
`delete m`  

`int *m = new [N]`  
`delete [] m`  

Operator `new` call constructor. `malloc` doesn't do it

# Constants  

Const referense for expresion on the left

Существует мнемоническое правило, позволяющее легко запомнить, к чему относится const. Надо провести черту через "*", если const слева, то оно относится к значению данных; если справа — к значению указателя.

`const int *` is equal `int const * `  - pointers for const  
But `int * const` - constant pointer  
`const int * const` - constant pointer on const  
`const int const * const` - same as above

# Multidimentions type cast  
![alt text for screen readers](/.images/array_types_cast.png "Functions")  


# Strings  
Don't use C-strings, it's hard and tedious  
Structs exist only in cimpile time, not after
Use `<string>` lib  

# Classes and Structures  
Classes = Structures, but in classes all fields are private
Struct with methods is a class. No ability to use standart struct initialization  
`StructWithMethoisd st1 = {...}` - error   
Can contains functions/classes...  
To use struct fields, use keyword `this`  
```Cpp  
struct Point{
    double x;
    double y;

    void shift(/* Point *this, */ double x, double y){
                    this->x += x;
                    this->y += y;
                }
};
```   


Struct Declaration: .h  
```Cpp
struct Point{
    double x;
    double y;
    void shift(double, double)
};
```  


Struct Defenition: .cpp  
```Cpp
void Point::shift(double x, double y)
{
    this->x += x;
    this->y += y;
}
```  


Constructor  
```cpp
struct Point{
    Point() {
        x = y = 0;
    }
    Point (double x, double y){
        this->x = x;
        this->y = y;
    }
    double x;
    double y;
};
```  


Initialization  
```cpp
struct Point{
    // Order is important
    Point() : x(0), y(0)
    {}

    Point(double x, double y) : x(x), y(y)
    {}

    double x;
    double y;
};
```  

Args by default  
```cpp
struct Point{
    // Order is important
    Point(double x = 0, double y = 0) : x(x), y(y)
    {}
    double x;
    double y;
};  
```   

Explicit cast  
```cpp
struct Segment {
    Segment() {}
    // Prohibit Segment s1 = N;
    explicit Segment (double length) : p2(length, 0)
    {}

    Point p1;
    Point p2;
};

// Segment s1 = 20; // Error
```   


Destructor  
```cpp
struct IntArray {
    explicit IntArray(size_t size) : size(size), data(new int[size])
    {}
    ~IntArray(){
        delete [] data;
    }

    size_t size;
    int *data;
};

void foo()
{   //Create struct
    IntArray a1(10);
    IntArray a2(20);
} // Delete struct. a2, then a1
```  

Methods can be also constant  
```cpp
struct Obj
{
    int i;
    char get_c() const {
        return 'h';
        }
};
```  

`mutable` allows change data in constant methods  
```cpp
struct Obj
{
    size_t size() const{
        ++counter_;
        return size_;
    }
private:
    size_t size;
    int *data;
    mutable size_t counter_;
};
```

Copy classes / structures  
Copy constructor calls when we initialize new variable with some other var
`Point p2 = p1;`
```cpp
struct Point{
    Point() { // Constructor
        x = y = 0;
    }
    Point (double x, double y){// Constructor
        this->x = x;
        this->y = y;
    }
    Point(Point const &p){ // Copy constructor
        ...
    }

    double x;
    double y;
};
```


Operator overload  
```cpp
struct Point{
    Point() { // Constructor
        x = y = 0;
    }

    Point &operator=(Point &p){ // Overload = operator
        if (this != p){ // Except a = a case
            ...
        }
        return *this;
    }

    double x;
    double y;
};
```

If we don't want that somebody comy data, place copy operator and `=` operator in private without realization  