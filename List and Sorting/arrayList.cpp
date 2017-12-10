#include "arrayList.h"
using namespace std;

template <class TYPE>
ArrayList<TYPE>::ArrayList(int initialSize)
{
	maxLength = initialSize;
	currentLength = 0;
	items = new TYPE[initialSize];
	originalLength = initialSize;
	
}

template<class TYPE>
ArrayList<TYPE>::ArrayList(const ArrayList & rhs)
{
	items = NULL;
	*this = rhs;
}

template<class TYPE>
ArrayList<TYPE>& ArrayList<TYPE>::operator=(const ArrayList<TYPE>& rhs)
{
	if (this != &rhs) {

		if (items != NULL){
		delete[] items;
		}
		currentLength = rhs.currentLength;

		items = new TYPE[rhs.maxLength];

		for (int i = 0; i < rhs.getSize(); i++) {
			items[i] = rhs.items[i];
		}
	}

	maxLength = rhs.maxLength;

	return *this;
}

template<class TYPE>
void ArrayList<TYPE>::growArray()
{
	int newSize = maxLength * 2;
	TYPE * tempArray = new TYPE[newSize];

	for (int i = 0; i < currentLength; i++) {
		tempArray[i] = items[i];
	}
	maxLength = newSize;
	delete[] items;
	items = tempArray;
}

template<class TYPE>
bool ArrayList<TYPE>::isEmpty() const
{
	if (currentLength == 0)
		return true;

	else
	return false;
}

template<class TYPE>
void ArrayList<TYPE>::append(const TYPE & app)
{
	if (currentLength == maxLength - 1) {
		growArray();
	}

	items[currentLength] = app;
	currentLength++;
	appendCount++;
}

template<class TYPE>
TYPE & ArrayList<TYPE>::operator[](int index) throw (std::out_of_range)
{
	if (index >= currentLength || index < 0) {
		throw std::out_of_range("Invalid index on operator []");
	}
	
	accessCount++;
	return items[index];
}

template<class TYPE>
int ArrayList<TYPE>::getSize() const
{
	return currentLength;
}

template<class TYPE>
void ArrayList<TYPE>::insertAt(int index, const TYPE & newEntry) throw(std::out_of_range)
{
	if (index > currentLength || index < 0) {
		throw std::out_of_range("Invalid Index");
	}

	if (currentLength == maxLength) {
		growArray();
	}

	for (int i = currentLength - 1; i >= index; i--) {
		items[i + 1] = items[i];
	}

	items[index] = newEntry;
	currentLength++;
	insertCount++;
}

template<class TYPE>
void ArrayList<TYPE>::removeAt(int index) throw(std::out_of_range)
{
	if (index >= currentLength || index < 0) {
		throw std::out_of_range("Invalid index on remove");
	}

	for (int i = index; i <= currentLength; i++) {
		items[i] = items[i + 1];
	}

	currentLength--;
	removeCount++;
}

template<class TYPE>
TYPE & ArrayList<TYPE>::getAt(int index) throw(std::out_of_range)
{
	if (index >= currentLength || index < 0) {
		throw std::out_of_range("Invalid index on Get");
	}
	
	accessCount++;
	return items[index];
}

template<class TYPE>
void ArrayList<TYPE>::swap(int from, int to) throw(std::out_of_range)
{
	TYPE temp;

	if (from >= currentLength || from < 0 || to >= currentLength || to < 0) {
		throw std::out_of_range("Invalid index on Get");
	}

	temp = items[to];
	items[to] = items[from];
	items[from] = temp;
	
	swapCount++;
}

template<class TYPE>
void ArrayList<TYPE>::clearAll()
{
	delete[] items;
}

template <class TYPE>
ArrayList<TYPE>::~ArrayList()
{
	delete[] items;
	
}

template<class TYPE>
void ArrayList<TYPE>::clearStatistics()
{
	accessCount = 0;
	swapCount = 0;
	removeCount = 0;
	insertCount = 0;
	appendCount = 0;
}

template<class TYPE>
int ArrayList<TYPE>::getNumAccess() const
{
	return accessCount;
}

template<class TYPE>
int ArrayList<TYPE>::getNumSwap() const
{
	return swapCount;
}

template<class TYPE>
int ArrayList<TYPE>::getNumRemove() const
{
	return removeCount;
}

template<class TYPE>
int ArrayList<TYPE>::getNumInsertAt() const
{
	return insertCount;
}

template<class TYPE>
int ArrayList<TYPE>::getNumAppends() const
{
	return appendCount;
}


