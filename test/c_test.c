#include "../ft_printf.h"
#include <stdio.h>



//Build a main function that will compare the output of ft_printf with printf using the c standard library functions. The comparison will be done using the %c specifier. 

int main()
{
	int res1;
	int res2;

	res1 = printf("%10c\n", 'a');
	/* res2 = ft_printf("%-6c\n", 'a'); */
	printf("res1 = %d\n", res1);
	/* printf("res2 = %d\n", res2); */

	/* res1 = printf("%c\n", 'a'); */
	/* res2 = ft_printf("%c\n", 'a'); */
	/* printf("res1 = %d\n", res1); */
	/* printf("res2 = %d\n", res2); */
	

	return (0);


}
