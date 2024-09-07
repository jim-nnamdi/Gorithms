
#include <cstdint>
#include <iostream>
#define STACK_LIMIT    10
#define STACK_OVERFLOW "stack overflow"
#define STACK_EMPTY    "empty stack"

template <typename T> 
class Stack {
    public:
    uint16_t items[STACK_LIMIT];
    int top;
    Stack():top(-1), count(0){}

    void createEmptyStack(Stack* s);
    T checkFullStack(Stack* s);
    T checkEmptyStack(Stack* s);
    void addToStack(Stack* s, uint16_t val);
    void popFromStack(Stack* s, uint16_t val);
    void countStackItems(Stack* s);

    private:
    int count;
};

template <typename T>
void Stack<T>::createEmptyStack(Stack* s) {
    s->top = -1;
}

template <typename T>
T Stack<T>::checkFullStack(Stack* s) {
    if(s->top == STACK_LIMIT - 1) 
        return 1;
    return 0;   
}

template <typename T> 
T Stack<T>::checkEmptyStack(Stack* s) {
    if(s->top == -1)
        return 1;
    return 0;
}

template <typename T> 
void Stack<T>::addToStack(Stack* s, uint16_t val) {
    if(checkFullStack(s)) std::cout << STACK_OVERFLOW;
    s->top++;
    s->items[s->top] = val; 
    count++;
}

template <typename T>
void Stack<T>::popFromStack(Stack* s, uint16_t val){
    if(checkEmptyStack(s)) std::cout << STACK_EMPTY << "\n";
    s->top--;
    std::cout << "popped" << s->items[s->top];
    count--;
}

template <typename T>
void Stack<T>::countStackItems(Stack* s) {
    if(checkEmptyStack(s)) std::cout << s->items[0];
    for(int i = 0; i < count; ++i){
        std::cout << s->items[i] << " -> ";
    }std::cout << std::endl;
}

int main(){
    Stack<int>* s = new Stack<int>();
    s->createEmptyStack(s);
    s->addToStack(s, 10);
    s->addToStack(s, 49);
    s->countStackItems(s);
}