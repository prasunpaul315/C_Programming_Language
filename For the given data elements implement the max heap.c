#include <stdio.h>
#include<stdlib.h>

void heapify(int arr[], int n, int i)
{
	int largest = i;
	int l = 2 * i + 1;
	int r = 2 * i + 2;

	if (l < n && arr[l] > arr[largest])
		largest = l;

	if (r < n && arr[r] > arr[largest])
		largest = r;

	if (largest != i) {

		int temp=arr[i];
		arr[i]=arr[largest];
		arr[largest]=temp;
		heapify(arr, n, largest);
	}
}


void buildHeap(int arr[], int n)
{
	int startIdx = (n / 2) - 1;
	for (int i = startIdx; i >= 0; i--) {
		heapify(arr, n, i);
	}
}

void printHeap(int arr[], int n)
{
	printf("Array representation of Heap is:\n");

	for (int i = 0; i < n; ++i)
		printf("%d ",arr[i]);
	printf("\n");
}

int main()
{
    int no;
    printf("enter no of elements: ");
    scanf("%d", &no);
    int arr[no];
    for(int i=0;i<no;i++)
    {
        scanf("%d", &arr[i]);
    }

	int n = sizeof(arr) / sizeof(arr[0]);

	buildHeap(arr, n);

	printHeap(arr, n);


	return 0;
}
