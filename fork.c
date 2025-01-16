#include <stdio.h>
#include <unistd.h>

int main() {
    for (int i = 0; i < 3; i++) {
        pid_t pid = fork();  // Fork a new process
        if (pid == 0) {
            // Child process
            printf("Child Process PID: %d\n", getpid());
            break; // Break the loop in the child process
        } else if (pid > 0) {
            // Parent process
            printf("Parent Process PID: %d\n", getpid());
        } else {
            // Error handling in case fork fails
            perror("fork failed");
            return 1;
        }
    }
    return 0;
}
