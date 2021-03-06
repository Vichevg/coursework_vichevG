#include "stdafx.h"
#include <queue>
#include <iostream>
#include <vector>
using namespace std;



//week 6  task 1   and  week 7 task 1
class Vert
{
public:
	Vert(int value) {
		this->value = value;
	}
	~Vert(){
	}
	int value;              //value of the vertex
	int arcPos = 0;   //the number of arcs that were appended
	Vert* _Arcs[8] = {};   //we already know that the array is going to be 8
};

class Graph
{
public:
	Graph(){
	}
	~Graph(){
	}
	int vertPos = 0;   //how many vertices added to this graph so far
	Vert* vertices[8] = {};

	Vert* getVert(int value)
	{
		int i = 0;
		while (i < 8)   //because the lenght of the "verticies" array is 8
		{
			Vert* currentVert = vertices[i];

			if (currentVert == NULL)
			{
				break;
			}

			if (value == currentVert->value)
			{
				return currentVert;
			}
			i++;
		}
		return NULL;
	}

	bool checkGraphFor(int value)
	{
		int i = 0;
		while(i < 8)   //because the lenght of the "verticies" array is 8
		{
			Vert* currentVert = vertices[i];

			if (currentVert == NULL) //if there's nothing to compare to, break the loop
			{
				break;
			}

			if (value == currentVert->value)
			{
				return true;
			}
			i++;
		}
		return false;       //if the loop breaks
	}

	void addVert(int value)
	{
		if (checkGraphFor(value) == false)  //function call to check if the value is pressent in the graph structure
		{
			vertices[vertPos] = new Vert(value); //appends a new vertecs to the graph structure
			vertPos = vertPos + 1;         //keeps us from overwriting key the vertices values
		}
	}

	void edgeConnect(int a, int b)   //from a   to  b
	{
		if (checkGraphFor(a) && checkGraphFor(b))   //if both statements
		{
			Vert* vertexA = getVert(a);                 //taking the pointers so we can connect them
			Vert* vertexB = getVert(b);
			vertexA->_Arcs[vertexA->arcPos] = vertexB;  //assigning their positions
			vertexA->arcPos = vertexA->arcPos + 1;      //increment the position of the Arcs so we don't overwrite 
			vertexB->_Arcs[vertexB->arcPos] = vertexA;
			vertexB->arcPos = vertexB->arcPos + 1;
		}
	}

	void breadthFirstSearch(Graph* N, int i)
	{
		queue<Vert*> queBFS;
		int visitedPos = 0;
		Vert* visited[10] = {};
		Vert* iVertex = N->getVert(i);
		queBFS.push(iVertex);


		while (queBFS.empty() == false)         //while the que is not empty
		{
			Vert* m = queBFS.front();    //put the vert in the que
			queBFS.pop();               //take away the vert from the que

			bool inVisited = false;
			for (int i = 0; i < sizeof(visited) / sizeof(visited[0]); i++)
			{
				Vert* currentVert = visited[i];
				if (currentVert == NULL)
				{
					break;
				}
				if (currentVert->value == m->value)
				{
					inVisited = true;
				}
			}
			if (inVisited == false)
			{
				visited[visitedPos] = m;
				visitedPos = visitedPos + 1;

				for (int i = 0; i < m->arcPos; i++)
				{
					queBFS.push(m->_Arcs[i]);
				}
			}
		}
	}

};
int main()
{
	Graph* _graph = new Graph();
	_graph->addVert(1);
	_graph->addVert(2);
	_graph->addVert(3);
	_graph->addVert(4);
	_graph->edgeConnect(1, 2);
	_graph->edgeConnect(1, 4);
	_graph->edgeConnect(2, 4);
	_graph->edgeConnect(3, 4);
}