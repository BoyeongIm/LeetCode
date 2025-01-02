typedef struct Node {
    int val;
    struct Node* next;
} Node;

typedef struct {
    int maxsize;
    int currsize;
    Node* front;
    Node* rear;
} MyCircularQueue;

bool myCircularQueueIsEmpty(MyCircularQueue* obj);
bool myCircularQueueIsFull(MyCircularQueue* obj);

MyCircularQueue* myCircularQueueCreate(int k) {
    MyCircularQueue* cq = (MyCircularQueue*)malloc(sizeof(MyCircularQueue));
    cq->maxsize = k;
    cq->currsize = 0;
    cq->front = NULL;
    cq->rear = NULL;
    return cq;
}

bool myCircularQueueEnQueue(MyCircularQueue* obj, int value) {
    if (myCircularQueueIsFull(obj)) return false;
    Node* newnode = (Node*)malloc(sizeof(Node));
    newnode->val = value;
    if (!obj->front && !obj->rear) {
        obj->front = newnode;
        obj->rear = newnode;
    }
    else {
        obj->rear->next = newnode;
        obj->rear = newnode;
    }
    obj->currsize++;
    return true;
}

bool myCircularQueueDeQueue(MyCircularQueue* obj) {
    if (myCircularQueueIsEmpty(obj)) return false;
    if (obj->front == obj->rear) {
        obj->front = NULL;
        obj->rear = NULL;
    }
    else {
        Node* to_delete = (Node*)malloc(sizeof(Node));
        to_delete = obj->front;
        obj->front = obj->front->next;
        to_delete = NULL;
        free(to_delete);
    }
    obj->currsize--;
    return true;
}

int myCircularQueueFront(MyCircularQueue* obj) {
    if (myCircularQueueIsEmpty(obj)) return -1;
    return obj->front->val;
}

int myCircularQueueRear(MyCircularQueue* obj) {
    if (myCircularQueueIsEmpty(obj)) return -1;
    return obj->rear->val;
}

bool myCircularQueueIsEmpty(MyCircularQueue* obj) {
    return obj->currsize==0;
}

bool myCircularQueueIsFull(MyCircularQueue* obj) {
    return obj->currsize == obj->maxsize;
}

void myCircularQueueFree(MyCircularQueue* obj) {
    free(obj);
}

/**
 * Your MyCircularQueue struct will be instantiated and called as such:
 * MyCircularQueue* obj = myCircularQueueCreate(k);
 * bool param_1 = myCircularQueueEnQueue(obj, value);
 
 * bool param_2 = myCircularQueueDeQueue(obj);
 
 * int param_3 = myCircularQueueFront(obj);
 
 * int param_4 = myCircularQueueRear(obj);
 
 * bool param_5 = myCircularQueueIsEmpty(obj);
 
 * bool param_6 = myCircularQueueIsFull(obj);
 
 * myCircularQueueFree(obj);
*/