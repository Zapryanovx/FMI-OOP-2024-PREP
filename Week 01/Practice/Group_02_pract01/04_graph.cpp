#include <iostream>

struct Vertice
{
	char name[10];
};

struct Edge
{
	Vertice start;
	Vertice end;
};

struct Graph
{
	int numOfVertices;
	int numOfEdges;
	Edge* edges;
};

void initializeGraph(Graph& graph, size_t m)
{
	graph.edges = new Edge[m];
	graph.numOfEdges = m;
}

void deleteGraph(Graph& graph)
{
	delete[] graph.edges;
	graph.edges = nullptr;

	graph.numOfEdges = 0;
}

void addEdgeBetweenVertices(const Vertice& verticeStart, const Vertice& verticeEnd, Graph& graph)
{
	graph.edges[graph.numOfEdges - 1] = { verticeStart, verticeEnd };
	graph.numOfEdges++;
}

void readGraph(Graph& graph, size_t mTwo)
{
	for (int i = 0; i < mTwo; i++)
	{
		std::cin >> graph.edges[i].start.name;
		std::cin >> graph.edges[i].end.name;
		addEdgeBetweenVertices(graph.edges[i].start, graph.edges[i].end, graph);
	}

}

bool compareVertices(const char* strOne, const char* strTwo)
{
	int i = 0;
	while (strOne[i] && strTwo[i])
	{
		if (strOne[i] == strTwo[i])
		{
			i++;
		}

		else
		{
			return false;
		}
	}

	if (strOne[i] || strTwo[i])
	{
		return false;
	}
	return true;
		
}

int getDegreeOfVertice(const Vertice& vertice, const Graph& graph)
{
	int countDeg = 0;
	for (int i = 0; i < graph.numOfEdges; i++)
	{
		if (compareVertices(graph.edges[i].start.name, vertice.name) ||
			compareVertices(graph.edges[i].end.name, vertice.name))
		{
			countDeg++;
		}
	}

	return countDeg;
}

bool isVerticeIsAlreadyFound(const Graph& graph, Vertice *vertices, int& verticesIdx, const int i)
{
	for (int j = 0; j < verticesIdx; j++)
	{
		if (compareVertices(vertices[j].name, graph.edges[i].start.name) ||
			compareVertices(vertices[j].name, graph.edges[i].end.name))
		{
			return true;
		}
	}

	return false;
}

bool isEdgeFound(const Graph& graph, const Edge& edge)
{
	for (int i = 0; i < graph.numOfEdges; i++)
	{
		if (compareVertices(edge.start.name, graph.edges[i].start.name) &&
			compareVertices(edge.end.name, graph.edges[i].end.name))
		{
			return true;
		}
	}

	return false;
}

bool isGraphFull(const Graph& graph)
{
	Vertice* vertices = new Vertice[graph.numOfEdges / 2];
	int verticesIdx = 0;

	for (int i = 0; i < graph.numOfEdges / 2; i++)
	{
		if (!isVerticeIsAlreadyFound(graph, vertices, verticesIdx, i))
		{
			replaceBy(vertices[verticesIdx++], graph.edges[i].start);
			replaceBy(vertices[verticesIdx++], graph.edges[i].end);
		}
	}

	for (int i = 0; i < verticesIdx - 1; i++)
	{
		for (int j = i + 1; j < verticesIdx; j++)
		{
			Edge edge = { vertices[i], vertices[j]};
			if (!isEdgeFound(graph, edge))
			{	
				delete[] vertices;
				return false;
			}
		}
	}
	
	delete[] vertices;
	return true;
}

void replaceBy(Vertice& first, Vertice& second)
{
	int idx = 0;
	while (second.name[idx])
	{
		first.name[idx] = second.name[idx];
		idx++;
	}

	first.name[idx] = '\0';
}

void shiftEdges(Graph& graph, int i)
{
	for (int j = i; j < graph.numOfEdges - 1; j++)
	{
		replaceBy(graph.edges[j].start, graph.edges[j + 1].start);
		replaceBy(graph.edges[j].end, graph.edges[j + 1].end);
	}
}


void deleteEdge(Graph& graph, const Edge& edge)
{
	for (int i = 0; i < graph.numOfEdges; i++)
	{
		if (compareVertices(edge.start.name, graph.edges[i].start.name) &&
			compareVertices(edge.end.name, graph.edges[i].end.name))
		{
			shiftEdges(graph, i);
			graph.numOfEdges--;
			return;
		}
	}

	std::cout << "[ERROR] Edge not found." << std::endl;
}

int main()
{
	Graph graph;
	
	int m = 0;
	std::cin >> m;
	initializeGraph(graph, m);
	deleteGraph(graph);

	Vertice verticeStart = { "1" };
	Vertice verticeEnd = { "2" };
	addEdgeBetweenVertices(verticeStart, verticeEnd, graph);
	
	int mTwo = 0;
	std::cin >> mTwo;
	readGraph(graph, mTwo);
	
	std::cout << getDegreeOfVertice(verticeStart, graph) << std::endl;
	std::cout << isGraphFull(graph) << std::endl;

	Edge edge = { verticeStart, verticeEnd };
	deleteEdge(graph, edge);

	return 0;
}