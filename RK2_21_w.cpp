#include <stdio.h>
#include <conio.h>
#include <random>
#include <time.h>

class SotOperator			//Base class
{
protected:
	int code;
	int NumberOfSubscribers;
public:
	virtual int calculation()
	{
		return NumberOfSubscribers;
	}
	SotOperator()						//Init
	{
		code=rand()%999;
		NumberOfSubscribers=rand()%10000;
	}
};

class MTS:public SotOperator			//derived class
{
	int tarif;
public:
	MTS()								//Init
	{
		code=rand()%999;
		NumberOfSubscribers=rand()%10000;
		tarif=rand()%10;
	}
	int calculation()
	{
		return tarif*NumberOfSubscribers;
	}
};


void main()
{
	srand(time(NULL));
	SotOperator a;		//Create object a
	MTS b;				//Create object b

	SotOperator *c;
	c=&a;
	printf("NumberOfSubscribers(base class)=%d\n",c->calculation());
	c=&b;
	printf("Income(derived class)=%d\n",c->calculation());
	getch();
}