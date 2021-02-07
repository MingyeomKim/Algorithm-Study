#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;
vector<vector<int>> list;
vector<bool> visit;
int answer = 0;

void dfs(int x)
{
	answer++;
	visit[x] = true;

	for (int i = 0;i < int(list[x].size()); i++)
	{
		if (!visit[list[x][i]])
			dfs(list[x][i]);
	}
}

int main()
{
	int computers; cin >> computers;
	int connect; cin >> connect; //연결된 컴퓨터 쌍의 개수
	int a, b;
	/*
	for (int i = 0;i < connect; i++)
	{
		list[i][0] = 0;
	} //연결리스트의 첫번째 요소를 default값으로 설정
	*/
	visit.resize(computers + 1);
	list.resize(computers + 1); //list의 사이즈 8로 지정
	for (int i = 0; i < connect; i++)
	{
		cin >> a >> b;
		list[a].push_back(b); // 벡터의 a번째 위치에 원소 b를 넣는다. 
		list[b].push_back(a);
	}
	// 이중 벡터에 연결리스트가 생성되었다.

	dfs(1);
	cout << answer - 1;
	return 0;
}
