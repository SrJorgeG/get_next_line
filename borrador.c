#include <stdio.h>
#include <stddef.h>

int main()
{
	printf("%d", ft_strlen("Hola Mundo"));
}
// COMPILE WITH SANITIZER: gcc -fsanitize=address get_next_line.c get_next_line_utils.c main.c