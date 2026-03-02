#include <iostream>
using namespace std;

// Function to perform Selection Sort
void selectionSort(int arr[])
{
    // Outer loop for each element (except last one)
    for (int i = 0; i < 4; i++)
    {
        // Assume the current index is the minimum
        int min = i;

        // Inner loop to find the smallest element
        // in the remaining unsorted array
        for (int j = i + 1; j < 5; j++)
        {
            // If a smaller element is found
            if (arr[j] < arr[min])
            {
                min = j; // Update index of minimum element
            }
        }

        // Swap only if a new minimum is found
        if (min != i)
        {
            int temp = arr[min];
            arr[min] = arr[i];
            arr[i] = temp;
        }
    }
}

int main()
{
    int myarr[5];

    // Taking input from user
    cout << "Enter 5 integers in random order: " << endl;
    for (int i = 0; i < 5; i++)
    {
        cin >> myarr[i];
    }

    // Printing unsorted array
    cout << "Unsorted Array: " << endl;
    for (int i = 0; i < 5; i++)
    {
        cout << myarr[i] << " ";
    }
    cout << endl;

    // Calling selection sort function
    selectionSort(myarr);

    // Printing sorted array
    cout << "Sorted Array: " << endl;
    for (int i = 0; i < 5; i++)
    {
        cout << myarr[i] << " ";
    }

    return 0;
}
