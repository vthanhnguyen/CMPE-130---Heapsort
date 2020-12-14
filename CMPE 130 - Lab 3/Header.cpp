#include "Header.h"

bool binaryTree::isMaxHeap(int arr[], int size)
{
	bool leftChild, rightChild;
	for (int i = 0; i <= (size / 2); i++)
	{
		leftChild = rightChild = false;
		if (i == 0)//Starting the array at index 0, where 0 is the max num
		{
			//Check if the branches are present or not
			if (arr[1] != NULL)
				leftChild = true;
			if (arr[2] != NULL)
				rightChild = true;

			//If both branches have a value then check if it qualifies
			if (leftChild == true && rightChild == true)
				if (arr[i] < arr[1] && arr[i] < arr[2])
					return false; //if the parent is less than either child then return false its not a heap
		}
		else
		{
			//check the next index and see if they have a child
			if (arr[2 * i] != NULL) //left child of index  i = 2*n
				leftChild = true;
			if (arr[2 * i + 1] != NULL) //right child index of i = 2*n+1
				rightChild = true;
			
			// Check if both branches have a value then check if it qualifies
			if (leftChild == true && rightChild == true)
				if (arr[i] < arr[2 * i] && arr[2 * i + 1] < arr[2])
					return false;//if the parent is less than either child then return false its not a heap

			// Check if there is only one child and check if parent is less than child
			if (leftChild == true && rightChild == true)
				if (arr[i] < arr[2 * i])
					return false;
		}
	}


	return true;
}

bool binaryTree::isMinHeap(int arr[], int size)
{

	bool leftChild, rightChild;
	for (int i = 0; i <= (size / 2); i++)
	{
		leftChild = rightChild = false;
		if (i == 0)//Starting the array at index 0, where 0 is the max num
		{
			//Check if the branches are present or not
			if (arr[1] != NULL)
				leftChild = true;
			if (arr[2] != NULL)
				rightChild = true;

			//If both branches have a value then check if it qualifies
			if (leftChild == true && rightChild == true)
				if (arr[i] > arr[1] && arr[i] > arr[2])
					return false; //if the parent is greater than either child then return false its not a heap
		}
		else
		{
			//check the next index and see if they have a child
			if (arr[2 * i] != NULL) //left child of index  i = 2*n
				leftChild = true;
			if (arr[2 * i + 1] != NULL) //right child index of i = 2*n+1
				rightChild = true;

			// Check if both branches have a value then check if it qualifies
			if (leftChild == true && rightChild == true)
				if (arr[i] > arr[2 * i] && arr[2 * i + 1] > arr[2])
					return false;//if the parent is greater than either child then return false its not a heap

			// Check if there is only one child and check if parent is less than child
			if (leftChild == true && rightChild == true)
				if (arr[i] > arr[2 * i])
					return false;
		}
	}
	return true;
}
