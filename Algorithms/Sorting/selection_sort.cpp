#include <iostream>

using namespace std;

void printArray(int *array, int len);
int *takeArray(int len);

void selectionSort(int *array, int len)
{

    int index;
    for (int i = 0; i < len - 1; i++)
    {
        index = i;
        for (int j = i + 1; j < len; j++)
        {
            if (array[j] < array[index])
            {
                index = j;
            }
        }

        int temp = array[i];
        array[i] = array[index];
        array[index] = temp;
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
    selectionSort(array, len);
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