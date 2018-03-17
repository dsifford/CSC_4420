#include <errno.h>
#include <stdio.h>
#include <stdlib.h>
#include "memory-manager.h"

MemoryManager *create_manager(size_t size) {
	MemoryManager *manager = malloc(sizeof(MemoryManager));
	MemoryNode *first = malloc(sizeof(MemoryNode));

	manager->size = size;
	manager->first = first;

	first->kind = HOLE_NODE;
	first->name = HOLE_NAME;
	first->start = 0;
	first->length = size;
	first->prev = 0;
	first->next = 0;

	return manager;
}

int insert_first_fit(MemoryManager *manager, unsigned int size, const char *name) {
	MemoryNode *node = manager->first;

	while (node) {
		switch (node->kind) {
			case HOLE_NODE:
				if (node->length < size) {
					break;
				}
				return _insert_at_node(manager, node, size, name);
			case PROCESS_NODE:
				break;
		}
		node = node->next;
	}

	return EOVERFLOW;
}

int free_named_units(MemoryManager *manager, unsigned int size, const char *name) {
	MemoryNode *node = manager->first;

	while (node) {
		if (node->kind == PROCESS_NODE && node->name == name) {
			return _free_at_node(manager, node, size);
		}
		node = node->next;
	}

	return ESRCH;
}

// Objectives: take a hole node, split it at the size needed for
// size, create a process node of size size, adjust links
int _insert_at_node(MemoryManager *manager, MemoryNode *hole, unsigned int size, const char *name) {
	if (hole->kind == PROCESS_NODE) {
		return EINVAL;
	}
	if (hole->length < size) {
		return EOVERFLOW;
	}
	// Perfect fit -- no need to split
	if (hole->length == size) {
		hole->kind = PROCESS_NODE;
		hole->name = name;
		return 0;
	}

	MemoryNode *node = malloc(sizeof(MemoryNode));
	node->name = name;
	node->kind = PROCESS_NODE;
	node->start = hole->start;
	node->length = size;

	hole->start += size;
	hole->length -= size;

	// Adjust links
	if (node->start == 0) {
		manager->first = node;
	}
	else {
		hole->prev->next = node;
	}

	node->next = hole;
	node->prev = hole->prev;

	hole->prev = node;

	return 0;
}

int _free_at_node(MemoryManager *manager, MemoryNode *node, unsigned int size) {
	if (node->kind == HOLE_NODE) {
		return EINVAL;
	}
	if (size > node->length) {
		return ERANGE;
	}

	node->length -= size;

	switch (_identify_surrounding_holes(node)) {
		case BOTH:
			if (node->next->length > node->prev->length) {
				node->next->length += size;
				node->next->start -= size;
			}
			else {
				node->prev->length += size;
				node->start += size;
			}
			break;
		case NEXT:
			node->next->length += size;
			node->next->start -= size;
			break;
		case PREV:
			node->prev->length += size;
			node->start += size;
			break;
		case NONE: {
			MemoryNode *hole = malloc(sizeof(MemoryNode));
			hole->kind = HOLE_NODE;
			hole->name = HOLE_NAME;
			hole->start = node->start + node->length;
			hole->length = size;

			// Adjust links
			hole->next = node->next;
			node->next->prev = hole;

			hole->prev = node;
			node->next = hole;
		}
	}

	if (node->length == 0) {
		if (node->next) {
			node->next->prev = node->prev;
		}
		if (node->prev) {
			node->prev->next = node->next;
		}
		else {
			manager->first = node->next;
		}
		free(node);
	}

	return 0;
}

enum SurroundingHoles _identify_surrounding_holes(const MemoryNode *node) {
	if ((node->next && node->next->kind == HOLE_NODE) &&
	    (node->prev && node->prev->kind == HOLE_NODE)) {
		return BOTH;
	}
	else if (node->next && node->next->kind == HOLE_NODE) {
		return NEXT;
	}
	else if (node->prev && node->prev->kind == HOLE_NODE) {
		return PREV;
	}
	else {
		return NONE;
	}
}

void print_manager(const MemoryManager *manager, const char *msg) {
	MemoryNode *node = manager->first;
	printf("%s\n", msg);
	while (node) {
		_print_node(node);
		node = node->next;
	}
}

void print_diagram(const MemoryManager *manager, const char *msg) {
	MemoryNode *node = manager->first;
	size_t i;
	printf("%15s: |", msg);
	while (node) {
		for (i = 0; i < node->length; i++) {
			printf("%s", node->kind == PROCESS_NODE ? node->name : "_");
		}
		node = node->next;
	}
	printf("|\n");
}

void _print_node(const MemoryNode *node) {
	printf(
		"+---------------------------------+\n"
		"|   Prev: %-5s %17p |\n"
		"+---------------------------------+\n"
		"|   Addr: %-23p |\n"
		"|  Start: %-23u | %s\n"
		"| Length: %-23u |\n"
		"+---------------------------------+\n"
		"|   Next: %-5s %17p |\n"
		"+---------------------------------+\n\n",
		node->prev ? node->prev->name : "",
		(void *) node->prev,
		(void *) node,
		node->start,
		node->name,
		node->length,
		node->next ? node->next->name : "",
		(void *) node->next
	);
}
