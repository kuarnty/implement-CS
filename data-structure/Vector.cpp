#include <iostream>

using namespace std;

template <typename T>
class Vector
{
public:
	Vector(const int capacity = 16)
		: capacity_(capacity), size_(0), array_(new T[capacity])
	{
		cout << "a vector is constructed with "
			<< "capacity: " << capacity_
			<< ", size: " << size_
			<< ", type: " << typeid(T).name()
			<< endl << endl;
	}

	~Vector()
	{
		cout << "a vector will be destructed" << endl << endl;
		delete[] array_;
	}

	int size()
	{
		cout << "returned size: " << size_ << endl << endl;
		return size_;
	}

	int capacity()
	{
		cout << "returned capacity: " << capacity_ << endl << endl;
		return capacity_;
	}

	bool isEmpty()
	{
		cout << "returned whether it's empty: " << size_ == 0 << endl << endl;
		return size_ == 0;
	}

	// Insert element at specific index where already an element exists.
	// But only pushing at the end is allowed, including inserting at the end or in an empty array.
	// Resize up if size exceeds capacity
	void insert(const T element, const int index)
	{
		if (index < 0 || index > size_)
		{
			cout << "insert error: Index out of bounds!" << endl;
			cout << "size: " << size_ << ", index: " << index << endl << endl;
			return;
		}

		if (size_ == capacity_)
			resize(capacity_ * 2);

		for (int i = size_; i > index; i--)
			array_[i] = array_[i - 1];
		array_[index] = element;
		size_++;

		cout << "inserted element: " << element << " at: " << index << endl << endl;
	}

	void push(const T element)
	{
		insert(element, size_);
	}

	// Removing
	// Resize down if size is one-fourth of capacity

	void removeAt(const int index)
	{
		if (size_ == 0)
		{
			cout << "remove error: Array is empty!" << endl;
			return;
		}
		else if (index < 0 || index >= size_)
		{
			cout << "remove error: Index out of bounds!" << endl;
			cout << "size: " << size_ << ", index: " << index << endl << endl;

			return;
		}

		for (int i = index; i < size_ - 1; i++)
			array_[i] = array_[i + 1];
		size_--;

		cout << "removed at index: " << index << endl << endl;

		if (size_ <= (int)(capacity_ / 4))
		{
			resize(capacity_ / 2);
		}
	}

	void pop()
	{
		removeAt(size_ - 1);
	}

	// Searching

	// Rturen index of an element, return -1 if not found
	int findIndex(const T element)
	{
		for (int i = 0; i < size_; i++)
			if (array_[i] == element)
			{
				cout << "found element: " << element << ", at: " << i << endl << endl;
				return i;
			}
		cout << "couldn't find element: " << element << endl << endl;
		return -1; // Indicating not found
	}

	// Return element at specific index, return NULL if index is out of bounds
	T at(const int index)
	{
		if (size_ == 0)
		{
			cout << "Array is empty!" << endl << endl;
			return NULL; // Indicating error
		}
		else if (index < 0 || index >= size_)
		{
			cout << "Index out of bounds!" << endl;
			cout << "size: " << size_ << ", index: " << index << endl << endl;
			return NULL; // Indicating error
		}
		else
		{
			cout << "returned element: " << array_[index] << ", at: " << index << endl << endl;
			return array_[index];
		}
	}

private:
	T* array_;
	int capacity_;
	int size_;

	// Resize capacity of internal array
	void resize(int capacity)
	{
		const int oldCapacity = capacity_;

		T* newArray = new T[capacity];
		for (int i = 0; i < size_ && i < capacity; i++)
			newArray[i] = array_[i];
		delete[] array_;
		array_ = newArray;
		capacity_ = capacity;

		cout << "capacity resized from: " << oldCapacity << " to " << capacity_ << endl << endl;
	}
};

int main()
{
	Vector<int> arr(2);

	arr.push(10);
	arr.push(20);
	arr.push(30);

	int a = arr.at(1);

	int size = arr.size();

	arr.pop();
	arr.pop();

	return 0;
}