//LCS: 
#include<iostream> 
#include<fstream> 
#include<limits>
#include<cstring>
using namespace std;
int count;
int c[40][40];	char b[40][40];
class LCS{
	private:
		char X[50],Y[50];
	public:	
	void readInput(){
		ifstream fin("lcs_input.txt"); 
		char s1[100],s2[100];
		fin>>s1;
		fin>>s2;
		X[0]=' ';	Y[0]=' ';
		for(int i=0;i<30; i++){
			X[i+1]=s1[i];
			Y[i+1]=s2[i];
		}
		fin.close();
	}
	void disp(){
		cout<<"X: "<<X<<"\t"<<"Y: "<<Y;	
	}
	void dispMat(int m,int n){
		cout<<endl;
		for(int i=0; i<m; i++){	
			for(int j=0; j<n; j++)
				cout<<c[i][j]<<" ";
			cout<<endl;
		}
		//cout<<endl;
		for(int i=0; i<m; i++){	
			for(int j=0; j<n; j++)
				cout<<b[i][j]<<" ";
			cout<<endl;
		}
	}
	int LCS_Len_DC(int i,int j){
		if(i==0||j==0)	return 0;
		count++;
		if(X[i]==Y[j])
			return LCS_Len_DC(i-1,j-1)+1;
		else{
			int t1= LCS_Len_DC(i-1,j);
			int t2= LCS_Len_DC(i,j-1);
			if(t1>=t2)	return t1;
			else	return t2;
		}
	}
	void LCS_Len_DP_BU(int m,int n){
		count=0;
		for(int j=0; j<=n; j++)	c[0][j]=0;
		for(int i=1; i<=m; i++)	c[i][0]=0;
		for(int i=1; i<=m; i++)	
			for(int j=1; j<=n; j++){
				count++;
				if(X[i]==Y[j]){
					c[i][j]=c[i-1][j-1]+1;
					b[i][j]='D';
				}
				else if(c[i-1][j] >= c[i][j-1]){
					c[i][j]= c[i-1][j];
					b[i][j]='T';
				}
				else{
					c[i][j]= c[i][j-1];
					b[i][j]='L';
				}
			}
	}
	
	int LCS_Len_DP_TD(int i,int j){
		if (c[i][j] >= 0)
			return c[i][j];
		if(i==0 || j==0){
			c[i][j]=0;
			return c[i][j];
		}
		count++;
		if(X[i]==Y[j]){
			c[i][j]= LCS_Len_DP_TD(i-1,j-1) + 1;
			b[i][j]='D';
		}
		else{
			int t1= LCS_Len_DP_TD(i-1,j);
			int t2= LCS_Len_DP_TD(i,j-1);
			if(t1>=t2){
				c[i][j]= t1;
				b[i][j]='T';
			}
			else{
				c[i][j]= t2;
				b[i][j]='L';
			}
			return c[i][j];
		}	
	}
	
	void print_LCS(int i,int j){
		if(i==0||j==0)	return;
		count++;
		if(b[i][j]=='D'){
			print_LCS(i-1,j-1);
			cout<<X[i];
		}
		else if(b[i][j]=='T')
			print_LCS(i-1,j);
		else if(b[i][j]=='L')
			print_LCS(i,j-1);
	}

};

int main()
{
	LCS s;
	int ch;
	int m=6,n=6;
	int len[6]={5,7,10,12,15,17};
	s.readInput();
	s.disp();
	count=0;
	cout<<"\nLCS DC length = "<<s.LCS_Len_DC(m,n);
	cout<<"\nComparison count = "<<count;
	
	count=0;	
	s.LCS_Len_DP_BU(m,n);
	cout<<endl;
	//cout<<endl;
	cout<<"\n\nLCS DP BU length = "<<c[m][n];
	cout<<"\nComparison count = "<<count;
	cout<<"\n\n";	s.print_LCS(m,n);
	cout<<"\n";	s.dispMat(m+1,n+1);
	
	/*count=0;	
	s.LCS_Len_DP_TD(m,n);
	cout<<endl;
	//cout<<endl;
	cout<<"\n\nLCS DP TD length = "<<c[m][n];
	cout<<"\nComparison count = "<<count;
	cout<<"\n\n";	s.print_LCS(m,n);
	cout<<"\n";	s.dispMat(m+1,n+1);
	
	/*do{
		cout<<"\n\n1. LCS by divide and conquer \n2. LCS by Dynamic prog Bottom up appraoch"; 
		cout<<"\nLCS by Dynamic prog Top down appraoch\n3. Exit";
		cout<<"\nEnter choice : ";
		cin>>ch;
		if(ch>=3) break;
		for(int i=0; i<7; i++){
			count=0;
			int n=len[i];
			s.readInput(n);
			switch(ch){
				case 1: R=s.max_sub(0,n-1); break;
				case 2: R=s.max_sub_BF2(n); break;
				case 3: break;		
			}
			//s.writeOutput(n);
			//cout<<"Input size : "<<n<<"\tComp no : "<<count<<endl;
			cout<<"\nLeft index:"<<R.n1<<"  Right Index:"<<R.n2<<"  Sum:"<<R.n3;
			cout<<"\nInput size : "<<n<<"\tComp no : "<<count<<endl;
		} 
	}while(ch!=3);*/
}
