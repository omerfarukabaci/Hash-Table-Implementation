#include "Hash.h"

class DoubleHash : public Hash {
	int prime;
	int hashFunction(int key, int collision = 0) {
		return ((key % capacity) + (collision * (prime - key % prime)) + collision) % capacity;
	};
public:
	DoubleHash(int capacity, int prime) : Hash(capacity) {
		this->prime = prime;
	}
};