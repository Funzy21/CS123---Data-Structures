#include <iostream>

using namespace std;

#define RUNNING 1
#define EXIT 2

//Global static variable that facilitates the program's state
static int program = RUNNING;


class Node{
    public:
        int data;
        Node *next;
        //Default constructor
        Node(){
            data = 0;
            next = NULL;
        }
        Node(int data){
            this->data = data;
            this->next = NULL;
        }
};
//Singly linked list using class implementation
class Stack{
    public:
        Node *head;
        int size;
        int capacity;
        //Default constructor
        Stack(){
            size = 0;
            capacity = 1;
            head = NULL;
        }
        /* Class methods */

        //Checks if the stack is empty
        bool Empty(){
            if(size == 0){
                return true;
            }
            else{
                return false;
            }
        }
        //Function that adds a node to the top of the stack
        void push(int data){
            //Instatiates a new node
            Node *node = new Node(data);
            //Ensures that the number of nodes dont exceed the stack's capacity
            if(capacity == size){
                capacity += 1;
            }
            //If the stack is empty, no link can be created
            if(Empty() == true){
                head = node;
            }
            //If the stack already has other nodes, the head node must link with the next node
            else{
                //Stores the address of the current head node to a temp pointer for linking purposes
                node->next = head;
                head = node;
            }
            size += 1;
            return;
        }
        //Function that removes the head node of the stack
        void pop(){
            Node *temp = NULL;
            temp = head;
            head = head->next;
            //Frees excess memory
            delete(temp);
            size -= 1;
            return;
        }
        //Returns the value stored in the head node
        int top(){
            if(Empty() == true){
                return -1;
            }
            else{
                return head->data;
            }
        }
        //Checks and returns the current size of the stack
        int stackSize(){
            return size;
        }
        //Displays the data stored in the nodes
        int displayNodes(){
            Node *temp = head;
            if(Empty() == true){
                cout << "The stack is currently empty" << endl;
                return -1;
            }
            else
                cout << "The stack currently contains the elements: ";
                //Iterates through each node and prints out their stored values
                for(int i = 0; i < size; i++){
                    cout << temp->data;
                    if(i != size - 1){
                        cout << ", ";
                    }
                    temp = temp->next;
                }
                cout << endl;
                return 0;
        }
        //Function that empties the stack
        void deleteAll(){
            Node *temp = head;
            if(Empty() == true){
                cout << "The stack is currently empty, no nodes can be deleted" << endl;
                return;
            }
            //Loops the pop function while iterating through the nodes in the stack
            for(int i = 0; i < size; i++){
                pop();
                temp = head->next;
            }
            size = 0;
            cout << "All nodes in the stack have been deleted" << endl;
            return;
        }
};

//Helper function that displays the main menu
void printMenu(){
        cout << endl;
        cout << "/Welcome to the Stack! What would you like to do?/" << endl;
        cout << "1. Push" << endl;
        cout << "2. Pop" << endl;
        cout << "3. Top" << endl;
        cout << "4. Check stack size" << endl;
        cout << "5. Display all nodes" << endl;
        cout << "6. Delete all nodes" << endl;
        cout << "7. Exit" << endl;
        cout << "? ";
}


int main(){
    int choice, data;
    Stack stack;
    //The program will run perpetually until the user chooses the exit option
    while(program == RUNNING){
        printMenu();
        cin >> choice;
        cout << endl;
        switch (choice)
        {
        case 1:
        {
            cout << "Input a value to store into the node: ";
            cin >> data;
            stack.push(data);
            cout << "Stack has been updated! " << stack.head->data << " has been stored" << endl;
            break;
        }
        case 2:
        {   
            if(stack.Empty() == true){
                cout << "The stack is currently empty, no nodes can be deleted" << endl;
            }
            else{
                stack.pop();
                cout << "Pop successful, head node has been deleted" << endl; 
            }
            break;
        }
        case 3:
        {
            int val = stack.top();
            if(val == -1){
                cout << "The stack is currently empty" << endl;
            }
            else
                cout << "The head node holds the value: " << val << endl;
            break;
        }
        case 4:
        {
            int stacksize = stack.stackSize();
                cout << "There are currently " << stacksize << " nodes in the stack" << endl;
            break;
        }
        case 5:
        {
            stack.displayNodes();
            break;
        }
        case 6:{
            stack.deleteAll();
            break;
        }
        //Terminates the menu loop
        case 7:{
            program = EXIT;
            break;
        }
        
        default:
            cout << "Invalid input!" << endl;
            break;
        }
    }
    system("cls");
    cout << "Program exited successfully. Goodbye!" << endl;
    return 0;
}
