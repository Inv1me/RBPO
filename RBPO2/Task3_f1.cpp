#include <math.h>
module student2;
double RBPO::Lab2::Variant20::Task3::f1(double x, double y)
{
	double res;
	res = ((x - 1) * sqrt(x) - (y - 1)) * sqrt(y) / (sqrt(pow(x, 3) * y) + x * y + pow(x, 2) - x);
	return res;
}