#include<bits/stdc++.h>
using namespace std;

void maxConsOnesBF(int arr[],int n,int m)
{
	int mx,count,n_one;
	mx = INT_MIN;
	count = 0;
	n_one = m;
	int j = 0;
	for(int i=0; i<n; i++)
	{
		if(arr[i]==1)
		{
			count++;
		}
		else if (arr[i]==0 && n_one>0)
		{
			count++;
			n_one--;
			if(n_one==1)
				j=i+1;
		}
		else
		{
			count=0;
			n_one = m;
			i=j;
		}

		mx = max(count,mx);
	}

	cout<<mx<<endl;
}

void maxConsOnes(int arr[],int n,int m)
{
	 // code here
        int mx = INT_MIN;
        int zeroCount = 0;
        int j=0;
        for(int i=0; i<n; i++)
        {
            if(arr[i]==0)
            {
                zeroCount++;
            }
            while(zeroCount>m)
            {
                if(arr[j]==0)
                    zeroCount--;
                j++;
            }
            
            mx= max(mx,i-j+1);
        }
	cout<<mx<<endl;
}
int main()
{
	int n,m;
	cin>>n>>m;

	int arr[n];
	for(int i=0; i<n; i++)
		cin>>arr[i];

	//maximum consecutive one's => maxConsOnes

	maxConsOnes(arr,n,m);
}