#include<bits/stdc++.h>
using namespace std;

#define BOLT        ios_base::sync_with_stdio(0)

#define IN_FILE     freopen("input.txt", "r", stdin);
#define OUT_FILE    freopen("output.txt", "w", stdout);

void USEFILE(bool yes){
    if(yes){
        IN_FILE;
        OUT_FILE;
    }
}

class Node{
  public:
    int data;
    Node *next;  
};

class List{
    private:
        Node *head;
    public:
        List(){
            head = NULL;
        }
        // Inserts the element
        void insert(int n){
            Node *newNode = new Node();
            newNode->data = n;
            newNode->next = NULL;
            if(head != NULL){
                Node *temp = head;
                while(temp->next!=NULL){
                    temp = temp->next;
                }
                temp->next = newNode;
            }
            else{
                head = newNode;
            }
        }
        // Inserts the element into the given index
        void insert(int n, int index){
            Node *newNode = new Node();
            newNode->data = n;
            newNode->next = NULL;
            Node *temp = head;
            if(index < 0){
                cout << ("invalid Index") << '\n';
            }
            if(index==0){
                newNode->next = head;
                head = newNode;
                return;
            }
            while(--index && temp->next != NULL){
                temp = temp->next;
            }
            newNode->next = temp->next;
            temp->next = newNode;
        }
        // Returns the searched element's Index
        int search(int n){
            Node *temp = head;
            int index = 0;
            while(temp != NULL){
                if(temp->data == n){
                    return index;
                }
                temp = temp->next;
                index++;
            }
            return -1;
        }
        // Gets the element at given index from the list
        int get(int index){
            Node *temp = head;
            if(index < 0){
                cout << "Invalid Index" << '\n';
                return -1;
            }
            while(temp != NULL && index--){
                temp = temp->next;
            }
            if(index > -1 || temp == NULL){
                cout << "Index out of bound by " << index << '\n';
                return -1;
            }
            return temp->data;
        }
        // Remove the element at given index from the list
        void removeAt(int index){
            Node *temp = head;
            
            if(index < 0){
                cout << "Invalid Index" << '\n';
                return;
            }

            if(index == 0){
                head = head->next;
                return;
            }

            while(index-- > 1){
                temp = temp->next;
                if(temp == NULL){
                    cout << "Index Out Of Bound By " << index << '\n';
                    return;
                }
            }
            temp->next = temp->next->next;
        }

        // Remove all n from the list
        void remove(int n){
            if(head != NULL){
                while(head->data == n){
                    head = head->next;
                }
            }
            Node *save = head;
            Node *prev = head;
            while(head != NULL){
                if(head->data != n){
                    prev = head;
                    head = head->next; 
                }
                else{
                    prev->next = head->next;
                    head = head->next;
                }
            }
            head = save;
        }
        // Prints the list
        void printList(){
            if(head== NULL){
                cout << "Empty List" << '\n';
                return;
            }
            Node* temp = head;
            while(temp->next!=NULL){
                cout << (temp->data) << " ";
                temp = temp->next;
            }
            cout << (temp->data) << '\n';
        }

};

int main(){
    BOLT;
    USEFILE(false);
    
    List *myList = new List();

    myList->printList();

    cout << "INSERT :\n";
    myList->insert(2);myList->printList();
    myList->insert(5);myList->printList();
    myList->insert(5);myList->printList();
    myList->insert(5);myList->printList();
    myList->insert(3);myList->printList();
    myList->insert(1);myList->printList();
    myList->insert(17,3);myList->printList();
    myList->insert(18,3);myList->printList();
    myList->insert(19,3);myList->printList();
    myList->insert(31);myList->printList();
    myList->insert(51,4);myList->printList();
    myList->insert(51,-110);myList->printList();
    myList->insert(2);myList->printList();
    myList->insert(5);myList->printList();
    myList->insert(3);myList->printList();
    myList->insert(1);myList->printList();
    myList->insert(17,3);myList->printList();

    cout << "SEARCH: "; myList->printList();
    cout << "Found at index: " << myList->search(31) << '\n';
    cout << "Found at index: " << myList->search(32) << '\n';
    cout << "Found at index: " << myList->search(17) << '\n';
    cout << "Found at index: " << myList->search(12) << '\n';
    cout << "Found at index: " << myList->search(3) << '\n';

    cout << "GET: "; myList->printList();
    cout << myList->get(2) << "\n";
    cout << myList->get(2) << "\n";
    cout << myList->get(0) << "\n";
    cout << myList->get(10) << "\n";
    cout << myList->get(9) << "\n";
    cout << myList->get(91) << "\n";

    cout << "DELETE: "; myList->printList();
    myList->removeAt(0);myList->printList();
    myList->removeAt(0);myList->printList();
    myList->removeAt(5);myList->printList();
    myList->removeAt(51);myList->printList();
    myList->removeAt(3);myList->printList();
    myList->removeAt(3);myList->printList();
    myList->removeAt(4);myList->printList();
    myList->removeAt(7);myList->printList();

    cout << "REMOVE: "; myList->printList();
    myList->remove(5);myList->printList();
    myList->remove(51);myList->printList();
    myList->remove(1);myList->printList();
    myList->remove(2);myList->printList();

    return 0;
}
