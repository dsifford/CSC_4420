#include <stdlib.h>
#include <stdio.h>
#include "shell.h"

int main() {
	History history = {
		.capacity = 0,
		.idx = 0,
		.items = calloc(0, sizeof(const char *)),
	};
	char *prompt_str = malloc(sizeof(char));
	char input[BUFFER_SIZE];
	Cmd command = _INVALID;

	while (command != QUIT && command != EXIT) {
		prompt(prompt_str, &history);

		// Main REPL stuff
		read_command(input);
		eval_command(input, &history, prompt_str, &command);
		print_command(command);

		history_append(&history, input);
		input[0] = 0; // clear input for next loop
	}

	return 0;
}
