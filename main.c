#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "myheader.h"

int main(){
    Queue q1 = newQueue();
    
    display(q1);
    visualize(q1);
    
    enqueue(&q1, newProduct(23101517, "Gabriel Gillera", 11.30));
    display(q1);
    enqueue(&q1, newProduct(23101518, "Lael Tagalog", 100.15));
    display(q1);

    visualize(q1);
    

    
    return 0;
}