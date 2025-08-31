#include <stdio.h>
#define SIZE 100
typedef struct{int arr[SIZE];int f,r;}Queue;
void init(Queue*q){q->f=q->r=-1;}
int isEmpty(Queue*q){return q->f==-1;}
void enqueue(Queue*q,int x){
    if(q->r==SIZE-1) return;
    if(q->f==-1) q->f=0;
    q->arr[++q->r]=x;
}
int dequeue(Queue*q){
    if(isEmpty(q)) return -1;
    int v=q->arr[q->f];
    if(q->f==q->r) q->f=q->r=-1;
    else q->f++;
    return v;
}
int main(){
    Queue q1,q2;init(&q1);init(&q2);
    int ch,x;
    while(1){
        printf("1-Push 2-Pop 3-Exit\n");
        scanf("%d",&ch);
        if(ch==1){
            scanf("%d",&x);enqueue(&q2,x);
            while(!isEmpty(&q1)) enqueue(&q2,dequeue(&q1));
            Queue t=q1;q1=q2;q2=t;
        }
        else if(ch==2){
            if(isEmpty(&q1)) printf("Empty\n");
            else printf("%d\n",dequeue(&q1));
        }
        else break;
    }
}
