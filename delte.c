#include "libft.h"

int main(void)
{
    int ret;

    // --- ft_printf tests ---
    ft_printf("=== ft_printf ===\n");

    ret = ft_printf("string: %s\n", "hello");
    ft_printf("  -> returned: %d\n", ret);

    ret = ft_printf("null string: %s\n", NULL);
    ft_printf("  -> returned: %d\n", ret);

    ret = ft_printf("char: %c\n", 'A');
    ft_printf("  -> returned: %d\n", ret);

    ret = ft_printf("int: %d\n", 42);
    ft_printf("  -> returned: %d\n", ret);

    ret = ft_printf("negative: %d\n", -1);
    ft_printf("  -> returned: %d\n", ret);

    ret = ft_printf("zero: %d\n", 0);
    ft_printf("  -> returned: %d\n", ret);

    ret = ft_printf("unsigned: %u\n", 4294967295U);
    ft_printf("  -> returned: %d\n", ret);

    ret = ft_printf("hex lower: %x\n", 255);
    ft_printf("  -> returned: %d\n", ret);

    ret = ft_printf("hex upper: %X\n", 255);
    ft_printf("  -> returned: %d\n", ret);

    ret = ft_printf("pointer: %p\n", (void *)&ret);
    ft_printf("  -> returned: %d\n", ret);

    ret = ft_printf("percent: %%\n");
    ft_printf("  -> returned: %d\n", ret);

    // --- ft_dprintf tests (fd=2 so output goes to stderr, visually separate) ---
    ft_printf("\n=== ft_dprintf (-> stderr) ===\n");

    ret = ft_dprintf(2, "string: %s\n", "hello");
    ft_printf("  -> returned: %d\n", ret);

    ret = ft_dprintf(2, "null string: %s\n", NULL);
    ft_printf("  -> returned: %d\n", ret);

    ret = ft_dprintf(2, "char: %c\n", 'A');
    ft_printf("  -> returned: %d\n", ret);

    ret = ft_dprintf(2, "int: %d\n", -42);
    ft_printf("  -> returned: %d\n", ret);

    ret = printf("hex: %x\n", 0xdeadbeef);
    ft_printf("  -> returned: %d\n", ret);

    ret = ft_dprintf(2, "pointer: %p\n", (void *)0);
    ft_printf("  -> returned: %d\n", ret);

    ret = ft_dprintf(2, "percent: %%\n");
    ft_printf("  -> returned: %d\n", ret);

    // --- bad fd ---
    ft_printf("\n=== ft_dprintf bad fd ===\n");
    ret = ft_dprintf(-1, "this should fail\n");
    ft_printf("  -> returned: %d (expect -1 or error)\n", ret);

    return 0;
}
