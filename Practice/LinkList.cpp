#include "LinkList.h"



bool  LinkList::add(int const & element) {
	node *ptr = head;
 	if (ptr == nullptr) {
		node *ptr = new node;

		ptr->element = element;
		ptr->next = nullptr;
		head = ptr;
	}
	else {
		while (ptr->next != nullptr) {
			ptr = ptr->next;
		}
		node *ptr1 = new node;
		ptr1->element = element;
		ptr1->next = nullptr;
		ptr->next = ptr1;
	}
	increaseSize();
	return true;
}


int LinkList::validateListSize() const {
	node *ptr = head; int size = 1;
	if (ptr == nullptr) {
		return 0;
	}
	else {
		while (ptr->next != nullptr)		{
			ptr=ptr->next;
			size++;
		}
	}
	return size;
}

bool   LinkList::getLastElement(int & element ) {
	node *ptr = head; 
	if (head == nullptr)
		return false;
	else {
		while (ptr->next != nullptr) {
			ptr = ptr->next;
		}
		element=ptr->element;
		return true;
	}
}