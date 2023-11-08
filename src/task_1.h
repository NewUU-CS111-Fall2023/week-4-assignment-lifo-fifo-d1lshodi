/*
 * Author:Dilshod Muxtorov
 * Date:8.11.2023
 * Name:
 */


struct Node {
    int data;
    Node* next;
};
class Stack {
private:
    Node* top; 

public:

    Stack() {
        top = nullptr; 
    }
    bool isEmpty() {
        return top == nullptr;
    }
    void push(int value) {
        Node* newNode = new Node(); 
        newNode->data = value;
        newNode->next = top; 
        top = newNode; 
        std::cout << value << " pushed to the stack." << std::endl;
    }
    void pop() {
        if (isEmpty()) {
            std::cout << "Stack is empty. Cannot pop an element." << std::endl;
            return;
        }
        Node* temp = top; 
        top = top->next;
        std::cout << temp->data << " popped from the stack." << std::endl;
        delete temp; 
    }
    int getTop() {
        if (isEmpty()) {
            std::cout << "Stack is empty. Cannot get the top element." << std::endl;
            return -1;
        }
        return top->data;
    }
};