module;
#include <math.h>
export module student3:f2;

namespace RBPO
{
	namespace Lab2
	{
		namespace Variant5
		{
			namespace Task4
			{
				export double f2(double x)
				{
					double res;
					if (x <= 9)
					{
						res = cos(2 * x) + 9;
					}
					else
					{
						res = -(cos(x) / (x - 9));
					}
					return res;
				}
			}
		}
	}
}