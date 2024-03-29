#include <iostream>
using namespace std;

struct Node{
    int data;
    Node *next;
};

class stackArray{
private:
    Node *top, *tail;
public:
    stackArray();
    bool isEmpty();
    void push(int value);
    void pop();
    void printStackArray();
    void swapPositions(int position1, int position2);
    void sortStackArray(int arr[], int size);
    ~stackArray();
};
stackArray::stackArray(){
    top = nullptr;
    tail = nullptr;
}
bool stackArray::isEmpty() {
    if(top == nullptr){
        return true;
    }
    return false;
}
void stackArray::push(int value){
    Node *temp = new Node;
    temp->data = value;
    temp->next = nullptr;

    if(top == nullptr){
        top = temp;
        tail = temp;
    } else{
        tail->next = temp;
        tail = temp;
    }
}
void stackArray::pop() {
    Node *currentptr, *prev;
    if(isEmpty()){
        cout << "Linked List is Empty (Pop Function)\n";
        return;
    }
    if(top->next == nullptr){
        currentptr = top;
        top = nullptr;
        delete currentptr;
        return;
    }
    currentptr = top;
    while(currentptr->next != nullptr){
        prev = currentptr;
        currentptr = currentptr->next;
    }
    prev->next = nullptr;
    delete currentptr;
}
void stackArray::printStackArray(){
    if(isEmpty()){
        cout << "Linked List is Empty (Print Function)\n";
        return;
    }
    Node *currentptr = top;
    while(currentptr->next != nullptr){
        cout << currentptr->data << " ";
        currentptr = currentptr->next;
    }
    cout << currentptr->data;
    cout << "\n";
}
void stackArray::swapPositions(int position1, int position2){
    //if Linked List is Empty
    if(isEmpty()){
        cout << "Linked List is Empty (Swap Function)\n";
        return;
    }
    //If user gives the same position
    if(position1 == position2){
        cout << "Cannot swap! Position (1) and Position (2) are the same.\n";
        return;
    }
    //search for position1
    int currentPositionX = 0;
    Node *ptrX = top;
    while(ptrX->next != nullptr){
        if(currentPositionX < position1){
            ptrX = ptrX->next;
            currentPositionX++;
        }
    }
    //search for position2
    int currentPositionY = 0;
    Node *ptrY = top;
    while(ptrY != nullptr){
        if(position2 == 0){
            break;
        }else if(currentPositionY < position2){
            ptrY = ptrY->next;
            currentPositionY++;
        }
    }
    //Return if position1 or position2 cannot be found
    if(currentPositionX != position1 || currentPositionY != position2){
        cout << "Sorry! One or more of the Positions is not a valid position.\n";
        return;
    }
    //swap if positions are valid
    int temp = ptrX->data;
    ptrX->data = ptrY->data;
    ptrY->data = temp;
    return;
}
void stackArray::sortStackArray(int arr[], int size){
    if(isEmpty()){
        cout << "Linked List is Empty (Sort Function)\n";
        return;
    }

    Node *currentptr = top;
    int count = 0;
    while(currentptr->next != nullptr){
        arr[count] = currentptr->data;
        count++;
        currentptr = currentptr->next;
    }
    arr[count] = currentptr->data;

    for(int i = 0; i < size; i++){
        for(int j = 0; j < size-i-1; j++){
            if(arr[j] > arr[j+1]){
                int temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
            }
        }
    }

    for(int i = 0; i < size; i++){
        cout << arr[i] << " ";
    }
    cout << "\n";
}
stackArray::~stackArray(){
    while(top != nullptr){
        Node *currentptr = top;
        top = top->next;
        delete currentptr;
        currentptr = nullptr;
    }
}
int main() {
    stackArray stack;
    int const size = 5;
    int arr[size] = {0,0,0,0,0};
    cout << "------------------ Testing isEmpty() ------------------\n";
    stack.pop();
    stack.swapPositions(1,2);
    stack.sortStackArray(arr, size);
    cout << "\n------------------ Testing Push ------------------\n";
    cout << "Test 1 (Pushing 3 Values):             ";
    stack.push(1);
    stack.push(2);
    stack.push(3);
    stack.printStackArray();
    cout << "Test 2 (Pushing 2 More Values):        ";
    stack.push(4);
    stack.push(5);
    stack.printStackArray();
    cout << "\n------------------ Testing Pop ------------------\n";
    cout << "Test 1 (Popping 1 Value):              ";
    stack.pop();
    stack.printStackArray();
    cout << "Test 2 (Popping Till Empty):           ";
    stack.pop();
    stack.pop();
    stack.pop();
    stack.pop();
    cout << "\n\n------------------ Testing Swap ------------------\n";
    cout << "Test 1 (Same Swap Positions):          ";
    stack.swapPositions(1,1);
    cout << "Test 2 (Positions Out of Bound):       ";
    stack.push(12);
    stack.push(5);
    stack.push(-12);
    stack.push(19);
    stack.push(-5);
    stack.swapPositions(7,8);
    cout << "Test 3 (Before Swap):                  ";
    stack.printStackArray();
    cout << "Test 3 (After Swap):                   ";
    stack.swapPositions(4,0);
    stack.printStackArray();
    cout << "\n------------------ Testing Sort ------------------\n";
    cout << "Test 1 (Sort Values from Stack):       ";
    stack.sortStackArray(arr, size);

    return 0;
}
