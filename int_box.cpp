#include "int_box.h"
#include <iostream>

using namespace std;

Container::Container() {
	head = NULL;
	tail = NULL;
}
Container::~Container() {
	delete head;
	delete tail;
}

void Container::add(int newdata) {
	size++;

	if (size == 1) {
		Node *temp = new Node;
		temp->data = newdata;
		temp->prev = NULL;
		temp->next = NULL;
		head = temp;
		tail = temp;
		return;
	}


	Node* newnode = new Node;
	newnode->data = newdata;
	newnode->prev = tail;
	tail->next = newnode;
	tail = newnode;
	tail->next = NULL;
}

void Container::display() {
	Node* ptr;
	ptr = head;
	while (ptr != NULL) {
		cout << ptr->data << " ";
		ptr = ptr->next;
	}
}

void Container::add_pos(int pos, int data) {
	if (size + 1 < pos) {
		cout << "You can`t do that" << endl;
		return;
	}

	if ((size == 0) || (pos == size + 1)) {
		add(data);
		return;
	}

	size++;
	if (pos > size / 2) {
		add_back(size - pos + 1, data);
	}
	else {
		add_front(pos, data);
	}
}

void Container::add_front(int pos, int data) { //head
	if (pos == 1) {
		Node *newnode = new Node;
		newnode->data = data;
		newnode->next = head;
		newnode->prev = NULL;
		head->prev = newnode;
		head = newnode;
		return;
	}
	Node *newnode = new Node;
	newnode = head;

	while (pos--) {
		if (pos == 0) {
			Node* temp = new Node;
			temp->data = data;
			temp->next = newnode;
			temp->prev = newnode->prev;
			newnode->prev->next = temp;
			newnode = temp;
		}
		else
			newnode = newnode->next;
	}
}
void Container::add_back(int pos, int data) { //tail
	Node* newnode = new Node;
	newnode = tail;
	while (pos--) {
		if (pos == 0) {
			Node* temp = new Node;
			temp->data = data;
			temp->next = newnode->next;
			newnode->next = temp;
			temp->prev = newnode;

			if (temp->next != NULL)
				temp->next->prev = temp;
		}
		else
			newnode = newnode->prev;
	}
}

void Container::remove(int data) {
	if (head == NULL) {
		return;
	}
	if (head->data == data) {
		remove_first();
		return;
	}
	if (tail->data == data) {
		remove_last();
		return;
	}

	Node* ptr = head;
	while (ptr != NULL) {
		if (ptr->data == data) {

			break;
		}
		ptr = ptr->next;
	}
	ptr->prev->next = ptr->next;
	ptr->next->prev = ptr->prev;
	delete ptr;
}
void Container::remove_pos(int pos) {
	if (pos == size) {
		remove_last();
		return;
	}
	if (pos == 1) {
		remove_first();
		return;
	}

	Node* ptr = head;
	while (--pos) {
		ptr = ptr->next;
	}
	ptr->prev->next = ptr->next;
	ptr->next->prev = ptr->prev;
	delete ptr;

}
void Container::remove_first() {
	Node* ptr = head;
	head = head->next;
	delete ptr;
}
void Container::remove_last() {
	Node* ptr = tail;
	tail = tail->prev;
	tail->next = NULL;
	delete ptr;
}

int Container::get_pos(int data) {
	Node* temp = head;
	int pos = 1;
	while (data != temp->data) {
		temp = temp->next;
		pos++;
		if (temp == NULL) {
			return 0;
		}
	}
	return pos;
}
int Container::get_first() {
	return head->data;
}
int Container::get_last() {
	return tail->data;
}
int Container::get_data(int pos) {
	Node* temp = head;
	while (--pos) {
		temp = temp->next;
		if (temp == NULL) {
			return 0;
		}
	}
	return temp->data;
}