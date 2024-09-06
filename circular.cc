
#include <cstdint>
#include <stdio.h>

class DVertex {
    public:
    uint16_t vertexData;
    DVertex* vertexNode;
    DVertex* pVertexNode;
    
    DVertex(){
        vertexHead = nullptr;
        vertexTail = nullptr;
    }

    DVertex(uint16_t vertexData);
    DVertex(uint16_t vertexData, DVertex* vertexNode, DVertex* pVertexNode);

    void addVertexFront(uint16_t vertexData);
    void addVertexBack(uint16_t vertexData);
    void displayVertex();
    void displayVertexInReverse();

    private:
    DVertex* vertexHead;
    DVertex* vertexTail;
};

void DVertex::addVertexFront(uint16_t vertexData){
    DVertex* sampleVertex = new DVertex();
    sampleVertex->vertexNode = vertexHead;
    sampleVertex->pVertexNode = nullptr;
    vertexHead->pVertexNode = sampleVertex;
}

void DVertex::addVertexBack(uint16_t data) {
    DVertex* sampleVertex = new DVertex();
    DVertex* temp = vertexHead;
    while(temp->vertexNode != nullptr) {
        temp = temp->vertexNode;
    }
    temp->vertexNode = sampleVertex;
    sampleVertex->vertexData = data;
    sampleVertex->vertexNode = nullptr;
    sampleVertex->pVertexNode = temp;
    temp = sampleVertex;
}

void DVertex::displayVertex(){
    DVertex* temp = vertexHead;
    while(temp != nullptr) {
        printf("%d\n",temp->vertexData);
        temp = temp->vertexNode;
    }
}

void DVertex::displayVertexInReverse(){
    DVertex* temp = vertexHead;
    DVertex* last = nullptr;
    while(temp->vertexNode != nullptr){
        last = temp;
        temp = temp->vertexNode;
    }

    while(last != nullptr) {
        printf("%d\n", last->vertexData);
        last = last->vertexNode;
    }
}

