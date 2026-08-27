#include<stdio.h>
#define size 10

int hashtable[size];
void init()
{
    for(int i = 0;i<size;i++)
    {
        hashtable[i]=-1;
    }
}
void insert(int key ){
    int index = key%size;
    int i=0;
    while(hashtable[(index+ i*i)%size]!=-1)
    {
        if(i==size){
            break;
        }
        i++;
    }
    hashtable[(index+i*i)%size]=key;
}
void display()
{
    for(int i=0;i<size;i++)
    {
        if(hashtable[i]!=-1)
        {
            printf("%d --> %d\n",i,hashtable[i]);
        }else{
            printf("%d --- > empty\n",i);
        }
    }
}
int main()
{
    init();
    insert(25);
    insert(19);
    insert(16);
    insert(26);
    insert(36);
    display();
    
}