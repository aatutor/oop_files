#include <iostream>
#include <string.h>
#include <string>
using namespace std;

class Person {
	char name_[100];
	short age_;
public:
	Person(const char name[100], short age): age_(age) {
		strcpy(name_, name);
	}
	void Info() {
		using namespace std;
		cout << "\nName: " << name_ <<"\nAge: "<< age_ << endl; 
	}
};
class Student: public Person {
	int group_;
public:
	Student(const char name[100], short age, int grp): Person(name, age), group_(grp) {}
	void Info() {
		Person::Info();
		cout << "Post: Student\nGroup: "<< group_ << endl;
	}
};
class Teacher: public Person {
	char education_[50];
public:
	Teacher(const char name[100], short age, const char edu[50]): Person(name, age) {
		strcpy(education_, edu);
	}
	void Info() {
		Person::Info();
		cout << "Post: Teacher\nEducation: "<< education_ << endl;
	}
};

void Test() 
{
	using namespace std;
	{
		Teacher t("Einstein", 42, "professor");
		t.Info();
		Student s("Ivan", 20, 321);
		s.Info();
	}
	cout << string(15, '-') << endl;
	{
		Teacher* t = new Teacher("Einstein", 42, "professor");
		t->Info();
		Student* s = new Student("Ivan", 20, 321);
		s->Info();
	}
	cout << string(15, '-') << endl;
	{
		Person* pt = new Teacher("Einstein", 42, "professor");
		pt->Info();
		Person* ps = new Student("Ivan", 20, 321);
		ps->Info();
	}
	cout << string(15, '-') << endl;
	{
		Person** person = new Person*[2];

		person[0] = new Teacher("Einstein", 42, "professor");
		person[1] = new Student("Ivan", 20, 321);
		person[2] = new Person("Petrovich", 53);

		for(int i = 0; i < 3; i++)
			person[i]->Info();
	}
}

int main ()
{
	Test();

	return 0;
}
