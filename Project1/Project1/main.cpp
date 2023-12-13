#include <iostream>
#include <thread>
#include <chrono>

int count = 1;
using namespace std::chrono_literals;

void Client() {
	while (count != 100) {
		std::this_thread::sleep_for(1000ms);
		++count;
		std::cout << "Client Flow: " << count << std::endl;
	}
}


void Operator() {
	while (count != 0) {
		std::this_thread::sleep_for(2000ms);
		--count;
		std::cout << "Operator flow: " << count << std::endl;
	}
}


int main() {
	setlocale(LC_ALL, "Ru");

	std::thread t1(Client);
	std::thread t2(Operator);


	t1.join();
	t2.join();

	return 0;
}
