#include<bits/stdc++.h>
using namespace std;


bool cmp(pair<int,int> a,pair<int,int> b)
{
	if(a.first==b.first)
		return a.second<b.second;
	return a>b;
}
void sortByFreqBF(int arr[],int n)
{
	map<int,int> freq;

	for(int i=0; i<n; i++)
		freq[arr[i]]++;

	set<pair<int,int>> st;

	for(int i=0; i<n; i++)
	{
		int x,y;
		x = freq[arr[i]];
		y = arr[i];

		st.insert({x,y});
	}

	vector<pair<int,int> > ans;

	int k = 0;
	for(auto &val : st)
	{
		ans.push_back({val.first,val.second});
	}

	sort(ans.begin(), ans.end(), cmp);

	for(auto &el : ans){

		while(el.first--)
		{
			arr[k++] = el.second;
		}
	}
}
int main()
{
	int t;
	cin>>t;

	while(t--)
	{
		int n;
		cin>>n; 

		int arr[n];
		for(int i=0; i<n; i++)
			cin>>arr[i];

		sortByFreqBF(arr,n);

		for(int i=0; i<n; i++)
			cout<<arr[i]<<" ";
		cout<<endl;
	}
}