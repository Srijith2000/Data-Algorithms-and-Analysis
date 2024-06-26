#include<iostream>
#include<fstream>
using namespace std;
class countingSort{
	long int A[10010],B[10010];
	public:
		void readInput(int n,int choice){
			ifstream fin;
			switch(choice){
				case 0:fin.open("Input10.txt");break;
				case 1:fin.open("Input50.txt");break;
				case 2:fin.open("Input100.txt");break;
				case 3:fin.open("Input500.txt");break;
				case 4:fin.open("Input1000.txt");break;
				case 5:fin.open("Input5000.txt");break;
				case 6:fin.open("Input10000.txt");break;
			}
			for(int i=0;i<n;i++)
				fin>>A[i];
			fin.close();
		}
		void writeOutput(int n){
			ofstream fout("OutputCountSort.txt");
			for(int i=0;i<n;i++)
				fout<<B[i]<<"\t";
			fout.close();
		}
		void count_sort(int n,int k,int& count){
			int C[k+1];
			for(int i=0;i<=k;i++)
				C[i]=0;
			for(int j=0;j<n;j++)
				C[A[j]]++;
			for(int i=1;i<=k;i++)
				C[i]+=C[i-1];
			for(int j=n-1;j>=0;j--){
				count++;
				B[C[A[j]]-1]=A[j];
				C[A[j]]--;
			}
		}
};
int main(){
	int choice,n,count;
	countingSort cs;
	int len[7]={10,50,100,500,1000,5000,10000};
	int k[7]={6,20,40,200,400,2000,4000};
	for(int i=0;i<7;i++){
		n=len[i];
		cs.readInput(n,i);
		count=0;
		cs.count_sort(n,k[i],count);
		cout<<"For input size="<<n<<",Number of comparisons:"<<count<<endl;
		cs.writeOutput(n);
	}	
}
