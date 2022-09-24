#include <unistd.h>
#include <string.h>

int main(int argc , char** argv )
{


	char* error;
	error = "Sorry, can't echo!\n";
	for(int i = 1 ; i < argc ; i++)
	{
		if ( write(1 , argv[i] , strlen(argv[i]) )  == -1 )
		{
			write(1 , error , strlen(error) );
			return -1;
		}
		if( i == argc - 1 )
		{
			write(1 , "\n" , 1);
		}
		else
		{
			write(1 , " " , 1);
		}
	}




	return 0;
}
