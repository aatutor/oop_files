#include <iostream>
using namespace std;

class File {
public:
	int stream_ = 0;
};
class InFile : public virtual File {
public: 
	int input_ = 10;
	InFile() { stream_ = 1; }
};
class OutFile : public virtual File {
public: 
	int output_ = 20;
	OutFile() { stream_ = 2; }
};

class IOFile : public InFile, public OutFile {};

int main ()
{
	IOFile file;
	cout << file.stream_ << endl; // 2
	cout << file.input_ << endl; // 10
	cout << file.output_<< endl; // 20
	cout << file.InFile::stream_ << endl; // 2
	cout << file.OutFile::stream_ << endl; // 2

	cout << file.File::stream_ << endl; // 2

	return 0;
}
