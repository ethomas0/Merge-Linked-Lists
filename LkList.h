#ifndef LKLIST_H
#define LKLIST_H
#include <string>

using namespace std;

class LkList {

	class Node {
		public:
		Node() {
			next = prev = NULL;
		}
		Node(int num) {
			data = num; next = prev = NULL;
		}

		int data;
		Node *next;
		Node *prev;
	};

	public:
	LkList();
	//        virtual ~LkList();
    LkList(const LkList& other);
	LkList& operator=(const LkList& other);

	bool insert(int num);
	void insert(const initializer_list<int>& il);
	void LkList::push_back(const int value);
	bool remove(const int value);
	void LkList::testConnections();
	void merge(LkList & src);

	void resetIterator();
	bool hasMore();
	int next();

	int size();
	void clear();

	private:
	Node *head, *tail, *it;
	int count;
};

ostream& operator << (ostream & outStr, LkList& lst);

#endif // LKLIST_H
