#include<Windows.h>
#include<iostream>
#include<conio.h>
using namespace std;

#define Enter		13
#define	Escape		27

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
	), fuel_level(0)	//Инициализация в заголовке.
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
	bool is_started;
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
		is_started = false;
		cout << "Engine is ready:\t" << this << endl;
	}
	~Engine()
	{
		cout << "Engine is over:\t" << this << endl;
	}

	void start()
	{
		is_started = true;
	}
	void stop()
	{
		is_started = false;
	}
	bool started()const
	{
		return is_started;
	}

	void info()const
	{
		cout << "Consumption:\t" << get_CONSUMPTION() << " liters\n";
		cout << "Consumption:\t" << get_consumption_per_second() << " liters/s\n";
	}
};

class Car
{
	Engine engine;
	Tank tank;
	bool driver_inside;
public:
	Car(double consumption, int capacity) :engine(consumption), tank(capacity)
	{
		driver_inside = false;
		cout << "Your car is ready to go, press Enter to get in ;-)" << endl;
	}
	~Car()
	{
		cout << "Your car is over" << endl;
	}

	void get_in()
	{
		driver_inside = true;
		panel();
	}
	void get_out()
	{
		driver_inside = false;
	}

	void panel()const
	{
		while (driver_inside)
		{
			system("CLS");
			cout << "Fuel level: " << tank.get_fuel_level() << " liters" << endl;
			cout << "Engine is " << (engine.started() ? "started" : "stopped") << endl;
			Sleep(100);	//100 - это задержка в миллисекундах.
		}
	}

	void control_car()
	{
		char key = 0;
		do
		{
			//Функция _kbhit() в фоновом режиме отслеживает нажатие клавиши . 
			//Если клавиша была нажата _kbhit() возвращает 'true', в противном слечае - 'false'.
			if (_kbhit())
			{
				key = _getch();	//Функция _getch() ожидает нажатие клавиши, и возвращает ASCII-код нажатой клавиши.
				//Т.е., _kbhit() ослеживает сам факт нажатия на клавишу (не важно на какую), а _getch() определяет,
				//какая клавиша была нажата.
			}
			//cout << (int)key << endl;

			switch (key)
			{
			case Enter:
				driver_inside ? get_out() : get_in();
				break;
			case 'F':	//Fill - заправить
			case 'f':
				if (engine.started() || driver_inside)
				{
					cout << "Для начала заглушите мотор и выйдите из машины" << endl;
				}
				else
				{
					double fuel_level;
					cout << "Введите объем топлива: "; cin >> fuel_level;
					tank.fill(fuel_level);
				}
				break;
			}
		} while (key != Escape);

		//thread - это последовательность команд Центральному процессору
	}

	void info()const
	{
		engine.info();
		tank.info();
	}
};

//#define TANK_CHECK	//Определяем TANK_CHECK
//#define ENGINE_CHECK

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

#ifdef ENGINE_CHECK
Engine engine(10);
engine.info();
#endif

	Car bmw(10, 80);
	bmw.control_car();
	bmw.info();

}