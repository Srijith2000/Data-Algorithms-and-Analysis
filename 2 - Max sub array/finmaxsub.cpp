#include<iostream>
#include<fstream>
#include<limits.h>
using namespace std;
struct retval
{
	int low;
	int high;
	int val;
	int count;
};
class maximum_subarray_prob
{
	private:
		int a[100010];
		int divconcount,brutecount;
	public:
	    maximum_subarray_prob()
	    {
	        divconcount=0;
	        brutecount=0;
	    }
		void readinput(int n)
		{	
			ifstream fin("input.txt");
			for(int i=0;i<n;i++)	
				fin>>a[i];	
			fin.close();
		}
		retval bruteforcestrategy(int n)
		{
			int max_sum,l,h;
			max_sum=-9999999;
			int sum;
			retval r1;
			r1.high=r1.low=r1.val=0;
			for(int i=0;i<n;i++)
			{
				sum=0;
				for(int j=i;j<n;j++)
				{
					sum=sum+a[j];
					brutecount++;
					if(sum>max_sum)
					{
						max_sum=sum;
						l=i;
						h=j;
					}	
				}
			}
		//	cout<<endl<<"Low:"<<l<<"\t"<<"High:"<<h<<"\t"<<"Sum(value):"<<max_sum;
		//	cout<<endl<<"Number of comparisons: "<<brutecount<<endl;
			r1.high=h;
			r1.low=l;
			r1.val=max_sum;
			r1.count=brutecount;
			return r1;
		}
		retval rec_maxsubarray(int low,int high)
		{
			int l,h,max_sum;
			retval r1,r2,r3;
			if(high==low)
			{	
				l=low;
				h=high;
				max_sum=a[low];
				r1.low=l;
				r1.high=h;
				r1.val=max_sum;
				return r1;
			}	
			else
			{
				int mid=(low+high)/2;
				r1=rec_maxsubarray(low,mid);
				r2=rec_maxsubarray(mid+1,high);
				r3=rec_crosssubarray(low,mid,high);
				
		//		cout<<endl<<"Number of comparisons: "<<divconcount<<endl;
				if((r1.val>=r2.val)&&(r1.val>=r3.val))
					return r1;
				else if((r2.val>=r1.val)&&(r2.val>=r3.val))
					return r2;
				else
					return r3;
			}
		}
		retval rec_crosssubarray(int low,int mid,int high)
		{
			int leftsum=-9999999;
			int sum,max_left,max_right;
			sum=0;
			retval r;
			for(int i=mid;i>=low;i--)
			{
				sum=sum+a[i];
				divconcount++;
				if(sum>leftsum)
				{
					leftsum=sum;
					max_left=i;
				}
			}
			int rightsum=-999999;
			sum=0;
			for(int i=mid+1;i<=high;i++)
			{
				sum=sum+a[i];
				divconcount++;
				if(sum>rightsum)
				{
					rightsum=sum;
					max_right=i;
				}
			}
			r.low=max_left;
			r.high=max_right;
			r.val=leftsum+rightsum;
			r.count=divconcount;
			return r;
		}
};
int main()
{
	maximum_subarray_prob m;
	retval ans;
	int len[]={10,50,100,500,1000,5000,10000};
	int choice;
	cout<<"1.BRUTE FORCE STRATEGY\n2.DIVIDE AND CONQUER:\nENTER YOUR CHOICE:\n";
	cin>>choice;
	switch(choice)
	{
	    case 1:
	        for(int i=0;i<7;i++)
	        {
	            m.readinput(len[i]);
	            ans=m.bruteforcestrategy(len[i]);
	            cout<<endl<<"Low:"<<ans.low<<"\t"<<"High:"<<ans.high<<"\t"<<"Sum(value):"<<ans.val<<"\tComparisons:"<<ans.count<<endl;
	        }
	        break;
	    case 2:
	        for(int i=0;i<7;i++)
	        {
	            m.readinput(len[i]);
	            ans=m.rec_maxsubarray(0,(len[i]-1));
	            cout<<endl<<"Low:"<<ans.low<<"\t"<<"High:"<<ans.high<<"\t"<<"Sum(value):"<<ans.val<<"\tComparisons:"<<ans.count<<endl;
	        }
	        break;
	}
	
	
}
