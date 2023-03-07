#include<bits/stdc++.h>
using namespace std;

vector<int> ftltOccurr(int arr[],int n,int x)
{
	vector<int> v;
    int foccur,loccur;
    foccur = loccur = -1;
    int first = lower_bound(arr,arr+n,x)-arr;
    int last = upper_bound(arr,arr+n,x) - arr;
    
    if(first<n && arr[first]==x) foccur = first;
    
    if(last>=1 && arr[last-1]==x) loccur = last-1;
    
    v.push_back(foccur);
    v.push_back(loccur);
    
    return v;
}
int solve(int n, int key, vector < int > & v) {
  int start = 0;
  int end = n - 1;
  int res = -1;

  while (start <= end) {
    int mid = start + (end - start) / 2;
    if (v[mid] == key) {
      res = mid;
      start = mid + 1;

    } else if (key < v[mid]) {
      end = mid - 1;
    } else {
      start = mid + 1;
    }
  }
  return res;
}
int main()
{
	int N,X;
	cin>>N>>X;

	int arr[N];
	for(int i=0; i<N; i++)
		cin>>arr[i];

	// first and last occurrence = ftltoccurr

	auto vac = ftltOccurr(arr,N,X);

	for(auto val : vac)
		cout<<val<<" ";
}