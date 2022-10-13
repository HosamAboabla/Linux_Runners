
#ifndef __SHELL__H_

#define __SHELL__H_

#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>


typedef enum {
    RET_ERROR = -1,
    RET_OK = 0,
    RET_COMMAND_NOT_FOUND
}RETURN_STATUS;

RETURN_STATUS promoteUser(char* buffer);
RETURN_STATUS setVariables(char* buffer);
RETURN_STATUS checkSetCommand(char* buffer);
void excuteCommand(char* buffer);


#endif