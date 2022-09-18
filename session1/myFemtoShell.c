#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    char input[1024];

    while(1)
    {
        printf("Listing to you > ");
        fgets(input , 1024 , stdin);

        if( strcmp("exit\n" , input) == 0)
        {
            break;
        }

        printf("you said : %s" , input);
    }
    printf("Good Bye :)\n");
    return 0;
}