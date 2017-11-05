#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include "menu.h"

int Quit(int argc, char* argv[])
{
	int ch;
	while ((ch = getopt(argc, argv, "ab:c")) != -1)
	{
		printf("optind: %d\n", optind);
		switch (ch)
		{
		case 'a':
			printf("HAVE option: -a\n\n");
			break;
		case 'b':
			printf("HAVE option: -b\n");
			printf("The argument of -b is %s\n\n", optarg);
			break;
		case 'c':
			printf("HAVE option: -c\n");
			printf("The argument of -c is %s\n\n", optarg);
			break;
		case '?':
			printf("Unknown option: %c\n", (char)optopt);
			break;
		}
	}


	exit(0);
}

int main()
{
	MenuConfig("version", "menu cmd program v7", NULL);
	MenuConfig("quit", "Quit from cmd", Quit);

	ExecuteMenu();
}