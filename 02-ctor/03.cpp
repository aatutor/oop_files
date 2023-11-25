
struct Point {
private: 
    int x_;
    int y_;
	char* name_ = nullptr;
public: 
	Point(int x, int y, const char* name){
		name_ = new char[strlen(name)+1];
		strcpy(name_, name);
	}
	~Point() {
		delete name_;
	}
};

int main()
{
    Point* point;
	point = new Point();// Object created
	delete point;		// Object deleted

	return 0;
}