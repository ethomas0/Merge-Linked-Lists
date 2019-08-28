#include "stdafx.h"
#include "LkList.h"
#include <iostream>
#include <vector>
using namespace std;

void LkList::merge(LkList &src)
{
	Node *list1Ptr, *list2_LowPtr, *list2_HighPtr;
	list1Ptr = head;
	list2_LowPtr = src.head;
	list2_HighPtr = src.head;
	resetIterator();
	src.resetIterator();
	if (src.head == nullptr)//if no data being passed in
	{
		return;
	}
	else if (head == nullptr && src.hasMore())//if no data in list one but data in list 2
	{
		*this = src;
		src.head = src.tail = nullptr;
		return;
	}
	count = count + src.count;
	src.count = 0;
	if (tail->data <= src.head->data)
	{
		tail->next = src.head;
		src.head->prev = tail;
		src.head = head;
		tail = src.tail;
		src.head = src.tail = nullptr;
		return;
	}

	
	if (head->data < src.head->data)
	{
		while (list1Ptr->data <= src.head->data)
		{
			list1Ptr = list1Ptr->next;
		}
		src.head->prev = list1Ptr->prev;
		list1Ptr->prev->next = list2_HighPtr;
		src.head = head;

	}
	if (src.head->data <= list1Ptr->data)
	{
		while (list2_HighPtr->data <= list1Ptr->data)
		{
			list2_HighPtr = list2_HighPtr->next;
		}
		list1Ptr->prev = list2_HighPtr->prev;
		list2_HighPtr->prev->next = list1Ptr;
		head = src.head;
		list2_LowPtr = list2_HighPtr;
		list1Ptr = list1Ptr->next;
	}
	
	
	while (list2_HighPtr->next != nullptr && list1Ptr->next != nullptr)
	{
		while ((list2_HighPtr->data <= list1Ptr->data) && list2_HighPtr->next != nullptr)
		{
			list2_HighPtr = list2_HighPtr->next;
		}
		if (list2_HighPtr->next == nullptr && list1Ptr != tail)
		{
			list2_HighPtr->next = list1Ptr;
			list1Ptr->prev->next = list2_LowPtr;
			list2_LowPtr->prev = list1Ptr->prev;
			list1Ptr->prev = list2_HighPtr;
			src.head = src.tail = nullptr;
			return;
		}
		
		else
		{
			list1Ptr->prev->next = list2_LowPtr;
			list2_LowPtr->prev = list1Ptr->prev;
			list1Ptr->prev = list2_HighPtr->prev;
			list2_HighPtr->prev->next = list1Ptr;
			list1Ptr = list1Ptr->next;
			list2_LowPtr = list2_HighPtr;
		}
	}
	if (list2_HighPtr != src.tail && list1Ptr->next == nullptr)
	{
		while (list2_HighPtr->data <= list1Ptr->data)
		{
			list2_HighPtr = list2_HighPtr->next;
		}
		if (list2_HighPtr != src.tail && list1Ptr->next == nullptr)
		{
			list1Ptr->prev->next = list2_LowPtr;
			list2_LowPtr->prev = list1Ptr->prev;
			list2_HighPtr->prev->next = list1Ptr;
			list1Ptr->prev = list2_HighPtr->prev;
		}
		if(list2_HighPtr->next != nullptr)
		{
			list1Ptr->next = list2_HighPtr;
			list2_HighPtr->prev = list1Ptr;
			tail = src.tail;
		}
		
	}
	src.head = src.tail = nullptr;
	
}


	
	
	
		
	
  // end of merge function


LkList::LkList() 
{
	head = nullptr;
	tail = nullptr;
	it = nullptr;
	count = 0;
}

LkList::LkList(const LkList &other)
{
	this->resetIterator();
	head = nullptr;
	tail = nullptr;
	count = 0;
	resetIterator();

	while (other.it->next != nullptr)
	{
		push_back(other.it->data);
		this->it = other.it->next;
	}
	push_back(other.it->data);
	this->resetIterator();
}

LkList & LkList::operator=(const LkList & other)
{
	Node *curr;
	if (hasMore())
	{
		for (curr = head; curr->next != nullptr; curr = curr->next)
		{
			remove(curr->data);
		}
	}

	for (curr = other.head; curr != nullptr; curr = curr->next)
	{
		push_back(curr->data);
	}
	resetIterator();
	return *this;
}

//LkList::~LkList(){}                      
//LkList::LkList(const LkList& other){}
//LkList& LkList::operator=(const LkList& rhs){}

int LkList::size()
{
	return count;
}

bool LkList::insert(int num) 
{
	if (count == 0) 
	{                      // empty list
		head = tail = new Node(num);
	}
	else 
	{                                   // >1 count, then add back
		Node* temp = new Node(num);
		tail->next = temp;
		temp->prev = tail;
		tail = temp;
	}
	count++;
	return true;
}

void LkList::insert(const initializer_list<int> &il) 
{
	for (int ele : il) 
	{
		insert(ele);
	}
}

void LkList::push_back(const int value)
{
	Node *temp = new Node(value);
	if (head == nullptr)
	{
		head = temp;
		tail = temp;
		count++;
	}
	else
	{
		tail->next = temp;
		temp->prev = tail;
		tail = temp;
		count++;
	}
}

bool LkList::remove(const int value)
{
	Node *curr;


	for (curr = head; curr != nullptr; curr = curr->next)
	{

		if (curr->data == value)
		{
			if (curr->prev == nullptr)
			{ /* Remove from beginning */
			  /* Fix beginning pointer. */
				head = curr->next;

			}
			else if (curr->next == nullptr)
			{ /* Remove from end */
				curr->prev->next = nullptr;
				tail = curr->prev;

			}
			else { /* Remove from middle */
				   /*
				   * Fix previous node's next to
				   * skip over the removed node.
				   */
				curr->prev->next = curr->next;

				/*
				* Fix next node's prev to
				* skip over the removed node.
				*/
				curr->next->prev = curr->prev;

			}

			delete curr;  /* Deallocate the node. */
			--count;
			return true;   /* Done searching. */
		}
	}

	return false;  /* Not in the list. */
}


void LkList::clear() 
{
	if (count == 0)
		return;

	while (tail != head)
	{
		tail = tail->prev;
		delete tail->next;
	}
	delete head;
	head = tail = nullptr;
	count = 0;
}

void LkList::resetIterator()
{
	it = head;
}

bool LkList::hasMore() 
{
	return (it != nullptr);
}

int LkList::next() 
{
	int num = it->data;
	it = it->next;
	return num;
}

ostream& operator << (ostream & outStr, LkList & lst) 
{
	lst.resetIterator();
	while (lst.hasMore())
		outStr << lst.next() << "  ";
	return outStr;
}

void LkList::testConnections()
{
	resetIterator();
	while (it != tail)
	{
		if (it->next->prev != it)
		{
			cout << "FAILED at " << it->data << endl;
			return;
		}
		it = it->next;
	}
	cout << "Passed" << endl;
}
