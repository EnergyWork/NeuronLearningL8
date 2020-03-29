#include "Neuron.h"

void Neuron::readData(string file) {
	ifstream fin(file);
	double tmp;
	int16_t tmp2;
	fin >> this->countInputs;
	for (size_t i = 0; i < countInputs; i++) {
		fin >> tmp;
		this->weight.push_back(tmp);
	}
	fin >> this->p >> this->alpha >> this->countStudyExampls;
	studyExamples.resize(countStudyExampls);
	for (size_t i = 0; i < this->countStudyExampls; i++) {
		for (size_t j = 0; j < this->countInputs; j++) {
			fin >> tmp;
			studyExamples[i].signalsIn.push_back(tmp);
		}
		fin >> tmp2;
		studyExamples[i].signalsOut = tmp2;
	}
}
bool Neuron::check(vector<double> exampleSignalsIn) {
	double sum = 0;
	for (size_t i = 0; i < this->countInputs; i++) {
		sum += weight[i] * exampleSignalsIn[i];
	}
	return (sum >= p ? true : false);
}
void Neuron::penalty(studyExample example, int outSignal) {
	for (size_t i = 0; i < this->countInputs; i++) {
		weight[i] += alpha * example.signalsIn[i] * (double(example.signalsOut) - double(outSignal));
	}
	p -= alpha * (double(example.signalsOut) - double(outSignal));
}
void Neuron::learning() {
	uint32_t tmpCount = 0;
	int outSignal;
	while (tmpCount != this->countStudyExampls) {
		tmpCount = 0;
		for (auto example : studyExamples) {
			outSignal = check(example.signalsIn);
			if (outSignal == example.signalsOut)
				tmpCount++;
			else 
				penalty(example, outSignal);
		}
	}
}
void Neuron::printTaskResult() {
	for (size_t i = 0; i < countInputs; i++) {
		cout << "w" + to_string(i + 1) + " = " << weight[i] << endl;
	}
	cout << "p = " << p << endl;
}