/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsmereka <gsmereka@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/13 17:18:43 by gsmereka          #+#    #+#             */
/*   Updated: 2022/07/14 23:54:45 by gsmereka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>
#include <stdio.h>
// gcc ft_printf.c main.c  -g libft/libft.a && valgrind -s --leak-check=full ./a.out
// gcc -Wall -Wextra -Werror -g ft_printf.c main.c libft/libft.a && valgrind -s --leak-check=full ./a.out
int		ft_printf(char *s, ...);

int mainh(void)
{
    char    *str = "rafaela";
    char    *oi = NULL;
    char    **ptr;

    ptr = &str;

    ft_printf("MIXED:%c|%s|%p|%d|%i|%u|%X|%x\n", str[6], oi, str, -912387, 00000, -99, 743, 743);
    ft_printf("\n---------original-----------\n");
    printf("MIXED:%c|%s|%p|%d|%i|%u|%X|%x\n", str[6], oi, str, -912387, 00000, -99, 743, 743);
	return (0);
}

int main(void)
{

	ft_printf("1, 2, 3, -d test, testing, 0.4s sound, 1, 2, 3xp, sound, -*dtest");
}

int main2(void) 
{
	int *ptr;
	int valor = 10;

	ptr = &valor;

	printf("Endereço = %p\n", &valor);
	printf("Endereço = %p\n", ptr);
	printf("Valor = %d\n", *ptr);
	ft_printf("Endereço = %p\n", &valor);
	ft_printf("Endereço = %p\n", ptr);
	ft_printf("Valor = %d\n", *ptr);
	return (0);
}

int main3(void) 
{
	char *valor = NULL;

	printf("Endereço = %p\n", &valor);
	ft_printf("Endereço = %p\n", &valor);
	return (0);
}


int main35(void)
{
	// int	i;
	// unsigned int j;

	// j = -15;
	// i = printf("%p\n", -2147483648);
	// printf("size final = %d\n", i);
	// i = ft_printf("%p\n", -2147483648);
	// printf("size final = %d\n", i);
	return (0);
}


int main10(void)
{
    char    *str = "rafaela";
    char    *oi = NULL;
    char    **ptr;

    ptr = &str;

    ft_printf("\n---------my func-----------\n");
    
    ft_printf("c flag: %c|%c|%c|%c|%c\n", 'r', str[2], 97 - 32, *str, 48);
    ft_printf("s flag: %s|%s|%s|%s|%s|%s\n", "rafaela", str, str + 2, "", "-", oi);
    ft_printf("p flag: %p|%p|%p|%p|%p|%p\n", str, &str, ptr, &ptr, oi, &oi);
    ft_printf("d flag: %d|%d|%d|%d|%d\n", 7, -7, 0, 2147483647, -2147483648);
    ft_printf("i flag: %i|%i|%i|%i|%i\n", 7, -7, 0, 2147483647, -2147483648);
    ft_printf("u flag: %u|%u|%u|%u|%u\n", 7, -7, 0, 2147483647, -2147483648);
    ft_printf("x flag: %x|%x|%x|%x|%x\n", 7, -7, 0, 2147483647, -2147483648);
    ft_printf("X flag: %X|%X|%X|%X|%X\n", 7, -7, 0, 2147483647, -2147483648);
    ft_printf("%% flag: %% | %%|%% \n");
    ft_printf(", I've printed %d characters!\n", ft_printf("d flag: %d|%d|%d|%d", 0, -37, 37, 187398217));
    ft_printf(", I've printed %d characters!\n", ft_printf("d flag: %d|%d|%d|%d", 0, -22222, 'n', 0));
    ft_printf(", I've printed %d characters!\n", ft_printf("INT MIN: %d", -2147483647 - 1));
    ft_printf("MIXED:%c|%s|%p|%d|%i|%u|%x|%X|%%\n", str[6], oi, str, -912387, 00000, -99, 743, 743);
    ft_printf("\n---------original-----------\n");

    // original
    printf("c flag: %c|%c|%c|%c|%c\n", 'r', str[2], 97 - 32, *str, 48);
    printf("s flag: %s|%s|%s|%s|%s|%s\n", "rafaela", str, str + 2, "", "-", oi);
    printf("p flag: %p|%p|%p|%p|%p|%p\n", str, &str, ptr, &ptr, oi, &oi);
    printf("d flag: %d|%d|%d|%d|%d\n", 7, -7, 0, 2147483647, -2147483647 - 1);
    printf("i flag: %i|%i|%i|%i|%i\n", 7, -7, 0, 2147483647, -2147483647 - 1);
    printf("u flag: %u|%u|%u|%u|%u\n", 7, -7, 0, 2147483647, -2147483647 - 1);
    printf("x flag: %x|%x|%x|%x|%x\n", 7, -7, 0, 2147483647, -2147483647 - 1);
    printf("X flag: %X|%X|%X|%X|%X\n", 7, -7, 0, 2147483647, -2147483647 - 1);
    printf("%% flag: %% | %%|%% \n");
    printf(", I've printed %d characters!\n", printf("d flag: %d|%d|%d|%d", 0, -37, 37, 187398217));
    printf(", I've printed %d characters!\n", printf("d flag: %d|%d|%d|%d", 0, -22222, 'n', 0));
    printf(", I've printed %d characters!\n", printf("INT MIN: %d", -2147483647 - 1));
    printf("MIXED:%c|%s|%p|%d|%i|%u|%x|%X|%%\n", str[6], oi, str, -912387, 00000, -99, 743, 743);

    // // ft_printf("\n---------Error Test-----------\n");
    // printf("original func: %c\n", "test");
    // ft_printf("my func: %c\n", "test");
    // printf("original func: %c\n", str);
    // ft_printf("my func: %c\n", str);
    // // printf("original func: %s\n", 'c');
	return (0);
}

// gcc *.c libft/libft.a && ./a.out
