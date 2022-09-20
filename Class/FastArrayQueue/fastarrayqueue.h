#ifndef FASTARRAYQUEUE_H
#define FASTARRAYQUEUE_H

#define DEFAULT_QUEUE_SIZE 5


class FastArrayQueue
{
private:
    int *L;
    int curSize;
    int maxSize;
    int in;
    int out;

public:
    FastArrayQueue(int maxSize = DEFAULT_QUEUE_SIZE);   //constructor
    ~FastArrayQueue();  //destructor
    void enQueue(int e);
    void append(int e) { enQueue(e); }
    int deQueue();
    int remove() { return deQueue(); }
    int front();
    int head() { return front(); }
    int rear();
    int back() { return rear(); }

    void clear();

    void display();
    int size(){return curSize;}
    void clsrc();

};

#endif // FASTARRAYQUEUE_H
