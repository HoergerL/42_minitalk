#include <signal.h>
#include <unistd.h>

//Achtung printf

void receive_char()
{
	return;
}

int main (int argc, char *argv[])
{
	int i;
	int shift;
	struct sigaction	sa;
	i = 0;
	if (argc != 3 || (isdigit(argv[1]))) //Achtung is digit
	{
		printf("Wrong input");
		return (1);
	}
	sa.sa_handler = &receive_char;
	sa.sa_flags = SA_RESTART;
	sigaction(SIGUSR1, &sa, NULL);
	while (argv[2][i] != '\0')
	{
		shift = 7;
		while(shift >= 0)
		{
			//printf("shift: %i, und: %i\n", 1 << shift, argv[2][i]& (1 << shift));
			if ((argv[2][i] & (1 << shift)) > 0)
			{
				printf("1");
				kill(atoi(argv[1]), SIGUSR1); // Achtung atoi
			}
			else 
			{
				printf("0");
				kill(atoi(argv[1]), SIGUSR2); // Achtung atoi
			}
			
			//write(1, "vor pause", 10);
			pause();
			usleep(40);
			shift--;
		}
		i++;
		//usleep(500);
	}
	return (0);
}



//11001000111101010000011001010100101 		0111101
//1100100011110101000001100101 001001010 0111101
