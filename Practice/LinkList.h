#pragma once

struct node
{
	int element = -1;
	node * next;
};

class LinkList
{
	node *head;
	int node_size;
public:
	
	LinkList() :node_size(0){}
	bool add(int const & element);
	int getSize() { return node_size;}
	void increaseSize() { node_size++;}
	void decreaseSize() { node_size--;}
	int getHead() const {return head->element;}
	bool getLastElement(int & element );
	int  validateListSize() const;
};
