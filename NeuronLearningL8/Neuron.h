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
		double signalsOut;
	};
	vector<studyExample> studyExamples;
	void readData(string file);
	void learning();
public:
	Neuron(string file)
	{
		readData(file);
		learning();
	}
	bool test(vector<double> signals);
};