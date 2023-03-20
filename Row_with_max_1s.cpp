#include<bits/stdc++.h>
using namespace std;

int rowithMax1s(vector< vector<int> > &arr,int n,int m)
{
	int mxrowIdx = 0;
	int mxOne = 0;
	for(int i=0; i<n; i++)
	{
		int ones = 0;
		for(int j=0; j<m; j++)
		{
			if(arr[i][j]==1)
				ones++;
		}
		if(ones>mxOne)
		{
			mxrowIdx = i;
			mxOne = ones;
		}
	}

	return mxrowIdx;
}
int main()
{
	int N,M;
	cin>>N>>M;

	vector< vector<int> > A(N,vector<int>());

	for(int i=0; i<N; i++){
		for(int j=0; j<M; j++)
		{
			int x;
			cin>>x;
			A[i].push_back(x);
		}
	}

	cout<<rowithMax1s(A,N,M);
}