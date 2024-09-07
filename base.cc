
#include <cstdint>
#include <stdio.h>

class LVertices {
    public:
    uint16_t data;
    LVertices* edge;
    int size;

    /*
     * LVertices hold the corresponding data for the list
     * creates a list of linked nodes and fetches data 
     */
    LVertices(){
        head = nullptr;
        tail = nullptr;
        size = 0;
    }
    LVertices(uint16_t data){
        this->data = data;
        this->edge = nullptr;
    }
    LVertices(uint16_t data, LVertices* edge){
        this->data = data;
        this->edge = edge;
    }
    
    void displayList();
    uint16_t deleteFirst();
    uint16_t deleteLast();
    LVertices* get(int index);
    void insertFirst(uint16_t data);
    void insertLast(uint16_t data);
    void insertPos(uint16_t data, int index);

    private:
    LVertices* head;
    LVertices* tail;
};

void LVertices::insertFirst(uint16_t data){
    LVertices* newVertice =  new LVertices(data);
    if(head == nullptr){
        head = newVertice;
        tail = newVertice;
    } else {
        newVertice->edge = head;
        head = newVertice;
    }
    size++;
}

void LVertices::insertLast(uint16_t data) {
    LVertices* lastVertice = new LVertices(data);
    LVertices* tempVertice = head;
    while(tempVertice->edge != nullptr) {
        tempVertice = tempVertice->edge;
    }
    tempVertice->edge = lastVertice; size++;
}

void LVertices::insertPos(uint16_t data, int index) {
    if (index == 0)
        insertFirst(data);
    if (index == size)
        insertLast(data);
    LVertices* prev = head;
    for(int i = 0; i < index-1; ++i){
        prev = prev->edge;
    }
    LVertices* newVertice = new LVertices(data, prev->edge);
    prev->edge = newVertice;size++;
}

void LVertices::displayList(){
    LVertices* temp = head;
    while(temp != nullptr) {
        printf("%d\n", temp->data);
        temp = temp->edge;
    }
}

uint16_t LVertices::deleteFirst(){
    uint16_t val = head->data;
    head = head->edge;
    if(head == nullptr)
        tail = nullptr;
    size--;
    printf("deleted: %d\n",val);
    return val;
}

LVertices* LVertices::get(int index){
    LVertices* vindex = head;
    for(int k =0; k < index; ++k){
       vindex = vindex->edge;
    } 
    printf("index is : %d\n", vindex->data);
    return vindex;
}

uint16_t LVertices::deleteLast(){
    if (size <= 1)
        deleteFirst();
    LVertices* sl = get(size - 2);
    int val = tail->data;
    tail = sl; tail->edge = nullptr;
    printf("deleted last: %d\n", val);
    return val;
}

int base(){
    LVertices* cvert = new LVertices();
    cvert->insertFirst(12);
    cvert->insertLast(90);
    cvert->insertLast(40);
    cvert->insertFirst(32);
    cvert->insertPos(11,1);
    cvert->deleteFirst();
    cvert->deleteLast();
    cvert->displayList();
}
