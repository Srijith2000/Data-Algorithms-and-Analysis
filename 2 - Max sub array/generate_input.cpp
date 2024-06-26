#include<iostream>
#include<fstream>
#include<stdlib.h>
#include<time.h>
using namespace std;

int main(){
	ofstream fout("input.txt");
	srand ((long int)clock());
	for (int i=0; i<10009; i++){
		int num=rand()%30;
		if(rand()%2==0)
			fout<< -1 * num<<"\t";
		else 
			fout<<num<<"\t";
		
	}
		fout.close();
		return 0;
}
