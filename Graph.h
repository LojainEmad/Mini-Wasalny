#pragma once
#include <iostream>
#include <list>
#include <vector>
#include <iterator>
#include <Queue>
#include <map>
#include<stack>
#include<fstream>
#include <limits>
#include <chrono>
#include <thread>

using namespace std;
const int INF = numeric_limits<int>::max();
class Vertix
{
public:
	int State_id;
	string State_name;
	list< pair<pair<string, int>, int>> edge; 
	map< string, int> mpVertix;
	
	void setName(string s)
	{
		State_name = s;
	}
	void setid(int id)
	{
		State_id = id;
	}
	void delete_Vertix2(string name)
	{
		bool find;

		

	}
};

class Graph
{

public:
	vector<Vertix>Vertices;

	bool Vertix_Exist(string Name);

	Vertix return_Vertix(string Name);



	bool Exist_Edge(string City1, string City2);
	void add_Edge(string City1, string City2, int Distannce, int dire);




	void add_Vertix(string Name);






	void read_data_Vertix();

	void read_data_Edge();



	void print();




	void Delete_Edge(string src, string destination);


	void delete_Vertix(string name);

	void dfs(string src, vector<bool>& visted);


	void Enter_source_DFS();


	void Bfs(string src);


	void Enter_source_Bfs();

	int dijkstra(Graph& g, string start, string end);

	void dijkstra_information(Graph G);





	void saveinfile(string id, vector<Vertix>Vertices);


	void saveinfile();


};



