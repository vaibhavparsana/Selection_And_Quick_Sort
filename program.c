

#include <stdio.h>
#include <stdlib.h>
#define SIZE 1000

static int quickCnt;

// Selection sort. 

// 'a' is the array to sort.
// 'n' is the size of the array (number of items to sort).
int selectionSort(int a[], int n) {
	int i,j;
	int count;
	for ( j = 0; j < n-1; j++) {
		int iMin = j;
		for ( i = j+1; i < n; i++) {
			if (a[i] < a[iMin]) {
				iMin = i;
			}

			count++;// ***Increment your counter here

		}

		if (iMin != j) {   // Swap if needed
			int tmp = a[j];
			a[j] = a[iMin];
			a[iMin] = tmp;
		}
	}
		return count;
}

// Quicksort
// 'a' is the array to sort.
// 'low' is the first (lowest) array index to be sorted.
// 'high' is the last (highest) array index to be sorted.

int quickSort(int a[], int low, int high) {
	int i;
	if (high > low) {
		int pivot = a[high];
		int split = low;
		for ( i=low; i<high; i++) {
			if (a[i] < pivot) {   // Swap if needed
				int tmp = a[i];
				a[i] = a[split];
				a[split] = tmp;
				split++;
			}

			quickCnt++;// ***Increment your counter here

		}
		int tmp = a[high];
		a[high] = a[split];
		a[split] = tmp;

		quickSort(a, low, split-1);
		quickSort(a, split+1, high);
	}
	return quickCnt;
}

int main(int argc, char** argv) {
	
	int arr1[SIZE]; 
	int arr2[SIZE];
	int i;
	int selectionCount;
	int quickCount;
	
	
	for(i=0; i <SIZE; i++) { 
		arr1[i] = rand(); //generating random numbers
		arr2[i]= arr1[i]; // copy random numbers 
	}

	
	selectionCount = selectionSort(arr1,SIZE); // passing aar1 to selection sort in order to sort numbers
	
	quickCount= quickSort(arr2,0,SIZE-1); // passing aar2 to quick sort in order to sort numbers
	
	for(i=0;i<SIZE;i++) {
		printf("%d  ",arr1[i]); // printing selection sorted numbers
	}
	
	printf("\n\n\n");
	
	for(i=0;i<SIZE;i++) {
		printf("%d  ",arr2[i]); // printing quick sorted numbers
	}
	
	printf("\n\n\n");
	
	printf("Selection Sort Count= %d",selectionCount); // Number of operation performed by selectionSort
	printf("\nQuick Sort Count= %d",quickCount); // Number of operation performed by quickSort
		
}
