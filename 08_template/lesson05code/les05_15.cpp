// les05_15
#include <iostream>
#include <string>
#include <conio.h>
using namespace std;

int main()
{
    std::cout << "Stirngs" << endl << endl;

    //            01234567890123456789
    //string text{ "this is a c++ string" };
    //char carr[10]{ 0 };
    //text.copy(carr, 8, 5);
    //cout << " " << carr << endl;

    //cout << " " << text.substr(5, 9) << endl;
    //cout << " " << text.substr(5) << endl;
    //cout << " " << text << endl;

    //if (str.empty())
    //{
    //    cout << "No content" << endl;
    //}
    
    string piIs = "Pi is " + to_string(3.1415926);
    cout << " " << piIs << endl;

    /*string orbits("365.24 29.53");
    unsigned int sz;

    double earthTurn = stod(orbits, &sz);
    double moonTurn = stod(orbits.substr(sz));
    cout << "  The moon completes " << (earthTurn / moonTurn) << " orbits per Earth year" << endl;

    *///string text1{ "129" };
    //unsigned int number1 = stoul(text1);
    //unsigned long number1 = stoul(text1);
    //cout << " " << number1 << endl;
    //


    //unsigned int pos;
    //string text2{ "124,8" };
    //int number2 = stoi(text2, &pos);
    //cout << " " << number2 << endl;
    //cout << " " << pos << endl;

    //string text3{ "1248" };
    //int number3 = stoi(text3, &pos, 8);
    //cout << " " << number3 << endl;
    //cout << " " << pos << endl;

    //string text{ "this is a c++ string" };
    //string str{ "abcdef" };
    //string none;
    //cout << " " << text.length() << endl;
    //cout << " " << text.size() << endl;
    //cout << " " << text.capacity() << endl;
    //cout << " " << text.max_size() << endl;

    //cout << " " << str.length() << endl;
    //cout << " " << str.capacity() << endl;
    //cout << " " << str.max_size() << endl;

    //cout << " " << none.length() << endl;
    //cout << " " << none.capacity() << endl;

    //text.reserve(8);
    //cout << text << endl;
    //cout << " " << text.capacity() << endl;

    //text.shrink_to_fit();
    //cout << " " << text.capacity() << endl;


    //string txt = text;
    //txt.replace(10, 3, str); 
    //cout << " " << txt << endl;

    //txt = text;
    //txt.replace(10, 3, str, 2, 2);
    //cout << " " << txt << endl;

    //txt = text;
    //txt.replace(10, 3, "new");
    //cout << " " << txt << endl;

    //txt = text;
    //txt.replace(10, 3, "1234", 1, 2);
    //cout << " " << txt << endl;

    //txt = text;
    //txt.replace(10, 3, 3, '!');
    //cout << " " << txt << endl;

    //txt = text;
    //txt.replace(txt.begin() + 10, txt.end() - 7, str);
    //cout << " " << txt << endl;

    //for (auto it = text.begin(); it < text.end(); it++)
    //{
    //    if (!isalpha(*it) && !isspace(*it))
    //    {
    //        cout << *it;
    //    }
    //}
    //cout << endl;

    //text.push_back('F');

    //text.pop_back();

    //string theStr{ "abcdef" };

    //string str = text;
    //cout << " " <<str.insert(5, theStr) << endl;

    //str = text;
    //cout << " " << str.insert(5, theStr, 2, 3) << endl;

    //str = text;
    //str.insert(str.begin() + 2, 'A');
    //cout << " " << str << endl;

    //cout << " " << text.assign(str, 3, 4) << endl;
    //cout << " " << text.assign("abcdef") << endl;
    //cout << " " << text.assign("abcdef", 2) << endl;
    //cout << " " << text.assign(5, 'a') << endl;
    //cout << " " << text << endl;
    //cout << " " << text.find_first_not_of("abcdefghijklmnopqrstuvwxyz ") << endl;
    //cout << " " << text.find_last_of("bac") << endl;

    //cout << " " << text.find("is") << endl;
    //cout << " " << text.find("is", 4) << endl;
    //cout << " " << text.rfind("is") << endl;
    //cout << " " << text.rfind("is", 4) << endl;
    //cout << " " << text.find("strong", 0, 3) << endl;
    //cout << " " << text.find("strong") << endl;

    //char stringC[]{ 'a', 'b', 'c', '\0', 'c', 'b', 'a' };
    //string stringCPP{ 'a', 'b', 'c', '\0', 'c', 'b', 'a'};

    //cout << "  |" << stringC << "|" << endl;
    //cout << "  |" << stringCPP << "|" << endl;

    //string s1;
    //string s2;
    //string s3;

    //s1 = "abc";
    //s2 = { 'x', 'y', 'z'};
    //s3 = s1;

    //cout << " " << s1 << " " << s2 << " " << s3 << endl;
    //cout << " " << (s1 == s2) << " " << (s1 != s2) << " " << (s1 < s2) << " " << (s1 >= s2) << endl;
    //cout << " " << s1 + s2 << endl;
    //s2 += s1;
    //cout << " " << s2 << endl;

    //s1.at();

    //char     ch{ 'a' };  
    //char8_t  ch8{ u8'a' };  //  требуется версия C++ 20
    //char16_t ch16{ u'a' };
    //char32_t ch32{ U'a' };
    //wchar_t  chw{ L'a' };   // нестандартный тип компилятора Microsoft

    //cout << ch << endl;
    //cout << ch8 << endl;
    //cout << ch16 << endl;
    //cout << ch32 << endl;
    //wcout << chw << endl;
    //ch = 127;
    //cout << ch << endl;

    //char text[20]{ "This a c-string" };
    //char text1[20]{ "This a string" };
    /*std::string text{ "This is a c++ string" };
    std::string aString;
    std::cout << text << endl;*/

    //string text{ "Hello" }; // строка из const char*
    //string text{ "Hello" };
    //cout << text;
    
    //string text;
    //getline(cin, text, '*');
    //cout << text << endl;
    //getline(cin, text, '*');
    //cout << text << endl;


    //string name0(8, 'a');  // строка из 8 'a' символов
    //string name( 8, 'a' );  // строка из 8 'a' символов
    //string name1(8, 'a');  // строка из 8 'a' символов
    //string name{ "1a2b3c4d5a" };
    //name.find()
    //const char* pname = name.data();
    //char& beg = name.front();
    //char& fin = name.back();
    //char c1 = name[10];
    //char c2 = name.at(10);
    //cout << c2 << endl;
    //string month = "March"; // то же, что string month{"March"};

    //cout << text.size();
    //int len = name.length();

    //cout << name << endl;
    //char ch = name[3];
    //cout << ch << endl;
    //for (int i = 0; i < name.length(); i++)
    //{
    //    cout << name[i];
    //}
    //cout << endl;
    //for (auto c : name)
    //{
    //    cout << c;
    //}
    //cout << endl;

    _getch();
    return 0;
}
