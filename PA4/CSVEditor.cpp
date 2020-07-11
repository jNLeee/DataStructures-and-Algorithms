#include "CSVEditor.hpp"

CSVEditor::CSVEditor(string &inputPath, string &rosterPath, string &outputPath, regex expr, int m)
{
	input.open(inputPath);
	roster.open(rosterPath);
	output.open(outputPath);
	regexPattern = expr;
	hashTable = new HashTable<string>(m); //table must be created in here since we pass m in
}

CSVEditor::~CSVEditor()
{
	delete hashTable;
}

void CSVEditor::readCSVToTable()
{
	int key;
	smatch matches;
	while (!input.eof())
	{
		string line;
		getline(input, line);
		if (regex_search(line, matches, regexPattern) == true)
		{
			stringstream converted(matches.str(1));
			converted >> key;
			hashTable->insert(key, matches.str(2));
		}
	}
}

void CSVEditor::writeCSVToFile()
{
	int key;
	smatch matches;
	while (!roster.eof())
	{
		string line;
		getline(roster, line);
		if (regex_search(line, matches, regexPattern) == true)
		{
			stringstream converted(matches.str(1));
			converted >> key;
			if (hashTable->search(key) != nullptr)
			{
				line.erase(line.length() - 1);
				output << line << *hashTable->search(key) << "\n";
			}
			else
			{
				output << line;
			}
		}
	}
}

std::tuple<int, int, double> CSVEditor::getStats() 
{
	int min = hashTable->minChainLen();
	int max = hashTable->maxChainLen();
	double avg = hashTable->averageChainLen();
	return std::make_tuple(min, max, avg);
}