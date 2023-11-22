#include <iostream>
#include <iomanip>
#include <cstring>
using namespace std;

const int MAX_LEN_NAME = 20;
const int MARK_COUNT = 3;     

struct Student 
{
    char name_[MAX_LEN_NAME]; // ФИО
    int marks_[MARK_COUNT];   // оценки
};
void InitStudent(Student&, const char*, const int []);
double AverageMark(Student);
void PrintStudent(Student);

int main()
{
    cout << "Student profile."
        << endl << endl;

    Student student;
    const char* studentName{ "Petrov A.O." };
    int studentMarks[]{ 4,4,3 };

    InitStudent(student, studentName, studentMarks);
    PrintStudent(student);
    cout << "Average mark: "
        << fixed << setprecision(2)
        << AverageMark(student) << endl;
    return 0;
}

// заполнение данных о студенте
void InitStudent(Student& student, const char* name, const int marks[])
{
    strcpy(student.name_, name);
    for (int i = 0; i < MARK_COUNT; i++)
        student.marks_[i] = marks[i];
}
// вычисление средней оценки
double AverageMark(Student student)
{
    double sum = 0;
    for (int i = 0; i < MARK_COUNT; i++)
        sum += student.marks_[i];
    return sum / MARK_COUNT;
}
// вывод данных о студенте
void PrintStudent(Student student)
{
    cout << student.name_ << endl;
    cout << "Marks: ";
    for (int i = 0; i < MARK_COUNT; i++)
        cout << setw(4) << student.marks_[i];
    cout << endl;
}