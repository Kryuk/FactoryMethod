// FactoryMethod.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include <iostream>
#include <string>
#include <vector>

using namespace std;

enum Transport_ID { Moto_ID = 0, Scooter_ID, Car_ID, Bus_ID };


class Transport
{
public:
	virtual void info() = 0;
	virtual ~Transport() {}

	static Transport* createTransport(Transport_ID id);
};

class Moto : public Transport
{
public:
	void info() {
		cout << "Moto" << endl;
	}
};

class Scooter : public Transport
{
public:
	void info() {
		cout << "Scooter" << endl;
	}
};

class Car : public Transport
{
public:
	void info() {
		cout << "Car" << endl;
	}
};

class Bus : public Transport
{
public:
	void info() {
		cout << "Bus" << endl;
	}
};

Transport* Transport::createTransport(Transport_ID  id)
{
	Transport * p = NULL;
	switch (id)
	{
	case Moto_ID:
		p = new Moto();
		break;
	case Scooter_ID:
		p = new Scooter();
		break;
	case Car_ID:
		p = new Car();
		break;
	case Bus_ID:
		p = new Bus();
		break;
	default:
		cout << "НЕИЗВЕСТНЫЙ ТИП ТРАНСПОРТА" << endl;
	}
	return p;
};


int main()
{

	vector<Transport*> v;
	v.push_back(Transport::createTransport(Moto_ID));
	v.push_back(Transport::createTransport(Scooter_ID));
	v.push_back(Transport::createTransport(Car_ID));
	v.push_back(Transport::createTransport(Bus_ID));

	system("pause");
    return 0;
}

