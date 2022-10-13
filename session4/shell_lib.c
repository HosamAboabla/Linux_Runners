#include "shell_lib.h"



RETURN_STATUS promoteUser(char* buffer)
{
    char* pathname;
    char hostname[1024];
    char* username;

    
    pathname = getenv("PWD");

    gethostname(hostname , 1024);
    
    username = getenv("USER");
    printf("%s@%s:%s$ ", username, hostname, pathname);
	// scanf("%[^\n]", buffer );       ---------> warning when using scanf, thread doesn't wait for input, there is something wrong
	fgets(buffer, 1024, stdin);
	buffer[strlen(buffer) - 1] = '\0';

    return RET_OK;
}


RETURN_STATUS setVariables(char* buffer)
{
        // check for =
		char* save = NULL;
		char* var_name = NULL;
		// getchar();
		var_name = strtok_r( buffer , "=", &save);
		if (var_name != NULL) 
		{
			char *var_value = strtok_r(NULL, "=", &save);
			// set en
			if (var_value) {
				setenv(var_name, var_value, 1);	// overwrite --> true
				return RET_OK;
			}
		}

    return RET_COMMAND_NOT_FOUND;
}




RETURN_STATUS checkSetCommand(char* buffer)
{
    if (strcmp(buffer, "set") == 0) {
        extern char** environ;
        char** env = environ;
        for (env; *env; ++env) 
        {
            printf("%s\n", *env);
        }
        return RET_OK;
    }

    return RET_COMMAND_NOT_FOUND;
}


void excuteCommand(char* buffer)
{
    char *argv2[100] = { NULL };
    char* save = NULL;
    char* token = strtok_r(buffer, " ", &save);
    int token_index = 0;

    if (token) {
        argv2[token_index++] = token;
    }
    while (token = strtok_r(NULL, " ", &save)) {
        argv2[token_index++] = token;
    }

    execvp(argv2[0], argv2);
}