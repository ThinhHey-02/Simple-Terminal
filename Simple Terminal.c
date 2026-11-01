#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define max_len 426

char string[max_len];

int main()
{
	printf("-SIMPLE TERMINAL-\n\n");
	printf("Type 'help'.\n\n");
	while (1)
	{
		printf("\033[1;32m$> \033[0m");
		if (fgets(string, max_len, stdin) == NULL)
		{
            break;
        }
        string[strcspn(string, "\n")] = '\0';
        
        int a;
        for (a = 0; string[a] != '\0'; a++)
		{
            string[a] = tolower((unsigned char)string[a]);
        }
		check();
	}
	
	return 0;
}

void check()
{
    if (strcmp(string, "help") == 0)
	{
        help();
    }
    
    else if (strcmp(string, "exit") == 0)
    {
    	exit(0);
	}
	
	else if (strncmp(string, "nf ", 3) == 0)
	{
		char *filename = string + 3; 
        newfile(filename);
	}
	
	else if(strncmp(string, "echo ",5) == 0)
	{
		printf("%s\n", string + 5);
	}
	
	else if (strcmp(string, "clear") == 0)
	{
		system("cls");
	}
	
	else if (strncmp(string, "open ",5) == 0)
	{
		char systemcmd[max_len + 10];
        snprintf(systemcmd, sizeof(systemcmd), "start %s", string + 5);
        system(systemcmd);
	}
}

void newfile(char *filename)
{
	FILE *file = fopen(filename, "w"); 
    
    if (file == NULL)
	{
        printf("\033[91mCan't create.\033[0m\n");
        return;
    }
    
    fclose(file);
    printf("\x1b[32mCreated!:\033[0m %s\n", filename);
}

void help()
{
	char *help[6] = {"HELP", "ECHO [CONTENT]", "CLEAR", "NF [NAME]: New File.", "EXIT", "OPEN [FILE NAME]"};
	int i;
	int length = sizeof (help) / sizeof (help[0]);
	for (i = 0; i < length; i++)
	{
		printf("%s\n", help[i]);
	}
}