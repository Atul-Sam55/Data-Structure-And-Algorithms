#include <iostream>
using namespace std;

void insertionSort(int arr[])
{
    for (int i = 1; i < 5; i++)   // start from 1
    {
        int key = arr[i];        // element to insert
        int j = i - 1;           // previous index

        // shift elements greater than key
        while (j >= 0 && arr[j] > key)
        {
            arr[j + 1] = arr[j];
            j = j - 1;
        }

        arr[j + 1] = key;        // place key at correct position
    }
}

int main()
{
    int myarray[5];   

    cout << "Enter 5 integers in any order: " << endl;
    for (int i = 0; i < 5; i++)
    {
        cin >> myarray[i];
    }

    cout << "Before Sorting: " << endl;
    for (int i = 0; i < 5; i++)
    {
        cout << myarray[i] << " ";
    }

    insertionSort(myarray);

    cout << endl << "After Sorting: " << endl;
    for (int i = 0; i < 5; i++)
    {
        cout << myarray[i] << " ";
    }

    return 0;
}
