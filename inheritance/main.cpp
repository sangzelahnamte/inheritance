#include <iostream>

class Base
{
private:
    int length, breadth;
public:
    Base(int length_a, int breadth_a);
    ~Base();
    int getArea();
};

Base::Base(int length_a, int breadth_a)
{
    length = length_a;
    breadth = breadth_a;
}
Base::~Base()
{
    std::cout << "Base object de-constructed\n";
}
int Base::getArea()
{
    return length * breadth;
}

class Derived : public Base // will inherit base class
{
private:
    int height;
public:
    // constructor initialization hi dik thei thlawt lo base class inherit ka duh bawk sia
    Derived(int length_a, int breadth_a, int height_a) : Base(length_a, breadth_a);
    ~Derived();
    int print();
};
// derived constructor declared outside class inheriting base class
Derived::Derived(int length_a, int breadth_a, int height_a) : Base(length_a, breadth_a)
{
    height = height_a;
}
Derived::~Derived()
{
    std::cout << "Derived object de-constructed\n";
}
int Derived::print()
{
    return Base::getArea() * height;
}

int main()
{
    Derived obj(2, 3, 5);
    obj.print();

    return 0;
}
