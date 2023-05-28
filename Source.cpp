#include<iostream>
using namespace std;
#include "Graph.cpp"


int main()
{
	std::cout << "\033[2J\033[1;1H";
	std::cout << "\033[34m";
	std::string text = "MINI WASALNY PROJECT";
	for (int i = 1; i <= 11; i++)
	{
		cout << "                                                                           " << endl;
	}
	cout << "                                     ";
	for (char c : text) {

		std::cout << c << std::flush;
		std::this_thread::sleep_for(std::chrono::milliseconds(200));
	}
	std::cout << "\033[0m\n";
	std::cout << "\033[2J\033[1;1H";


	int c;
	int option;
	string Edge_name1, Edge_name2;
	string edge_name;
	cout << "--------------------------------------------  Welcome to mini waslny system  -------------------------------------------" << endl << endl << endl;
	cout << "1 if you want load graph from " << endl;
	cout << "2 if you want create new  graph from " << endl;
	cout << "Enter option " << endl;
	cin >> option;
	if (option == 1)
	{
		Graph gra;
		string id_graph;
		cout << "enter the id of graph " << endl;
		cin >> id_graph;
		gra = LoadData(id_graph);
		system("cls");
		cout << "You load graph successfully , enter your option" << endl;
		do {
			cout << "what operation you want to perform " << endl;
			cout << "select option number ,enter 9 to exit " << endl;
			cout << "1 add vertix" << endl;
			cout << "2 Dijistra algorithm" << endl;
			cout << "3 delete edge" << endl;
			cout << "4 add Edge" << endl;
			cout << "5 delete vertex" << endl;
			cout << "6 print Graph " << endl;
			cout << "7 Breadth Traverse the Graph " << endl;
			cout << "8 Depth Traverse the Graph " << endl;
			cout << "9 save in file and exit " << endl;
			cin >> c;
			switch (c)
			{

			case 1:
				cout << "add vertix operation " << endl;
				gra.read_data_Vertix();
				break;
			case 2:
				cout << " Dijkstra vertix operation " << endl;
				gra.dijkstra_information(gra);
				break;

			case 3:
				cout << " delete edge operation " << endl;
				cout << "enter the source and destiantion" << endl;

				cin >> Edge_name1 >> Edge_name2;
				gra.Delete_Edge(Edge_name1, Edge_name2);
				break;
			case 4:
				cout << " add Edge operation " << endl;
				gra.read_data_Edge();
				break;
			case 5:
				cout << " delete vertex operation " << endl;
				cout << "enter the name of vertex to delete" << endl;

				cin >> edge_name;
				gra.delete_Vertix(edge_name);

				break;
			case 6:
				cout << " print Graph operation " << endl;
				gra.print();
				break;

			case 7:
				cout << " bfs traversal operation " << endl;
				gra.Enter_source_Bfs();
				break;

			case 8:
				cout << " dfs traversal operation " << endl;
				gra.Enter_source_DFS();
				break;
			case 9:
				cout << " save in graph " << endl;
				gra.saveinfile();
				break;

			default:
				break;
			}


		}
		while (c != 9);

	}
	else if (option == 2)
	{
		Graph g;

		do {
			cout << "what operation you want to perform " << endl;
			cout << "select option number ,enter 9 to exit " << endl;
			cout << "1 add vertix" << endl;
			cout << "2 the shortest path vertix" << endl;
			cout << "3 delete edge" << endl;
			cout << "4 add Edge" << endl;
			cout << "5 delete vertex" << endl;
			cout << "6 print Graph " << endl;
			cout << "7 Breadth Traverse the Graph " << endl;
			cout << "8 Depth Traverse the Graph " << endl;
			cout << "9 save in file and exit " << endl;
			cin >> c;
			switch (c)
			{

			case 1:
				cout << "add vertix operation " << endl;
				g.read_data_Vertix();
				break;
			case 2:
				cout << " Dijstra vertix operation " << endl;
				g.dijkstra_information(g);
				break;
			case 3:
				cout << " delete edge operation " << endl;
				cout << "enter the source and destiantion" << endl;

				cin >> Edge_name1 >> Edge_name2;
				g.Delete_Edge(Edge_name1, Edge_name2);
				break;
			case 4:
				cout << " add Edge operation " << endl;
				g.read_data_Edge();
				break;
			case 5:
				cout << " delete vertex operation " << endl;
				cout << "enter the name of vertex to delete" << endl;

				cin >> edge_name;
				g.delete_Vertix(edge_name);

				break;
			case 6:
				cout << " print Graph  operation " << endl;
				g.print();
				break;

			case 7:
				cout << " bfs traversal operation " << endl;
				g.Enter_source_Bfs();
				break;

			case 8:
				cout << " dfs traversal operation " << endl;
				g.Enter_source_DFS();
				break;
			case 9:
				cout << " save in graph " << endl;
				g.saveinfile();
				break;

			default:
				break;
			}


		} while (c != 9);



	}
	else
	{

		cout << " Enter correct number ";


	}
}