#include "Hash.h"
#include <stdlib.h>
#include <time.h>

class UniversalHash : public Hash {
	int randomNumbers[3];
	int hashFunction(int key, int collision = 0) {
		int keyDigits[3];
		int hashedKey = 0;

		keyDigits[0] = key / 10000;
		keyDigits[1] = (key / 100) - keyDigits[0] * 100;
		keyDigits[2] = key - ((keyDigits[0] * 10000) + (keyDigits[1] * 100));
		
		for (int i = 0; i < 3; i++) {
			hashedKey += keyDigits[i] * randomNumbers[i];
		}

		return (hashedKey + collision) % capacity;
	};
public:
	UniversalHash(int capacity) : Hash(capacity) {
		srand(time(NULL));
		for (int i = 0; i < 3; i++) {
			randomNumbers[i] = rand() % capacity;
		}
	}
};