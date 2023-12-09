main(void)
{
	int nb;
	int nb2 = -5;
	int nb3 = 2564;
	nb = -2147483648;
	char c;
	c = 55;
	char *str1 = "Salut les amis";
	char *str2 = NULL;
	int nb_hex = 2147483647;
	int nb_unsigned = -2;
	int *ptr_nb2 = &nb2;
	int *ptr_nb3 = &nb3;
	ptr_nb3 = NULL;

	printf("Total : %d\n",
		ft_printf("Resultat de la fonction : [%c] [%d] [%s] [%s] [%x] [%X] [%u]\n",
			c, nb, str1, str2, nb_hex, nb_hex, nb_unsigned));
	printf("Total : %d\n",
		printf("Resultat de la fonction : [%c] [%d] [%s] [%s] [%x] [%X] [%u]\n",
			c, nb, str1, str2, nb_hex, nb_hex, nb_unsigned));

	printf("Total : %d\n",
		ft_printf("Resultat de la fonction : [%p] [%p] [%p]\n", ptr_nb2,
			ptr_nb3, NULL));
	printf("Total : %d\n", printf("Resultat de la fonction : [%p] [%p] [%p]\n",
			ptr_nb2, ptr_nb3, NULL));

	printf("Resultat attendu : %d || ", printf(NULL));
	printf("Resultat de ft_printf : %d\n", ft_printf(NULL));

		printf("%s\n", "%");
	ft_printf("%s\n", "%");
	printf("%d\n", ft_printf(0));
	ft_printf("%d\n", ft_printf(0));
}
