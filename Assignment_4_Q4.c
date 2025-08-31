#include <stdio.h>
#include <string.h>
#define SIZE 256
char q[SIZE];int front=-1,rear=-1;
int freq[256];
void enqueue(char c){
    if(rear==SIZE-1) return;
    if(front==-1) front=0;
    q[++rear]=c;
}
void dequeue(){
    if(front==-1||front>rear) return;
    front++;
}
char getFront(){
    if(front==-1||front>rear) return 0;
    return q[front];
}
int main(){
    char s[100];scanf("%s",s);
    for(int i=0;i<strlen(s);i++){
        char c=s[i];
        freq[c]++;
        enqueue(c);
        while(front<=rear&&freq[getFront()]>1) dequeue();
        if(front>rear) printf("-1 ");
        else printf("%c ",getFront());
    }
}
