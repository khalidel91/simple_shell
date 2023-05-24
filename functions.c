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
}
