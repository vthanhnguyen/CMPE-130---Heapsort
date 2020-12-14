
/**
*   Author: Thanh Nguyen
*   Date:   09/16/2020
*   This website was used to track the function of time for each function.
*   https://stackoverflow.com/questions/22387586/measuring-execution-time-of-a-function-in-c
*/

#include "Header.h"
#include <chrono> //used for function time

void heapify(int arr[], int size, int index)
{
    int largest = index; //largest as root
    int l = 2 * index + 1; // left child
    int r = 2 * index + 2; //right child

    if (l < size && arr[l] > arr[largest]) //if left child is larger than parent
        largest = l;
    if (r < size && arr[r] > arr[largest]) //if right child is larger than parent
        largest = r;

    if (largest != index) //if largest is not the in the postion of largest parent
    {
        swap(arr[index], arr[largest]);
        heapify(arr, size, largest); //recursively headpify the affected sub tree
    }
}
void heapSort(int arr[], int size)
{
    for (int i = size / 2 - 1; i >= 0; i--)
        heapify(arr, size, i);

    for (int i = size - 1; i > 0; i--)
    {
        swap(arr[0], arr[i]);
        heapify(arr, i, 0);
    }
}
void merge(int arr[], int firstIndex,int midIndex, int lastIndex)
{
    int i,j,k;
    int temp[10000];
    
    i= firstIndex;
    k = firstIndex;
    j = midIndex + 1;

    while (i < midIndex && j < lastIndex) 
    {
        if (arr[i] <= arr[j])
        {
            temp[k] = arr[i];
            k++;
            i++;
        }
        else
        {
            temp[k] = arr[j];
            k++;
            j++;
        }
    }

    while (i <= midIndex)
    {
        temp[k] = arr[i];
        k++;
        i++;
    }
    while (j <= lastIndex)
    {
        temp[k] = arr[j];
        k++;
        j++;
    }
    for (i = firstIndex; i < k; i++)
    {
        arr[i] = temp[i];
    }

}
void mergeSort(int arr[], int firstIndex, int lastIndex)
{
    int mid;
    if (firstIndex < lastIndex)
    {
        int midIndex = (firstIndex + lastIndex) / 2;
        mergeSort(arr, firstIndex, midIndex);//creating left array
        mergeSort(arr, midIndex + 1, lastIndex);//creating right array

        merge(arr, firstIndex, midIndex, lastIndex);
    }
}




int main()
{
    const int size = 1000;
    int arr[size]; //dynamically allocated array of declared size

    auto t1 = std::chrono::high_resolution_clock::now(); //from web
    for (int i = 0; i < 10000; i++) //loop that repeats 1000 times
    {
        for (int j = 0; j < size; j++) //loop that creates 100,000 random num and store it inside arr
            arr[j] = rand();
        heapSort(arr, size);
    }
    auto t2 = std::chrono::high_resolution_clock::now(); // from web
    auto duration1 = std::chrono::duration_cast<std::chrono::seconds>(t2 - t1).count(); //from web
    cout << "The duration for heap sort: " << duration1 << " seconds" << endl;



    auto t3 = std::chrono::high_resolution_clock::now(); //from web
    for (int i = 0; i < 10000; i++) //loop that repeats 1000 times
    {
        for (int j = 0; j < size; j++) //loop that creates 100,000 random num and store it inside arr
            arr[j] = rand();
       mergeSort(arr,0, size);
    }
    auto t4 = std::chrono::high_resolution_clock::now(); // from web
    auto duration2 = std::chrono::duration_cast<std::chrono::seconds>(t4 - t3).count(); //from web
    cout << "The duration for merge sort: " << duration2 << " seconds" << endl;

    return 0;
}

