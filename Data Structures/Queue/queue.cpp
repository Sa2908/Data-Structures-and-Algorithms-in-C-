#include<iostream>

using namespace std;

class Queue {
    int size;
    int front, last;
    int * array;
public:
    Queue(int size) {
        this->size = size;
        front = last = 0;
        array = new int[size];
    }

    //
    int isEmpty() {
        if (front == last) {
            return 1;
        }
        return 0;
    }

    //
    int isFull() {
        if (last == size - 1) {
            return 1;
        }
        return 0;
    }
    
    //
    void enqueue(int value) {
        if(isFull()) {
            cout<<"Queue is full"<<endl;
            return ;
        }
        last++;
        array[last] = value;
    }

    int dequeue() {
        if (isEmpty()) {
            cout<<"Queue is empty"<<endl;
            return -1;
        }
        front++;
        return array[front];
    }

    //
    void display() {
        for (int i = 1; i < last; i++) {
            cout<<array[i]<<endl;
        }
    }


};

int main(){

    Queue q(10);

    q.enqueue(5);
    q.enqueue(6);
    q.enqueue(7);
    q.enqueue(8);
    
    q.display();
    cout<<endl;

    cout<<q.dequeue()<<endl;
    q.display();
    return 0;
}