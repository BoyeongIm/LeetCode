struct Node {
    Node* prev;
    int val;
    Node* next;
};

class MyCircularDeque {
private:
    int maxsize;
    int currsize;
    Node* front;
    Node* rear;
public: 
    MyCircularDeque(int k) : maxsize(k), currsize(0) {  
        front = NULL;
        rear = NULL;
    }
    
    bool insertFront(int value) {
        if (isFull()) return false;
        Node* newNode = new Node;
        newNode->val = value;
        if (!front && !rear) {
            front = newNode;
            rear = newNode;
        }
        else {
            front->prev = newNode;
            newNode->next = front;
            front = newNode;
        }
        currsize ++;
        return true;
    }
    
    bool insertLast(int value) {
        if (isFull()) return false;
        Node* newNode = new Node;
        newNode->val = value;
        if (!front && !rear) {
            front = newNode;
            rear = newNode;
        }
        else {
            newNode->prev = rear;
            rear->next = newNode;
            rear = newNode;
        }
        currsize ++;
        return true;
    }
    
    bool deleteFront() {
        if (isEmpty()) return false;
        if (front==rear) {
            front=nullptr;
            rear=nullptr;
        }
        else {
            Node* to_delete = front;
            front = front->next;
            to_delete = nullptr;
            delete to_delete;
        }
        currsize --;
        return true;
    }
    
    bool deleteLast() {
        if (isEmpty()) return false;
        if (front==rear) {
            front=nullptr;
            rear=nullptr;
        }
        else {
            Node* to_delete = rear;
            rear = rear->prev;
            to_delete = nullptr;
            delete to_delete;
        }
        currsize --;
        return true;
    }
    
    int getFront() {
        if (isEmpty()) return -1;
        return front->val;
    }
    
    int getRear() {
        if (isEmpty()) return -1;
        return rear->val;
    }
    
    bool isEmpty() {
        return currsize==0;
    }
    
    bool isFull() {
        return currsize==maxsize;
    }
};

/**
 * Your MyCircularDeque object will be instantiated and called as such:
 * MyCircularDeque* obj = new MyCircularDeque(k);
 * bool param_1 = obj->insertFront(value);
 * bool param_2 = obj->insertLast(value);
 * bool param_3 = obj->deleteFront();
 * bool param_4 = obj->deleteLast();
 * int param_5 = obj->getFront();
 * int param_6 = obj->getRear();
 * bool param_7 = obj->isEmpty();
 * bool param_8 = obj->isFull();
 */