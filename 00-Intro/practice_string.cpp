#include <iostream>
#include <string> // включить класс string

int main()
{
    using namespace std; // + std::string

    string h {"Hello"};    
    string w = "world";
    string str = h;
    
    str += " " + w + "!";

    cout << str << endl;
    cout << str.size() << endl;

	return 0;
}
