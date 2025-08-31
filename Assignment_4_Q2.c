#include <stdio.h>
#define SIZE 5
int cq[SIZE], front=-1, rear=-1;
void enqueue(int x){
    if((rear+1)%SIZE==front) printf("Queue is full\n");
    else{
        if(front==-1) front=0;
        rear=(rear+1)%SIZE;
        cq[rear]=x;
        printf("%d inserted\n",x);
    }
}
void dequeue(){
    if(front==-1) printf("Queue is empty\n");
    else{
        printf("%d removed\n",cq[front]);
        if(front==rear) front=rear=-1;
        else front=(front+1)%SIZE;
    }
}
void display(){
    if(front==-1) printf("Queue is empty\n");
    else{
        int i=front;
        while(1){
            printf("%d ",cq[i]);
            if(i==rear) break;
            i=(i+1)%SIZE;
        }
        printf("\n");
    }
}
void peek(){
    if(front==-1) printf("Queue empty\n");
    else printf("Front: %d\n",cq[front]);
}
int main(){
    int ch,x;
    while(1){
        printf("1-Enqueue 2-Dequeue 3-Display 4-Peek 5-Exit\n");
        scanf("%d",&ch);
        if(ch==1){scanf("%d",&x);enqueue(x);}
        else if(ch==2) dequeue();
        else if(ch==3) display();
        else if(ch==4) peek();
        else break;
    }
}
