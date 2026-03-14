

# include "../libft.h"

enum ap_arg_type{
    option,
    argument
}

typedef struct s_argument{
    int type;
    char *value;
    struct s_argument* next;
} t_argument;

