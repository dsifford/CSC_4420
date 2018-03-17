#include <stdio.h>
#include "memory-manager.h"

#define VERBOSE 0

int main() {

	void (*logger)(const MemoryManager *, const char *) =
		VERBOSE ? print_manager : print_diagram;

	MemoryManager *manager = create_manager(10);
	logger(manager, "Empty manager");

	insert_first_fit(manager, 2, "A");
	logger(manager, "use  2 (A)");

	insert_first_fit(manager, 3, "B");
	logger(manager, "use  3 (B)");

	insert_first_fit(manager, 4, "C");
	logger(manager, "use  4 (C)");

	free_named_units(manager, 3, "B");
	logger(manager, "free 3 (B)");

	insert_first_fit(manager, 1, "E");
	logger(manager, "use  1 (E)");

	free_named_units(manager, 4, "C");
	logger(manager, "free 4 (C)");

	free_named_units(manager, 2, "A");
	logger(manager, "free 2 (A)");

	insert_first_fit(manager, 5, "H");
	logger(manager, "use  5 (H)");

	return 0;
}
