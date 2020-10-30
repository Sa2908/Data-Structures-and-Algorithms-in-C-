#include<iostream>

using namespace std;


// This is the code for Array Abstract Data Type Implementation
class ArrayADT{
    int total_size;
    int used_size;
    int * array;
public:
    ArrayADT(int totalSize, int usedSize){
        total_size = totalSize;
        used_size = usedSize;
        array = new int[total_size];
    }
    void show(){
        for (int i = 0; i < used_size; i++)
        {
            cout<<array[i]<<endl;
        }
    }
    void setVal(){
        int n;
        for (int i = 0; i < used_size; i++)
        {
            cout<<"Enter Element:  ";
            cin>>n;
            array[i] = n;
        }       
    }
    // Insert element at index
    int insert(int element, int index){
        if (used_size == total_size){
            return -1;
        }
        else {
            for (int i = used_size-1; i >= index; i--)
            {
                array[i+1] = array[i];
            }
            array[index] = element;
            used_size++;
            return 1;
        }
    }
    // Delete element at a index
    int deleteAt(int index) {
        for (int i = index; i < used_size-1; i++)
        {
            array[i] = array[i+1];
        }
        return 1;
    }
};

//Code to run the class
int main(){
    ArrayADT array(10, 5);
    cout<<"Running setVal Now"<<endl;
    array.setVal();


    int index, element;
    cout<<"Inserting into array"<<endl;
    cout<<"Enter index: ";
    cin>>index;
    cout<<"Enter Element: ";
    cin>>element;

    array.insert(element, index);

    int del;
    cout<<"Enter delete index: ";
    cin>>del;
    array.deleteAt(del);
    // Showing the array
    cout<<"Showing the array"<<endl;
    array.show();
    return 0;
}