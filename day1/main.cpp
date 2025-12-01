#include "InputParser.hpp"
#include "Dial.hpp"

int main()
{
	InputParser parser("../data/day1/test.txt");
	Dial dial;
	auto data = parser.GetData();
	int num = 0;
	int count = 0;
	for (int i = 0; i < data.size(); i++) {
		num = dial.GetNext(data[i]);
		if (num == 0)
			count++;
	}
	std::cout << "The first answer is: " << count << std::endl;
	std::cout << "The second answer is: " << count + dial.GetPassThru() << std::endl;
	return 0;
}