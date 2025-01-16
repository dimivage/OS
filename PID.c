#include <stdio.h>
#include <unistd.h>

int main() {
    pid_t pid;
    FILE *file = fopen("pids.txt", "w");

    if (!file) {
        perror("Failed to open file");
        return 1;
    }

    pid = fork();

    if (pid < 0) {
        perror("Fork failed");
        fclose(file);
        return 1;
    }

    if (pid > 0) {  // Parent process
        fprintf(file, "Parent PID: %d\n", getpid());
    } else {  // Child process
        fprintf(file, "Child PID: %d\n", getpid());
    }

    fclose(file);
    return 0;
}
