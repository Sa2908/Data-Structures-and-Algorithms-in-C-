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


void insertionSort(int * array, int len) {

    int temp;
    for (int i = 1; i < len ; i++) {
        temp = array[i];  
        int j = i-1;
        while (j >= 0 && array[j] > temp) {
            array[j+1] = array[j];
            j--;
        }
        array[j+1] = temp;
    }
}



int main(){
    cout<<"Enter the length of array: ";
    int len;
    cin>>len;
    cout<<"Enter the array elements"<<endl;
    int * array = takeArray(len);
    printArray(array, len);
    insertionSort(array, len);
    printArray(array, len);    
    return 0;
}