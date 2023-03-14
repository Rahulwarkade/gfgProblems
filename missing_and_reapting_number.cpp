#include<bits/stdc++.h>
using namespace std;

void mrn(int ar[],int n)
{
	int ans[2];
	map<int,int> missReap;

	for(int i=0; i<n; i++)
		missReap[ar[i]]++;

	for(int j=1; j<=n; j++)
	{
		auto it = missReap.find(j);
		if(it==missReap.end())
		{
			ans[1] = j;
		}
		if(it!=missReap.end() &&missReap[j]>1)
		{
			ans[0] = j;
		}

	}

	cout<<ans[0]<<" "<<ans[1];

}

void countSortMRN(int arr[],int n)
{
	int range[n+1];
	int ans[2];
	for(int i=0; i<=n; i++)
		range[i] = 0;
	for(int i=0; i<n; i++)
		range[arr[i]]++;

	for(int i=1; i<=n; i++)
	{
		if(range[i]>1)
			ans[0] = i;
		else if(range[i]<1)
			ans[1] = i;
	}

	cout<<ans[0]<<" "<<ans[1]<<endl;
}

void summationMRN(int arr[],int n)
{
	long long int s = (n*(n+1))/2;
	long long int S = (n*(n+1)*(2*n+1))/6;

	long long missing;
	long long repeating;
	missing = repeating = 0;

	for(int i=0; i<n; i++)
	{
		s -= (long long int)arr[i];
		S -= (long long int)arr[i]*(long long int)arr[i];
	}

	missing = (s+S/s)/2;
	repeating = missing - s;

	cout<<"Missing = "<<missing<<" "<<"repeating = "<<repeating<<endl;
}

void xorMRN(int arr[],int n)
{
	int res= 0;
	int j =1; 
	for(int i=0; i<n; i++)
	{
		res = j^arr[i];
		j++;
	}
	int pos= 0;
	int nb = log2(res)+1;
	for(int i=0; i<nb; i++)
	{
		if((res&1)==1)
		{
			pos = i;
			break;
		}
			res>>1;
	}
	int missing,repeating;
	missing = repeating = 0;

	for(int i=0; i<n; i++)
	{
		int bitmask = 1<<pos;
		if(arr[i]&bitmask==1)
		{
			missing ^= arr[i];
		}
		else{
			repeating ^= arr[i];
		}
	}

	for(int i=1; i<=n; i++)
	{
		int mask = 1<<pos;
		if(i&mask==1)
		{
			missing ^= i;
		}
		else
		{
			repeating ^= i;
		}
	}
	int count = 0;
	for(int i=0; i<n; i++)
	{
		if(arr[i]==missing)
			count++;
	}

	if(count>0)
	{
		swap(missing,repeating);
	}

	cout<<"Missing = "<<missing<<" repeating = "<< repeating<<endl;

}
int main()
{
	int ar[] = {3,1,2,5,3};

	//missing and reapting number = mrn
	xorMRN(ar,5);
}