#include <stdio.h>

typedef struct s_complex
{
	//x
	double real;
	//y
	double i;

}t_complex;

int main()
{
	t_complex z;
	t_complex c;
	z.real = 0;
	z.i = 0;
	c.real = -1;
	c.i = 0;
	double tmp_z;
	int i = 0;
	while (i < 5)
	{
		tmp_z = (z.real * z.real) - (z.i * z.i);
		z.i += 2 * z.real * z.i;
		z.real = tmp_z;
		z.real += c.real;
		z.i += z.i;
		printf("(%.2f.%.2f)\n", z.real , z.i);
		i++;
	}
}