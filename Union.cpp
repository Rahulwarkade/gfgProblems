#include<bits/stdc++.h>
using namespace std;
void printVec(vector<int> arr)
{
	for(int i=0; i<arr.size(); i++)
	{
		cout<<arr[i]<<" ";
	}
	cout<<endl;
}
void printSet(set<int> arr)
{
	for(int val : arr)
		cout<<val<<" ";
	cout<<endl;
}
void UnionBF(int arr1[], int arr2[],int n,int m)
{
	vector<int> unArr;
	for(int i=0; i<n; i++)
		unArr.push_back(arr1[i]);

	for(int i=0; i<m; i++)
	{
		bool flag = true;
		for(int j=0; j<n; j++)
		{
			if(arr1[j]==arr2[i])
			{
				flag = false;
				break;
			}
		}
		if(flag==true){
			unArr.push_back(arr2[i]);
		}
	}
	sort(unArr.begin(),unArr.end());
	printVec(unArr);
}

void UnionUsingSet(int arr1[],int arr2[],int n,int m)
{
	set<int> unionSet;

	for(int i=0; i<n; i++)
		unionSet.insert(arr1[i]);

	for(int i=0; i<m; i++)
	{
		if(unionSet.find(arr2[i])==unionSet.end())
		{
			unionSet.insert(arr2[i]);
		}
	}

	printSet(unionSet);
}

void UnionUsingMap(int arr1[],int arr2[],int n,int m)
{
	vector < int > UnionVac;
	map<int,int> UnionMap;
	for(int i=0; i<n; i++)
		UnionMap[arr1[i]]++;

	for(int i=0; i<m; i++)
		UnionMap[arr2[i]]++;

	for(pair<int,int> el : UnionMap)
		UnionVac.push_back(el.first);
	
	printVec(UnionVac);
}

void twoPointerApproach(int arr1[],int arr2[], int n,int m)
{
	int i,j;
	i = j = 0;
	vector< int > Union;
	while(i<n && j<m)
	{
		if(arr1[i]<= arr2[j])
		{
			if(Union.empty() || Union.back()!=arr1[i])
				Union.push_back(arr1[i]);
			i++;
		}
		else{
			if(Union.empty() || Union.back()!=arr2[j])
				Union.push_back(arr2[j]);
			j++;
		}
	}

	while(i<n)
	{
		if(Union.empty() || Union.back()!=arr1[i])
			Union.push_back(arr1[i]);
		i++;
	}
	while(j<m)
	{
		if(Union.empty() || Union.back()!=arr2[j])
			Union.push_back(arr2[j]);
		j++;
	}

	printVec(Union);
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