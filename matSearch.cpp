#include<bits/stdc++.h>
using namespace std;


int matSearch(vector< vector<int> > &mat,int N,int M,int X)
{
	int i = 0;
	int j = M-1;

	while(i<N && j>=0)
	{
		if(mat[i][j]==X)
			{return 1;}
		else if(mat[i][j]<X)
		{
			i++;
		}
		else{
			j--;
		}
	}
	return 0;
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

	cout<<matSearch(A,N,M,31);
}