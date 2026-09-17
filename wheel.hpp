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

struct data {
	int quantity{};
	int probability{};
};


class Wheel {
private:
	int _stage{ 1 };
	std::unordered_map<std::string, data> _roll;
	std::unordered_map<int, std::unordered_map<std::string, data>> _jackpot;
	std::map<std::string, int> _totalGain;
public:
	void load();
	void stageUpdate();
	void spinJackpot();
	void spin();
};