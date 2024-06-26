#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

class PascalTri {
public:

    string toSciNot(unsigned long long num) {
        string sn = to_string(num);
        string ret;
        ret.push_back(sn[0]);
        ret.push_back('.');
        ret.push_back(sn[1]);
        ret.push_back(sn[2]);
        ret.push_back('e');
        ret += to_string(sn.length() - 1);
        return ret;
    }


    vector<vector<unsigned long long>> generate(unsigned long long numRows) {
        //Base cases
        if (numRows == 1) return { {1} };
        else if (numRows == 2) return { {1}, {1, 1} };

        //Else create it iteratively, not using factorial as it even
        //exceeds unsigned long long at row 20ish.
        vector<vector<unsigned long long>> tri = { {1}, {1, 1} };

        for (unsigned long long row = 2; row < numRows; row++) {
            vector<unsigned long long> curr = { 1 }; //insert starting 1
            for (unsigned long long k = 1; k <= row - 1; k++) {
                curr.push_back(tri[row - 1][k] + tri[row - 1][k - 1]);
            }
            curr.push_back(1); //insert ending 1
            tri.push_back(curr); //add to tree
        }
        return tri;
    }

};

int main()
{
    bool running = true;
    unsigned long long depth;
    cout << "Pascal Triangle Generator v2.0 - Andrew Ridgely\n";

    while (running) {
        cout << "Enter depth (-1 to quit): ";
        cin >> depth;
        cout << "\n";
        
        if (depth == -1) {
            running = false;
            continue;
        }

        PascalTri p;
        vector<vector<unsigned long long>> tri = p.generate(depth);
        int rowCount = 0;
        for (vector<unsigned long long>& v : tri) {
            string spacer(max((int)tri.size() - rowCount++, 0), ' ');
            cout << spacer;
            for (unsigned long long& i : v) {
                if (i > 100000) {
                    cout << p.toSciNot(i) << " ";
                }
                else cout << i << " ";
            }
            cout << "\n";
        }
        cout << "\n";
    }

    system("pause");
    return 0;
}


