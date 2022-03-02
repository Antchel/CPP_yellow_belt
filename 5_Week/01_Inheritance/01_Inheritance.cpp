#include <iostream>

using namespace std;

class Animal {
public:
    Animal() {};
    Animal(const string str) :Name(str) {};
    const string Name;
};

class Dog: public Animal{
public:
    Dog(const string name) :Animal(name) {};

    void Bark() {
        cout << Name << " barks: woof!" << endl;
    }
};

int main()
{
    Dog d("Jack");
    d.Bark();
}