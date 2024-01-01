#include <iostream>
#include <thread>
#include <vector>
#include <chrono>


int SumVectors(std::vector<int> vector1, std::vector<int> vector2, int sum) {
	for (int i = 0; i < vector1.size(); i++) {
		sum += vector1.at(i) + vector2.at(i);
	}
	return sum;
}
int main() {
	setlocale(LC_ALL, "Ru");
	std::cout << "Количество аппаратных ядер - " << std::thread::hardware_concurrency() << std::endl;
	std::vector<int> vector1;
	std::vector<int> vector2;
	std::vector<int> streams{ 1, 2, 4, 8, 16 };
	std::vector<int> size{ 1000, 10000, 100000, 1000000 };
	int sum = 0;
	
	std::cout << std::endl;

	for (const auto& count : streams) {
		std::cout << count << " потоков\t";
		for (const auto& vectorSize : size) {
			vector1.resize(vectorSize, 1);
			vector2.resize(vectorSize, 2);


			std::vector<std::thread> Threads;
			int vectorsSize = vectorSize / count;


			auto begin = std::chrono::steady_clock::now();

			for (int i = 0; i < count; i++) {
				std::vector<int> newVector1;
				std::vector<int> newVector2;

				int border = 0;

				if (border = (i != count - 1)) {
					vectorsSize* (i + 1);
				}
				else {
					vectorSize;
				}


				for (int j = vectorsSize * i; j < border; j++) {
					newVector1.push_back(vector1.at(j));
					newVector2.push_back(vector2.at(j));
				}
				Threads.push_back(std::thread(SumVectors, newVector1, newVector2, sum));
			}
			for (auto& value : Threads) {
				value.join();
			}
		}
		std::cout << std::endl;
	}
	return 0;
}