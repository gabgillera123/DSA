#ifndef MYHEADER_H
#define MYHEADER_H

#define MAX 5

typedef struct{
    int id;
    char name[20];
    double price;
}Product;

typedef struct{
    Product elems[MAX];
    int front;
    int rear;
}Queue;


void initQueue(Queue *q);
Queue newQueue();

int isEmpty(Queue q);
int isFull(Queue q);

void enqueue(Queue *q, Product item);
Product dequeue(Queue *q);
Product front(Queue q);

void display(Queue q);
void visualize(Queue q);

Product newProduct(int id, char *name, double price);
void displayProduct(Product p);

#endif