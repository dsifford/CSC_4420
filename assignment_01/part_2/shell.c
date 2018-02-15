#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "shell.h"

void history_append(History *h, const char *cmd) {
	char *cmd_copy = calloc(strlen(cmd), sizeof(char));
	strcpy(cmd_copy, cmd);
	if (h->capacity == h->idx) {
		h->items = realloc(h->items, (h->capacity + 10) * sizeof(char *));
		h->capacity += 10;
	}
	h->items[h->idx] = cmd_copy;
	h->idx++;
}

void prompt(const char *prompt_str, const History *h) {
	printf("%s[%lu]: ", prompt_str, h->idx + 1);
}

void read_command(char *input) {
	do {
		fgets(input, BUFFER_SIZE, stdin);
		// Remove newline
		input[strlen(input) - 1] = 0;
	} while (strcmp("", input) == 0);
}

static void eval_command_history(const History *history) {
	size_t items, i = 0;

	printf("Enter number of items to show: ");
	if (scanf("%lu", &items) != 1) {
		printf("Invalid input\n");
		return;
	}

	items = items < history->idx ? items : history->idx;

	while (i != items) {
		printf("%s\n", history->items[history->idx - 1 - i]);
		i++;
	}
}

static void eval_command_prompt(char *prompt) {
	char input[BUFFER_SIZE];
	printf("Enter new prompt value: ");
	read_command(input);
	prompt = realloc(prompt, strlen(input) + 1);
	strcpy(prompt, input);
}

void eval_command(const char *input, const History *history, char *prompt, Cmd *command) {
	if (strcmp("desp", input) == 0) {
		*command = DESP;
		return;
	}
	if (strcmp("exit", input) == 0) {
		*command = EXIT;
		return;
	}
	if (strcmp("help", input) == 0) {
		*command = HELP;
		return;
	}
	if (strcmp("history", input) == 0) {
		eval_command_history(history);
		*command = HISTORY;
		return;
	}
	if (strcmp("hour", input) == 0) {
		*command = HOUR;
		return;
	}
	if (strcmp("pma", input) == 0) {
		*command = PMA;
		return;
	}
	if (strcmp("poh", input) == 0) {
		*command = POH;
		return;
	}
	if (strcmp("pol", input) == 0) {
		*command = POL;
		return;
	}
	if (strcmp("prof", input) == 0) {
		*command = PROF;
		return;
	}
	if (strcmp("prompt", input) == 0) {
		eval_command_prompt(prompt);
		*command = PROMPT;
		return;
	}
	if (strcmp("quit", input) == 0) {
		*command = QUIT;
		return;
	}
	if (strcmp("ref", input) == 0) {
		*command = REF;
		return;
	}
	if (strcmp("room", input) == 0) {
		*command = ROOM;
		return;
	}
	if (strcmp("ta", input) == 0) {
		*command = TA;
		return;
	}
	if (strcmp("text", input) == 0) {
		*command = TEXT;
		return;
	}
	if (strcmp("tma", input) == 0) {
		*command = TMA;
		return;
	}
	if (strcmp("toh", input) == 0) {
		*command = TOH;
		return;
	}
	if (strcmp("tol", input) == 0) {
		*command = TOL;
		return;
	}
	if (strcmp("url", input) == 0) {
		*command = URL;
		return;
	}
	if (strcmp("", input) != 0) {
		printf("%s: command not found\n", input);
	}
	*command = _INVALID;
}

void print_command(const Cmd command) {
	switch (command) {
		case DESP: {
			printf(
				"Course Description:\n"
				"\tOperating system is an essential software layer to use various "
				"computing devices. This course covers the basic components and "
				"design principles of modern operating systems, including "
				"process and thread, CPU scheduling, memory management, file "
				"system and others. This course also provides hand-on "
				"programming experiences of using Linux system.\n"
			);
			break;
		}
		case HOUR: {
			printf(
				"Class times:\n"
				"\t%-20s\t%-20s\n"
				"\t%-20s\t%-20s\n",
				"Tuesday",
				"Thursday",
				"05:30pm-06:45pm",
				"05:30pm-06:45pm"
			);
			break;
		}
		case PMA: {
			printf(
				"Professor's email address:\n"
				"\tec8951@wayne.edu\n"
			);
			break;
		}
		case POL: {
			printf(
				"Professor's office location:\n"
				"\tVaries by appointment\n"
			);
			break;
		}
		case POH: {
			printf(
				"Professor's office hours:\n"
				"\tAfter the class or by appointment\n"
			);
			break;
		}
		case PROF: {
			printf(
				"Professor:\n"
				"\tRaed Almomani\n"
			);
			break;
		}
		case REF: {
			printf(
				"Reference books:\n"
				"\tOperating System Concepts, 8th Edition, Wiley, 2008.\n"
				"\tUnderstanding the Linux Kernel, 3rd Edition, O'Reilly Media, 2005.\n"
				"\tAdvanced UNIX Programming, 2nd Edition, Pearson, 2004.\n"
				"\tAdvanced Programming in the UNIX Environment, Addison-Wesley, 1992.\n"
			);
			break;
		}
		case ROOM: {
			printf(
				"Classroom location:\n"
				"\tATEC Room 0151\n"
			);
			break;
		}
		case TOL:
		case TOH:
		case TMA:
		case TA: {
			puts("[INFO]: TA not assigned this semester");
			break;
		}
		case TEXT: {
			printf(
				"Textbook:\n"
				"\tModern Operating Systems, Andrew S. Tanenbaum, 4th Edition, Pearson, 2015\n"
			);
			break;
		}
		case URL: {
			printf(
				"Course website:\n"
				"\thttps://blackboard.wayne.edu/webapps/blackboard/execute/"
				"announcement?method=search&course_id=_1231670_1\n"
			);
			break;
		}
		case HELP: {
			printf(
				"CSC4420 Shell Commands:\n"
				"\t%-15s: %s\n"
				"\t%-15s: %s\n"
				"\t%-15s: %s\n"
				"\t%-15s: %s\n"
				"\t%-15s: %s\n"
				"\t%-15s: %s\n"
				"\t%-15s: %s\n"
				"\t%-15s: %s\n"
				"\t%-15s: %s\n"
				"\t%-15s: %s\n"
				"\t%-15s: %s\n"
				"\t%-15s: %s\n"
				"\t%-15s: %s\n"
				"\t%-15s: %s\n"
				"\t%-15s: %s\n"
				"\t%-15s: %s\n"
				"\t%-15s: %s\n"
				"\t%-15s: %s\n",
				"prompt",
				"set the shell prompt",
				"url",
				"list the course web site",
				"hour",
				"list class times",
				"room",
				"list classroom location",
				"desp",
				"list the description of this course",
				"text",
				"list the textbook",
				"ref",
				"list the reference books",
				"prof",
				"list the professor's name",
				"pol",
				"professor's office location",
				"poh",
				"professor's office hours",
				"pma",
				"professor's email address",
				"ta",
				"list the TA's name",
				"tol",
				"TA's office location",
				"toh",
				"TA's office hours",
				"tma",
				"TA's email address",
				"history",
				"list history of events up to the number you set",
				"help",
				"list all the available commands",
				"exit or quit",
				"exit CSC4420 shell"
			);
			break;
		}
		default:
			break;
	}
}
