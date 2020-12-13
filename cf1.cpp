
#include<set>
#include<iostream>
#include<queue>
#include<stack>
#include<vector>
#define mod 100000009

using namespace std;

void f1()
{
	int n;
	//int arr[n];

	cin>>n;
	int arr[n];

	if(n==1)
	{
		cout<<0<<" "<<1<<endl;
		return;
	}

	for(int i=0;i<n;i++){cin>>arr[i];}

	int t_a,t_b;

	int i,j;
	i=0;
	j=n-1;

	t_a=arr[i];
	t_b=arr[j];

	while(i<j)
	{
		if(arr[i]<arr[j])
		{
			arr[j]=arr[j]-arr[i];
			arr[i]=0;
			i++;
			//arr[j]=arr[]
		}
		else if(arr[i]>arr[j])
		{
			arr[i]=arr[i]-arr[j];
			arr[j]=0;
			j--;
		}
		else
		{
			arr[i]=0;
			arr[j]=0;
			i++;
			j--;
		}
		


	}
	cout<<i<<" "<<n-j<<endl;


}


void f2()
{
	int n,m;char c;
	cin>>n>>m>>c;

	queue< pair<int,int> > q;

	char arr[n][m];
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<m;j++)
		{
			cin>>arr[i][j];
			//cout<<arr[i][j]<<" ";
			if(arr[i][j]==c)
			{
				q.push({i,j});
			}
		}
		//cout<<endl;
	}

	//         -1,0
	//     0,-1     0,1
	//          1,0
	int dx[4]={0,-1,0,1};
	int dy[4]={-1,0,1,0};

	set<int> st;
	while(!q.empty())
	{

		pair<int,int> temp=q.front();
		q.pop();

		int x=temp.first;
		int y=temp.second;

		for(int i=0;i<4;i++)
		{
			int adj_x=x+dx[i];
			int adj_y=y+dy[i];

			if(adj_x>=0 && adj_y>=0 && adj_y<m && adj_x<n && (arr[adj_x][adj_y]!=c && arr[adj_x][adj_y]!='.' ) )
			{
				if(st.find(arr[adj_x][adj_y])==st.end())
				{
					//cout<<arr[adj_x][adj_y]<<" ";
					st.insert(arr[adj_x][adj_y]);
					
				}
				 
			}

		}


	}

	cout<<st.size()<<endl;

}



int main()
{

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	f1();

	//f2();

	/*
	int t;
	cin>>t;
	while(t--)
	{



	} */


	return 0;
}
