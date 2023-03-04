#include<bits/stdc++.h>
using namespace std;
int countOccurr(int arr[],int n,int x)
{
    int foccur,loccur;
    foccur = loccur = -1;
    int first = lower_bound(arr,arr+n,x)-arr;
    int last = upper_bound(arr,arr+n,x) - arr;
    
    if(first<n && arr[first]==x) foccur = first;
    
    if(last>=1 && arr[last-1]==x) loccur = last-1;
    
    if(foccur==-1 )
        return 0;
    else
        return (loccur-foccur)+1;
}
int binary(int arr[], int n, int x) {
  int s = 0;
  int e = n - 1;

  while (s <= e) {
    int m = (s + e) / 2;

    if (arr[m] == x) {
      return m;
    } else if (arr[m] < x) {
      s = m + 1;
    } else {
      e = m - 1;
    }
  }
  return -1;
}

int count(int arr[], int n, int x) {
  // code here
  // get the index of X in array
  int idx = binary(arr, n, x);

  // if X does not exist return 0;
  if (idx == -1) {
    return 0;
  }

  int k = 1;
  int left = idx - 1;

  // check left half for X
  while (left >= 0 && arr[left] == x) {
    k++;
    left--;
  }
  // check right half for X
  int right = idx + 1;
  while (right < n && arr[right] == x) {
    k++;
    right++;
  }

  return k;
}
int main()
{
	int N,X;
	cin>>N>>X;

	int arr[N];
	for(int i=0; i<N; i++)
		cin>>arr[i];

  cout<<countOccurr(arr,N,X);
}