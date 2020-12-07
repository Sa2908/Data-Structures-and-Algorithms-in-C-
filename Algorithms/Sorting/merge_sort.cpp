#include <iostream>

using namespace std;

void printArray(int *array, int len);
int *takeArray(int len);

void merge(int *array, int mid, int low, int high)
{
    int i, j, k;
    int arr[high - low + 1];
    i = low;
    j = mid + 1;
    k = low;

    while (i <= mid && j <= high)
    {
        if (array[i] < array[j])
        {
            arr[k] = array[i];
            i++;
            k++;
        }
        else
        {
            arr[k] = array[j];
            j++;
            k++;
        }
    }

    while (i <= mid)
    {

        arr[k] = array[i];
        k++;
        i++;
    }
    while (j <= high)
    {

        arr[k] = array[j];
        k++;
        j++;
    }

    for (int i = low; i <= high; i++)
    {
        array[i] = arr[i];
    }
}

void mergeSort(int *array, int low, int high)
{
    int mid;
    if (low < high)
    {
        mid = (low + high) / 2;
        mergeSort(array, low, mid);
        mergeSort(array, mid + 1, high);
        merge(array, mid, low, high);
    }
}

int main()
{
    cout << "Enter the length of array: ";
    int len;
    cin >> len;
    cout << "Enter the array elements" << endl;
    int *array = takeArray(len);
    printArray(array, len);
    mergeSort(array, 0, len - 1);
    printArray(array, len);
    return 0;
    return 0;
}

int *takeArray(int len)
{
    int *array = new int[len];
    for (int i = 0; i < len; i++)
    {
        cout << "Enter the element at " << i << ": ";
        cin >> array[i];
    }
    return array;
}

void printArray(int *array, int len)
{
    // int len = sizeof(array) / sizeof(int);
    for (int i = 0; i < len; i++)
    {
        cout << array[i] << " ";
    }
    cout << endl;
}