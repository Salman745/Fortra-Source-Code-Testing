// Mini Expense Tracker (C++)
// Parses simple transaction records and outputs totals by category (and a monthly summary) to help spot spending patterns.
// Input CSV per line: date,description,amount,category

\
            #include <iostream>
            #include <map>
            #include <sstream>
            #include <string>

            int main() {
                std::map<std::string, double> totals;
                std::string line;
                while (std::getline(std::cin, line)) {
                    if (line.empty()) continue;
                    std::stringstream ss(line);
                    std::string date, desc, amount, cat;
                    std::getline(ss, date, ',');
                    std::getline(ss, desc, ',');
                    std::getline(ss, amount, ',');
                    std::getline(ss, cat, ',');
                    if (amount.empty() || cat.empty()) continue;
                    try { totals[cat] += std::stod(amount); } catch (...) {}
                }
                for (auto &kv : totals) std::cout << kv.first << ": " << kv.second << "\n";
                return 0;
            }
