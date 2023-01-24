#include <stdio.h>
#include <stdlib.h>

static double const eps1m05 = 1.0 - 0x1P-05;
static double const eps1p05 = 1.0 + 0x1P-05;
static double const eps1m24 = 1.0 - 0x1P-24;
static double const eps1p24 = 1.0 + 0x1P-24;

int main(int argc, char *argv[argc + 1])
{
	printf("eps1m05: %f\n", eps1m05);
	printf("eps1p05: %f\n", eps1m05);

	for (int i = 1; i < argc; ++i) {
		double const a = strtod(argv[i], 0);
		double x = 1.0;

		printf("target number: %g\n", a);
		for (;;) {
			double prod = a * x;
			if (prod < eps1m05) {
				x *= 2.0;
			} else if (eps1p05 < prod) {
				x *= 0.5;
			} else {
				break;
			}

			printf("x = %.12f\n", x);
		}

		for (;;) {
			double prod = a * x;
			if ((prod < eps1m24) || (eps1p24 < prod))
				x *= (2.0 - prod);
			else
				break;

			printf("x = %.12f\n", x);
		}

		printf("heron: a=%.5e,\tx=%.5e,\ta*x=%.12f\n\n",
			a, x, a*x);
	}

	return EXIT_SUCCESS;
}
