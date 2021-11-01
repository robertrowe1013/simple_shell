#  0x16. C - Simple Shell
An assignment to create a simple shell using all the concepts learned in the first three months of Holberton with the following requirements and restrictions on function calls: 

## Requirements

* Allowed editors: vi, vim, emacs
* All files are compiled on Ubuntu 14.04 LTS
* Programs and functions are compiled with gcc 4.8.4 using the flags -Wall -Werror -Wextra and -pedantic
* All files should end with a new line
* A README.md file, at the root of the folder of the project is mandatory
* Code should use the Betty style. It is checked using betty-style.pl and betty-doc.pl
* No more than 5 functions per file
* All header files should be include guarded
* Use system calls only when needed

## List of allowed functions and system calls

* access (man 2 access)
* chdir (man 2 chdir)
* close (man 2 close)
* closedir (man 3 closedir)
* execve (man 2 execve)
* exit (man 3 exit)
* _exit (man 2 _exit)
* fflush (man 3 fflush)
* fork (man 2 fork)
* free (man 3 free)
* getcwd (man 3 getcwd)
* getline (man 3 getline)
* isatty (man 3 isatty)
* kill (man 2 kill)
* malloc (man 3 malloc)
* open (man 2 open)
* opendir (man 3 opendir)
* perror (man 3 perror)
* read (man 2 read)
* readdir (man 3 readdir)
* signal (man 2 signal)
* stat (__xstat) (man 2 stat)
* lstat (__lxstat) (man 2 lstat)
* fstat (__fxstat) (man 2 fstat)
* strtok (man 3 strtok)
* wait (man 2 wait)
* waitpid (man 2 waitpid)
* wait3 (man 2 wait3)
* wait4 (man 2 wait4)
* write (man 2 write)

## Compilation

```bash
gcc -Wall -Werror -Wextra -pedantic *.c -o vrsh
```

## Usage
The shell works like this in interactive mode:

```bash
$ ./vrsh
 ($) /bin/ls
vrsh main.c shell.c
 ($) exit
$
```

The shell works like this in non-interactive mode:

```bash
$ echo "/bin/ls" | ./vrsh
vrsh main.c shell.c test_ls_2
$
$ cat test_ls_2
/bin/ls
/bin/ls
$
$ cat test_ls_2 | ./vrsh
vrsh main.c shell.c test_ls_2
vrsh main.c shell.c test_ls_2
$
```

## Examples

```bash
$ ls -l
total 204
-rw-rw-r-- 1 vagrant vagrant    169 Apr 14 23:22 AUTHORS
-rw-rw-r-- 1 vagrant vagrant   3326 Apr 17 02:14 README.md
-rw-rw-r-- 1 vagrant vagrant   2083 Apr 16 23:00 badcom.c
-rw-rw-r-- 1 vagrant vagrant    854 Apr 17 02:04 builtins.c
-rw-rw-r-- 1 vagrant vagrant    887 Apr 17 02:06 curpath.c
-rw-rw-r-- 1 vagrant vagrant    618 Apr 17 01:10 executearg.c
-rw-rw-r-- 1 vagrant vagrant   2716 Apr  9 22:55 man_1_simple_shell
-rw-rw-r-- 1 vagrant vagrant   1014 Apr 10 23:41 memfuncs.c
-rw-rw-r-- 1 vagrant vagrant   1435 Apr 15 22:49 parse_str.c
-rw-rw-r-- 1 vagrant vagrant   2605 Apr 17 02:06 pathfinder.c
-rw-rw-r-- 1 vagrant vagrant    434 Apr 17 02:06 readline.c
-rw-rw-r-- 1 vagrant vagrant   1816 Apr 15 02:20 str_funcs.c
-rwxr-xr-x 1 vagrant vagrant 110080 Apr 16 15:34 test
-rwxrw-r-- 1 vagrant vagrant     16 Apr 11 13:12 test_ls_2
drwxrwxr-x 3 vagrant vagrant   4096 Apr 11 12:42 this_works
-rwxrwxr-x 1 vagrant vagrant  28322 Apr 17 02:04 vrsh
-rw-rw-r-- 1 vagrant vagrant    793 Apr 17 02:06 vrsh.c
-rw-rw-r-- 1 vagrant vagrant   1054 Apr 17 02:06 vrshell.h
drwxrwxr-x 4 vagrant vagrant   4096 Apr 17 01:42 working
$ ./vrsh
 ($) pwd
/home/vagrant/simple_shell
 ($) cd ..
 ($) pwd
/home/vagrant
 ($) qwerty
./vrsh: 7: qwerty: not found
 ($) echo $?
127
 ($) exit
$
```

## Authors

This project was pair programmed with daily check-ins to update progress and distribute tasks.

Robert Rowe [github](https://github.com/robertrowe1013) [LinkedIn](https://www.linkedin.com/in/robertrowe1013/)

Viet Tran [github](https://github.com/veeteeran)
