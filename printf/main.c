#include "printf_submit/includes/ft_printf.h"
#include <stdio.h>

int main()
{
	int y = 99;
	printf("%d\n" , ft_printf("|%*.3d|\n", 5, 0));
	printf("%d\n", printf("|%*.3d|\n", 5, 0));
	//printf("@main_ftprintf: %###-#0000 33...12..#0+0d", 256);
	return 0;
}
