#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdio.h>

int main(int argc , char** argv)
{
	char* error;

	if( argc != 3)
	{
		error = "Ivalid parameters!\n";
		write(1 , error , strlen(error) );
		return -1;
	}

	int source_fd = open(argv[1] , O_RDONLY);

	if( source_fd == -1 )
	{
		error = "Source file not found!\n";
		write(1 , error , strlen(error) );
		return -1;
	}	

	int destination_fd = open(argv[2] , O_CREAT|O_WRONLY , 0644);
	if( destination_fd == -1 )
	{
		error = "Can't create destination file!\n";
		write(1 , error , strlen(error) );
		return -1;
	}

	int count;
	char buffer[255];

	while( (count = read(source_fd , buffer , 255) ) != 0 )
	{
		if( write(destination_fd , buffer , count) == -1 )
		{
			error = "Can't write to destination file!\n";
			write(1 , error , strlen(error) );
			return -1;
		}
	}

	close(source_fd);
	close(destination_fd);
	if( remove(argv[1])  == -1 )
	{
		error = "Can't delete source file!\n";
		write(1 , error , strlen(error) );
		return -1;
	}

	return 0;
}
