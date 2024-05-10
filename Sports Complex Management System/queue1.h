#include <iostream>
#include<conio.h>
#include <bits/stdc++.h> 
using namespace std;

class Node {

public:
	string cname;
	Node* link;
	
	Node() {
		link = NULL;
	}
};


class Queue {

	public:
	Node* front;
	Node* rear;
	

public:
	int size;
	Queue() {
		front = NULL;
		rear = NULL;
		size = 0;
	}


	//Function to check if queue is empty or not
	bool isempty()
	{
		if (front == NULL && rear == NULL)
			return true;
		else
			return false;
	}

	//function to enter elements in queue
	void enqueue(string name)
	{
		Node* ptr = new Node();
		ptr->cname = name;
		ptr->link = NULL;

		//inserting the first element
		if (front == NULL)
		{
			front = ptr;
			rear = ptr;
		}
		else
		{
			rear->link = ptr;
			rear = ptr;
		}
		size++;
	}

	//function to delete/remove element from queue
	void dequeue()
	{
		if (isempty())
			cout << " ";
		else
			//only one element/node in queue.
			if (front == rear)
			{
				delete front;
				front = rear = NULL;
			}
			else
			{
				Node* ptr = front;
				front = front->link;
				delete ptr;
			}
		size--;
	}

	//function to show the element at front
	void showfront()
	{
		if (isempty())
			cout << "Queue is empty\n";
		else
			cout << "element at front is:" << front->cname << "\n";
	}

	//function to display queue
	void displayQueue()
	{
		if (isempty())
			cout << "\t\tQueue is empty\n";
		else
		{
			Node* ptr = front;
			while (ptr != NULL)
			{
				cout << "\t" << ptr->cname << "\t  " << endl;
				ptr = ptr->link;

			}
		}
	}

};


