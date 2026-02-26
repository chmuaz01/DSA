#include<iostream>
#include<string>
using namespace std;
template<typename T>
int linearSearch(T Array[], T intKey, int Size) {

	for (int i = 0; i < Size; i++)
	{
		if (Array[i] == intKey) {
			return i;
		}
	}

	return -1;
}

template<typename T, typename T1>
void printSearchResult(T intIndex, T1 intKey) {
	cout << " The Element " << intKey << " is Found at Index " << intIndex << endl;
}

int main() {
	// Test with an integer array of size 5 int 
	int intArray[5] = {64, 25, 12, 22, 11};
	int intKey = 12;
	int intSize = 5;
	int intIndex = linearSearch(intArray, intKey, intSize);
	printSearchResult(intIndex, intKey);
	// Test with a float array of size 4
	float floatArray[4] = { 3.14, 2.71, 1.62, 0.57 }; 
	float floatKey = 1.62;
	int floatSize = 4;
	int floatIndex = linearSearch(floatArray, floatKey, floatSize); 
	printSearchResult(floatIndex, floatKey);
	// Test with a string array of size 4
	string stringArray[4] = { "apple", "orange", "banana", "grape" }; 
	string stringKey = "banana";
	int stringSize = 4;
	int stringIndex = linearSearch(stringArray, stringKey, stringSize); 
	printSearchResult(stringIndex, stringKey);
	return 0;
}