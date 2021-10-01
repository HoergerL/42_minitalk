#include <signal.h>

//Achtung printf
void send_char(int signal)
{

}
int main (int argc, char *argv[])
{
	int i;
	int shift;
	i = 0;
	if (argc != 3 || (isdigit(argv[1]))) //Achtung is digit
	{
		printf("Wrong input");
		return (1);
	}
	
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
			shift--;
			//usleep(40);
		}
		i++;
		//usleep(500);
	}
	return (0);
}