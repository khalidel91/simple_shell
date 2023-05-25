#include <sys/wait.h>
#include <sys/types.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

/*
  Function Declarations for builtin shell commands:
 */

int func_exit(char **args);

/*
  List of builtin commands, followed by their corresponding functions.
 */
char *builtin_str[] = {

  "exit"
};

int (*builtin_func[]) (char **) = {
  
  &func_exit
};

int func_num_builtins() {
  return sizeof(builtin_str) / sizeof(char *);
}
int func_exit(char **args)
{
        (void) args;
  return 0;
}

/**
  @brief Launch a program and wait for it to terminate.
  @param args Null terminated list of arguments (including program).
  @return Always returns 1, to continue execution.
 */
int func_launch(char **args)
{
  pid_t pid;
  int status;

  pid = fork();
  if (pid == 0) {
    
    if (execvp(args[0], args) == -1) {
      perror("func");
    }
    exit(EXIT_FAILURE);
  } else if (pid < 0) {
    
    perror("func");
  } else {
 
    do {
      waitpid(pid, &status, WUNTRACED);
    } while (!WIFEXITED(status) && !WIFSIGNALED(status));
  }

  return 1;
}
int func_execute(char **args)
{
  int i;

  if (args[0] == NULL) {
    return 1;
  }

  for (i = 0; i < func_num_builtins(); i++) {
    if (strcmp(args[0], builtin_str[i]) == 0) {
      return (*builtin_func[i])(args);
    }
  }

  return func_launch(args);
}
/**
   @brief Read a line of input from stdin.
   @return The line from stdin.
 */
char *func_read_line(void)
{
#ifdef func_USE_STD_GETLINE
  char *line = NULL;
  ssize_t bufsize = 0; 
  if (getline(&line, &bufsize, stdin) == -1) {
    if (feof(stdin)) {
      exit(EXIT_SUCCESS);  
    } else  {
      perror("func: getline\n");
      exit(EXIT_FAILURE);
    }
  }
  return line;
#else
#define func_RL_BUFSIZE 1024
  int bufsize = func_RL_BUFSIZE;
  int position = 0;
  char *buffer = malloc(sizeof(char) * bufsize);
  int c;

  if (!buffer) {
    fprintf(stderr, "func: allocation error\n");
    exit(EXIT_FAILURE);
  }

  while (1) {
    
    c = getchar();

    if (c == EOF) {
      exit(EXIT_SUCCESS);
    } else if (c == '\n') {
      buffer[position] = '\0';
      return buffer;
    } else {
      buffer[position] = c;
    }
    position++;

    
    if (position >= bufsize) {
      bufsize += func_RL_BUFSIZE;
      buffer = realloc(buffer, bufsize);
      if (!buffer) {
        fprintf(stderr, "func: allocation error\n");
        exit(EXIT_FAILURE);
      }
    }
  }
