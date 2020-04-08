#ifndef VRSHELL_H
#define VRSHELL_H
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/stat.h>
#include <string.h>
#include <errno.h>

char *read_line(void);
char **parse_str(char *str);
int executearg(char **arg);
int _strlen(char *str);
int _strncmp(char *s1, char *s2, int n);
char *_strncpy(char *dest, char *src, int from, int n);
char *_strcat(char *dest, char *src);
char *_getenv(const char *name);
char **_paths(void);
extern char **environ;
void *_realloc(void *ptr, unsigned int old_size, unsigned int new_size);
char *_finder(char **paths, char *cmd);

#endif /* VRSHELL_H */
