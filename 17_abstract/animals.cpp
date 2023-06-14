#include <iostream>
#include <string.h>
using namespace std;

class Animal {
protected:
	char name_[100];
	char kind_[50];
public:
	Animal(const char *t, const char* p){
		strcpy(name_, t);
		strcpy(kind_, p);
	}
	// чисто виртуальный метод (абстрактный)
	virtual void Speak()=0;
};

class Frog: public Animal {
public:
	Frog( const char *name_): Animal(name_, "amphibian"){};
	virtual void Speak() override {
		cout << name_ <<" say \'kwa-kwa\'("<< kind_ <<")\n";
	}
};
class Dog: public Animal {
public:
	Dog(const char *name_): Animal(name_, "animal"){};
	virtual void Speak(){
		cout << name_ <<" say \'gav-gav\'("<< kind_ <<")\n";
	}
};
class Cat: public Animal {
public:
	Cat(const char *name_): Animal(name_, "animal"){};
	virtual void Speak(){
		cout << name_ <<" say \'mya-mya\'("<< kind_ <<")\n";
	}
};
class Lion: public Cat {
public:
	char* zoo_;
	Lion(const char *name_): Cat(name_) {
		strcat(kind_, "-hunter");

		zoo_ = new char[100];
		strcpy(zoo_, "Taiga");
	}
	
	virtual void Speak(){
		cout << name_ <<" say \'rrr-rrr\'("<< kind_ <<": "<< zoo_ <<")\n";
	}
};

int main ()
{
	Animal *animals[4] = {new Dog("Jack"),
						new Cat("Murka"),
						new Frog("Bob"),
						new Lion("King")};
						
	for(int k=0; k<4; k++)
		animals[k]->Speak();
	
	return 0;
}
