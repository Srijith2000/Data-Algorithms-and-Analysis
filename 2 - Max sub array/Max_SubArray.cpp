#include<iostream> 
#include<fstream> 
#include<limits>
using namespace std;
struct ret_values{
	int n1,n2,n3;
};
int count;
class Max_Subarray{
	private:
		int a[10009];
	public:	
	void readInput(int n){
		ifstream fin("input.txt");
		for (int i=0; i<n; i++)  fin>>a[i];
		fin.close();
	}
	ret_values max_cross(int low, int mid, int high){
		ret_values CS;
		int lsum = INT_MIN;
		int sum = 0,lmax,rmax;
		for(int i=mid; i>low; i--){
			sum= sum+a[i];
			count++;
			if(sum>lsum){
				lsum=sum;
				lmax=i;
			}
		}
		int rsum = INT_MIN;
		sum=0;
		for(int j=mid+1; j<high; j++){
			sum= sum+a[j];
			count++;
			if(sum>rsum){
				rsum=sum;
				rmax=j;
			}
		}
		CS.n1=lmax; CS.n2=rmax; CS.n3= lsum+rsum;
		return CS;
	}
	ret_values max_sub(int low, int high){
		ret_values S,Left,Right,Cross;
		if(high==low){
			S.n1=low; S.n2=high; S.n3=a[low];
			return S;
		}
		else{
			int ll,lh,lsum,rl,rh,rsum,crl,crh,crsum;
			int mid= (low + high)/2;
			Left =max_sub(low,mid);
			Right =max_sub(mid+1,high);
			Cross =max_cross(low,mid,high);
			count++;
			if(lsum>=rsum && lsum>=crsum)	S=Left;
			else if(rsum>=lsum && rsum>=crsum)	S=Right;
			else	S=Cross;
		}
		return S;
	}
	ret_values max_sub_BF2(int n){
		int max_sum,l,h;
			max_sum=-9999999;
			int sum;
			ret_values r;
			r.n2=r.n1=r.n3=0;
			for(int i=0;i<n;i++)
			{
				sum=0;
				for(int j=i;j<n;j++)
				{
					sum=sum+a[j];
					count++;
					if(sum>max_sum)
					{
						max_sum=sum;
						l=i;
						h=j;
					}	
				}
			}
			r.n2=h;
			r.n1=l;
			r.n3=max_sum;
			return r;
	}
};

int main()
{
	Max_Subarray s;
	ret_values R;
	int ch;
	int len[7]={10,50,100,500,1000,5000,10000};
	do{
		cout<<"\n\n1. Max sub_array by divide and conquer \n2. Max sub_array by Brute force \n3. Exit";
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
	}while(ch!=3);
}
