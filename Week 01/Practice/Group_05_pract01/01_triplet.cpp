#include <iostream>

struct Triplet
{
	int first;
	int second;
	int third;
};

// read triplet
void readTriplet(Triplet& triplet)
{
	std::cin >> triplet.first >> triplet.second >> triplet.third;
}

// compare components
// < 0 if lhs < rhs
// == 0 if lhs == rhs
// > 0 if lhs > rhs
int compare(const Triplet& lhs, const Triplet& rhs)
{
	if (lhs.first == rhs.first)
	{
		if (lhs.second == rhs.second)
		{
			return lhs.third - rhs.third;
		}

		return lhs.second - rhs.second;
	}

	return lhs.first - rhs.first;
}

// find index of min triplet
int findMinTripletIndex(const Triplet* triplets, int size)
{
	int minIdx = 0;

	for (int i = 1; i < size ; i++)
	{
		if (compare(triplets[i], triplets[minIdx]) < 0)
		{
			minIdx = i;
		}
	}

	return minIdx;
}

int main()
{
	const int MAX_SIZE = 10;
	Triplet triplets[MAX_SIZE] = {};
	
	int n = 0;
	std::cin >> n;
	
	for (int i = 0; i < n; i++)
	{
		readTriplet(triplets[i]);
	}

	std::cout<<findMinTripletIndex(triplets, n);

	return 0;
}