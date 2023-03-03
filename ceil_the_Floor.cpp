#include<bits/stdc++.h>
using namespace std;

pair<int, int> getFloorAndCeil(int arr[], int n, int x) 
{
	int lb,ub;
	pair<int,int> pr;
	sort(arr,arr+n);

	int idx_lb = lower_bound(arr,arr+n,x)-arr;
	
	int idx_ub = upper_bound(arr,arr+n,x)-arr;

	if(idx_lb>=0){
		if(x==arr[idx_lb])
			lb = arr[idx_lb];
		else{
			if(idx_lb-1>=0)
				lb = arr[idx_lb-1];
			else
				lb = -1;
		}
	}
	else{	
	lb = -1;
	}

	if(idx_ub<n){
		if((1<=idx_ub && x==arr[idx_ub-1])){
			ub= arr[idx_ub-1];
		}

		else{
	 		ub = arr[idx_ub];
		}
	}
	else {	
	ub = -1;
	}

	pr.first = lb;
	pr.second = ub;

	return pr;
}

int main()
{
	int N,X;
	cin>>N>>X;

	int arr[N];

	for(int i=0; i<N; i++)
		cin>>arr[i];

	auto pr = getFloorAndCeil(arr,N,X);

	cout<<pr.first<<" "<<pr.second<<endl;

}