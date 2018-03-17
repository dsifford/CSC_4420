#include <stdlib.h>

#ifndef MEMORY_MANAGER_H
#define MEMORY_MANAGER_H

#define HOLE_NAME "HOLE"

enum NodeKind { PROCESS_NODE, HOLE_NODE };
enum SurroundingHoles { PREV, NEXT, BOTH, NONE };

typedef struct memory_manager {
	size_t size;
	struct memory_node *first;
} MemoryManager;

typedef struct memory_node {
	enum NodeKind kind;
	const char *name;
	unsigned int start;
	unsigned int length;
	struct memory_node *next;
	struct memory_node *prev;
} MemoryNode;

MemoryManager *create_manager(size_t size);

int insert_first_fit(MemoryManager *manager, unsigned int size, const char *name);
int free_named_units(MemoryManager *manager, unsigned int size, const char *name);

int _insert_at_node(MemoryManager *manager, MemoryNode *hole, unsigned int size, const char *name);
int _free_at_node(MemoryManager *manager, MemoryNode *node, unsigned int size);

enum SurroundingHoles _identify_surrounding_holes(const MemoryNode *node);

void print_manager(const MemoryManager *manager, const char *msg);
void print_diagram(const MemoryManager *manager, const char *msg);

void _print_node(const MemoryNode *node);

#endif
