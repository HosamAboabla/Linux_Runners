#include <unistd.h>
#include <string.h>

int main(int argc , char** argv)
{
	char pathname[255];

	if(getcwd(pathname , 255) == NULL )
	{
		char* error;
		error = "Sorry, can't print current directory!\n";
		write(1 , error , strlen(error) );
		return -1;
	}

	write(1 , pathname , strlen(pathname) );
	write(1 , "\n" , 1);

	return 0;
}
