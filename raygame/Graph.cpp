#include "graph.h"
#include "Node.h"
#include "Edge.h"
#include <deque>

Graph::Graph(int width, int height, int nodeSize, int nodeSpacing)
{
	m_width = width;
	m_height = height;

	createGraph(nodeSize, nodeSpacing);
}

void Graph::draw()
{
	for (int i = 0; i < m_nodes.size(); i++)
	{
		m_nodes[i]->draw();
	}
}

void Graph::update(float deltaTime)
{
	Actor::update(deltaTime);

	for (int i = 0; i < m_node
}

void Graph::BFS(int startX, int startY, int goalX, int goalY)
{
	//Get a reference to the start and end nodes
	Node* start = getNode(startX, startY);
	Node* goal = getNode(goalX, goalY);

	//If the start or the end is null return
	if (!start || !goal)
		return;

	//Set the color to start and mark it as visited
	start->color = ColorToInt(GREEN);
	start->visited = true;

	//Set the iterator to be the start node
	Node* currentNode = start;


	//Create a queue to store the nodes
	std::deque<Node*> queue;

	//Add the start node to the queue
	queue.push_front(start);


	//Search for the goal wjile the
	while (!queue.empty())
	{
		currentNode = queue[0];
		queue.pop_front();


		//Check if the iterator is the goal node
		if (currentNode == goal)
		{
			//Set the current node color to be yellow to mark it as found
			currentNode->color = ColorToInt(YELLOW);
			return;
		}


		//If the node wasn't the goal loop through its edges to get its neighbors
		for (int i = 0; i < currentNode->edges.size(); i++)
		{

			//Create a pointer to store the node at the other end of the edge
			Node* currentEdgeEnd = nullptr;


			//Set the pointer to be the opposite end of the edge
			if (currentNode == currentNode->edges[i]->connectedNode2)
			{
				currentEdgeEnd == currentNode->edges[i]->connectedNode1;
			}
			else
			{
				currentEdgeEnd = currentEdgeEnd->edges[i]->connectedNode2;
			}


			//If the node at the opposite end hasn't been visited mark it as visited and add it to the queue
			if (!currentEdgeEnd->visited)
			{
				currentEdgeEnd->color = ColorToInt(RED);
				currentEdgeEnd->visited = true;
				queue.push_front(currentEdgeEnd);
			}
		}
	}

	Node* Graph::getNode(int xPos, int yPos)
	{
		if (xPos < 0 || xPos > m_width || yPos < 0 || yPos > m_height)
			return nullptr;

		for (int i = 0; i < m_nodes.size(); i++)
		{
			if (m_nodes[i]->graphPostition == MathLibrary::Vector2(xPos, yPos))
				return m_nodes[i];
		}

		return nullptr;
	}


	void Graph::createGraph(int nodeSize, int nodeSpacing)
	{
		float xPos = 0;
		float yPos = 0;

		for (int i = 0; i < m_width * m_height; i++)
		{
			Node* currentNode = new Node(xPos, yPos
		}
		currentNode->setLocalPosition();
	}
}
