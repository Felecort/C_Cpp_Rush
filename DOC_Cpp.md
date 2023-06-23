# Memory allocation  
`new` for single value and `new []` for arrays  
`delete` for single value and `delete []` for arrays  

`int (*)m = new int (5)`  
`delete m`  

`int *m = new [N]`  
`delete [] m`  

`new (this) Class(other.field)` - copy
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

# Scope enums  
Scoped enums more safety, they required `::` operator  
```cpp
enum class Motion {
    Forward,
    Back,
    Left,
    Right,
};

int main(void)
{
    Motion m = Motion::Back; 
    return 0;
}
```

# Range-based loops  
`for(element_type element_name : array)`  
```cpp
int arr[] = {10, 20, 30};
for (int i : arr){}

```
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
`struct A : <public/private/protected> B`  


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
# Polymorfizm  
## Overriding. Virtual methods  
If one method is virtual, you must to define virtual destructor  
In constructors virtual methos behave like nonvirtual methosd  

```cpp

struct Person_1 {
    Person_1(string s) : name_(s) {};
    string name() const {return name_;}
    string name_;
};

struct Person_2 {
    Person_2(string s) : name_(s) {};
    virtual string name() const {return name_;}
    string name_;
};

struct Professor_1 : Person_1 {
    Professor_1(string s) : Person_1(s) {};
    string name() const {
        return "Prof. " + Person_1::name(); // Explisit call method `name`
    }
};

struct Professor_2 : Person_2 {
    Professor_2(string s) : Person_2(s) {};
    string name() const {
        return "Prof. " + Person_2::name(); // Explisit call method `name`
    }
};

int main(void)
{
    
    Professor_1 pr_1("Stroustrup");
    Person_1 *p_1 = &pr_1;
    // Choose in compiletime
    cout << p_1->name() << endl; // Strousturp. Not Prof.

    Professor_2 pr_2("Stroustrup");
    // Choose in runtime
    Person_2 *p_2 = &pr_2;
    cout << p_2->name() << endl; // Prof. Strousturp.
    
    return 0;
}

```  

## Pure(Clear) virtual methods / abstract methods  
```cpp
// Can't create class instance. But can create a pointer for instance of inherint class 
struct Person {
    virtual string occupation() const = 0;
}

```

## Virtual methods table  
When we have pilimorfic behaviour, compiler create a virtual methods table.  
`p->occupation();` -> `p->vptr[1]()` - virtual method call  
Htis mechanism allow us to reach dynamin polimorfitzm  

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

# Pure virtual methods realization  

```cpp
struct NetworkDevice {
    virtual void send(void *data, size_t size) = 0;
    ...
};

void NetworkDevice::send(void *data, size_z size){
    ...
}

struct Router : NetworkDevice {
    void send(void *data, size_t size){
        ...
        // nonvirtual method
        NetworkDevice::send(data, size);
    }
}
```

# Aggregation and Inheritence  

для агрегирования и наследования есть правило:

"если a имеет b " -  пишем агрегацию

"если a является b" - наследование
