#include <cstdint>
#include <type_traits>
#include <iostream>

template <typename T>
class Queue {
    public:
    static const int QUEUE_MAX = 10;
    uint16_t items[QUEUE_MAX];
    int top, head, tail;

    Queue(): top(-1), head(-1), tail(-1) {}
    Queue(uint16_t data);
    void createEmptyQueue();
    typename std::enable_if_t<std::is_integral<T>::value, bool>
    checkIsQueueFull();
    typename std::enable_if_t<std::is_integral<T>::value, bool>
    checkIsQueueEmpty();
    void enqueue(uint16_t data);
    uint16_t dequeue();
    void displayQueue();

    private:
    int count;
};

template <typename T>
void Queue<T>::createEmptyQueue() {
    head = -1; 
    tail = -1;
} 

template <typename T> 
typename std::enable_if_t<std::is_integral<T>::value, bool>
Queue<T>::checkIsQueueFull(){
    return tail == QUEUE_MAX - 1; 
}

template <typename T> 
typename std::enable_if_t<std::is_integral<T>::value, bool>
Queue<T>::checkIsQueueEmpty(){
    return head == -1 && 
           tail == -1;
}

template <typename T> 
void Queue<T>::enqueue(uint16_t data) {
    if(this->checkIsQueueFull()) return;
    if(head == -1) head = 0;
    tail++; items[tail] = data;
    top++; count++;
}

template <typename T> 
uint16_t Queue<T>::dequeue() {
    if(this->checkIsQueueEmpty()) return 0;
    uint16_t element = items[head];
    if(head >= tail){
        head = -1;
        tail = -1;
    } else { head++;}
    top--; count--;
    return element;
}

template <typename T> 
void Queue<T>::displayQueue() {
    for(int i = 0; i < count; ++i){
        std::cout << items[i] << " -> ";
    } std::cout << std::endl;
}

int main(){
    Queue<int> que;
    que.createEmptyQueue();
    que.enqueue(10);
    que.enqueue(80);
    que.enqueue(438);
    que.dequeue();
    que.displayQueue();
}