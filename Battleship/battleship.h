#include "stdbool.h"

struct Location {
	int r;
	int c;
	bool h;
};

struct Vessel {
	//char name[20];
	bool sunk;
	unsigned int length;
	struct Location locations[5];
};
