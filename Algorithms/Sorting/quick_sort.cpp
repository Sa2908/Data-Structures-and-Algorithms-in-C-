#include<iostream> 
using namespace std;

void printArray(int * array, int len);
int * takeArray(int len);

int partition(int * array, int low, int high) {
    int pivot = array[low];

    int i = low + 1;
    int j = high;  
    int temp;

    do {
        while (array[i] <= pivot) {
            i++;
        } 


        while (array[j] > pivot) {
            j--;
        } 

        if (i < j) {
            temp = array[i];
            array[i] = array[j];
            array[j] = temp;
        }
    } while (i<j);

    temp = array[low];
    array[low] = array[j];
    array[j] = temp;
    
    return j;

}


void quickSort(int * array, int low, int high) {
    int partitionIndex;

    if (low < high) { 
        partitionIndex = partition(array, low, high);
        quickSort(array, low, partitionIndex-1);
        quickSort(array, partitionIndex+1, high);
    }
    
}  


int main(){
    cout<<"Enter the length of array: ";
    int len;
    cin>>len;
    cout<<"Enter the array elements"<<endl;
    int * array = takeArray(len);
    printArray(array, len);
    quickSort(array, 0, len-1);
    printArray(array, len);    
    return 0;
    return 0;
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



void printArray(int * array, int len) {
    // int len = sizeof(array) / sizeof(int);
    for (int i = 0; i < len; i++)
    {
        cout<<array[i]<<" ";
    }
    cout<<endl;
}