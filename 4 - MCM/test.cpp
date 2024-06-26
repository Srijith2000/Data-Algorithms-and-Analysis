#include<iostream>
#include<limits.h>
using namespace std;
class MCM{
	private:
		int P[1000];
		int M[1000][1000];
		int s[1000][1000];
	public:
		void input(int size){
			cout<<"\nEnter elements of P array : ";
			for(int i=0;i<=size;i++){
				cin>>P[i];
			}
		}
		int MCM_DC(int i, int j){
			if(i==j)
				return 0;
			M[i][j] = INT_MAX;
			for(int k=i;k<j;k++){
				int q = MCM_DC(i,k) + MCM_DC(k+1,j) + P[i-1]*P[k]*P[j];
				if(q<M[i][j])
					M[i][j] = q;
			}
			return M[i][j];
		}
		void MCM_DP_BT(int &m1, int &s1, int size){
			int n = size;
			for(int i=1;i<=n;i++){
				M[i][i] = 0;
			}
			for(int l=1;l<n;l++){
				for(int i=1;i<=n-l;i++){
					int j = i+l;
				    M[i][j] = INT_MAX;
    				for(int k=i;k<j;k++){
    						int q = M[i][k]+M[k+1][j]+P[i-1]*P[k]*P[j];
    						if(q<M[i][j])
    						{
    						s[i][j] = k;
    						M[i][j] = q;
    						}
    				}
				}
			}
				m1 = M[1][n];
			    s1 = s[1][n];
		}
		int MCM_DP_TB(int i, int j){
		    if(M[i][j]>=0)
		        return M[i][j];
		    else if(i==j){
		        M[i][i] = 0;
		        return M[i][i];
		    }
		    else{
		        int t = INT_MAX;
		        for(int k=i;k<j;k++){
		            int q = MCM_DP_TB(i,k) + MCM_DP_TB(k+1,j) + P[i-1]*P[k]*P[j];
		            if(q<t){
		                t = q;
		                M[i][j] = t;
		            }
		        }
		        return M[i][j];
		    }
		}
		void OPT_PAR(int i, int j){
			if(i==j)
				cout<<"A"<<i;
			else{
				cout<<"(";
				OPT_PAR(i,s[i][j]);
				OPT_PAR(s[i][j]+1,j);
				cout<<")";
			}
		}
};

int main(){
	cout<<"hello";
}
