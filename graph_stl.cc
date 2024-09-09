#include <stack>
#include <cstdint>
#include <list>

#define MAX_STACK_ITEMS 10

class Stack {
    public:
    uint16_t items[MAX_STACK_ITEMS];
    uint16_t vertices;
    std::list<uint16_t>* adjList;

    Stack(uint16_t data);
    
    void createEmptyStack();
    bool checkIfStackFull();
    void addToStack(uint16_t data);
    void popFromStack();
    int getStackItems();
    void DFS(uint16_t source);
    void addEdge(int from, int to);
    void DFS_Util(uint16_t graphItem, bool visited[]);

    private:
    uint16_t data;
    uint16_t top;
    uint16_t size;
};

Stack::Stack(uint16_t data) {
    this->data = data;
    this->top = -1;
    this->size = 0;
}

void Stack::createEmptyStack(){
    this->top = -1;
}

bool Stack::checkIfStackFull() {
    if (this->top == MAX_STACK_ITEMS - 1)
        return 1;
    return 0;
}

void Stack::addToStack(uint16_t data) {
    if(this->checkIfStackFull())
        fprintf(stdout, "stack overflow");
    this->top++;
    this->items[this->top] = data;
    this->size++;
}

void Stack::popFromStack(){
    if(this->top == -1)
        fprintf(stderr, "cannot pop from empty stack: %d\n", this->top);
    this->top--;
    printf("%d\n", this->items[this->top]);
    this->size--;
}

int Stack::getStackItems(){
    if(this->top == -1)
        return this->items[this->top];
    for(int i = 0; i < this->size; ++i){
        printf("%d\n", this->items[i]);
    return this->size;
    }
}

void Stack::DFS(uint16_t source) {
    bool* visited =  new bool[vertices];
    for(int i = 0; i < vertices; ++i){
        visited[i] = false;
    }
    DFS_Util(source, visited);
    delete[] visited;
}

void Stack::DFS_Util(uint16_t graphItem, bool visited[]){
    visited[vertices] = true;
    for(auto vertice = adjList[graphItem].begin(); 
        vertice != adjList[graphItem].end(); ++vertice){
            if(!visited[*vertice])  
                DFS_Util(*vertice, visited);
        }
}

int main() {}