#include <iostream>
using namespace std;

class Animal {
	char name[100];
public:
	
}

class File {
public:
	int stream_ = 0;
};
class InFile : public virtual File {
	public: InFile() { stream_ = 1; }
};
class OutFile : public virtual File {
	public: OutFile() { stream_ = 2; }
};

class IOFile : public InFile, public OutFile {};

int main ()
{
	IOFile file;
	cout << file.stream_ << endl; // ok
	cout << file.InFile::stream_ << endl;
	cout << file.OutFile::stream_ << endl;

	cout << file.File::stream_ << endl; // ok

	return 0;
}
