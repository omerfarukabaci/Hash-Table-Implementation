#include "Hash.h"

Hash::Hash(int capacity) {
	this->capacity = capacity;
	this->size = 0;
	this->insertCollisionCounter = 0;
	this->searchCollisionCounter = 0;
	this->table = new Node[capacity];
}

Hash::~Hash() {
	delete[] this->table;
}

void Hash::insert(Node input) {
	int collision = 0;
	int index = hashFunction(input.key);

	if (size > capacity)
		return;

	while (table[index].key != -1)
	{
		collision++;
		index = hashFunction(input.key, collision);
	}

	table[index] = input;
	size++;
	insertCollisionCounter += collision;
}

string Hash::search(int key) {
	int collision = 0;
	int index = hashFunction(key);
	int counter = 0;
	Node result;

	while (table[index].key != -1)
	{
		if (table[index].key == key) {
			searchCollisionCounter += collision;
			return table[index].value;
		}

		index = hashFunction(key, collision);
		collision++;
		counter++;
		if (counter==capacity)
			return result.value;
	}

	return result.value;
}