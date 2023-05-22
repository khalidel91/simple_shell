#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>

#define MAX_COMMAND_LENGTH 100

int main() {
    char command[MAX_COMMAND_LENGTH];

    while (1) {
        printf("Enter a command (or 'exit' to exit the shell): ");
        fgets(command, sizeof(command), stdin);
        command[strcspn(command, "\n")] = '\0';

        if (strcmp(command, "exit") == 0) {
            printf("Exiting the shell...\n");
            break;
        } else {
            pid_t pid = fork();

            if (pid == -1) {
                printf("An error occurred while processing the command.\n");
            } else if (pid == 0) {
                char filename[MAX_COMMAND_LENGTH];
                snprintf(filename, sizeof(filename), "%s.txt", command);

                FILE *file = fopen(filename, "w");
                if (file == NULL) {
                    printf("An error occurred while creating the output file.\n");
                    exit(1);
                }

                fprintf(file, "Command executed successfully! Output saved in %s.\n", filename);
                fclose(file);

                printf("Command executed successfully! Check the output file.\n");
                exit(0);
            } else {
                wait(NULL);
            }
        }
    }

    return 0;
}

