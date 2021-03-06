// FactoryMethod.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include <iostream>
#include <vector>
#include <string>

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
	Moto(string name, int wheels, int maxSpeed) {
		this->name = name;
		this->wheels = wheels;
		this->maxSpeed = maxSpeed;
	}
void info() {
	cout << "Наименование транспорта: "<< name << endl << "Число колес: " << wheels << endl << "Максимальная скорость: "<<maxSpeed<< endl;
	}
private:
	string name;
	int wheels, maxSpeed;
};

class Scooter : public Transport
{
public:
	Scooter(string name, int wheels, int maxSpeed) {
		this->name = name;
		this->wheels = wheels;
		this->maxSpeed = maxSpeed;
	}
	void info() {
		cout << "Наименование транспорта: " << name << endl << "Число колес: " << wheels << endl << "Максимальная скорость: " << maxSpeed << endl;
	}
private:
	string name;
	int wheels, maxSpeed;
};

class Car : public Transport
{
public:
	Car(string name, int wheels, int maxSpeed) {
		this->name = name;
		this->wheels = wheels;
		this->maxSpeed = maxSpeed;
	}
	void info() {
		cout << "Наименование транспорта: " << name << endl << "Число колес: " << wheels << endl << "Максимальная скорость: " << maxSpeed << endl;
	}
private:
	string name;
	int wheels, maxSpeed;
};

class Bus : public Transport
{
public:
	Bus(string name, int wheels, int maxSpeed) {
		this->name = name;
		this->wheels = wheels;
		this->maxSpeed = maxSpeed;
	}
	void info() {
		cout << "Наименование транспорта: " << name << endl << "Число колес: " << wheels << endl << "Максимальная скорость: " << maxSpeed << endl;
	}
private:
	string name;
	int wheels, maxSpeed;
};

Transport* Transport::createTransport(Transport_ID  id)
{
	Transport * transport = NULL;
	switch (id)
	{
	case (0):
		transport = new Moto("Мотоцикл", 2, 250);
		break;
	case (1):
		transport = new Scooter("Самокат", 2, 20);
		break;
	case (2):
		transport = new Car("Автомобиль", 4, 450);
		break;
	case (3):
		transport = new Bus("Автобус", 6, 100);
		break;
	default:
		cout << "НЕИЗВЕСТНЫЙ ТИП ТРАНСПОРТА" << endl;
	}
	return transport;
};


int main(int argc, char *argv[])
{
	setlocale(LC_ALL, "Russian");
	

	vector<int>mas;
	while (cin.peek() != 10 && cin.peek() != 13)
	{
		int temp;
		cin >> temp;
		mas.push_back(temp);
	}
	
	vector<int>::iterator it ;
	for (it = mas.begin(); it != mas.end(); it++) {
		Transport_ID num = static_cast<Transport_ID>(*it);

		Transport* transport = Transport::createTransport(num);

		if (transport != NULL) {
			transport->info();
		}
	}
	system("pause");
    return 0;
}

