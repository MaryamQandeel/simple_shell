#ifndef SHELL_H
#define SHELL_H

#include <sys/types.h>
#include <time.h>
#include <stdarg.h>
#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#include <string.h>
#include <sys/wait.h>
#include <sys/stat.h>
#include <stdbool.h>

/* free efficiency for assistant function */
void freeArr(char **Arr);

struct builtin
{
	char *env;
	char *exit;
} builtin;

struct info
{
	int final_exit;
	int ln_count;
} info;

struct flags
{
	bool interactive;
} flags;

/* my list strings */
int strngcomp(char *s1, char *s2);
int stringlen(char *s);
int strngcompn(char *s1, char *s2, int n);
char *stringdup(char *s);
char *stringchar(char *s, char c);

void Execute(char *cmnd, char **arg);
char *findlocatepath(void);

/* built-in plugins */
int mytchecker(char **cmd, char *buf);
void usrimmed(void);
void signalhandle(int m);
char **_symbol(char *line);
char *pathtesting(char **path, char *command);
char *pathy(char *path, char *command);
int built(char **command, char *line);
void out(char **command, char *line);

void envprnt(void);

/* variables env */
extern char **environ;

#endif
