#include <variant>
#include <string>
#include <map>
#include <unordered_map>
#include <vector>
#include <random>

std::random_device rd;
std::mt19937 gen(rd());
std::uniform_int_distribution<int> distrib(0, 10000);

using prize = std::variant<std::string, int>;

class Wheel {
private:
	int stage{ 1 };
	std::unordered_map<int, std::unordered_map<std::string, std::vector<int, int>>> database;
	std::map<std::string, int> totalGain;
public:
	void stageUpdate();
	void spinJackpot();
	void spin();
};