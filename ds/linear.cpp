#include <iostream>
#include <vector>

using namespace std;


class LinkedList {
private:
	struct Node {
		int data;
		Node* next;
		Node(int value) : data(value), next(nullptr) {}
	};
	Node* head;
	
public:
	LinkedList() : head(nullptr) {}
	
	void insert(int value) {
		Node* node = new Node(value);
		if (!head) {
			head = node;
			return;
		}
		Node* temp = head;
		while (temp->next) {
			temp = temp->next;
		}
		temp->next = node;
	}
	
	void remove(int value) { // rightmost node
		if (!head) return;
		if (head->data == value) {
			Node* temp = head;
			head = head->next;
			delete temp;
			return;
		}
		Node* temp = head;
		while (temp->next && temp->next->data != value) {
			temp = temp->next;
		}
		if (temp->next) {
			Node* node = temp->next;
			temp->next = temp->next->next;
			delete node;
		}
	}
	
	void display() {
		Node* temp = head;
		while (temp) {
			cout << temp->data << " -> ";
			temp = temp->next;
		}
		cout << "nullptr" << endl;
		delete temp;
	}
	
	~LinkedList() {
		Node* temp;
		while (head) {
			temp = head;
			head = head->next;
			delete temp;
		}
	}
};

class Stack {
private:
	struct Node {
		int data;
		Node* next;
		Node(int value) : data(value), next(nullptr) {}
	};
	Node* top;

public:
	Stack() : top(nullptr) {}
	
	void push(int value) {
		Node* node = new Node(value);
		node->next = top;
		top = node;
	}
	
	void pop() {
		if (!top) return;
		Node* temp = top;
		top = top->next;
		delete temp;
	}

	int peek() {
		return top ? top->data : -1;
	}
	
	~Stack() {
		while (top) pop(); // maybe??
	}
};

class Queue {
private:
	struct Node {
		int data;
		Node* next;
		Node(int value) : data(value), next(nullptr) {}
	};
	Node* front;
	Node* rear;

public:
	Queue() : front(nullptr), rear(nullptr) {}
	
	void enqueue(int value) {
		Node* node = new Node(value);
		if (!rear) {
			front = rear = node;
			return;
		}
		rear->next = node;
		rear = node;
	}
	
	void dequeue() {
		if (!front) return;
		Node* temp = front;
		front = front->next;
		if (!front) rear = nullptr;
		delete temp;
	}
	
	int peek() {
		return front ? front->data : -1;
	}
	
	~Queue() {
		while (front) dequeue();
	}
};

int main() {
	std::cout << "Hi" << std::endl;
}



/*

순서쌍, 구간


정렬
- 버블 stable
- 선택 ..
- 삽입 stable

- 병합 O(nlogn) stable
- 힙 O(nlogn) unstable
- 퀵 O(nlogn)~O(n^2) unstable
*/