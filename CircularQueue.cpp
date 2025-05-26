#include <iostream>
using namespace std;

#define SIZE 6

class CirQueue{
    private:
        int front, rear;
        int Q[SIZE];
        int countval;
    public:
        CirQueue(){
            front = rear = -1;
            countval = 0;
        }
        int count(){
            return countval;
        }
        bool isFull()  {return (count()==SIZE);}
        bool isEmpty()  {return (count()==0);}
        
        bool enQueue(int v){
            if (isFull()){
                cout<<"Queue is Full "<<endl;
                return false;
            }
            else if (isEmpty()){
                front = rear = 0;
            }
            else{
                rear = (rear+1)%SIZE;   //0-->1 1-->2 2-->3 3-->4 4-->5 5-->0 0-->1 ...
            }
            Q[rear]=v;
            countval ++;
            return true;
        }
        int deQueue(){
            int ret;
            if (isEmpty())
                return -1;
            else if(front == rear){
                ret = Q[front];     //just 1 elemt case
                front = rear = -1;
            }
            else{
                ret = Q[front];
                front = (front+1)%SIZE;    //0-->1 1-->2 2-->3 3-->4 4-->5 5-->0 0-->1 ...
            }
            countval--;
            return ret;      
        }

        void display(){
            int i;
            cout<<"The circular array is "<<endl;
            if(front <= rear){
                for (i=front; i<=rear; i++){
                    cout<<Q[i]<<" ";
                }
            }
            else{
                for (i=front; i<SIZE; i++){     //first part from front
                    cout<<Q[i]<<" ";
                }for (i=0; i<=rear; i++){       //remaining part from 0 to rear 
                    cout<<Q[i]<<" ";
                }
            }
            cout<<"\n";
        }
};



int main(){
    CirQueue queue;
    int option=0;
    while(option<7){
        cout<<"Enter a value \n 1.enQueue 2.deQueue 3.isFUll? 4.isEmpty? 5.Number of elements 6.print queue 7.exit"<<endl;
        cin>>option;
        switch (option){
            case 1:
                int val;
                cout<<"Enter value to enter the queue ";
                cin>>val;
                queue.enQueue(val);
                break;
            case 2:
                int ret;
                ret = queue.deQueue();
                cout<<ret<<" is the dequeued value"<<endl;
                break;
            case 3:
                if (queue.isFull())
                    cout<<"The queue is full"<<endl;
                else
                    cout<<"The queue is Not full"<<endl;
                break;
            case 4:
                if (queue.isEmpty())
                    cout<<"The queue is empty"<<endl;
                else
                    cout<<"The queue is Not empty"<<endl;
                break;
            case 5:
                int num;
                num = queue.count();
                cout<<"The number of elements is "<<num<<endl;
                break;
            case 6:
                queue.display();
                break;
            case 7:
                cout<<"Exiting ..."<<endl;
                break;
            default:
                cout<<"Invalid input!!!";               
        }
    }
    return 0;
}
