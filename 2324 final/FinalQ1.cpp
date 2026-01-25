#include <iostream>
#include <fstream>
using namespace std;
// Function Prototype
int *anotherArray(int[], int);
void displayArray(int[], int);
//Function Main
int main()
{
	// Declaration
	const int SIZE = 25;
	int values[SIZE];
	int n;
	// The Input Data
	cin >> n;
	if (n<=0 || n>=SIZE)
		return 0;
	// File Processing
	ifstream inFile;
	inFile.open("input.dat");
	for (int k=0; k<n; k++)
		inFile >> values[k];// Reading from File
	inFile.close();
	// Declare and create another array
	int *arrCopy = anotherArray(values, n);
	// Display the contents of the new array.
	displayArray(arrCopy, n*2);
	return 0;
}
//Create Another Function
int *anotherArray(int arr[], int size)
{
	// Verify the size value
	if (size <= 0)
		return NULL;
	// Declare and create triple size of a new array
	int *copy = new int[size*3];
	// Copy the value to the new array
	for (int index = 0; index < size; index++)
		copy[index] = arr[index];
	// Assign the remaining elements to 0
	for (int index = size; index < size * 3; index++)
		copy[index] = 0;
	// Return a pointer to the new array.
	return copy;
}
//Create Display Function
void displayArray(int arr[], int size)
{
	for (int index = 0; index < size; index++)
		cout << arr[index] << endl;
}
