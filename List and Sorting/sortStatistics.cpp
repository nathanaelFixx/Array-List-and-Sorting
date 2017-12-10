//__________________________
//Nathanael Fixx
//CSS 342 - Project 5
//23 hours
//Cygwin
//__________________________

#include <iostream>
#include "arrayList.h"
#include "arrayList.cpp"
#include <fstream>
#include <iomanip>

void selectionSort(ArrayList<int>&test);
void merge(ArrayList<int>&test2, int left, int mid, int right, 
		ArrayList<int>&temp);
void mergeSort(ArrayList<int>& test2, int left, int right,
	       	ArrayList<int>&temp);
void quickSort(ArrayList<int>& test3, int left, int right);
int getWall(ArrayList<int>& test3, int left, int right);
void output(ArrayList<int>&test);

using namespace std;

int main(int argc, char *argv[])
{

	ifstream fin;
	int fill;
	ArrayList<int>test;
	ArrayList<int>test2;
	ArrayList<int>test3;
	string check(argv[1]);

	if (check == "-d"){
	    string filename(argv[2]);
	    fin.open(filename);
	}

	else {
	     string filename(argv[1]);
	     fin.open(filename);
	}

	while (fin >> fill) {
		test.append(fill);
		test2.append(fill);
		test3.append(fill);
	}

//___________________________________________
//Selection Sort
	selectionSort(test);
	int selectionAccess = test.getNumAccess();
	int selectionSwap = test.getNumSwap();
	int selectionRemove = test.getNumRemove();
	int selectionInsert = test.getNumInsertAt();
	int selectionAppend = test.getNumAppends();
	test.clearStatistics();
//___________________________________________

//___________________________________________
//Merge Sort
	int left = 0;
	int right = test2.getSize() - 1;
	ArrayList<int>temp(test2.getSize());
	mergeSort(test2, left, right, temp);
	int mergeAccess = test2.getNumAccess();
	int mergeSwap = test2.getNumSwap();
	int mergeRemove = test2.getNumRemove();
	int mergeInsert = test2.getNumInsertAt();
	int mergeAppend = test2.getNumAppends();
	test.clearStatistics();
//___________________________________________

//___________________________________________
//Quick Sort
	quickSort(test3, left, right);
	int quickAccess = test3.getNumAccess();
	int quickSwap = test3.getNumSwap();
	int quickRemove = test3.getNumRemove();
	int quickInsert = test3.getNumInsertAt();
	int quickAppend = test3.getNumAppends();
	test.clearStatistics();
//___________________________________________
	

	string checkName(argv[1]);

	if (checkName == "-d") {
	cout << endl << "Filename: " << argv[2] << endl;
	}

	else {
		cout << endl << "Filename: " << argv[1] << endl;
	}

	cout << "Number of Elements: " << test.getSize() << endl;
	
  if (check == "-d"){
	cout << endl << "Selection Sort:" << endl;
	output(test);
	cout << "Merge Sort:" << endl;
	output(test2);
	cout << "Quick Sort:" << endl;
	output(test3);
	
  }

	cout << "Access: " << "Selection = " << selectionAccess;
	cout << "  " << "Merge = ";
	cout << mergeAccess << "     " << "Quick = " << quickAccess << endl;
	
	cout << "Swap:   " << "Selection = " << selectionSwap << "   "; 
	cout << "Merge = ";
	cout << mergeSwap << "        " << "Quick = " << quickSwap << endl;
	
	cout << "Remove: " << "Selection = " << selectionRemove << "     "; 
	cout << "Merge = ";
	cout << mergeRemove << "     " << "Quick = " << quickRemove << endl;
	
	cout << "Insert: " << "Selection = " << selectionInsert << "     "; 
	cout << "Merge = ";
	cout << mergeInsert << "     " << "Quick = " << quickInsert << endl;

	cout << "Append: " << "Selection = " << selectionAppend << "     ";
	cout << "Merge = ";
	cout << mergeAppend << "        " << "Quick = " << quickAppend << endl;
	cout << endl << endl;

    return 0;
}

//_____________________________________________________________________________
//Selection Sort
//
//First the highest item in the list is found and it is swapped with the item
//in the last spot of the list. Then the second highest item is found and that
// is swapped with the item in the second to last spot in the list and so on
// until the list is sorted.  
//_____________________________________________________________________________
void selectionSort(ArrayList<int> &test)
{

	int highest = 0;
	int highIndex = 0;
	int looped = 0; //how many times we have looped

	while (test.getSize() - looped > 0) {

		for (int i = 0; i < test.getSize() - looped; i++) {
			if (test[i] >= highest) {
				highest = test[i];
				highIndex = i;

			}
		}

		test.swap(highIndex, test.getSize() - looped - 1);
		looped++;
		highest = 0;
	}
}

//____________________________________________________________________
//Merge Sort
//
//The list is first split in half recursively until there are only 
//single elements left. The single elements are sorted until the
// whole list is sorted.
//____________________________________________________________________
void merge(ArrayList<int>& test2, int left, int mid, int right, 
		ArrayList<int>&temp)
{
	
	for (int i = left; i <= right; i++) {
		if (i < temp.getSize()) {
			temp.removeAt(i);
		}
		temp.insertAt(i, test2[i]);
		
	}

	int i = left;
	int j = mid + 1;
	int k = left;

	while (i <= mid && j <= right) {
		if (temp[i] <= temp[j]) {
			test2.removeAt(k);
			test2.insertAt(k, temp[i]);
			i++;
		}
		else {
			test2.removeAt(k);
			test2.insertAt(k, temp[j]);
			j++;
		}
		k++;
	}
	
	while (i <= mid) {
		test2.removeAt(k);
		test2.insertAt(k, temp[i]);
		k++;
		i++;
	}

}
//_____________________________________________________________________________
//recursive part for merge
void mergeSort(ArrayList<int>& test2, int left, int right, ArrayList<int>&temp)
{
	if (left < right) {
 
		int mid = left + (right - left) / 2;
		mergeSort(test2, left, mid, temp);
		mergeSort(test2, mid + 1, right, temp);
		
		merge(test2, left, mid, right, temp);
	}

}

//______________________________________________________________________
//Quick Sort
//______________________________________________________________________
int getWall(ArrayList<int>& test3, int left, int right)
{
	int pivot = test3[right];
	int i = (left - 1);

	for (int j = left; j <= right - 1; j++) {
		if (test3[j] <= pivot)
		{
			i++;
			test3.swap(i, j);
		}
	}
	test3.swap(i + 1, right);
	return (i + 1);
}

//______________________________________________________________
//recursive part for quick
void quickSort(ArrayList<int>& test3, int left, int right)
{
	if (left < right)
	{
		int wall = getWall(test3, left, right);

		quickSort(test3, left, wall - 1);
		quickSort(test3, wall + 1, right);
	}
}


//__________________________________
//Prints out the array list
void output(ArrayList<int>&test)
{

	for (int i = 0; i < test.getSize(); i++) {
		cout << test[i] << "|";
	}
	cout << endl << endl;

}
//__________________________________
