#include <iostream>
using namespace std;

template <typename T, int size_>
class Array {
	T arr_[size_];
public:
	Array(initializer_list<T> list){
		// 1 var
		if (list.size() == size_){
			int i = 0;
			for(T elem : list)
				arr_[i++] = elem;
		}
		else {
			cout << "Error: not valid size\n";
		}
		// 2 var
		int size = list.size() > size_ ? size_ : list.size();
		auto* pElem = list.begin();
		for(int i = 0; i < size; i++, pElem++)
		{
			arr_[i] = *pElem;
		}
		if (list.size() != size_) 
			cout <<	"not full initializing\n";
	}
	void Sort(){
		for (int k = size_ - 1; k > 0; k--)
			for (int j = 0; j < k; j++)
				if (arr_[j] > arr_[j + 1])
					swap(arr_[j], arr_[j + 1]);
	}
	void Print() {
		for(int i = 0; i < size_; i++)
			cout << arr_[i] <<" ";
		cout << endl;
	}
};

int main ()
{
	Array<int> arr5({1,2,3,4,5});
	arr5.Print();

    return 0;
}
