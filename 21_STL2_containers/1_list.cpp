// more examples: https://www.geeksforgeeks.org/lior-in-cpp-stl/

// #define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <list>
using namespace std;

void ShowList(list<int> li)
{
	cout << "\nlist ["<< li.size() <<"] -->\t";
	for (auto elem : li)
		cout << elem << "\t";
	
	cout << "\n-----------------------------------\n";
}
// list<int>::iterator
auto Find(list<int>& li, int val) // return auto start in c++14 std
{
	auto iter = li.begin();
	while((*iter != val) && (iter != li.end()))
		++iter;

	return iter;
}

int main()
{
	list<int> one, two, clone_one;

	for(int i = 0; i < 5; ++i)
	{
		one.push_back(i);
		two.push_front(i*2);
	}
	clone_one = one;

	cout << "List one:";
	ShowList(one);

	cout << "Reversed:";
	one.reverse();
	ShowList(one);

	cout << "\nList two:";
	ShowList(two);

	cout << "Splice in two:";
	two.splice( Find(two, 4), 	// iter of emplace ,
				one, 			// other list obj,
				Find(one, 2), 	// [ start iter,
				--(one.end())	// end iter ]
			);
	ShowList(two);
	cout << "One:";
	ShowList(one);

	cout << "\nSorted greater:";
	two.sort(std::greater<int>());
	ShowList(two);
	cout << "Less:";
	two.sort(); // default = less
	ShowList(two);

	cout << "\nMerge in two:";
	one.sort(); // now we can merge
	two.merge(one);
	ShowList(two);
	cout << "One:";
	ShowList(one);

	cout << "\nUnique:";
	two.unique();
	ShowList(two);

	cout << "\nOne in begining:";
	ShowList(clone_one);

	return 0;
}