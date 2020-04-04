#ifndef VRSHELL_H
#define VRSHELL_H
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

int read_line(void);
char *parse_str(char *str, int n);
int executearg(char **arg);
#endif /* VRSHELL_H */
