#include "Graph.h"
bool Graph::Vertix_Exist(string Name)
{

	bool find = false;

	for (int i = 0; i < Vertices.size(); i++)
	{
		if (Vertices.at(i).State_name._Equal(Name))
		{
			find = true;
			break;
		}

	}
	return find;

}
Vertix Graph::return_Vertix(string Name)
{

	bool find = false;
	Vertix v;
	for (int i = 0; i < Vertices.size(); i++)
	{
		if (Vertices.at(i).State_name._Equal(Name))
		{
			find = true;
			v = Vertices.at(i);
			break;
		}

	}
	return v;
}
bool Graph::Exist_Edge(string City1, string City2)
{
	bool flag = false;

	for (int i = 0; i < Vertices.size(); i++)
	{
		if (Vertices.at(i).State_name._Equal(City1))
		{
			for (auto j = Vertices.at(i).edge.begin(); j != Vertices.at(i).edge.end(); j++)

			{
				if (j->first.first._Equal(City2))
				{
					flag = true;
					break;
				}

			}
		}


		 if (Vertices.at(i).State_name._Equal(City2))
		{
			for (auto j = Vertices.at(i).edge.begin(); j != Vertices.at(i).edge.end(); j++)

			{
				if (j->first.first._Equal(City1))
				{
					flag = true;
					break;
				}

			}
		}

	}

	return flag;




}
void Graph::add_Edge(string City1, string City2, int Distannce, int dire)
{

	bool find1 = Vertix_Exist(City1);
	bool find2 = Vertix_Exist(City2);
	bool find3 = Exist_Edge(City1, City2);


	if (dire == 1)
	{
		if (find3 == true)
		{
			cout << "the Edge is Exist" << endl;

		}

		else if (find3 == false && find2 == true && find1 == true)
		{

			for (int i = 0; i < Vertices.size(); i++)
			{


				if (Vertices.at(i).State_name._Equal(City1))
				{
					Vertices.at(i).edge.push_back(make_pair(make_pair(City2, Distannce), 1));

					cout << "edge added successfully" << endl;
				}


			}
		}

		else if (find2 == false && find1 == true || find1 == false && find2 == true || find2 == false && find1 == false)
			cout << "there is some thing wrong  or this city not Exist " << endl;
	}

	else if (dire == 2)
	{

		if (find3 == true)
		{
			cout << "the Edge is Exist" << endl;

		}


		else if (find3 == false && find2 == true && find1 == true)
		{

			for (int i = 0; i < Vertices.size(); i++)
			{


				if (Vertices.at(i).State_name._Equal(City1))
				{
					Vertices.at(i).edge.push_back(make_pair(make_pair(City2, Distannce), 2));
					cout << "edge added successfully" << endl;
				}
			    if (Vertices.at(i).State_name._Equal(City2))
				{
					Vertices.at(i).edge.push_back(make_pair(make_pair(City1, Distannce), 2));

					cout << "edge added successfully" << endl;
				}


			}




		}
		else if (find2 == false && find1 == true || find1 == false && find2 == true || find2 == false && find1 == false)
			cout << "there is some thing wrong  or this city not Exist " << endl;

	}




}
void Graph::add_Vertix(string Name)
{

	bool find = Vertix_Exist(Name);
	if (find == false)
	{
		Vertix V;
		V.setName(Name);
		V.setid(Vertices.size());
		V.mpVertix[V.State_name] = V.State_id;
		Vertices.push_back(V);
	}
	else
	{
		cout << "The Vertix is Exist" << endl;
	}


}
void Graph::read_data_Vertix()
{
	string c1;
	cout << "enter the  city " << endl;
	cin >> c1;
	add_Vertix(c1);

}
void Graph::read_data_Edge()
{
	string c1;
	string c2;
	int d, direc;
	cout << "enter the Two cites and distance " << endl;

	cin >> c1 >> c2 >> d;
	cout << "enter the direction 1 if directed 2 if undirected " << endl;
	cin >> direc;
	if (direc == 1)
	{
		add_Edge(c1, c2, d, 1);
	}
	else if (direc == 2)
	{
		add_Edge(c1, c2, d, 2);

	}

}
void Graph::print()
{
	cout << "Graph is" << endl;
	for (int i = 0; i < Vertices.size(); i++)
	{
		cout << "   " << Vertices.at(i).State_name << "(";
		for (auto j = Vertices.at(i).edge.begin(); j != Vertices.at(i).edge.end(); j++)
		{

			cout << j->first.first << ",";

		}
		cout << ")";
		cout << "[  ";
		for (auto j = Vertices.at(i).edge.begin(); j != Vertices.at(i).edge.end(); j++)
		{

			cout << j->first.first << "-->" << " distance " << j->first.second << " Km ";

		}
		cout << "]";
		cout << endl;
	}


}
void Graph::Delete_Edge(string src, string destination)
{

	bool find1 = Vertix_Exist(src);
	bool find2 = Vertix_Exist(destination);
	if (find1 == true && find2 == true)
	{
		for (int i = 0; i < Vertices.size(); i++)
		{
			if (Vertices.at(i).State_name._Equal(src))
			{
				for (auto it = Vertices.at(i).edge.begin(); it != Vertices.at(i).edge.end(); it++)
				{
					if (it->first.first._Equal(destination))
					{
						Vertices.at(i).edge.erase(it);
						break;
					}

				}
			}


			 if (Vertices.at(i).State_name._Equal(destination))
			{
				for (auto it = Vertices.at(i).edge.begin(); it != Vertices.at(i).edge.end(); it++)
				{
					if (it->first.first._Equal(src))
					{
						Vertices.at(i).edge.erase(it);
						break;
					}

				}
			}
		}



		cout << "the edge deleted successfully" << endl;
	}
	else
	{
		cout << " the edge not exist " << endl;

	}

}
void Graph::delete_Vertix(string name)
{
	bool find1 = Vertix_Exist(name);

	if (find1 == true)
	{

		for (int i = 0; i < Vertices.size(); i++)
		{
			if (Vertices.at(i).State_name == name)
			{
				auto it = Vertices.at(i).edge.begin();
				while (it != Vertices.at(i).edge.end())
				{
					Delete_Edge(Vertices.at(i).State_name, it->first.first);
					// increment iterator ممسوحه intialized عشان هو كان // بيضرب Exception
					it = Vertices.at(i).edge.begin();

				}
				Vertices.erase(Vertices.begin() + i); //(begin()+i) الي عايز امسحها vertix  بتاع index  بيشاور ع الiterator بترجع    

				break;
			}


		}
		cout << " the verix deleted successfully" << endl;

	}

	else
	{
		cout << " the vertix is not exist " << endl;

	}

}
void Graph::dfs(string src, vector<bool>& visted)

