#include<iostream>
using namespace std;

#define MIN_TANK_CAPACITY	 20
#define MAX_TANK_CAPACITY	120
//define (определить).
//Директива #define создает макроопределение, которое показывает компилятору ЧТО_ЗАМЕНИТЬ и ЧЕМ_ЗАМЕНИТЬ

class Tank
{
	const int CAPACITY;
	double fuel_level;
public:
	int get_CAPACITY()const
	{
		return CAPACITY;
	}
	double get_fuel_level()const
	{
		return fuel_level;
	}
	double fill(double amount)
	{
		if (amount < 0)return fuel_level;
		fuel_level += amount;
		if (fuel_level > CAPACITY)fuel_level = CAPACITY;
		return fuel_level;
	}
	double give_fuel(double amount)
	{
		fuel_level -= amount;
		if (fuel_level < 0)fuel_level = 0;
		return fuel_level;
	}

	//				Constructors:
	Tank(int capacity) :CAPACITY
	(
		capacity < MIN_TANK_CAPACITY ? MIN_TANK_CAPACITY :
		capacity > MAX_TANK_CAPACITY ? MAX_TANK_CAPACITY :
		capacity
	),fuel_level(0)	//Инициализация в заголовке.
		//Если в классе есть константа, то ее можно проинициализировать только в заголовке.
		//Инициализация в заголовке отрабатывает еще до того, как отрабатывает тело конструктора
	{
		//this->CAPACITY = capacity;
		//this->fuel_level = 0;
		cout << "Tank is ready:\t" << this << endl;
	}
	~Tank()
	{
		cout << "Tank is over:\t" << this << endl;
	}

	void info()const
	{
		cout << "Capacity:\t" << get_CAPACITY() << " liters\n";
		cout << "Fuel level:\t" << get_fuel_level() << " liters\n";
	}
};

#define MIN_ENGINE_CONSUMPTION	 4
#define MAX_ENGINE_CONSUMPTION	30

class Engine
{
	const double CONSUMPTION;
	double consumption_per_second;
	bool started;
public:
	double get_CONSUMPTION()const
	{
		return CONSUMPTION;
	}
	double get_consumption_per_second()const
	{
		return consumption_per_second;
	}
	void set_consumption_per_second()
	{
		this->consumption_per_second = CONSUMPTION * 3e-5;
	}

	//					Constructors:
	Engine(double consumption) :CONSUMPTION
	(
		consumption < MIN_ENGINE_CONSUMPTION ? MIN_ENGINE_CONSUMPTION :
		consumption > MAX_ENGINE_CONSUMPTION ? MAX_ENGINE_CONSUMPTION :
		consumption
	)
	{
		set_consumption_per_second();
		cout << "Engine is ready:\t" << this << endl;
	}
	~Engine()
	{
		cout << "Engine is over:\t" << this << endl;
	}

	void info()const
	{
		cout << "Consumption:\t" << get_CONSUMPTION() << " liters\n";
		cout << "Consumption:\t" << get_consumption_per_second() << " liters/s\n";
	}
};

//#define TANK_CHECK	//Определяем TANK_CHECK

void main()
{
	setlocale(LC_ALL, "");

#ifdef TANK_CHECK	//Если определено TASK_CHECK, то нижеследующий код будет виден компилятору, до директивы #endif
	Tank tank(60);
	tank.info();
	int fuel;
	do
	{
		cout << "Введите объем топлива: "; cin >> fuel;
		tank.fill(fuel);
		tank.info();
	} while (fuel > 0);
#endif // TANK_CHECK

	Engine engine(10);
	engine.info();

}