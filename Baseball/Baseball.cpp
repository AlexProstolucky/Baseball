#include <iostream>
#include <string>
#include <vector>
using namespace std;
int baseball(string str) 
{
	try
	{
		char a = 1;
		vector <int> vec;
		string text = str;
		string subtext;
		string separator = " ";
		int f_pos = 0;
		int s_pos = 0;

		text += separator;

		while (f_pos != text.size() && s_pos != text.size())
		{
			subtext = "";
			s_pos = text.find(separator, f_pos);
			subtext = text.substr(f_pos, s_pos - f_pos);

			if (subtext == "+" && vec.size() > 1)
			{
				vec.push_back(vec[vec.size() - 1] + vec[vec.size() - 2]);
			}

			else if (subtext == "d" && !vec.empty()) {
				vec.push_back((vec[vec.size() - 1]) * 2);
			}

			else if (subtext == "c" && !vec.empty())
			{
				vec.pop_back();
			}

			else if (stoi(subtext) > -333 && stoi(subtext) < 333)
			{
				vec.push_back(stoi(subtext));
			}

			else
			{
				cout << "\nWRONG INPUT\n";
				return 0;
			}

			f_pos = s_pos;
			f_pos++;
		}
		for (size_t i = 0; i < vec.size(); i++)
		{
			cout << vec[i] << " ";
		}
	}
	catch (const std::exception& ex)
	{
		cout << ex.what();
	}
}
int main()
{
	string text;
	cout << "Input your text -> ";
	getline(cin, text);
	baseball(text);
}