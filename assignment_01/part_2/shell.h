#include <stdlib.h>

#ifndef SHELL_H
#define SHELL_H

#define BUFFER_SIZE 100

typedef enum Cmd {
	_INVALID = -1,
	DESP,
	EXIT,
	HELP,
	HISTORY,
	HOUR,
	PMA,
	POH,
	POL,
	PROF,
	PROMPT,
	QUIT,
	REF,
	ROOM,
	TA,
	TEXT,
	TMA,
	TOH,
	TOL,
	URL,
} Cmd;

typedef struct History {
	size_t capacity;
	size_t idx;
	const char **items;
} History;


void read_command(char *input);
void eval_command(const char *input, const History *history, char *prompt, Cmd *command);
void print_command(const Cmd command);

void history_append(History *h, const char *cmd);
void prompt(const char *prompt_str, const History *h);

#endif
