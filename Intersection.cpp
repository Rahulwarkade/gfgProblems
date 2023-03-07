#include<bits/stdc++.h>
using namespace std;

void printVec(vector< int > &vac)
{
	for(int &val : vac)
		cout<<val<<" ";
	cout<<endl;
}
void intersectionBF(int arr1[],int arr2[],int n,int m)
{
	vector< int > Intersection;
	vector< int > visited(m,0);

	for(int i=0; i<n; i++)
	{
		for(int j=0; j<m; j++)
		{
			if(arr1[i]==arr2[j] && visited[j]==0)
			{
				Intersection.push_back(arr1[i]);
				visited[j] = 1;
				break;
			}
			else if(arr1[i]<arr2[j])
			{
				break;
			}
		}

	}
	sort(Intersection.begin(),Intersection.end());
	printVec(Intersection);
}

void IntersectionUsingMap(int arr1[],int arr2[],int n,int m)
{
	map<int,int> freq1;
	map<int,int> freq2;
	vector<int> Intersection;
	for(int i=0; i<n; i++)
		freq1[arr1[i]]++;
	for(int i=0; i<m; i++)
		freq2[arr2[i]]++;

	for(pair<int,int> val : freq1)
	{
		if(freq2.find(val.first)!=freq1.end())
		{
			int count = min(freq1[val.first],freq2[val.first]);

			while(count>0)
			{
				Intersection.push_back(val.first);
				count--;
			}
		}
	}
	printVec(Intersection);
}

void twoPointerApproach(int arr1[],int arr2[],int n,int m)
{
	int i,j;
	i = j = 0;
	vector < int > Intersection;
	while(i<n && j<m)
	{
		if(arr1[i]==arr2[j])
		{
			Intersection.push_back(arr1[i]);
			i++;
			j++;
		}
		else if(arr1[i]<arr2[j])
		{
			i++;
		}
		else
		{
			j++;
		}
	}

	printVec(Intersection);
}
int main()
{
	int n,m;
	cin>>n>>m;
	int arr1[n];
	int arr2[m];

	for(int i=0; i<n; i++)
		cin>>arr1[i];	
	for(int i=0; i<m; i++)
		cin>>arr2[i];

	twoPointerApproach(arr1,arr2,n,m);
}