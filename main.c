#include <unistd.h>

int main(int argc ,char **argv)
{
	//convert ascii to bits
	int i = 0;
	int  bit = 7;
	while (argv[1][i])
	{
		while (bit >= 0)
		{
			if (argv[1][i] & (1 << bit))
				write(1, "1", 1);
			else
				write(1, "0", 1);
			bit--;
		}
		i++;
	}
}