#include <stdio.h>
#include <stdlib.h>


#define N 5

struct TQueue{
        char buffer[N];
        int summit;
};

struct TQueue buffer;

bool push (struct TQueue *b, unsigned char c){
    if(b->summit >= N)
        return false;

    b->buffer[b->summit++] = c;
    return true;
}

bool pop (struct TQueue *b, unsigned char c){
    if(b->summit >= 0)
        return false;

    b->buffer[b->summit--] = c;
}

void imprime(struct TQueue *b){
    for(int i=0; i<7; i++)
        printf("%c", &b->buffer[i]);
}

int main(int argc, char *argv[]){

    unsigned char c = 'p';

    push(TQueue *buffer, c);
    pop(TQueue * buffer, c);
    imprime(TQueue);


	    return EXIT_SUCCESS;
}
