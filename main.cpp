// Задание 3. Проверка корректности email-адреса
// Интересно: Реализован isNumber для string
// Интересно: Реализован split для string
// Интересно: Использован all_of для итерации по строке
#include <iostream>
#include <string>
#include <vector>
#include <algorithm> // all_of, isdigit

using std::cout;
using std::cin;
using std::endl;
using std::string;
using std::vector;

bool isNumber(const string &text) {
    return std::all_of(text.begin(), text.end(), [](char const &c) {
        return std::isdigit(c);
    });
}

// v0.1 returns a vector with strings separated by delim
vector<string> getSubstrings(const string &text, const char &delim, bool includeEmptyCells = false) {
    vector<string> substrings;
    string temp;

    for (char c: text) {
        if ((c == delim && temp.length() && !includeEmptyCells) || (c == delim && includeEmptyCells)) {
            substrings.push_back(temp);
            temp = "";
        }

        if (c != delim) temp += c;
    }

    if (temp.length()) substrings.push_back(temp);

    return substrings;
}

int main() {
    vector<string> ipList = {
            "13.8.0.9",
            "100.xyz.1.15",
            "115.300.10.60",
            "127.0.0.1",
            "255.255.255.255",
            "1.2.3.4",
            "55.77.213.101",
            "255.256.257.258",
            "0.55.33.22.",
            "10.00.000.0",
            "23.055.255.033",
            "65.123..9",
            "a.b.c.d",
            ".13.8.0.9",
    };

    for (auto &ip : ipList) {
        cout << "-----------" << endl;
        cout << "test: " << ip << endl;
        vector<string> tokens = getSubstrings(ip, '.', true);

        if (tokens.size() != 4) {
            cout << "Error! Number of tokens must be 4" << endl;
            continue;
        }

        bool isTroublesFound = false;

        for (string &token : tokens) {
            bool result = !token.empty() && isNumber(token) && std::stoi(token) >= 0 && std::stoi(token) <= 255;

            if (!result) {
                cout << "Error! Token is empty, or is not number, or out of range (0...255)" << endl;
                isTroublesFound = true;
                break;
            }

            if (token.length() > 1 && token[0] == '0') {
                cout << "Error! Token contains a leading zero" << endl;
                isTroublesFound = true;
                break;
            }
        }

        if (isTroublesFound) continue;

        cout << "IP is good!" << endl;
    }
}
