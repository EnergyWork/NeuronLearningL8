#include "Neuron.h"

int main() {
	Neuron *neuron = new Neuron("GopnicData.txt");
	neuron->printTaskResult();
	double t;
	uint32_t c = neuron->getCountInputs();
	vector<double> s;
	cout << "Count of inputs: " << c << endl;
	while (true) {
		c = neuron->getCountInputs();
		while (c != 0) {
			cin >> t;
			s.push_back(t);
			c--;
		}
		cout << "out = " << neuron->check(s) << endl;
		s.clear();
	}
	return EXIT_SUCCESS;
}