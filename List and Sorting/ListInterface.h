#ifndef LISTINTERFACE_H
#define LISTINTERFACE_H

#include <stdexcept>

template < class TYPE>
class  ListInterface {
public:
	// Note this one is not a pure virtual.
	virtual ~ListInterface() { }
	// The easy way to access an element
	virtual TYPE & operator[] (int) throw (std::out_of_range) = 0;
	// Tell of it is empty
	virtual bool isEmpty() const = 0;
	// Return the number of elements in the list
	virtual int getSize() const = 0;
	// Inserts at the location.
	virtual void insertAt(int index, const TYPE & newEntry) throw (std::out_of_range) = 0;
	// delete at location
	virtual void removeAt(int index) throw (std::out_of_range) = 0;
	// Append to end
	virtual void append(const TYPE & app) = 0;
	virtual void swap(int from, int to) throw(std::out_of_range) = 0;
	// Get an item at location
	virtual TYPE & getAt(int index) throw (std::out_of_range) = 0;
	// Clear everything
	virtual void clearAll() = 0;
	 //clear out any instrumentation
	virtual void clearStatistics() = 0;
	// provide statistics on number of times method was performed
	virtual int getNumAccess() const = 0;    // operator [] or getAt
	virtual int getNumSwap() const = 0;
	virtual int getNumRemove() const = 0;
	virtual int getNumInsertAt() const = 0;
	virtual int getNumAppends() const = 0;
};
#endif












