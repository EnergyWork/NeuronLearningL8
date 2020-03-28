#include "Neuron.h"

void Neuron::readData(string file) {
	ifstream fin(file);
	double tmp;
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
		fin >> tmp;
		studyExamples[i].signalsOut = tmp;
	}
}
void Neuron::learning() {
	function<bool(studyExample)> check = [](studyExample example) -> bool {

		return true;
	};
	function<bool()> penalty = []() -> bool {

	};
	uint32_t tmpCount = 0;
	while (tmpCount != this->countStudyExampls) {
		tmpCount = 0;
		for (auto example : studyExamples) {
			check(example) ? tmpCount++ : penalty();
		}
	}
}
bool Neuron::test(vector<double> signals) {

	return false;
}