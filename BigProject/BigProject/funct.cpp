#include "funct.h"

vector<string> split(string s, string del) {
	vector<string> words;
	stringstream stringStream(s);
	string line;
	while (getline(stringStream, line))
	{
		int prev = 0, pos;
		while (line != "") {
			string word;
			pos = line.find_first_of(del, prev);
			if (pos > prev) {
				word = line.substr(prev, pos - prev);
				for (int i = 0; i < word.length(); i++)
					word[i] = tolower(word[i]);
				words.push_back(word);
			}
			else if (prev < line.length() && pos < 0) {
				word = line.substr(prev, line.length());
				for (int i = 0; i < word.length(); i++)
					word[i] = tolower(word[i]);
				words.push_back(word);
			}
			line.erase(0, pos);
			prev = line.find_first_of(ALPHA);
		}
	}
	return words;
}