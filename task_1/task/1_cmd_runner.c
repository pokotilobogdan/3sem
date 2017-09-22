#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <string.h>
#include <time.h>
#include <sys/wait.h>
#include <ctype.h>



int main()
{
	char path[100];
	char name[100];
	int n;

	printf("Путь к программе: ");
	scanf("%s", path);
	printf("Имя программы: ");
	scanf("%s", name);

	const pid_t pid = fork();
	if (pid < 0) {
		printf("fork() error\n");
		return -1;
	}
	if (pid) {
			int status;
			waitpid(pid, &status, 0);
			printf("Ret code: %d\n", WEXITSTATUS(status));
	} else {
			execl(path,name,NULL);
		}
	return 0;
}

