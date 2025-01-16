#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <signal.h>

void signal_handler(int sig) {
    printf("Child received signal %d\n", sig);
}

int main() {
    pid_t pid;
    pid = fork();

    if (pid < 0) {
        perror("Fork failed");
        return 1;
    }

    if (pid > 0) {  // Parent process
        sleep(1);  // Allow child to set signal handler
        kill(pid, SIGUSR1);  // Send signal to child
        wait(NULL);
    } else {  // Child process
        signal(SIGUSR1, signal_handler);  // Set signal handler
        while (1) {
            pause();  // Wait for signal
        }
    }
    return 0;
}
