#include <iostream>
using namespace std;

class File {
public:
	int stream_ = 0;
};
class InFile : public File {};
class OutFile : public File {};

class IOFile : public InFile, public OutFile {};

int main ()
{
	IOFile ioFile;
	// cout << ioFile.stream_ << endl; // fail: 'stream_' is ambiguous
	cout << ioFile.InFile::stream_ << endl;
	cout << ioFile.OutFile::stream_ << endl;

	// cout << ioFile.File::stream_ << endl; // fail too

  return 0;
}
