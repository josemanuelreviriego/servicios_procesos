#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <signal.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>

int main(int argc, char *argv[]) {

	pid_t pid, sid;
	FILE* fp;

	pid = fork();

	if (pid > 0) { return EXIT_SUCCESS; }
	umask(0);
	printf("\n");
	printf("Demonio");
	fp = fopen("demonio.txt", "w+");
	for (int i = 0; i < 100; i++);
	fclose(fp);

	sleep(5);

	sid = setsid();
	
	close(STDIN_FILENO);
	close(STDOUT_FILENO);
	close(STDERR_FILENO);
	signal(SIGTTOU, SIG_IGN);
	signal(SIGTTIN, SIG_IGN);
	signal(SIGTSTP, SIG_IGN);

	while (true) {
		sleep(60);
	}
}