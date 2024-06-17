#include<bits/stdc++.h>

using namespace std;

const int sz=100000;
template<class T>
class Queue{
	private :
		T *q;
		int front,rear;
	public:
		Queue(){
			q=new T[sz+1];
			front=0;
			rear=0;
		}
		bool isEmpty();
		void enqueue(T val);
		void dequeue();
		T Front();
		~Queue(){
			delete [] q;
		}
};


template<class T>
bool Queue<T>::isEmpty(){
	if(rear==front){
		return true;
	}
	else{
		return false;
	}
}

template<class T>
void Queue<T>::enqueue(T val){
	try{
		if(rear!=sz){
			q[rear]=val;
			rear++;
		}
		else{
			throw "Queue is Full";
		}
	}
	catch(const char* msg){
		cout<<msg<<"\n";
	}
}

template<class T>
void Queue<T>::dequeue(){
	try{
		if(!isEmpty()){
			front++;
		}
		else{
			throw "Queue is empty";
		}
	}
	catch(const char* msg){
		cout<<msg<<"\n";
	}
}

template<class T>
T Queue<T> :: Front(){
	try{
		if(!isEmpty()){
			return q[front];
		}
		else{
			throw "Queue is empty";
		}
	}
	catch(const char* msg){
		cout<<msg<<"\n";
	}
}

int main(){
	// data type is int 
	Queue<int>q;
	q.dequeue();
	cout<<q.Front()<<"\n";
	cout<<q.isEmpty()<<"\n";
	q.enqueue(21);
	q.enqueue(22);
	q.enqueue(23);
	q.enqueue(24);
	cout<<q.Front()<<"\n";
	q.dequeue();
	cout<<q.Front()<<"\n";
	q.dequeue();
	cout<<q.Front()<<"\n";
	q.dequeue();
	cout<<q.Front()<<"\n";
	q.dequeue();
	cout<<q.Front()<<"\n";
	q.dequeue();
	// data type is char
	Queue<char>q1;
	q1.Front();
	q1.dequeue();
	q1.enqueue('m');
	q1.enqueue('a');
	q1.enqueue('h');
	q1.enqueue('i');
	cout<<q1.Front()<<"\n";
	q1.dequeue();
	cout<<q1.Front()<<"\n";
	q1.dequeue();
	cout<<q1.Front()<<"\n";
	q1.dequeue();
	cout<<q1.Front()<<"\n";
	q1.dequeue();
	q1.Front();
	return 0;
}