{
	
	Vertix v = return_Vertix(src);
	stack<Vertix> st;
	visted[v.mpVertix[src]] = true;

	st.push(v);
	while (!st.empty())
	{
		v = st.top();
		st.pop();

		cout << v.State_name<< ">>";
		
	
		for (auto i = v.edge.begin(); i != v.edge.end(); i++)
		{

			string d = i->first.first;
			Vertix v2 = return_Vertix(d);

			if (!visted[v2.mpVertix[d]])
			{
				visted[v2.mpVertix[d]] = true;

				dfs(v2.State_name, visted);

			}
		}
	}
}
void Graph::Enter_source_DFS()
{
	vector<bool> visted(Vertices.size(), false);
	string w;
	cout << "Enter Source distination  ";
	cin >> w;
	dfs(w, visted);

}
void Graph::Bfs(string src)
{

	Vertix v = return_Vertix(src);
	bool* visted = new bool[Vertices.size()];
	for (int i = 0; i < Vertices.size(); i++)
	{
		visted[i] = false;
	}
	queue<Vertix> qu;
	visted[v.mpVertix[src]] = true;
	qu.push(v);
	while (!qu.empty())
	{
		v = qu.front();
		//vec.push_back(v.State_name);
		qu.pop();
		cout << v.State_name << "-->";
		for (auto i = v.edge.begin(); i != v.edge.end(); i++)
		{
			string d = i->first.first;
			Vertix v2 = return_Vertix(d);
			if (!visted[v2.mpVertix[d]])
			{
				visted[v2.mpVertix[d]] = true;
				qu.push(v2);
			}

		}
	}

}
void Graph::Enter_source_Bfs()
{
	string c;
	cout << "Enter Source distination  ";
	cin >> c;
	Bfs(c);

}
int Graph::dijkstra(Graph& g, string start, string end)
{
	priority_queue<pair<int, string>, vector<pair<int, string>>, greater<pair<int, string>>> pq;
	map<string, int> dist;
	map<string, string> p;
	string curr_vertex = start;
	pq.push(make_pair(0, curr_vertex));
	dist[curr_vertex] = 0;
	while (!pq.empty()) {
		curr_vertex = pq.top().second;
		pq.pop();
		if (curr_vertex == end) {
			break;
		}
		Vertix curr_Vertix = g.return_Vertix(curr_vertex);
		for (auto& neighbor : curr_Vertix.edge) {
			string neighbor_node = neighbor.first.first;
			int neighbor_weight = neighbor.first.second;
			int distance = dist[curr_vertex] + neighbor_weight;
			if (!dist.count(neighbor_node) || distance < dist[neighbor_node]) {
				dist[neighbor_node] = distance;
				p[neighbor_node] = curr_vertex; 
				pq.push(make_pair(distance, neighbor_node));
			}
		}
	}

	vector<string> path;
	string curr = end;
	while (p.count(curr)) {
		path.push_back(curr);
		curr = p[curr];
	}
	path.push_back(start);
	reverse(path.begin(), path.end()); 
	
	for (auto& vertex : path) {
		std::cout  << vertex <<"<<" ;
	}
	return dist[end];
}
void Graph::dijkstra_information(Graph G) {
	string City1, City2;
	cout << "Enter the two cities: " << endl;
	cin >> City1 >> City2;

	int distance = dijkstra(G, City1, City2);

	cout << "Shortest distance between " << City1 << " and " << City2 << ": " << distance << endl;

}
void Graph::saveinfile(string id, vector<Vertix>Vertices)
{

	if (Vertices.size() == 0)
		return;
	ifstream IFileStream("Storage.txt");
	list<string> ls;
	bool found = false;
	while (!IFileStream.eof()) {
		string input;
		IFileStream >> input;
		if (input.empty())
			break;
		if (input == "$" + id) {
			found = true;
		}
		else if (input[0] == '$' && found) {
			found = false;
		}
		if (!found) {
			ls.push_back(input);
		}
	}
	IFileStream.close();

	ofstream OFileStream("Storage.txt");

	for (auto& Item : ls) {
		OFileStream << Item << '\n';
	}

	OFileStream << "$" + id << '\n';
	OFileStream << Vertices.size() << '\n';
	for (int i = 0; i < Vertices.size(); i++) {
		OFileStream << Vertices.at(i).State_name << '\n';
	}
	for (int i = 0; i < Vertices.size(); i++)
	{
		OFileStream << Vertices.at(i).State_name << '\n';
		OFileStream << Vertices.at(i).edge.size() << '\n';

		for (auto it = Vertices.at(i).edge.begin(); it != Vertices.at(i).edge.end(); it++)
		{
			OFileStream << it->second << '\n';
			OFileStream << it->first.first << '\n';
			OFileStream << it->first.second << '\n';
		}

	}
	OFileStream.close();
}
void Graph::saveinfile()
{
	string Graph_id;

	cout << "enter the id " << endl;
	cin >> Graph_id;
	saveinfile(Graph_id, Vertices);

}
Graph LoadData(string Graphloaded_id)
{
	Graph G;
	std::ifstream FileStream("Storage.txt");
	while (!FileStream.eof()) {
		string input;
		FileStream >> input; //out from file 
		if (input == "$" + Graphloaded_id)
		{
			int cntOfTowns;
			FileStream >> cntOfTowns;

			while (cntOfTowns--) {
				string townName;
				FileStream >> townName;
				G.add_Vertix(townName);
			}


			while (!FileStream.eof())
			{

				std::string townName;
				FileStream >> townName;
				if (townName.empty() || townName[0] == '$') {
					FileStream.close();
					return G;
				}
				int numOfEdges;
				FileStream >> numOfEdges;

				while (numOfEdges--) {
					string secTownName;//2
					int direction;
					int cost;
					FileStream >> direction;
					if (direction == 1)
					{
						FileStream >> secTownName;
						FileStream >> cost;
						G.add_Edge(townName, secTownName, cost, 1);
					}
					else if (direction == 2)
					{
						FileStream >> secTownName;
						FileStream >> cost;
						G.add_Edge(townName, secTownName, cost, 2);
					}

				}

			}

		}
	}
	FileStream.close();
	return G;

}
