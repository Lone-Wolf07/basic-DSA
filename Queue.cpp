#include <iostream>
using namespace std;

#define SIZE 5

class Queue{
	private:
		int frontIndex;
		int rearIndex;
		int countval; //needed 
		int Q[SIZE];
	public:
		Queue(){	//constructor intialisation
			frontIndex = -1;
			rearIndex = -1;
			countval = 0;
		}
		/*int count(){
			return rearIndex + 1;	//wont work cuz in case of deQueue rearIndex doesn't change value
		}*/
		int count(){
			return countval;
		}
		int isEmpty(){
			return (count()==0);
		}
		int isFull(){
			return (count()==SIZE);
		}
		
		bool enQueue(int v){
			if (isFull()) return false; //queue overflow case 
			//first insertion
			if (isEmpty()) frontIndex=0;
			rearIndex ++;
			countval++;
			Q[rearIndex] = v;
			return true;
		}
		int deQueue(){
			if (isEmpty()) return false; //queue underflow case
			int v;
			v = Q[frontIndex];
			countval--;
			frontIndex ++;
			return v;
		}
		void display(){
			int i;
			for(i=frontIndex; i<=rearIndex; i++){
				cout<<Q[i]<<"  ";
			}
			cout<<endl;
		}
};


int main(){
	Queue queue;
	
	queue.enQueue(4);
	queue.enQueue(123);
	queue.enQueue(45);
	cout<<queue.deQueue()<<endl;
	queue.display();
		
	cout<<queue.isEmpty();
	
	return 0;
}
