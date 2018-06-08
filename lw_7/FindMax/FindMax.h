#pragma once
#include <vector>
#include <functional>

template <typename T, typename Less = std::less<T>>
bool FindMaxEx(std::vector<T> const &arr, T &maxValue, Less const &less = Less())
{
	if (arr.empty())
	{
		return false;
	}

	size_t n = arr.size();
	const T *max = &arr[0];
	for (size_t i = 0; i < n; ++i)
	{
		if (less(*max, arr[i]))
		{
			max = &arr[i];
		}
	}

	maxValue = *max;
	return true;
}

