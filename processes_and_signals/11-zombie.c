#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>

/**
 * main - Creates a zombie process that exists for 100 seconds.
 *
 * Return: Always 0.
 */
int main(void)
{
    pid_t child_pid;

    child_pid = fork();

    if (child_pid < 0)
    {
        perror("Fork failed");
        return (1);
    }

    if (child_pid == 0)
    {
        /* Child process execution path: exits immediately */
        printf("Zombie process created, PID: %d\n", getpid());
        exit(0);
    }
    else
    {
        /* Parent process execution path: sleeps for 100 seconds */
        sleep(100);
    }

    return (0);
}
