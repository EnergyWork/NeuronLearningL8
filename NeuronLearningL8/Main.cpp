#include "Neuron.h"

int main() {
	Neuron *neuron = new Neuron("NeuronData2.txt");
	neuron->printTaskResult();
	return EXIT_SUCCESS;
}