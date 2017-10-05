#include <iostream>
#include <vector>

using namespace std;

class Graph
{
public:

	int n, m;

	vector<int> I, J, H, L, IJ;

	void GenHl();
	void ReadIJ();
	void GenIJ();
	void Export();
	void PrintIJHL();
	void Add(int, int);
	Graph(int, vector<int>&, vector<int>&);
	Graph();
	~Graph() {};

};

Graph::Graph()
{
	//ReadIJ();
	GenIJ();
}

Graph::Graph(int _n, vector<int>&_I, vector<int>&_J) : n(_n), m(_I.size())
{
	IJ.resize(2 * m);
	for (int k(0); k < m; ++k) {
		IJ[k] = _I[k];
		int ind = 2 * m - k - 1;
		IJ[ind] = _J[k];
	}
	I = _I;
	J = _J;
	GenHl();
}

void Graph::GenHl()
{
	//	H.clear();
	//	L.clear();
	//printf("!!!\n");
	H.assign(n, -1);
	L.resize(2 * m);
	for (int k = 0; k < m * 2; ++k)
	{
		int i = IJ[k];
		L[k] = H[i];
		H[i] = k;
	}
}

void Graph::PrintIJHL()
{
	cout << endl;
	cout << endl;
	cout << endl;
	printf("|  # | I | J |  H |  L | IJ |\n");
	int k = 0;



	while (k < n)
	{
		printf("| %2d | %d | %d | %2d | %2d | %2d |\n", k, I[k], J[k], H[k], L[k], IJ[k]);
		k++;
	}

	while (k < m)
	{
		printf("| %2d | %d | %d |    | %2d | %2d |\n", k, I[k], J[k], L[k], IJ[k]);
		k++;
	}
	while (k < 2 * m)
	{
		printf("| %2d |   |   |    | %2d | %2d |\n", k, L[k], IJ[k]);
		k++;
	}
}

void Graph::ReadIJ()
{
	int k = 1;
	int buf;
	int max = 0;

	printf("Сколько нод будет?\n");
	cin >> n;
	printf("Сколько дуг?\n");
	cin >> m;

	printf("| # | I | J |\n");
	printf("| 0 | ? | J |\n");
	cin >> buf;
	I.push_back(buf);
	if (buf > max) max = buf;
	printf("| 0 | %d | ? |\n", buf);
	cin >> buf;
	J.push_back(buf);
	if (buf > max) max = buf;



	while (buf >= 0 && k < m)
	{
		printf("| %d | ? | J |\n", k);
		cin >> buf;
		if (buf >= 0)
		{
			I.push_back(buf);
			if (buf > max) max = buf;
			printf("| %d | %d | ? |\n", k, buf);
			cin >> buf;
			J.push_back(buf);
			if (buf > max) max = buf;
			k++;
		}
	}



}
void Graph::Add(int i, int j)
{
	I.push_back(i);
	J.push_back(j);
	m++;
	// IJ.clear();
	//  GenIJ();
	IJ.insert(IJ.begin() + m - 1, i);
	IJ.insert(IJ.begin() + m, j);
	H.clear();
	L.clear();
	GenHl();
}

void Graph::GenIJ()
{
	for (int k = m - 1; k >= 0; k--)
	{
		IJ.insert(IJ.begin(), I[k]);
		IJ.push_back(J[k]);
	}
	GenHl();
}

void Graph::Export()
{
	FILE *out;
	out = fopen("graph.dot", "w");
	fprintf(out, "graph graphname {\n");
	for (int i = 0; i < n; i++)
	{
		fprintf(out, "  %d;\n", i);
	}
	for (int i = 0; i < m; i++)
	{
		// fprintf(out, "  %d -- %d;\n", I[i], J[i]);
		fprintf(out, "  %d -- %d;\n", IJ[i], IJ[2 * m - i - 1]);
	}
	fprintf(out, "}\n");
	fclose(out);
}

int main(int argc, char const *argv[])
	{

		//Graph a;
		//a.ReadIJ();
		vector<int> vi = { 0, 1, 0, 3, 3, 4, 2 };
		vector<int> vj = { 1, 3, 2, 2, 4, 2, 4 };

		Graph a(5, vi, vj);
		a.PrintIJHL();
		a.Add(0, 3);
		a.PrintIJHL();
		a.Export();
		return 0;
	}
