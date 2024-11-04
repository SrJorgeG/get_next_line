size_t  ft_strlen(const char *s)
{
        char    *z;

        z = (char *)s;
        while (*z)
                z++;
        return (z - s);
}

#include <stdio.h>
#include <stddef.h>

int main()
{
	printf("%d", ft_strlen("Hola Mundo"));
}
