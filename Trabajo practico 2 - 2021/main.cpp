#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <string>

using namespace std;

int main() {

	string h = "05:10";

	int hora;
	int min;

	sscanf(h.c_str(), "%d:%d", &hora, &min);


}