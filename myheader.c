#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "myheader.h"

void initQueue(Queue *q){
    q->rear = 2;
    q->front = 2;
}

Queue newQueue(){
    Queue q;
    
    q.rear = MAX - 1;
    q.front = MAX - 1;
    
    return q; //same thing but just returns the queue
}

Product newProduct(int id, char *name, double price){
    Product p;
    
    p.id = id;
    strcpy(p.name, name);
    p.price = price;
    
    return p;
}

void displayProduct (Product p){
    printf("[");
    printf("%d, ", p.id);
    printf("%s, ", p.name);
    printf("%.lf ]", p.price);
}

int isEmpty(Queue q){
    return q.front == q.rear;    
}

int isFull(Queue q){
    return q.front == (q.rear + 1) % MAX; 
}

void enqueue(Queue *q, Product item){
    if(!isFull(*q)){
        q->elems[q->rear] = item;
        q->rear = (q->rear + 1) % MAX; //goes around the circular queue before landing on the correct index
    }
}

Product dequeue(Queue *q){
    Product data;
    if(!isEmpty(*q)){
        data = q->elems[q->front];
        q->front  = (q->front + 1) % MAX; //basically % MAX is an indicator to move around (in a circle) the queue
    }
    return data;
}
Product front(Queue q){
    Product data;
    if(!isEmpty(q)){
       data = q.elems[q.front]; //basically dequeue but you dont need to move the front of it
    }
    return data;
}

void display(Queue q){
    printf("{");
    while(!isEmpty(q)){
        displayProduct(dequeue(&q));
        
        if(!isEmpty(q)){
            printf(", ");
        }
    }
    printf("}\n");
}

void visualize(Queue q){
    printf("%-10s | %-10s | %-10s | %s\n", "INDEX", "ID", "NAME", "PRICE");
    for(int i = 0; i < MAX; ++i){
        printf("%-10d | %-10d | %-10s | %-10lf", i, q.elems[i].id, q.elems[i].name, q.elems[i].price);
        if(i == q.front){
            printf(" -> front");
        } 
        if(i == q.rear){
            printf(" -> rear");
        }
        printf("\n");
    }
}