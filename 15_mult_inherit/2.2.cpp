#include <iostream>
using namespace std;

class File {
public:
	int stream_ = 0;
};
class InFile : public File {
	public: InFile() { stream_ = 1; }
};
class OutFile : public File {
	public: OutFile() { stream_ = 2; }
};

class IOFile : public InFile, public OutFile {};

int main ()
{
	IOFile ch;
	cout << ch.InFile::stream_ << endl;
	cout << ch.OutFile::stream_ << endl;

	return 0;
}
