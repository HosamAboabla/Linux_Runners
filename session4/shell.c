#include "shell_lib.h"


int main(int argc, char *argv[])
{

    int status;
    while (1) 
	{
		char buffer[1024];

		
		if( promoteUser(buffer) != RET_OK )
		{
			printf("ERROR OCURRED!\n");
			return RET_ERROR;
		}


		if( setVariables(buffer) == RET_OK )
		{
			continue;
		}

		int pid = fork();
		if (pid < 0) {
			// error
			printf("fork failed\n");
			return RET_ERROR;
		} 
		else if ( pid > 0 ) {
			// parent
			wait(&status);

		} 
		else {
			// the child
			if( checkSetCommand(buffer) == RET_OK) 
			{
				return RET_OK;
			}

			excuteCommand(buffer);

			return RET_OK;		// to stop creating zombie processes if execvp faild
		}

    }


    return 0;
}
