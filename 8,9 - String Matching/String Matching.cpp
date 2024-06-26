//String matching
#include<iostream>
#include<cstring>
#include<math.h>
using namespace std;

class StrMatch{
private:
	string T,P;
	int pi[100];
	int m,n;
public:
	void getIP(){
		P=" GTXCGGGTXCGTXC";
		T=" GTGTXCGGGTXCGTXCGGGTXCGTXCGTCG";
		for(int i=0; i<100; i++)	pi[i]=0;
		n= T.length()-1;
		m= P.length()-1;
	}
	void disp(){
		cout<<"Pattern: "<<P;
		cout<<"\nText: "<<T;
		cout<<endl;
	}
	//NAIVE
	int Naive(){
		int count=0,flag;
		for (int s=0; s<=(n-m); s++){
			flag=0;
			for(int j=1; j<=m; j++){
				count++;
				if (P[j]!= T[s+j]){
					flag=1;
					break;
				}
			}
			if (flag==0)
			   cout<<"\nPattern occurs with valid shift = "<<s;
		}
		return count;
	}
	
	//RABIN-KARP
	int PreProcess(int d,int q){
		int count=0,p=0;
		for(int i=1; i<=m; i++){
			count++;
			p= (d*p + P[i]) % q;
		}
		cout<<"\nPre Processing count = "<<count;
		return p;
	}
	int RK_Match(int p,int d,int q){
		
		int h = 1;
		for(int i=1;i<m;i++){
			h*=d;
			h = h%q;
		}
		//int h= (int)pow(d,m-1) % q;
		int count=0,flag,t;
		t=0;
		for(int i=1; i<=m; i++){
			count++;
			t= (d*t +T[i]) % q;
		}
		if(t<0)  t+=q;
		for(int s=0; s<=n-m; s++){
			count++;
			flag=0;
			if(p==t){
				for(int j=1; j<=m; j++){
					count++;
					if(P[j]!=T[s+j]){
						flag=1;
						break;
					}
				}
				if (flag==0)
				   cout<<"\nPattern occurs with valid shift = "<<s;
			}
			if(s<(n-m)){
			   t = (d*(t-(T[s+1]*h)) + T[s+m+1]) % q;
			   if(t<0)  t+=q;
			   }
        }
		return count;
	}
	
	//KMP
	void Comp_Prefix(){
		int k=0,count=0;
		pi[1]=0;
		for(int q=2; q<=m; q++){
			count++;
			while(k>0 && P[k+1]!=P[q]){
				k=pi[k];
				count++;
			}
			if(P[k+1]==P[q]) k++;
			pi[q]=k;
		}
		cout<<"\nPre Processing count = "<<count;
	}
	int KMP(){
		int count=0,q=0;
		for(int i=1; i<=n; i++){
			count++;
			while(q>0 && P[q+1]!=T[i]){
				q=pi[q];
				count++;
			}
			if(P[q+1]==T[i])	q++;
			if(q==m){
				cout<<"\nPattern occurs with valid shift = "<<(i-m);
				q=pi[q];
			}
		}
		return count;
	}
};

int main(){
	StrMatch a;
	int c;
	int d=10, q=4999;
	a.getIP();
	a.disp();
		
	cout<<"\n\nNAIVE STRING MATCHING:\n";
	cout<<"\nPre Processing count = 0";
	cout<<"\nNo of comparisons = "<<a.Naive();
	
	cout<<"\n\nRabin-Karp STRING MATCHING:\n";
	c= a.RK_Match(a.PreProcess(d,q) ,d,q);
	cout<<"\nNo of comparisons = "<<c;
	
	cout<<"\n\nKMP STRING MATCHING:\n";
	a.Comp_Prefix();
	cout<<"\nNo of comparisons = "<<a.KMP();
	
	return 0;
}
