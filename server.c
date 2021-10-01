#include <signal.h>
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>


int	ft_do_calculation(int n, int new_n)
{
	if (n < 0)
	{
		write (1, "-", 1);
		n = -n;
	}
	if (n / 10 == 0)
	{
		n = n + 48;
		write(1, &n, 1);
		return (0);
	}
	new_n = n / 10;
	ft_do_calculation(new_n, 0);
	n = (n % 10) + 48;
	write(1, &n, 1);
	return (1);
}

void	ft_putnbr(int n)
{
	int	new_n;

	new_n = 0;
	if (n == -2147483648)
	{
		write(1, "-2147483648", strlen("-2147483648")); //Achtung strlen
		return ;
	}
	if (!(ft_do_calculation(n, new_n)))
		return ;
}


void receive_char(int signal)
{
	static char c = 0;
	static int shift = 7;
	//write(1, "receive char", 10);

	if (signal == SIGUSR1)
	{
		//write(1, &c, 1);
		c = (c ^ (1 << shift));
		//ft_putnbr(c);
	}
	if (shift == 0)
	{
		write(1, &c, 1);
		shift = 8;
		c = 0;
	}
	shift--;
	
	//else if (signal == SIGUSR2)
	//{
	//	write(1, "0", 1);
	//}
}

int main(void)
{
	write(1, "PID: ", 5);
	ft_putnbr(getpid());
	write(1, "\n", 1);
	struct sigaction sa;
	//sa.sa_flags = SA_RESTART;
	sa.sa_handler = &receive_char;
	
	while(1)
	{
		sigaction(SIGUSR1, &sa, NULL);
		sigaction(SIGUSR2, &sa, NULL);
		pause();
	}
	return (0);
}