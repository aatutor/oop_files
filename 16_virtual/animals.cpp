#include <iostream>
#include <string.h>
using namespace std;

class Animal {
public:
    char name[20];
    Animal(const char *t){
        strcpy(name,t);
    }
    // чистый виртуальный метод (абстрактный)
    virtual void speak()=0;
};

class Frog: public Animal {
public:
    Frog( const char *name): Animal(name){};
    virtual void speak() override {
        cout<<name<<" say "<<"\'kwa-kwa\'\n";
    }
};
class Dog: public Animal {
public:
    Dog(const char *name): Animal(name){};
    virtual void speak(){
        cout<<name<<" say "<<"\'gav-gav\'\n";
    }
};
class Cat: public Animal {
public:
    Cat(const char *name): Animal(name){};
    virtual void speak(){
        cout<<name<<" say "<<"\'myau-myau\'\n";
    }
};
class Lion: public Cat {
public:
    Lion(const char *name): Cat(name) {};
    
    virtual void speak(){
        cout<<name<<" say "<<"\'rrr-rrr\'\n";
    }
};

int main ()
{
    Animal *animals[4] = {new Dog("Bob"),
                        new Cat("Murka"),
                        new Frog("Vasya"),
                        new Lion("King")};
                        
    for(int k=0; k<4; k++)
        animals[k]->speak();
    
    return 0;
}
