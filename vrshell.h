#ifndef VRSHELL_H
#define VRSHELL_H
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

char *read_line(void);
char *parse_str(char *str);
int executearg(char **arg);
int _strlen(char *str);

#endif /* VRSHELL_H */
