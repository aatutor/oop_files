#include <iostream>
#include <string.h>
using namespace std;

// Animal
class Animal {
protected:
	char name_[100];
	char kind_[50];
public:
	Animal(const char *t, const char* p);
	// чисто виртуальный метод (абстрактный)
	virtual void Speak()=0;
	virtual ~Animal() {};
};
Animal::Animal(const char *t, const char* p){
	strcpy(name_, t);
	strcpy(kind_, p);
}

// Frog
class Frog: public Animal {
public:
	Frog( const char *name): Animal(name, "amphibian"){};
	void Speak() override;
};
void Frog::Speak() {
	cout << name_ <<" say \'kwa-kwa\'("<< kind_ <<")\n";
}

// Dog
class Dog: public Animal {
public:
	Dog(const char *name): Animal(name, "animal"){};
	void Speak() override;
};
void Dog::Speak() {
	cout << name_ <<" say \'gav-gav\'("<< kind_ <<")\n";
}

// Cat
class Cat: public Animal {
public:
	Cat(const char *name): Animal(name, "animal"){};
	void Speak() override;
};
void Cat::Speak(){
	cout << name_ <<" say \'mya-mya\'("<< kind_ <<")\n";
}

// Lion
class Lion: public Cat {
public:
	char* zoo_;
	Lion(const char *name, const char *z);
	~Lion();
	void Speak() override;
};
Lion::Lion(const char *name, const char *z): Cat(name) {
	char t[]{"-hunter"};
	strcat(kind_, "-hunter");

	zoo_ = new char[100];
	strcpy(zoo_, z);
}
Lion::~Lion() {
	delete[] zoo_;
}
void Lion::Speak(){
	cout << name_ <<" say \'rrr-rrr\'("<< kind_ <<": "<< zoo_ <<")\n";
}

int main ()
{
	{	
		Animal *animals[4] = {new Dog("Jack"),
							new Cat("Murka"),
							new Frog("Bob"),
							new Lion("King", "Taiga")};
							
		for(int k=0; k<4; k++)
			animals[k]->Speak();
	}
	{
		Lion* lion = new Lion("Simba", "Africa");
		char* s = lion->zoo_;
		cout << s << endl;

		delete lion;

		cout << s << endl;
	}
	{
		Lion* lion = new Lion("Simba", "Africa");
		char* s = lion->zoo_;
		cout << s << endl;

		Animal* ptr = lion;
		delete ptr;

		cout << s << endl;
	}



	return 0;
}
