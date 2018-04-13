#pragma once
#include <set>

bool GetNumber(const std::string &arg, int &upperBound);

std::set<int> GeneratePrimeNumbersSet(int upperBound);

void UseSieveErythosthene(std::vector<bool> &sieve);

std::set<int> GetPrimeNumbers(const std::vector<bool> &numbers);

void PrintPrimeNumbers(std::ostream &output, const std::set<int> &primeNumbers);
