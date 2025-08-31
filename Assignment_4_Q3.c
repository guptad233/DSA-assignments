#include <stdio.h>
#include <stdlib.h>
#define SIZE 100
typedef struct{int arr[SIZE];int front,rear;}Queue;
void init(Queue*q){q->front=q->rear=-1;}
int isEmpty(Queue*q){return q->front==-1;}
void enqueue(Queue*q,int x){
    if(q->rear==SIZE-1) return;
    if(q->front==-1) q->front=0;
    q->arr[++q->rear]=x;
}
int dequeue(Queue*q){
    if(isEmpty(q)) return -1;
    int v=q->arr[q->front];
    if(q->front==q->rear) q->front=q->rear=-1;
    else q->front++;
    return v;
}
int main(){
    Queue q;init(&q);
    int n,x;scanf("%d",&n);
    for(int i=0;i<n;i++){scanf("%d",&x);enqueue(&q,x);}
    Queue first,second;init(&first);init(&second);
    for(int i=0;i<n/2;i++) enqueue(&first,dequeue(&q));
    while(!isEmpty(&q)) enqueue(&second,dequeue(&q));
    while(!isEmpty(&first)&&!isEmpty(&second)){
        printf("%d %d ",dequeue(&first),dequeue(&second));
    }
}
