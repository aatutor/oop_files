#include <iostream>
#include <iomanip>
#include <cstring>
using namespace std;

const int MAX_LEN_NAME = 20;
const int MARK_COUNT = 3;     

struct Student 
{
    char* name_; // ФИО
    int* marks_;   // оценки
	int marks_count_;

	Student();
	Student(const char*);
	Student(const char*, const int[], int);
	~Student();

	void InitStudent(const char*, const int [], int);
	double AverageMark();
	void PrintStudent();
};

int main()
{
    cout << "Student profile.\n";

    Student student;
    const char* studentName{ "Petrov A.O." };
    int studentMarks[]{ 4,4,3 };

    student.InitStudent(studentName, int[]{1, 2 ,3}, 3);
    student.PrintStudent();
    cout << "Average mark: "
        << fixed << setprecision(2)
        << student.AverageMark() << endl;
    return 0;
}

Student::Student(): Student("Ivan") {}
Student::Student(const char* name): Student(name, {}, 0) {}
Student::Student(const char* name, const int marks[], int count){
	InitStudent(name, marks, count);
}
Student::~Student(){
	delete [] name_;
}

// заполнение данных о студенте
void Student::InitStudent(const char* name, const int marks[], int count)
{
	marks_count_ = count;
	if (name_ == nullptr)
		name_ = new char[strlen(name)+1];

	if (strlen(name_)>=strlen(name))
	    strcpy(name_, name);

    for (int i = 0; i < marks_count_; i++)
        marks_[i] = marks[i];
}
// вычисление средней оценки
double Student::AverageMark()
{
    double sum = 0;
    for (int i = 0; i < marks_count_; i++)
        sum += marks_[i];
    return sum / marks_count_;
}
// вывод данных о студенте
void Student::PrintStudent()
{
    cout << name_ << endl;
    cout << "Marks: ";
    for (int i = 0; i < marks_count_; i++)
        cout << setw(4) << marks_[i];
    cout << endl;
}