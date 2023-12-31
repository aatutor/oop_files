// #define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <iterator>
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

		copy(arr.begin(), arr.end(), ostream_iterator<int>(cout, " "));
		cout << endl;

		{
			sort(begin(arr), end(arr));

			for_each(arr.begin(), arr.end(), [](int x){
				cout << x <<" ";
			});
			cout << endl;
		}
		{
			sort(arr.begin(), arr.end(), greater<int>()); // default = std::less

			for(auto x : arr) {
				cout << x <<" ";
			}
		}
	}

	return 0;
}
