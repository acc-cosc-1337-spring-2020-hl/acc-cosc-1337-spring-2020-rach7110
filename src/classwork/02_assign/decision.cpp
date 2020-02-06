//Write the function code that returns the product of hours and hourly_rate.
#include "decision.h";

double gross_pay(double hours, double hourly_rate)
{
	double rate_multiplier;
	double gross_pay;

	switch (hours <= 40)
	{
	case true: 
		gross_pay = hours *hourly_rate;
		break;
	case false:
		gross_pay = 40 * hourly_rate + 1.5*(hours - 40)*hourly_rate;
		break;
	}

	return gross_pay;
}

