#ifndef _SHELL_H_
#define _SHELL_H_

/**###### ENVIRON VAR ######*/

extern char **environ;

/**##### MACROS ######*/

#define BUFSIZE 1024
#define DELIM " \t\r\n\a"
#define PRINTER(c) (write(STDOUT_FILENO, c, _strlen(c)))

/**###### LIBS USED ######*/

#include <stdlib.h>
#include <errno.h>
#include <sys/types.h>
#include <signal.h>
#include <sys/wait.h>
#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <linux/limits.h>

/**###### STRING FUNCTION ######*/

char *_strtok(char *str, const char *tok);
unsigned int check_delim(char c, const char *str);
char *_strncpy(char *dest, char *src, int n);
int _strlen(char *s);
int _putchar(char c);
int _atoi(char *s);
void _puts(char *str);
int _strcmp(char *s1, char *s2);
int _isalpha(int c);
void array_rev(char *arr, int len);
int intlen(int num);
char *_itoa(unsigned int n);
char *string_concatenate(char *dest, char *src);
char *string_copy(char *dest, char *src);
char *string_find_char(char *s, char c);
int string_compare(const char *s1, const char *s2, size_t n);
char *string_duplicate(char *str);

/**###### MEMORY MANAGEMENT ######*/

void free_env(char **env);
void *fill_an_array(void *a, int el, unsigned int len);
char *_memcpy(char *dest, char *src, unsigned int n);
void *_calloc(unsigned int size);
void *_realloc(void *ptr, unsigned int old_size, unsigned int new_size);
void free_all(char **input, char *line);

/**###### INPUT FUNCTION ######*/

void prompt(void);
void signal_to_handel(int sig);
char *_getline(void);

/**###### COMMAND PARSER AND EXTRACTOR ######*/

int path_cmd(char **line);
char *_getenv(char *name);
char **parse_cmd(char *cmd);
int handle_builtin(char **cmd, int er);
void read_file(char *filename, char **argv);
char *build(char *token, char *value);
int check_builtin(char **cmd);
void creat_envi(char **envi);
int check_cmd(char **tokens, char *line, int count, char **argv);
void treat_file(char *line, int counter, FILE *fd, char **argv);
void exit_bul_for_file(char **cmd, char *line, FILE *fd);

/**###### BUL FUNCTION ######*/

void hashtag_handle(char *buff);
int history(char *input);
int history_dis(char **cmd, int er);
int display_environment(char **cmd, int er);
int change_directory(char **cmd, int er);
int display_help(char **cmd, int er);
int echo_command(char **cmd, int er);
void  exit_shell(char **cmd, char *input, char **argv, int c);
int print_echo(char **cmd);

/**###### ERROR HANDLE AND PRINTER ######*/

void print_number(unsigned int n);
void print_number_in(int n);
void print_error(char *line, int c, char **argv);
void _prerror(char **argv, int c, char **cmd);


/**
 * struct bulltin - contain builtin to handle and function to execute
 * @command:pointer to char
 * @fun:fun to excute when bultin true
 */

typedef struct bulltin
{
	char *command;
	int (*fun)(char **line, int er);
} bul_t;

#endif
