#include "Hash.h"

class LinearHash : public Hash {
	int hashFunction(int key, int collision = 0) {
		return (key + collision) % capacity;
	};
public:
	LinearHash(int capacity) : Hash(capacity) {
	}
};

