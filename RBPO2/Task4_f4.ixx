module;
#include <math.h>
export module student3:f4;
import :a;
namespace RBPO
{
	namespace Lab2
	{
		namespace Variant5
		{
			namespace Task4
			{
				export double f4(double epsilon)
				{
					double pred = 0;
					double now = a(0);
					double sum = pred + now;
					int i = 1;
					while (fabs(now - pred) > epsilon)
					{
						pred = now;
						now = a(i);
						sum += now;
						i++;
					}
					return sum;
				}
			}
		}
	}
}