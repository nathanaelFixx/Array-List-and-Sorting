#ifndef ARRAYLIST_H
#define ARRAYLIST_H

#include "ListInterface.h"
#include <iostream>

template <class TYPE>
class ArrayList : public ListInterface<TYPE>
{
private:
	static const int DEFAULT_CAPACITY = 10;

	TYPE * items;
	int maxLength;
	int currentLength;
	int originalLength;
	void growArray();
	//counters//////
	static int appendCount;
	static int accessCount;
	static int swapCount;
	static int removeCount;
	static int insertCount;

public:
	ArrayList(int initialSize = DEFAULT_CAPACITY);
	ArrayList(const ArrayList & rhs);
	ArrayList<TYPE> & operator =(const ArrayList<TYPE> & rhs);
	bool isEmpty() const;
	void append(const TYPE & app);
	TYPE & operator[] (int) throw (std::out_of_range);
	int getSize() const;
	void insertAt(int index, const TYPE & newEntry) throw (std::out_of_range);
	void removeAt(int index) throw (std::out_of_range);
	TYPE & getAt(int index) throw (std::out_of_range);
	void swap(int from, int to) throw(std::out_of_range);
	void clearAll();
	~ArrayList();

	void clearStatistics();
	// Provide statistics on number of times method was performed
	int getNumAccess() const;    // operator [] OR getAt
	int getNumSwap() const;
	int getNumRemove() const;
	int getNumInsertAt() const;
	int getNumAppends() const;

};

template<class TYPE> int ArrayList<TYPE>::appendCount = 0;
template<class TYPE> int ArrayList<TYPE>::accessCount = 0;
template<class TYPE> int ArrayList<TYPE>::swapCount = 0;
template<class TYPE> int ArrayList<TYPE>::removeCount = 0;
template<class TYPE> int ArrayList<TYPE>::insertCount = 0;

#endif
