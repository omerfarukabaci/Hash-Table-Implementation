#include "Node.h"
#ifndef HASH_H
#define HASH_H

using namespace std;
class Hash {
protected:
	int capacity;
	int size;
	virtual int hashFunction(int key, int collision = 0) = 0;

public:
	Node* table;
	int searchCollisionCounter;
	int insertCollisionCounter;
	Hash(int capacity);
	~Hash();
	void insert(Node input);
	string search(int key);
};

#endif
