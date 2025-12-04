#include "libft.h"

int ft_count_split(char **spl){
    int i = 0;
    if (!spl)
        return 0;

    for (i =0; spl[i]; ++i)
        ;
    return i;
}
