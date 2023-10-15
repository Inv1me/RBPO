#include <math.h>
module student2;

double RBPO::Lab2::Variant5::Task3::a(int i)
{
	return pow(-1, i % 2) * (i - 1.) / ((2 * pow(i, 2) + 1));
}