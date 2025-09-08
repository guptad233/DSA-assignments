
// Q-1
#include <stdio.h>
#define SIZE 5

int queue[SIZE], front=-1, rear=-1;
void enqueue(int x){
    if(rear==SIZE-1) printf("Queue is full\n");
    else{
        if(front==-1) front=0;
        queue[++rear]=x;
        printf("%d inserted\n",x);
    }
}
void dequeue(){
    if(front==-1||front>rear) printf("Queue is empty\n");
    else printf("%d removed\n",queue[front++]);
}
void display(){
    if(front==-1||front>rear) printf("Queue is empty\n");
    else{
        for(int i=front;i<=rear;i++) printf("%d ",queue[i]);
        printf("\n");
    }
}
void peek(){
    if(front==-1||front>rear) printf("Queue empty\n");
    else printf("Front: %d\n",queue[front]);
}
int main(){
    int ch,x;
    while(1){
        printf("1-Enqueue 2-Dequeue 3-Display 4-Peek 5-Exit\n");
        scanf("%d",&ch);
        if(ch==1){scanf("%d",&x);enqueue(x);}
        else if(ch==2) 
        {
            dequeue();
        }
        else if(ch==3) 
        {
        display();
        }
        else if(ch==4) 
        {
        peek();
        }
        else if(ch==5) 
        {
            break;
        }
        else
         {
            continue;
         }
    }
}
