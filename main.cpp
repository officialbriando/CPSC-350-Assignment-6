//Author: Brian Do

#include <iostream>
#include <fstream>
#include <string>
#include <ctime>
#include "SortAlgorithms.h"

using namespace std;

int main(int argc, char ** argv)
{
	if(argc < 2)
	{
		cout << "You did not give a file name." << endl;
		return 0;
	}

	int length = 0;

	string fileName = argv[1];

	//Counts every double in the text file.
	ifstream inputStream;
	inputStream.open(fileName.c_str());

	double placeholder;

	while(inputStream >> placeholder)
	{
		length++;
	}

	inputStream.close();
	cout << "Number of doubles in file: " << length << endl;


	//Creates an array to match the number of doubles.
	double myArray[length];					
	int index = 0;

	//Inputs all doubles into the array.
	inputStream.open(fileName.c_str());
	while(inputStream >> placeholder)
	{
		myArray[index++] = placeholder;		
	}

	/*cout << "Doubles in file: " << endl << endl;
	for(int i = 0; i < length; ++i)
	{
		cout << myArray[i] << " ";
	}
	cout << endl;*/


	//Copies array into two more for sorting purposes.
	double myArray2[length];
	double myArray3[length];

	for(int i = 0; i < length; ++i)
	{
		myArray2[i] = myArray[i];
		myArray3[i] = myArray[i];
	}


	//Running sorting algorithms.
	SortAlgorithms<double> sortAlgos;

	cout << "Algorithm: Insertion Sort" << endl;
	clock_t startTime = clock();
	sortAlgos.InsertionSort(myArray, length);
	clock_t endTime = clock();

	cout << "Start time: " << startTime << endl
		<< "End time: " << endTime << endl
		<< "Time in seconds: " << ((endTime - startTime)/(double)CLOCKS_PER_SEC) << endl << endl;



	cout << "Algorithm: QuickSort" << endl;
	startTime = clock();
	sortAlgos.QuickSort(myArray2, 0, length - 1);
	endTime = clock();

	cout << "Start time: " << startTime << endl
		<< "End time: " << endTime << endl
		<< "Time in seconds: " << ((endTime - startTime)/(double)CLOCKS_PER_SEC) << endl << endl;

	

	cout << "Algorithm: ShellSort" << endl;
	startTime = clock();
	sortAlgos.ShellSort(myArray3, length);
	endTime = clock();

	cout << "Start time: " << startTime << endl
		<< "End time: " << endTime << endl
		<< "Time in seconds: " << ((endTime - startTime)/(double)CLOCKS_PER_SEC) << endl << endl;

	return 0;
}
