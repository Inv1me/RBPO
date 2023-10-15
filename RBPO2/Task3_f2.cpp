#include <math.h>
import student2;
double RBPO::Lab2::Variant20::Task3::f2(double x)
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