// https://metanit.com/cpp/tutorial/16.5.php

// #define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>
#include <vector>
#include <algorithm> // sort, copy, for_each, greater...
#include <iterator>  // ostream_iterator
using namespace std;

int main ()
{
	{
		string line{"hello world"};
		cout <<"Source string: |"<< line <<"|\n";

		sort(line.begin(), line.end());
		cout <<"sorted: |"<< line <<"|\n\n";
	}
	{
		vector<int> arr{3, 5, 1, 8, -20};

		{
			for(auto x : arr) {
				cout << x <<" ";
			}
			cout << endl;
		}
		{
			sort(begin(arr), end(arr));

			for_each(arr.begin(), arr.end(), [](int x){
				cout << x <<" ";
			});
			cout << endl;
		}
		{
			sort(arr.begin(), arr.end(), greater<int>()); // default = std::less - функторы/предикаты

			copy(arr.begin(), arr.end(), ostream_iterator<int>(cout, " "));
			cout << endl;
		}
	}

	return 0;
}
