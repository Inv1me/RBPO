module;
#include <math.h>
export module student;

namespace RBPO
{
	namespace Lab2
	{
		namespace Variant5
		{
			namespace Task1
			{
				export double f1(double x, double y)
				{
					double res;
					res = ((x - 1) * sqrt(x) - (y - 1)) * sqrt(y) / (sqrt(pow(x, 3) * y) + x * y + pow(x, 2) - x);
					return res;
				}
				export double f2(double x)
				{
					double res;
					x <= 9 ? res = cos(2 * x) + 9 : res = -(cos(x) / (x - 9));
					return res;
				}
				export double a(int i)
				{
					return pow(-1, i % 2) * (i - 1.) / ((2 * pow(i, 2) + 1));
				}
				export double f3(int n)
				{
					double sum = 0;
					for (int i = 0; i <= n; i++)
					{
						sum += a(i);
					}
					return sum;
				}
				export double f4(double epsilon)
				{
					double pred = a(0);
					double now;
					double sum = pred;
					for (int i = 1; ; i++)
					{
						now = a(i);
						sum += now;
						if (fabs(now - pred) <= epsilon)
						{
							return sum;
						}
						pred = now;
					}
				}
			}
		}
	}
}