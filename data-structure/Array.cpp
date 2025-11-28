#include <iostream>

using namespace std;

int main()
{
	const int size = 5;
	int arr[size];

	arr[0] = 10;
	arr[1] = 20;

	cout << "Element at index 0: " << arr[0] << endl; // print 10
	cout << "Element at index 1: " << arr[1] << endl; // print 20
	cout << endl;

	cout << "Element at index 2: " << arr[2] << endl; // not assigned -> print garbage value(usually 0)
	arr[2] = 40; // assign value to index 2
	cout << "Element at index 2: " << arr[2] << endl; // print 40

	cout << arr[5];
	// the size of array is 5, so index range is 0 to 4.
	// The index 5 is out of bounds -> IDE may give warning
	// If code is executed, it may print garbage value or may cause runtime error.

	return 0;
}