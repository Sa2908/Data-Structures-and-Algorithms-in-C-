#include<iostream>
#include<string>
#include<string.h>

using namespace std;


class Stack {
    int size;
    int top;
    char * array;
public:
    Stack(int size) {
        this->size = size;
        top = -1;
        array = new char[size];
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
    void push(char value) {
        if(isFull()) {
            cout<<"Stack overflow! Cannot push "<<value<<" to the stack"
            <<endl;
            return ;
        }

        top++;
        array[top] = value;
    }

    //
    char pop() {
        if(isEmpty()) {
            cout<<"Stack Underflow!"<<endl;
            return '\0';
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

    char peek(int index) {
        int ind = top - index + 1;
        if (ind < 0) {
            cout<<"Not a valid position for stack"<<endl;
            return -1;
        }
        return array[ind];
    }

    //
    char stackTop() {
        if(!isEmpty()) {
            return array[top];
        }
        return -1;
    }

    //
    char stackBottom() {
        if(!isEmpty()) {
            return array[0];
        }
        return -1;
    }


    

};

int checkParenthesis(string exp) {
    int len = exp.length();

    Stack st(len);

    for (int i = 0; i < len; i++) {
        char s = exp[i];
        if (s == '(' || s == '[' || s == '{') {
            st.push(s);
        }
        else if (s == ')' || s == ']' || s == '}') {
            if(st.isEmpty()) {
                return 0;
            } else {
                char a = st.pop();
            }
        }
    }
    if (st.isEmpty()) {
        return 1;
    }
    return 0;
}

int main(){


    string exp = "{[((5+6)-87/2)}";
    
    if (checkParenthesis(exp)) {
        cout<<"The expression is balanced"<<endl;
    } else {
        cout<<"The expression is not balanced"<<endl;
    }

    return 0;
}