#include <vector>
#include <string>
#include <unordered_set>
using namespace std;

class Solution {
public:
    int numUniqueEmails(vector<string>& emails) {
        unordered_set<string> uniqueEmails;

        for (string email : emails) {
            int atPos = email.find('@');
            
            string local = email.substr(0, atPos);
            string domain = email.substr(atPos);

            string cleanLocal = "";
            
            for (char c : local) {
                if (c == '+') break;     // ignore after +
                if (c == '.') continue;  // skip dots
                cleanLocal += c;
            }

            uniqueEmails.insert(cleanLocal + domain);
        }

        return uniqueEmails.size();
    }
};