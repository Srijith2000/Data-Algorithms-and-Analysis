//graph Floyd Warshall
#include<iostream>
using namespace std;

class FW_graph{
	int w[10][10];
	int d[10][10], pi[10][10];
	int rows;
	public:
	void getip(){
		rows=5;
		cout<<"Enter I/P Matrix "<<rows<<"x"<<rows<<" :\n";
		for(int i=0; i<rows; i++)
		  for(int j=0; j<rows; j++){
	   	  		  cin>>w[i][j];
	   	  		  pi[i][j]=0;
	   	  	}
	}
	void FW(){
		int n= rows;
		for(int i=0; i<rows; i++)
		  for(int j=0; j<rows; j++)
		  		  d[i][j]=w[i][j];
		for(int k=0; k<n; k++)
		  for(int i=0; i<n; i++)
		    for(int j=0; j<n; j++){
		    	if(d[i][j]>= d[i][k]+ d[k][j]){
		    		d[i][j] = d[i][k]+ d[k][j];
		    		pi[i][j] = pi[k][j];
				}
			}
	}
	void disp(){
		cout<<"\nINPUT Matrix:\n";
		for(int i=0; i<rows; i++){
		  for(int j=0; j<rows; j++){
		  		  if(w[i][j]==99999)	cout<<"inf\t";
		  		  else	cout<<w[i][j]<<"\t";
		  	}
		  cout<<endl;
  		  }
		cout<<"\nMatrix D:\n";
		for(int i=0; i<rows; i++){
		  for(int j=0; j<rows; j++)
		  		  cout<<d[i][j]<<"\t";
		  cout<<endl;
  		  }
  		cout<<"\nMatrix Pi:\n";  
  		for(int i=0; i<rows; i++){
		  for(int j=0; j<rows; j++)
		  		  cout<<pi[i][j]<<"\t";
		  cout<<endl;
  		  }
	}
};

int main(){
	FW_graph s;
	s.getip();
	s.FW();
	s.disp();
}
