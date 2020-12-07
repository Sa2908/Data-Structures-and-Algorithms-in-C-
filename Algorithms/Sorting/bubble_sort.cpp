#include<iostream>
using namespace std;


void printArray(int * array, int len) {
    // int len = sizeof(array) / sizeof(int);
    for (int i = 0; i < len; i++)
    {
        cout<<array[i]<<" ";
    }
    cout<<endl;
}

int * takeArray(int len) {
    int * array = new int[len];
    for (int i = 0; i < len; i++)
    {
        cout<<"Enter the element at "<<i<<": ";
        cin>>array[i];
    }
    return array;
}

void bubbleSort(int * array, int len) {
    int isSorted = 0;
    for (int i = 0; i < len-1; i++) {
        cout<<"pass "<<i+1<<endl;
        isSorted = 1;
        for (int j = 0; j < len-1-i; j++) {
            if(array[j] > array[j+1]) {
                int temp = array[j+1];
                array[j+1] = array[j];
                array[j] = temp;
                isSorted = 0;
            }
        }

        if(isSorted) {
            return ;
        }
    }
}

int main(){
    cout<<"Enter the length of array: ";
    int len;
    cin>>len;
    cout<<"Enter the array elements"<<endl;
    int * array = takeArray(len);
    printArray(array, len);
    bubbleSort(array, len);
    printArray(array, len);
    return 0;
}