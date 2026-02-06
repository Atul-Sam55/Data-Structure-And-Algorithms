#include <iostream>
using namespace std;

void linearSearch(int a[], int size, int key)
{
    int temp = -1;

    for (int i = 0; i < size; i++)
    {
        if (a[i] == key)
        {
            cout << "Element found at position: " << i + 1 << endl;
            temp = 0;
            break;   // stop after finding
        }
    }

    if (temp == -1)
    {
        cout << "No Element Found" << endl;
    }
}

int main()
{
    int arr[5];

    cout << "Enter 5 elements of array:" << endl;
    for (int i = 0; i < 5; i++)
    {
        cin >> arr[i];
    }

    int num;
    cout << "Enter element to search: ";
    cin >> num;

    linearSearch(arr, 5, num);

    return 0;
}
