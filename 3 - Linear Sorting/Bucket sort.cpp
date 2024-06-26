#include <iostream>
#include <fstream>
#include <cmath>
using namespace std;

struct Node
{ double data; Node* next; };

class List{
	Node *A; int size,count;
public:
	List(){
		A=NULL; 
		size = 0; 
	}
	bool search (int n, double& data){
		Node* temp = A;
		int c=1; 
		while (temp != NULL){
			count++; 
			if(c==n){ 
				data=temp->data; return true; } 
			temp = temp->next; 
			c++;
		} return false; 
	}
	void insert (double data){ 
		Node* N = new Node;
		N->data = data; 
		N->next = A;
		A=N;
		size ++; 
	} 
	void sort (int& count){ 
		Node* i;
		Node* j; 
		double t;
		i= A;
		for (i= A; i!= NULL; i= i->next)
			for (j= i->next; j!= NULL; j= j->next)
				if(j->data < i->data){
					t= i->data;
					i->data = j->data;
					j->data=t; 
					count++; 
				}
		}
};

class Bucketsort{
	double A[10000]; 
public:
	void readinput(int n){ 
		ifstream fin("uni_rand.txt");
		for (int i=0; i<n; i++) fin>>A[i];
	}
	void writeoutput (int n){
		ofstream fout ("output-BS.txt");
		for(int i=0; i<n; i++) fout<<A[i]<<"\t";
	}
	void bucketsort(int n, int& count){ 
		List* bs= new List[n];
		for (int i=0; i<n; i++){
			count++;
			bs[(int)floor(A[i]*n)].insert(A[i]);
		}
		for(int i=0; i<n; i++)
			bs[i].sort(count);
		double t;
		int j=0;
		for(int i=0; i<n;i++)
			for(int k=1; k<=sizeof(bs[i]); k++) 
				if (bs[i].search(k,t))	A[j++]=t;
		}
};
int main()
{
	Bucketsort b;
	int count, size;
	cout<<"Enter Array size:";
	cin>>size;
	b.readinput(size);
	count = 0;
	b.bucketsort(size, count);
	b.writeoutput(size);
	cout<<endl<<" No of operations: "<<count;
	return 0;
}


