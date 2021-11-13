/*
//https://www.geeksforgeeks.org/random-number-generator-in-arbitrary-probability-distribution-fashion/
//C program to generate random numbers according to given frequency distribution
#include <stdio.h>
#include <stdlib.h>

// Utility function to find ceiling of r in arr[l..h]
int findCeil(int arr[], int r, int l, int h)
{
	int mid;
	while (l < h)
	{
		mid = l + ((h - l) >> 1); // Same as mid = (l+h)/2
		(r > arr[mid]) ? (l = mid + 1) : (h = mid);
	}
	return (arr[l] >= r) ? l : -1;
}

// The main function that returns a random number from arr[] according to
// distribution array defined by freq[]. n is size of arrays.
int myRand(int arr[], int freq[], int n)
{
	// Create and fill prefix array
	int prefix[n], i;
	prefix[0] = freq[0];
	for (i = 1; i < n; ++i)
		prefix[i] = prefix[i - 1] + freq[i];

	// prefix[n-1] is sum of all frequencies. Generate a random number
	// with value from 1 to this sum
	int r = (rand() % prefix[n - 1]) + 1;

	// Find index of ceiling of r in prefix array
	int indexc = findCeil(prefix, r, 0, n - 1);
	return arr[indexc];
}

// Driver program to test above functions
int main()
{
	int arr[] = {1, 2, 3, 4};
	int freq[] = {10, 5, 20, 100};
	int i, n = sizeof(arr) / sizeof(arr[0]);

	// Use a different seed value for every run.
	srand(time(NULL));

	// Let us generate 10 random numbers according to
	// given distribution
	for (i = 0; i < 5; i++)
	printf("%d\n", myRand(arr, freq, n));

	return 0;
}

*/
typedef struct {
    int* prob;
    int size; 
} Solution;


Solution* solutionCreate(int* w, int wSize) {
    
    Solution* obj = (Solution*)calloc(1, sizeof(Solution));
    if(obj == NULL || w == NULL)
        return NULL; 
    obj->prob = (int*)calloc(wSize, sizeof(int));
    if(obj->prob == NULL)
        return NULL; 
    obj->prob[0] = w[0];
    for(int i=1; i< wSize; i++)
        obj->prob[i] = w[i] +  obj->prob[i-1];
    obj->size = wSize; 
    srand(time(0));
    
    return obj; 
}
int findCeil(int* arr, int r, int l, int h)
{
    int mid;
    while (l < h)
    {
         mid = l + ((h - l) >> 1);  // Same as mid = (l+h)/2
        (r > arr[mid]) ? (l = mid + 1) : (h = mid);
    }
 return (arr[l] >= r) ? l : -1;
}
int solutionPickIndex(Solution* obj) {
    
    if(obj == NULL)
        return -1; 
  
    int r = (rand() % obj->prob[obj->size - 1]) +1 ;
    
     int indexc = findCeil(obj->prob, r, 0, obj->size);
    
    return indexc;
}

void solutionFree(Solution* obj) {
    
    if(obj == NULL)
        return ; 
    
    free(obj->prob);
    
    free(obj);
    
}

/**
 * Your Solution struct will be instantiated and called as such:
 * Solution* obj = solutionCreate(w, wSize);
 * int param_1 = solutionPickIndex(obj);
 
 * solutionFree(obj);
*/
