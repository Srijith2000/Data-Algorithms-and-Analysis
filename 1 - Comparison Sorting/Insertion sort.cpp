#include<iostream>
#include<fstream>
#include<limits>
using namespace std;

class sort{
	private: 
		long int a[10009];
		int heapsize,len,counts;
	public:
		void readInput(int n){
			ifstream fin("input.txt");
			for (int i=0; i<n; i++)  fin>>a[i];
			fin.close();
		}
		void writeOutput(int n){
			ofstream fout("output.txt");
			for (int i=0; i<n; i++)  fout<<a[i]<<"\t"; //change a[i] to [n-1-i] for desc order output
			fout.close();
		}
		int insertionSort(int n){
			int count=0;
			int key,j;
			for(int i=1; i<n; i++){
				key=a[i];
				j=i-1;
				count++;
				while(j>=0 && a[j]>key){
					a[j+1] = a[j];
					j=j-1;
					count++;
				}
				a[j+1]=key;
			}
			return count;
		}
		void mergeSort(int p, int r, int &count){
			if(p<r){
				int q=(p+r)/2;
				mergeSort(p, q, count);
				mergeSort(q+1, r, count);
				merge(p,q,r,count);
			}
		}
		void merge(int p, int q, int r, int &count){
			int i,j;
			int n1=q-p+1;
			int n2=r-q;
			int L[n1+1], R[n2+1];
			for(int i=0; i<n1; i++)
				L[i]=a[p+i];
			L[n1]= INT_MAX;
			for(int j=0; j<n2; j++)
				R[j]=a[q+j+1];
			R[n2]=INT_MAX;
			i=0; j=0;
			for(int k=p; k<=r; k++){
				count++;
				if(L[i]<=R[j]){
					a[k]=L[i];
					i++;	
				}
				else{
					a[k]=R[j];
					j=j+1;
				}
			}	
		}
		int heapsort(int n){
			counts=0;
			len = n-1;
			buildmaxheap();
			int temp;
			for(int i=len;i>=1;i--){
				temp=a[0];
				a[0]=a[i];
				a[i]=temp;
				heapsize=heapsize-1;
				maxheapify(0);
			}
			return counts;
		}
		void buildmaxheap(){
			heapsize=len;
			for(int i=len;i>=0;i--){
				maxheapify(i);
			}
		}
		void maxheapify(int num){
			int temp,largest,l,r;
			l=2*num;
			r=(2*num)+1;
			if(l<=heapsize && a[l]>a[num]){
				largest=l;
				counts++;
			}
			else{
				largest=num;
				counts++;
			}
			if(r<=heapsize && a[r]>a[largest]){
				largest=r;
			}
			if(largest!=num){
				temp=a[num];
				a[num]=a[largest];
				a[largest]=temp;
				maxheapify(largest);
			}
		}
		int partition(int p, int r, int &count){
			int x=a[r], i=p-1;
			int temp;
			for(int j=p; j<=r-1; j++){
				count++;
				if(a[j]<=x){
					i++;
					temp=a[i];	a[i]=a[j];	a[j]=temp;
				}	
			}
			temp=a[i+1];	a[i+1]=a[r];	a[r]=temp;
			return i+1;
		}
		void quicksort(int p,int r, int &count){
			if(p<r){
				int q=partition(p,r,count);
				quicksort(p,q-1,count);
				quicksort(q+1,r,count);
			}
		}
};

int main()
{
	sort s;
	int ch;
	int len[7]={10,50,100,500,1000,5000,10000};
	do{
		cout<<"1. Insertion sort \n2. Merge sort \n3. Heap sort \n4. Quick sort \n5. Exit";
		cout<<"\nEnter choice : ";
		cin>>ch;
		if(ch>=5) break;
		for(int i=0; i<7; i++){
			int count=0;
			int n=len[i];
			s.readInput(n);
			switch(ch){
				case 1: count=s.insertionSort(n); break;
				case 2: s.mergeSort(0,n-1,count); break;
				case 3: count= s.heapsort(n); break;	
				case 4: s.quicksort(0,n,count); break;	
			}
			s.writeOutput(n);
			cout<<"Input size : "<<n<<"\tComp no : "<<count<<endl;
		} 
	}while(ch!=5);
}
