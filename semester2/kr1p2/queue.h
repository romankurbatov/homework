#pragma once

template<typename T> class Queue
{
public:
    Queue();
    ~Queue();
    void enqueue(const T &value, const int priority);
    class QueueIsEmpty
    {
    };
    T dequeue() throw(QueueIsEmpty);
private:
    struct Element
    {
        T value;
        int priority;
        Element *next;
        Element *previous;
    };
    Element *front;
    Element *back;
};

template<typename T> Queue<T>::Queue() : front(nullptr), back(nullptr)
{
}

template<typename T> Queue<T>::~Queue()
{
    Element *currentElement = front;
    while (currentElement != nullptr)
    {
        Element *removingElement = currentElement;
        currentElement = currentElement->next;
        delete removingElement;
    }
}

template<typename T> void Queue<T>::enqueue(const T &value, const int priority)
{
    Element *newElement = new Element;
    newElement->value = value;
    newElement->priority = priority;
    newElement->next = nullptr;
    newElement->previous = nullptr;
    if (front == nullptr) //очередь пуста
    {
        front = newElement;
        back = newElement;
    }
    else
    {
        //ищем элемент, после которого нужно вставить новый
        Element *currentElement = back;
        while (currentElement != nullptr && currentElement->priority < priority)
            currentElement = currentElement->previous;

        if (currentElement == nullptr) //добавляем в начало очереди
        {
            newElement->next = front;
            front = newElement;
        }
        else if (currentElement->next == nullptr) //добавляем в конец очереди
        {
            newElement->previous = currentElement;
            currentElement->next = newElement;
            back = newElement;
        }
        else //добавляем в середину очереди
        {
            Element *nextElement = currentElement->next;
            newElement->previous = currentElement;
            newElement->next = nextElement;
            currentElement->next = newElement;
            nextElement->previous = newElement;
        }
    }
}

template<typename T> T Queue<T>::dequeue() throw(QueueIsEmpty)
{
    if (front == nullptr)
        throw QueueIsEmpty();
    T value = front->value;
    Element *removingElement = front;
    front = front->next;
    delete removingElement;
    if (front == nullptr)
        back = nullptr;
    return value;
}
