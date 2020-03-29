#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <functional>
using namespace std;

class Neuron {
	uint32_t countInputs, countStudyExampls;
	double p, alpha;
	vector<double> weight;
	struct studyExample	{
		vector<double> signalsIn;
		int signalsOut;
	};
	vector<studyExample> studyExamples;
	void readData(string file);

	void penalty(studyExample example, int outSignal);
	void learning();
public:
	Neuron(string file)
	{
		readData(file);
		learning();
	}
	inline uint32_t getCountInputs() { return countInputs; }
	bool check(vector<double> exampleSignalsIn);
	void printTaskResult();
};