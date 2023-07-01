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

# Global variables  
Not in main:
`extern` - keyword. Equal zero bu defauld  
`extern int global;` - declaration - in header  
`int global = 10;` - declaration and defenition - in .cpp

# Static variable  
Not in main  
`static` - global variable or func, but only inside module / translation unit  
Problems with multithreads  
Static class fields like static variables, but they containce not in class instance, but in class. Static field in class like ordinary function and has access for private fields    
In some func. Func remember value in all calls. Save state  
```cpp
int next(int start = 0){
    static int k = start;
    return k++;
}
```  

# Inline  
We aks compiler to put in function inside code. Should me in .h  

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
int sum = 0;

for (int x : arr){ sum += x; } // sum elements

for (int &x : arr){ x *= 2; } // double every element
```  

# Initialization list  
```cpp
template<typename T>
struct Array{
    Array(std::initializer_list<T> list);
};
Array<int> primes = {2, 3, 4, 5}; // Like standart init

int sum(std::initializer_list<int> list){
    int res = 0;
    for(int x : list) res += x;
    return res;
}
int s = sum({1, 2, 3, 4}) // -> 10
```

# Lambda expression and std::function  
std::function is a wrapper. Creates a pointer for func   
`int foo(bool, float); std::function<int, (bool, float)> *pointer*`  
(op created using `std::function`)
`op = [](*parametrs*) {return *body*};` - default  
`op = [](*parametrs*) -> *return type* {*body*}` - with return type  
`op = [](auto *param*) {*body*}` - with template (`auto`)   
Capturing LOCAL VAR by reference/value. Allowed to capture `this`  
`[&]` and `[=]` - all local vars, `[=, &z]` - except `z`  
```cpp
int total = 0;
auto addToTotal = [&total](int x) {total += x;};
```
# Raw strings  
`R"(some text, d\user\vadim...)"` - raw str, brackets ignors    
`R"delimiter |start. some text. End|" )delimiter"`

# Enum class  
It's save version of enums. Use enum name and var to get access for data  
```cpp
enum class COLORS { // int by default
    BLACK, WHITE, RED = 4, GREEN = 8
};
cout << COLORS::RED;
// explicit data type 
enum class CONSTANTS : double { // int by default
    e = 2.718281828459045, pi = 3.14
};
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


# Friend  
Do not use this keyword  

# Singleton  
Menas, that some class can have only one instance. Operation system, access for database - are examples  

```cpp
struct Singleton {
    static Singleton & instance() {
        static Singleton s;
        return s;
    }
    Data &data() {return data_;}

private:
    Singleton() {}

    Singleton(Singleton const&);
    Singleton operator=(Singleton const &);
    Data data_;
}

int main(){
    Singleton &s = Singleton::instance();
    Data d = s.data();

    d = Singleton::instance().data() // s.data();
    return 0;
}

```



# Templates  
## Class templates  
```cpp
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
```


# virtual inheritance  
Without virtual inheritance:  
```
ArtWork     ArtWork  
   |           |  
Lyrics       Music  
   |           |  
   \           /  
    \         /  
     \       /  
      \     /  
       \   /  
        \ /  
         |  
        Song  
```
Using virt inheritance. Diamond inheritance  
```
    Unit
     /\
    /  \   
   /    \
 Elf   Archer
   \    /
    \  /
     \/
  ElfArcher  
```  
Use `virtual` keyword, solution with many constructors problem: explicitly call constructor  
```cpp
struct Unit{
    Unit(unitid id, int health);
};
struct Elf: virtual Unit{
    explicit Elf(unitid id) : Unit(id, 100){}
};
struct Archer: virtual Unit{
    explicit Archer(unitid id) : Unit(id, 200){}
};
struct ElfArcher: Elf, Archer {
    explicit ElfArcher(unit id): unit(id, 150), Elf(id), Archer(id){}
};
```  
Vitrual tables make work  (`__get<Class>Ptr__()-><field>`) - problems with perfomance  

# Static cast  
Standart cast (numerical, pointers...)  
```cpp
double s = static_cast<double>(2) / 3 * 100;
s = static_cast<int>(d);
```  

# Const cast  
Allow to put off and add const  
Put off const is not safe  

# Reinterpret cast  
If we need to send double data like a char  

```cpp
double *m = static_cast<double *>(malloc(sizeof(double) * 100));
char *mc = reinterptered_cast<char *>(m);
send(mc);
```  


# Runtime type information (RTTI)  
`typeid` return `std::type_info`  
`typeid(var).name()`
`dynamic_cast` - check validity in runtime, `dynamic_cast<void *>` - returns address of first byte  

# Namespaces  
Do not include full namespace (`using namespace std` - evil)
These are the ways to distinguish names scopes  
In C the main approach is to set prefix:  
`struct XML_Parser;`  
`in XML_GetCurrentline`  

In C++ we can use namespaces  
```cpp
namespace XML{
    struct Parser;
    int GetCurrentLine;
};

XML::Parser;
XML::GetCurrentLine
```   

Namespaces can be nested
```cpp
namespace items {
    namespace food {
        struct Fruit{};
    }
}

items::food::Fruit apple("Apple");
```  

And can be separete  
```cpp
namespace weapon { struct Bow {};}

namespace items{
    struct Scroll {};
    struct Artefact {};
}
namespace weapon { struct Sword {};}

```  
Something in class/struct is part of namespace  
Inside namespace we can call any object inside this namespace, but of we call outer object, we need to use "root catalog", if we have func with the same nami in namespace (name resoution mechanism in compiletime)  
```cpp
// But if we call object outer namespace, we need prefix  
int var;
namespace items{
    int *c = ::(&var);
}


