#include <iostream>
#include <string.h>
using namespace std;

fstream() - создает поток, не открывая файла;
fstream(const char* name, //имя файла
        int omode, //режим открытия
        int = filebuf::openprot //защита файла
        )// - создает поток, открывает файл и связывает его с потоком;
fstream(int f // дескриптор файла
        )// - создает поток и связывает его с уже открытым файлом
fstream(int f, //дескриптор файла
        char *buf, //буфер
        int len //размер буфера
        )// - то же, что предыдущий конструктор, но потоку назначается буфер.

void open(const char *fileName, int mode = знач_по_ум, int protection = знач_по_ум);
int close();
enum _Openmode {
    in = 0x01, //открыть только для чтения
    out = 0x02, //открыть только для записи
    ate = 0x04, //установить указатель на конец файла
    app = 0x08, //дописывать данные в конец файла
    trunc = 0x10, //усечь файл до нулевой длины 
    _Nocreate = 0x40, //если файл не существует, ошибка открытия
    _Noreplace = 0x80, //если файл уже существует, ошибка открытия
    binary = 0x20 //открыть файл для двоичного обмена
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
