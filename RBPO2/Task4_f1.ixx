module;
#include <math.h>
export module student3:f1;
//export module student3:f1;

namespace RBPO
{
	namespace Lab2
	{
		namespace Variant5
		{
			namespace Task4
			{
				export double f1(double x, double y)
				{
					double res;
					res = ((x - 1) * sqrt(x) - (y - 1)) * sqrt(y) / (sqrt(pow(x, 3) * y) + x * y + pow(x, 2) - x);
					return res;
				}
			}
		}
	}
}