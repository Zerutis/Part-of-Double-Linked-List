#ifndef INT_BOX_H
#define INT_BOX_H

#include <iostream>
#include <stdlib.h>

class Container {
	struct Node {
		int data;
		struct Node *prev;
		struct Node *next;
	} *head, *tail;
	int size = 0;

public:
	Container();
	~Container();
	void add(int data);
	void add_pos(int pos, int data);
	void add_front(int pos, int data);
	void add_back(int pos, int data);

	void remove(int data);
	void remove_pos(int pos);
	void remove_first();
	void remove_last();

	int get_pos(int data);
	int get_first();
	int get_last();
	int get_data(int pos);

	void display();
};

#endif // !INT_BOX_H

