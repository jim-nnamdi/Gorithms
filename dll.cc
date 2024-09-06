#include <cstdint>
#include <stdio.h>

class DLL{
    public:
    DLL(){
        head = nullptr;
        tail = nullptr;
        size = 0;
    }
    
    uint16_t size;
    uint16_t data;
    DLL* fnode;
    DLL* pnode;

    void insertFront(uint16_t data);
    void displayDLL();
    void displayDLLReverse();
    void insertLast(uint16_t data);

    private:
    DLL* head;
    DLL* tail;
};

void DLL::insertFront(uint16_t data) {
    DLL* newList = new DLL();
    newList->data = data;
    newList->fnode = head;
    newList->pnode = nullptr;
    head->pnode = newList;
    size++;
}

void DLL::displayDLL(){
    DLL* temp = head;
    while(temp != nullptr) {
        printf("%d ->", temp->data);
        temp = temp->fnode;
    }
}

void DLL::displayDLLReverse() {
    DLL* temp = head;
    DLL* last = nullptr;
    while(temp != nullptr){
        last = temp;
        temp = temp->fnode;
    }

    while(last != nullptr){
        printf("%d\n", last->data);
        last = last->pnode;
    }
}

void DLL::insertLast(uint16_t data){

    DLL* temp = head;  
    DLL* newDLL = new DLL();
    newDLL->data = data;
    if(head == nullptr){
        newDLL->pnode = nullptr;
        newDLL->fnode = nullptr;
        head = newDLL;
        return;
    }

    while(temp->fnode != nullptr){
        temp = temp->fnode;
    }
    temp->fnode = newDLL;
    newDLL->fnode = nullptr;
    newDLL->pnode = temp;
    size++;
}

 int main(){

     DLL* cDLL =  new DLL();
     cDLL->insertFront(23);
     cDLL->insertFront(45);
     cDLL->insertLast(84);
     cDLL->displayDLL();
 }
