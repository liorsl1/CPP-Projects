#pragma once
template<class T>
class Array
{
	int physicalSize, logicalSize;
	char delimiter;
	T** arr;
public:
	Array(int size = 10, char delimiter = '\n');
	Array(const Array& other);
	~Array();

	const Array& operator=(const Array&other);
	const Array& operator+=(const T& newVal);

	friend ostream& operator<<(ostream& os, const Array& arr) {
		for (int i = 0; i < arr.logicalSize; i++) {
			os <<i+1<<". "<<*(arr.arr[i]) << arr.delimiter;
		}
		return os;
	}
};

template<class T>
Array<T>::Array(int maxSize, char delimiter) :physicalSize(maxSize), logicalSize(0), delimiter(delimiter) {
	arr = new T*[physicalSize];
}
template<class T>
inline Array<T>::Array(const Array& other)
{
}
template <class T>
Array<T>::~Array() {
	delete[] arr;
}

template<class T>
const Array<T>& Array<T>::operator=(const Array& other) {
	if (this != &other) {
		delete[]arr;
		physicalSize = other.physicalSize;
		logicalSize = other.logicalSize;
		delimiter = other.delimiter;
		arr = new T*[physicalSize];
		for (int i = 0; i < logicalSize; i++) {
			*arr[i] = *other.arr[i];
		}
	}
	return *this;
}
template<class T>
const Array<T>& Array<T>::operator+=(const T& newVal) {
	
	if (logicalSize < physicalSize) {
		arr[logicalSize++] = new T(newVal);
	}
	else {
		T** prev;
		++physicalSize;
		physicalSize=physicalSize*2;
		prev = arr;
		arr = new T*[physicalSize];
		for (int i=0;i<logicalSize;i++)
		{
			(arr[i]) = new T(*prev[i]);
		}
		arr[logicalSize++] = new T(newVal);
	}
	return *this;
}

