#include <stdlib.h>
#include <stdio.h>

#define N 5
#define LONGITUD(x) ((x)->summit - (x)->head)

struct TBuffer
{
    int data[N];
    int head;
    int summit;
};

bool push(struct TBuffer *b, int d)
{
    if(LONGITUD(b) >= N)
        return false;
    b->data[(b->summit) % N] = d;
    b->summit++;

    return true;
}

int shift(struct TBuffer *b){
    if(LONGITUD(b) == 0)
        return 666;
    int d = b->data[(b->head) % N];
    b->head++;
return d;
}

void peep(struct TBuffer b){
    for(int i=b.head; i<b.summit;i++)
        printf("%3i", b.data[i%N]);
    printf("\n");
}
int main(int argc, char *argv[]){

    struct TBuffer buffer;
    buffer.head = 0;
    buffer.summit = 0;

    push(&buffer,2);
    push(&buffer,2);
    push(&buffer,5);
    push(&buffer,3);
    shift(&buffer);
    push(&buffer,7);

    peep(buffer);

    return EXIT_SUCCESS;

}
