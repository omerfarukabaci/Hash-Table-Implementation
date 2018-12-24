#include <string>
#ifndef NODE_H
#define NODE_H

using namespace std;
class Node {
public:
	int key;
	string value;

	Node() {
		this->key = -1;
		this->value = "";
	}

	Node(int key, string value) {
		this->key = key;
		this->value = value;
	}
};

#endif