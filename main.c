#include "ft_printf.h"

int    main (){

    char a = 'a';
    char *b = "abc";
    int i = -5;
    unsigned int u = 10;

    ft_printf("FT_PRINTF: %c, %s, %p, %d, %i, %u, %x, %X, %% \n", a, b, b, i, i, u, 4321, 4321);
    printf("PRINTF: %c, %s, %p, %d, %i, %u, %x, %X, %%", a, b, b, i, i, u, 4321, 4321);
}

