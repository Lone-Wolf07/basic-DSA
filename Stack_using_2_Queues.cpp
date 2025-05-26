#include <iostream>
using namespace std;

#define SIZE 5

class Queue{
    private:
        int front,rear;
        int countval;
        int Q[SIZE];
    public:
        Queue(){
            front = rear = -1;
            countval = 0;
        }
        int count(){
            return countval;
        }
        bool isEmpty(){
            return (count()==0);
        }
        bool isFull(){
            return (count()==SIZE);
        }
        bool enQueue(int v){
            if (isFull()){
                cout<<"Queue is full!!"<<endl;
                return false;
            }
            if(isEmpty()){
                front = 0;
            }
            rear = (rear+1)%SIZE;       //circular queue
            Q[rear] = v;
            countval++;
            return true;
        }
        int deQueue(){
            if (isEmpty()){
                cout<<"Queue is empty!!"<<endl;
                return INT16_MAX;
            }
            int v;
            if (front == rear){     //one element case
                v=Q[front];
                front = rear = -1;
            }
            else{
                v=Q[front];
                front = (front+1)%SIZE;
            }
            countval--;
            return v;
        }





        void display(){
            int i;
            if (front<= rear){      //normal condition 
                for(i=front; i<rear; i++){
                    cout<<Q[i]<<" ";
               }
            }
            else{
                for (i=front; i<SIZE; i++){     //print first half 
                    cout<<Q[i]<<" ";
                }
                for (i=0; i<=rear; i++){        //remaining section 
                    cout<<Q[i]<<" ";
                }
            }
            cout<<"\n";
        }
};

int main(){
    //stack using 2 queues
    Queue q1,q2;
    //stack = q1 as o/p
    int o=2;
    while(o<3){
        cout<<"Enter value 1.push 2.pop 3.print 4.exit";
        cin>>o;
        switch(o){
            case 1: //push in constant time
                int val;
                cout<<"Enter element to push: ";
                cin>>val;
                q1.enQueue(val);
                break;
            case 2: //pop in linear time
                if(q1.isEmpty()){
                    cout<<"Empty stack"<<endl;
                }
                //pop all elements except one in q1
                while(q1.count()!=1){
                    q2.enQueue(q1.deQueue());   //our pop gets n removes the value 
                }
                //dequeue the last element in q1 and that is the result 
                int res; 
                res = q1.deQueue();
                cout<<"Popped element is "<<res<<endl;
                //now swap
                swap(q1,q2);
                break;
            case 3:
                cout<<"Stack is given by :"<<endl;
                q1.display();
                break;



            case 4:
                cout<<"Exiting ...";
                break;
        }
    }
}
