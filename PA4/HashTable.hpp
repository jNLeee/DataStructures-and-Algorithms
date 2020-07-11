#pragma once
#include <list>
#include <string>
#include <vector>
#include <utility>
#include <iterator>

using namespace std;

template <typename T>
class HashTable
{
private:
	int size;
	//IMPLEMENT
	int total_elements;
	int hash(const int _key)
	{
		return _key % size;
	}

	vector<list<pair<int, T>>> table;

public:
	HashTable(const int _size)
	{
		size = _size;
		total_elements = 0;
		table = vector<list<pair<int, T>>>(_size);
	}

	~HashTable() {} //not needed

	void insert(const int _key, T _value)
	{
		table[hash(_key)].push_back(make_pair(_key, _value));
		total_elements++;
	}

	int minChainLen()
	{
		int min = 0;
		if (!table.empty())
		{
			min = table[0].size();
			for (int i = 0; i < size; i++)
			{
				if (min > table[i].size())
				{
					min = table[i].size();
				}
			}
		}
		return min;
	}

	int maxChainLen()
	{
		int max = 0;
		if (!table.empty())
		{
			max = table[0].size();
			for (int i = 0; i < size; i++)
			{
				if (max < table[i].size())
				{
					max = table[i].size();
				}
			}
		}
		return max;
	}

	double averageChainLen()
	{
		return total_elements / (double)size;
	}

	T *search(int _key)
	{
		int index = this->hash(_key);
		typename list<pair<int, T>>::iterator i;
		for (i = table[index].begin(); i != table[index].end(); i++)
		{
			if (i->first == _key)
			{
				return &i->second;
			}
		}
		return nullptr;
	}
};
