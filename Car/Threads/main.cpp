#include<iostream>
#include<thread>
using namespace std::literals::chrono_literals;
//using namespace std;
using std::cin;
using std::cout;
using std::endl;

bool finish = false;

void Plus()
{
	while (!finish)
	{
		cout << "+ ";
		std::this_thread::sleep_for(100ms);
	}
}
void Minus()
{
	while (!finish)
	{
		cout << "- ";
		std::this_thread::sleep_for(100ms);
	}
}

void main()
{
	setlocale(LC_ALL, "");
	//Plus();
	//Minus();

	//std::thread thread_name(FunctionName);
	//thread_name.join();

	std::thread plus_thread(Plus);
	std::thread minus_thread(Minus);

	cin.get();	//ќжидает нажатие 'Enter';
	finish = true;

	if(plus_thread.joinable())plus_thread.join();
	if(minus_thread.joinable())minus_thread.join();
	if(minus_thread.joinable())minus_thread.join();
	if(minus_thread.joinable())minus_thread.join();
	if(minus_thread.joinable())minus_thread.join();
	if(minus_thread.joinable())minus_thread.join();
	if(minus_thread.joinable())minus_thread.join();
	if(minus_thread.joinable())minus_thread.join();
	if(minus_thread.joinable())minus_thread.join();
}

/*
	std::thread thread_name(&object, &MemberFunction);
	member-variable - переменна€-член класса
	member-function - функиц€-член класса
*/