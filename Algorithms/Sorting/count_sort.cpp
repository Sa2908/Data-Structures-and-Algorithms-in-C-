// Count sort Algorithm

#include<iostream>
using namespace std;

void countsort(int * array, int size) {
    int max = 0;
    int len = size;

    for (int i = 0; i < len; i++) {
        if(array[i] > max){
            max = array[i];
        }
    }

    int * count = new int[max+1];

    for (int i = 0; i < max+1; i++) {
        count[i] = 0;
    }

    for (int i = 0; i < len; i++) {
        int e = array[i];
        count[e] = count[e] + 1;
    }

    int j = 0;
    int i = 0;
    while (i <= max) {
        if (count[i] > 0){
            array[j] = i;
            count[i] = count[i] - 1;
            j++;
        } else{
            i++;
        }
    }   

}

void print(int * array, int size) {
    for(int i = 0; i < size; i++) {
        cout<<array[i]<<" ";
    }
    cout<<endl;
}

using namespace std;
int main(){
    int array[] = {2, 10, 74, 10, 65, 12, 49, 1100};
    int len = sizeof(array)/sizeof(array[0]);
    print(array, len);
    countsort(array, len);
    print(array, len);


    return 0;
}