#include <iostream>
using namespace std;

class ITransport abstract {
public:
	virtual void Drive() abstract;
};

class Auto : public ITransport {
public:
	void Drive() override {
		cout << "The car drives on the road.\n";
	}
};

class Driver {
public:
	void Travel(ITransport* transport) {
		transport->Drive();
	}
};

class IAnimal abstract {
public:
	virtual void Move() abstract;
};

class Camel : public IAnimal {
public:
	void Move() override {
		cout << "Camel rides on the sands of the desert.\n";
	}
};

class CamelAdapter : public ITransport {
	Camel camel;
public:
	CamelAdapter(Camel animal) {
		camel = animal;
	}
	void Drive() override {
		camel.Move();
	}
};


class Deer : public IAnimal {
public:
	void Move() override {
		cout << "Deer gracefully runs through the snow forest.\n";
	}
};

class DeerAdapter : public ITransport {
	Deer deer;
public:
	DeerAdapter(Deer animal) {
		deer = animal;
	}
	void Drive() override {
		deer.Move();
	}
};

class Elephant : public IAnimal {
public:
	void Move() override {
		cout << "Elephant slowly walks through the jungle.\n";
	}
};

class ElephanttAdapter : public ITransport {
	Elephant elephant;
public:
	ElephanttAdapter(Elephant animal) {
		elephant = animal;
	}
	void Drive() override {
		elephant.Move();
	}
};


class Horse : public IAnimal {
public:
	void Move() override {
		cout << "Horse gallops across the field.\n";
	}
};

class HorseToTransportAdapter : public ITransport {
	Horse horse;
public:
	HorseToTransportAdapter(Horse animal) {
		horse = animal;
	}
	void Drive() override {
		horse.Move();
	}
};


int main() {
	Driver driver;

	Auto car;
	ITransport* transport = &car;
	driver.Travel(transport);

	
	Camel camel;
	CamelAdapter camelAdapter(camel);
	transport = &camelAdapter;
	driver.Travel(transport);

	Elephant elephant;
	ElephanttAdapter elephantAdapter(elephant);
	transport = &elephantAdapter;
	driver.Travel(transport);

	
	Deer deer;
	DeerAdapter deerAdapter(deer);
	transport = &deerAdapter;
	driver.Travel(transport);

	
	Horse horse;
	HorseToTransportAdapter horseAdapter(horse);
	transport = &horseAdapter;
	driver.Travel(transport);

	return 0;
}