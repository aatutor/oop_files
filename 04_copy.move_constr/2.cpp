class Empty {
	Empty();	// ctor
	~Empty();	// dtor
	Empty(Empty& ptr);// copy ctor
	Empty& operator= (const Empty& ptr); // copy optor
}
{
	Empty x; Empty y(x); x = y;
}	// auto-delete x, y
