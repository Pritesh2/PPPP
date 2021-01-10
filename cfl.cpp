

#include<iostream>
#include<queue>
#include<stack>
#include<set>
#include<vector>
#include<map>
#define mod 100000009

using namespace std;

void f1()
{
	int n;
	cin>>n;

	int arr[n];
	for(int i=0;i<n;i++)
	{
		//int a;
		cin>>arr[i];
	}

	if(n>1)
	{
		int ans=1;
		set<int> st;
		for(int i=0;i<n;i++)
		{
			for(int j=i+1;j<n;j++)
			{
				ans=ans*(-arr[i]+arr[j]);
				if(st.find(ans)==st.end())
				{
					st.insert(ans);
					//ans=1;
				}
				ans=1;
			}

		}
		cout<<st.size()<<endl;
		st.clear();
		
	}
	else
	{
		cout<<0<<endl;
	}


}


void f2()
{
	int n;
	cin>>n;
	map<int,int> mp;
	for(int i=0;i<n;i++)
	{
		int x;
		cin>>x;
		mp[x]++;
	}
	map<int,int>::iterator itr;
	for(itr=mp.begin();itr!=mp.end();itr++)
	{
		if(itr->second>1)
		{
			int x=1+itr->first;
			mp[x]++;
			itr->second--;
		}
	}

	cout<<mp.size()<<endl;

}

int main()
{

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	int t;
	cin>>t;
	while(t--)
	{
		//f1();
			f2();

	}


	return 0;
}
