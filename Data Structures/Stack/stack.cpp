#include<iostream>

using namespace std;


class Stack {
    int size;
    int top;
    int * array;
public:
    Stack(int size) {
        this->size = size;
        top = -1;
        array = new int[size];
    }

    // 
    int isEmpty() {
        if (top == -1) {
            return 1;
        }
        return 0;
    }

    //
    int isFull() {
        if (top == size - 1) {
            return 1;
        }
        return 0;
    }

    //
    void push(int value) {
        if(isFull()) {
            cout<<"Stack overflow! Cannot push "<<value<<" to the stack"
            <<endl;
            return ;
        }

        top++;
        array[top] = value;
    }

    //
    int pop() {
        if(isEmpty()) {
            cout<<"Stack Underflow!"<<endl;
            return -1;
        }

        int val = array[top];
        top--;
        return val;
    }

    void display() {
        if(top != -1){
            for (int i = 0; i < top + 1; i++) {
                cout<<array[i]<<endl;
            }
            return;
        }
        cout<<"There is nothing in the stack"<<endl;
    }

    int peek(int index) {
        int ind = top - index + 1;
        if (ind < 0) {
            cout<<"Not a valid position for stack"<<endl;
            return -1;
        }
        return array[ind];
    }

    //
    int stackTop() {
        if(!isEmpty()) {
            return array[top];
        }
        return -1;
    }

    //
    int stackBottom() {
        if(!isEmpty()) {
            return array[0];
        }
        return -1;
    }


    

};

int main(){

    Stack st(5);

    st.push(1);
    st.push(2);
    st.push(3);
    st.push(4);

    st.pop();
    st.display();
    return 0;
}