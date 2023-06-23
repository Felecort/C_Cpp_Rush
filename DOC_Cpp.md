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

# OOP  
## Inheritance  
`struct Derived <public/private/protected> : Base`: public by defauld  
`class Derived <public/private/protected> : Base`: private by defauld  
Child class haven't access for private fields in parent class.  
Keyword `protected` get access for private fields and methods for his children. But better not to use this modifyer for fields, only for methods    
```cpp

struct Person {
    Person(string name, int age) : name_(name), age_(age)
    {}
private:
    string name_;
    int age_;
};

struct Student : Person {
    Student(string name, int age, string uni)
        : Person(name, age), uni_(uni)
    {}
private:
    string uni_;
};

```  


## Overload  
```cpp
struct File {
    void write(char const *s);
    ...
};

struct FormattedFile : File {
    void write(int i);
    void write(double d);
    using File::write; // Overload for write(const char*s)
    ...
};

FormattedFile f;
f.write(4;)
f.write("Hello");
```  
## polymorfizm  
## Overriding. Virtual methods

```cpp
struct Person_1 {
    string name() const {return name_;}
    ...
};

struct Person_2 {
    virtual string name() const {return name_;}
    ...
};

struct Professor : Person {
    string name() const {
        return "Prof. " + Person::name(); // Explisit call method `name`
    }
};

Professor pr("Stroustrup");
Person_1 *p = &pr;
// Choose in compiletime
p->name() // Strousturp. Not Prof.

// Choose in runtime
Person_2 *p = &pr;
p->name() // Prof. Strousturp.

```  

## Pure virtual methods / abstract methods  
```cpp
// Can't create class instance. But can create a pointer for instance of inherint class 
struct Person {
    virtual string occupation() const = 0;
}

```  
## virtual destructor   
Incorrect  
```cpp
struct Person {
    ...         };

struct Student : Person{
    ...
private:
    string uni_;
};

int main(){
    Person *p = new Student("Alex", 24, "Foxford");
    ...
    delete p; // ~Person. Memory leaks, uni_ unreleased 
}

```   
Correct  
```cpp
struct Person {
    ...
    virtual ~Person(){};
};

struct Student : Person{
    ...
private:
    string uni_;
};

int main(){
    Person *p = new Student("Alex", 24, "Foxford");
    ...
    delete p; // ~Student 
}

```
