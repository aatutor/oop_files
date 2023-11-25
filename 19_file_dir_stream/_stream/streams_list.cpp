#include <iostream>
#include <string.h>
using namespace std;

fstream() - ������� �����, �� �������� �����;
fstream(const char* name, //��� �����
        int omode, //����� ��������
        int = filebuf::openprot //������ �����
        )// - ������� �����, ��������� ���� � ��������� ��� � �������;
fstream(int f // ���������� �����
        )// - ������� ����� � ��������� ��� � ��� �������� ������
fstream(int f, //���������� �����
        char *buf, //�����
        int len //������ ������
        )// - �� ��, ��� ���������� �����������, �� ������ ����������� �����.

void open(const char *fileName, int mode = ����_��_��, int protection = ����_��_��);
int close();
enum _Openmode {
    in = 0x01, //������� ������ ��� ������
    out = 0x02, //������� ������ ��� ������
    ate = 0x04, //���������� ��������� �� ����� �����
    app = 0x08, //���������� ������ � ����� �����
    trunc = 0x10, //����� ���� �� ������� ����� 
    _Nocreate = 0x40, //���� ���� �� ����������, ������ ��������
    _Noreplace = 0x80, //���� ���� ��� ����������, ������ ��������
    binary = 0x20 //������� ���� ��� ��������� ������
};

istream& amp; istream::read(unsigned char *buf, int len);
istream& amp; istream::read(signed char *buf, int len);
ostream& amp; osteram::write(const unsigned char *buf, int n);
ostream& amp; osteram::write(const signed char *buf, int n);

int istream::get();
istream& istream::get(unsigned char&);
istream& istream::get(signed char&);
ostream& ostream::put(char);

istream& istream::get(unsigned char *buf, int n, char c = '\n');
istream& istream::get(signed char *buf, int n, char c = '\n');

istream& istream::getline(unsigned char *buf, int n, char c = '\n');
istream& istream::getline(signed char *buf, int n, char c = '\n');

istream& istream::ignore(int n = 1, int d = EOF);

int istream::gcount();

int istream::peek();

istream& istream::putback(char cc);

istream& istream::seekg(long pos);
istream& istream::seekg(long off, ios::seek_dir dir);
ostream& ostream::seekp(long pos);
ostream& ostream::seekp(long off, ios::seek_dir dir);

long istream::tellg();
long ostream::tellp();

int main ()
{
    return 0;
}
