#include <bits/stdc++.h>

using namespace std;

template<class T>
class Vector{
	
	private:
		T *data;
		int Size;
		int maxSize;
	public:
		
		Vector(){
			data=NULL;
			Size=0;
			maxSize=0;
		}
		
		Vector(T *arr[],int n){
			Size=n;
			data = new T[Size];
			for(int i=0;i<Size;i++){
				data[i]=arr[i];
			}
			maxSize=n;
		}
		
		int getSize();
		
		void push_back(const T &val);
		
		void pop_back(); 
		
		T back();
		
		T& operator[](int index){
			try{
				if(index<Size && index>=0){
					return data[index];
				}
				else{
					throw "out of bounds";
				}
			}
			catch(const char* msg){
				cout<<msg<<"\n";
			}
		}
		
		friend ostream & operator<<(ostream &Vout,Vector<T> &v){
			Vout<<" [ ";
				for(int i=0;i<v.getSize();i++){
					Vout<<v[i]<<" ";
				}
			Vout<<"]";
			return Vout;
		}
		
		~Vector(){
			if(data!=NULL){
				delete [] data;
			}
		}
};

template<class T>
int Vector<T>::getSize(){
	return Size;
}

template<class T>
void Vector<T>::push_back(const T &val){
	if(maxSize==Size){
		maxSize+=maxSize;
		T *data1 =new T[maxSize];
		for(int i=0;i<Size;i++){
			data1[i]=data[i];
		}
		if(data==NULL)
			delete [] data;
		data=data1;
	}
	data[Size]=val;
	Size++;
}

template<class T>
void Vector<T>::pop_back(){
	try{
		if(Size!=0){
			Size--;
		}
		else{
			throw "Vector is empty";
		}
	}
	catch(const char* msg){
		cout<<msg<<"\n";
	}
}

template<class T>
T Vector<T>:: back(){
	try{
		if(Size!=0){
			return data[Size-1];
		}
		else{
			throw "Vector is empty";
		}
	}
	catch(const char* msg){
		cout<<msg<<"\n";
	}
}


int main(){
	Vector<int> v;
	v.push_back(1);
	v.push_back(2);
	v.push_back(3);
	v.pop_back();
	v.push_back(4);
	v.push_back(5);
	v.push_back(6);
	cout<<v[4]<<"\n";
	cout<<v.back()<<"\n";
	cout<<v<<"\n";
	//now implementing with other data type
	Vector<char> v1;
	v1.push_back('m');
	v1.push_back('a');
	v1.push_back('h');
	v1.push_back('i');
	v1.pop_back();
	v1.push_back('e');
	v1.push_back('s');
	v1.push_back('h');
	cout<<v1[5]<<"\n";
	cout<<v1.back()<<"\n";
	cout<<v1<<"\n";
	return 0;
}