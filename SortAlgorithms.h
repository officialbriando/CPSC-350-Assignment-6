//Author: Brian Do 

using namespace std;

template<class E>

class SortAlgorithms
{
	public:
		SortAlgorithms();
		~SortAlgorithms();

		void InsertionSort(E* myArray, int length);
		void QuickSort(E* myArray, int lo, int hi);
		void ShellSort(E* myArray, int length);
};

template<class E>
SortAlgorithms<E>::SortAlgorithms()
{

}

template<class E>
SortAlgorithms<E>::~SortAlgorithms()
{
	
}

template<class E>
void SortAlgorithms<E>::InsertionSort(E* myArray, int length)
{
	for(int i = 0; i < length; ++i)
	{
		int j = i;
		while(j > 0 && myArray[j] < myArray[j-1])	//While j is greater than index 0, and the data at index j is less than the previous.
		{
			E temp = myArray[j];
			myArray[j] = myArray[j-1];				//The current index j becomes the previous value.
			myArray[j-1] = temp;					//The previous index becomes the current value.
			--j;									//Decrement j and repeat.
		}
	}
}

template<class E>
void SortAlgorithms<E>::QuickSort(E* myArray, int lo, int hi)
{
	//Partitioning the array.
	int i = lo, j = hi;
	E temp;
	int pivot = myArray[(lo + (hi - lo)) / 2]; //Takes the middle index of the array as the pivot.
	while(i <= j)
	{
		while(myArray[i] < pivot && i < hi)
		{
			i++;	//Keeps finding a value greater than the pivot on left side.
		} 
		while(myArray[j] >= pivot && j > lo)
		{
			j--;	//Keeps finding a value less than the pivot on right side.
		} 

		if(i <= j)
		{
			temp = myArray[i];			//Once out of place values are found, swaps the two values.
			myArray[i] = myArray[j];
			myArray[j] = temp;

			i++, j--;
		}
		else
		{
			if(j > lo) QuickSort(myArray, lo, j);	//Recursively calls quick sort until the positional
			if(i < hi) QuickSort(myArray, i, hi);	//indices reach the ends of the array.
		}

		//Stops once the indices pass the pivot.
	}
}

template<class E>
void SortAlgorithms<E>::ShellSort(E* myArray, int length)
{
	int j;

	for(int g = length/2; g > 0; g /= 2)	//Narrowing the array by half per iteration.
	{
		for(int i = g; i < length; ++i)
		{
			E temp = myArray[i];

			for(j = i; j >= g && temp < myArray[j - g]; j -= g)	//Compares elements which are the gap distance apart.
			{
				myArray[j] = myArray[j - g];
			}
			myArray[j] = temp;
		}
	}
}
