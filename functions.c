#include "head.h"
/**
  @brief Launch a program and wait for it to terminate.
  @param args Null terminated list of arguments (including program).
  @return Always returns 1, to continue execution.
 */ 
int func_launch (char **args) 
{  
	pid_t pid; 
	int status;
	pid = fork ();
	
	if (pid == 0)
	{
	if (execvp (args[0], args) == -1)
	{  
		perror ("func");	
	}
	exit (EXIT_FAILURE);
	}
	else if (pid < 0)
	{
		perror ("func");
	}
	else
	{
		do
		{
			waitpid (pid, &status, WUNTRACED);
		}
		while (!WIFEXITED (status) && !WIFSIGNALED (status));
	}
	return 1;

	
/**
 * func_read_line -  Read a line of input from stdin.
 * @return The line from stdin
 *
 */ 
char *
func_read_line (void) 
{
  
#ifdef func_USE_STD_GETLINE
  char *line = NULL;
  
ssize_t bufsize = 0;
  
if (getline (&line, &bufsize, stdin) == -1)
    {
      
if (feof (stdin))
	{
	  
exit (EXIT_SUCCESS);
	
}
      else
	{
	  
perror ("func: getline\n");
	  
exit (EXIT_FAILURE);
	
}
    
}
  
return line;
  
#else	/* 
 */
#define func_RL_BUFSIZE 1024
  int bufsize = func_RL_BUFSIZE;
  
int position = 0;
  
char *buffer = malloc (sizeof (char) * bufsize);
  
int c;
  
 
if (!buffer)
    {
      
fprintf (stderr, "func: allocation error\n");
      
exit (EXIT_FAILURE);
    
}
  
 
while (1)
    {
      
 
c = getchar ();
      
 
if (c == EOF)
	{
	  
exit (EXIT_SUCCESS);
	
}
      else if (c == '\n')
	{
	  
buffer[position] = '\0';
	  
return buffer;
	
}
      else
	{
	  
buffer[position] = c;
	
}
      
position++;
      
 
 
if (position >= bufsize)
	{
	  
bufsize += func_RL_BUFSIZE;
	  
buffer = realloc (buffer, bufsize);
	  
if (!buffer)
	    {
	      
fprintf (stderr, "func: allocation error\n");
	      
exit (EXIT_FAILURE);
	    
}
	
}
    
}
  
#endif
}
#define func_TOK_BUFSIZE 64
#define func_TOK_DELIM " \t\r\n\a"
/**
 * @brief Split a line into tokens (very naively).
 * @param line The line.
 * @return Null-terminated array of tokens.
 */ 
char **func_split_line (char *line) 
{
	int bufsize = func_TOK_BUFSIZE, position = 0;
	char **tokens = malloc (bufsize * sizeof (char *));
	char *token, **tokens_backup;

	if (!tokens)
	{
		fprintf (stderr, "func: allocation error\n");
		exit (EXIT_FAILURE);
	}
	token = strtok (line, func_TOK_DELIM);
	while (token != NULL)
	{      
		tokens[position] = token;
		position++;
		if (position >= bufsize)
		{
			bufsize += func_TOK_BUFSIZE;
			tokens_backup = tokens;
			tokens = realloc (tokens, bufsize * sizeof (char *));
			if (!tokens)
			{
				free (tokens_backup);
				fprintf (stderr, "func: allocation error\n");
				exit (EXIT_FAILURE);
			}
		}
		token = strtok (NULL, func_TOK_DELIM);
	}
	tokens[position] = NULL;
	return (tokens);
}
/**
 * func_loop - loop function
 *
 */
void
func_loop (void) 
{
char *line;
char **args;
int status;
  
  do
    {
printf ("cisfun> ");
line = func_read_line ();
args = func_split_line (line);
status = func_execute (args);
free (args);
}
  while (status);
}
