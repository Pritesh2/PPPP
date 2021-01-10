
#include<map>
#include<iostream>
#include<queue>
#include<stack>
#include<vector>
#define mod 100000009

using namespace std;

map<int,vector<int>> graph;
vector<int> visited(10005);
vector<int> disc(10005);
vector<int> low(10005);
vector<bool> articulation(10005);

int count=1;

void dfs(int ver,int par)
{
	//cout<<ver<<" ";
	visited[ver]=1;

	
	for(int i=0;i<graph[ver].size();i++)
	{
		//cout<<graph[ver][i]<<"---"<<visited[graph[ver][i]]<<"     ";
		//cout<<graph[ver][i]<<" ";

	} 
	//cout<<endl;
	disc[ver]=low[ver]=count++;
	int ind_child=0; // 
	for(int i=0;i<graph[ver].size();i++)
	{
		//cout<<graph[ver][i]<<" ";
		if(visited[graph[ver][i]]==0)
		{
			ind_child++;
			dfs(graph[ver][i],ver);

			low[ver]=min(low[ver],low[graph[ver][i]]);

			
			if( par!=-1 &&  low[graph[ver][i]]>=disc[ver] )
			{
					//cout<<ver<<" ";
					articulation[ver]=true;
			}

			if( par==-1 && ind_child>1)
			{
				articulation[ver]=true;
			}

		}
		else if(graph[ver][i]!=par)
		{
			low[ver]=min(low[ver],disc[graph[ver][i]]);
		}

	}
	//cout<<endl;

	//cout<<ver<<"--Disc---"<<disc[ver]<<"----low----"<<low[ver]<<endl;


}

void f1(int n,int e)
{
	//cout<<n<<" --"<<e<<endl;
	if(n==0 && e==0){return;}

	for(int i=0;i<10005;i++){
		
		visited[i]=0;
		articulation[i]=false;
		disc[i]=0;
		low[i]=0;
	}
	graph.clear();
	
		for(int i=0;i<e;i++)
	{
		int u,v;

		cin>>u>>v;
		graph[u].push_back(v);
		graph[v].push_back(u);

	}
	count=1;
	dfs(1,-1);
	
	int ans=0;
	for(int i=0;i<10005;i++)
	{
		if(articulation[i]==true)
		{
			//cout<<i<<" ";
			ans++;
		}
	}
	//cout<<disc[3]<<"---"<<low[3]<<endl;
	//cout<<" ------------"<<endl;
	cout<<ans<<endl;

}

int main()
{

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	int n,e;
	do{
		
		cin>>n>>e;
		f1(n,e);
	

	}while(n!=0 && e!=0);
	


	return 0;
}