int foo(int i) { return 1; }

namespace re{
    int foo(float f) { return 2; } // Process finding names stops, when we found name
    int foo(double d1, double d2) { return 3; }
    
    namespace spb {
        int global = foo(5); // int foo(float f) will be call
    }
}
```  

Keyword `using` can includ some namespace in current  
Really, C++ uses Kenning search (ADL - argument-dependent name lookup)    
```cpp
namespace cg{
    struct Vector2 {};
    Vector2 operator+(Vector2 a, Vector2 const &b) {}
}

cg::Vector a(1, 1);
cg::Vector b(1, 3);
b = a + b; // equal to b = operator+(a, b);
// But how compiler found cg::operator+(...)
```  

## Anonimus namespaces  
Like static structs. Structures are defined in one translation unit    
```cpp
namespace {
    struct Test {};
}
// Equal to:
namespace $GeneratedName$ {
    struct test {std::strung name; };
}
using namespace $GeneratedName$;

```

Namespace can have a aliaces(synonims):  
`namespace sword = Items::Weapons::Melee;`  

## Keyword `using`  
Much more powerfull, allows sustain `typedef`  
```cpp
template<class A, class B, int N>
class SomeType;

template<typenameB>
using TypedefName = SomeType<double, B, 5>;

// Lines below are equal
typedef void(*OtherType)(double);
using OtherType = void (*)(double);
```  


# Auto and decltype keywords  
`auto` - use type, that have rvalue  
`decltype` - "compute" type of some expression    
auto cut off outer feference and const  
`auto a = items[0]` - a - Item  
`decltype(items[0]) b = a` b - Item const &  

`decltype(a) c = a` c - Item  
`decltype((a)) d = a` d - Item &  


```cpp
Array<Unit *> units;
for(size_t i = 0; i != units.size(); i++){
    auto u = units[i];
    // decltype(u->items()) - equal type of u->items()
    decltype(u->items()) items = u->items();
}

```

# delete and default keywords  

`default` - Constructor by default  
`delete` - do not generate method  

```cpp
struct Sometype {
    Sometype() = default; // construct by default
    Sometype(OtherType p) {}
};

struct NonCopyble {
    NonCopyble() = defualt;
    NonCopyble(const NonCopyble&) = delete;
    NonCopyble & operator=(const NonCopyble) = delete;
};
```  

# Constructors delegation  

# Explicit methods overriding  

fields by default, new approach to init constr  
`override` - Explicit say to compiter, that ve override some virtual method   
`final` - Forbide child classes overriding this method, or fobide nested from some class   
```cpp
struct Base{
    virtual void update();
    virtual void foo(int);
    virtual void bar() const;
};

struct Derived : Base {
    void updata() override; // Error. updatA, not updatE
    void foo(int) override; // Ok
    virtual void foo(long) override; // Error. Not `int`
    virtual void foo(int) const override; // Error. Not const
    virtual int foo(int) override; // Error. return type is not int
    virtual void bar(long); // new virtual method. Ok.
    virtual void bar(long) const final; // Ok. Forbide child classes overriding this method
}
```  

# Rvalue preferance. Moving constructor  
We "take away" boofer and data  
```cpp
struct String{
    String(String && s) // && - rvalue preference
    : data_(s.data_),   // take away
    size_(s.size_)      // take away
    {
        s.data_ = nullptr; // Consent object
        s.size_ = 0;       // Consent object
    }
    String operator=(String && s){
        delete [] data_;
        // take away data
        data_ = s.data_;
        size_ = s.size_;

        // Consent data
        s.data = nullptr;
        s.size_ = 0;
        return *this;
    }
}
```
`std::move(x)` allosw move var insted coping  
But be careful, because compiler can make optimizations and `std::move` may threat him  


# constexpr  
calculation value in compile time  
`constexpr double accOfG = 9.8;`  
constexpr func may call only constexpr funcs and have one return `statement`
`constexpr int pow(...){...}`  

# STL. Standart template library   
Part of std lib  
Containers, iterators, adapters, algorithms, functors

## Containers: consecutive and associative  
### consecutive contsiners  

`*Container*::value_type/iterator/const_iterator`  
Common methors: `size, max_size, empty, clear`  
`begin, end, cbegin, cend`  
compare operators `==, !=, <...`  

Constructors have:  
* constructor: by first and last elements  
* constructor: const_count, def_value  
* std::initializer_list    
* `back`, `front`  
* `push_back`, `emplace_back`  
* `assign`, `insert`, `emplace`, `erase`  


### Vector template  
Efficiency add/del in the end  
* `operator[]` - fast, not safety, method `at` - slow, but safe  
* `resize`  
* `capacity` - buffer size, `reserve` - enlarge buffer, `shrink_to_fir` - set capacity equal to size  
* `pop_back` - delete from the end, `data`  

### deque - double ended queue  
Efficiency add/del element at the end and beginning  
`push_front`


### List - double linked list  
pop and add for O(n)  
No `oparator[]`. If need to iterate, use range-based for  
for more complicated actions:  
`*container type*::iterator i = list.begin;`  
`for(; i != l.end(); ++i) if(*i == "Two") break;`  
`l.erase(i)l` - delete element "two"  

### Forward list - linked list  


### String  
String is an instance of `basic_string<char>`  

### Adapters  
Wrappers on the containers  
`valarray` - array for numerical data  

## Associative containers  
Have methods: `find`, `count`, `erase`  

### Set - balanced binary tree  
add, del, find - O(log(n))  

### Multiset - balanced binary tree  
Like Set, bat can contain repetitives

### Map - dictionary - balanced binary tree
`std::pair<const Key, T>`  


### Multipam  
Like multiset - can containn repetitives keys  


