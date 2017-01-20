#include <stdio.h>

int main (int argc, char* argv[])
{
	int i = 1;
	printf ("The name of this program is `%s'.\n", argv[0]);
	printf ("This program was invoked with %d arguments.\n", argc - 1);

	if (argc > 1)
	{
		while(i <= atoi(argv[1]))
		{
			sleep(1);
			fprintf(stderr,"%d",i); // Scrive sullo standard error stderr che non è bufferizzato, va direttamente sulla 
      
			i++;
		}
    
    		printf("Stop\n");
  	}
  	else 
		printf("Nessun tempo settato\n");
  
	return 0;
}
