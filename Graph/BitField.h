#pragma once
#include<vector>
#include<string>
using std::string;
using std::vector;
class BitField32
{
	vector<int> fields;
	int maxNumOfBits;
public:

	BitField32()
	{
		fields.push_back(0);
		maxNumOfBits = 31;
	}
	BitField32(int count)
	{
		
	}
	void resize(int count)
	{
		int num_integers_needed = count >> 5;
		if (fields.size() >= num_integers_needed) return;
		int num_to_add = abs((int)(num_integers_needed - fields.size()));
		while (num_to_add > 0)
		{
			fields.push_back(0);
			num_to_add--;
		}
	}
	~BitField32()
	{
		
	}
	void set(int bit)
	{
		if (bit > maxNumOfBits)
			resize(bit);
		int location = bit / 32;
		int offset = bit % 32;
		fields[location] |= (1 << offset);
	}
	void reset(int bit)
	{
		int location = bit / 32;
		int offset = bit % 32;
		fields[location] &= ~(1 << offset);
	}
	void flip(int bit)
	{
		int location = bit / 32;
		int offset = bit % 32;
		fields[location] ^= (1 << offset);
	}
	bool test(int bit)
	{
		int location = bit / 32;
		int offset = bit % 32;
		return ((1 << offset) & fields[location]) != 0;
	}
	bool operator[](int bit)
	{
		return test(bit);
	}
	BitField32& operator=(string bit_pattern)
	{
		int offset = 0;
		int location = 0;
		return *this;
	}
};

