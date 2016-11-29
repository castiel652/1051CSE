#include <iostream>
#include <cmath>
#include <vector>

using namespace std;
int order4[16] = {0, 1, 3, 2, 4, 5, 7, 6, 12, 13, 15, 14, 8, 9, 11, 10};
int truthtable4[16][5] = {{0, 0, 0, 0, 0}, {0, 0, 0, 1, 1}, {0, 0, 1, 1, 2}, {0, 0, 1, 0, 1},
                          {0, 1, 0, 0, 1}, {0, 1, 0, 1, 2}, {0, 1, 1, 1, 3}, {0, 1, 1, 0, 2},
                          {1, 1, 0, 0, 2}, {1, 1, 0, 1, 3}, {1, 1, 1, 1, 4}, {1, 1, 1, 0, 3},
                          {1, 0, 0, 0, 1}, {1, 0, 0, 1, 2}, {1, 0, 1, 1, 3}, {1, 0, 1, 0, 2}};
class PI4
{
    public:
    int vars[4];
    int ones;
    int term;
};

class combinedTerm
{
    public:
        vector<int> terms;
}

int compareTerms(PI4 pi1, PI4 pi2)
{
    if(pi1.var[0] != pi2.var[0] && pi1.var[1] == pi2.var[1] && pi1.var[2] == pi2.var[2] && pi1.var[3] == pi2.var[3])
        return 0;
    else if(pi1.var[0] == pi2.var[0] && pi1.var[1] != pi2.var[1] && pi1.var[2] == pi2.var[2] && pi1.var[3] == pi2.var[3])
        return 1;
    else if(pi1.var[0] == pi2.var[0] && pi1.var[1] == pi2.var[1] && pi1.var[2] != pi2.var[2] && pi1.var[3] == pi2.var[3])
        return 2;
    else if(pi1.var[0] == pi2.var[0] && pi1.var[1] == pi2.var[1] && pi1.var[2] == pi2.var[2] && pi1.var[3] != pi2.var[3])
        return 3;
    else return 4;
}

int main()
{
    int type, **mapTerms = NULL, lines;
    cin >> lines;
    string input;   cin >> input;
    vector<int> primei;
    type = sqrt(input.length());
    for(int i = 0; i < input.length(); ++i) {
        if(input[i] == 1 || input[i] == 2)
            primei.push_back(i);
    }
    vector<PI4> pis; vector<PI4> pis1; vector<PI4> pis2; vector<PI4> pis3; vector<PI4> pis4;
    PI4 temp;
    //PI4 pis[primei.size()];
    for(int i = 0; i < primei.size(); ++i) {
        for(int j = 0; j < type; ++j)
            temp.vars[i] = truthtable4[primei[i]][j];
        temp.ones = truthtable4[primei[i]][type];
        temp.term = order4[primei[i]];
        if(temp.ones == 1)
            pis1.push_back(temp);
        else if(temp.ones == 2)
            pis2.push_back(temp);
        else if(temp.ones == 3)
            pis3.push_back(temp);
        else if(temp.ones == 4)
            pis4.push_back(temp);
    }
    combinedTerm terms;
    for(int i = 0; i < pis1.size(); ++i) {
        for(int j = i + 1; j < pis1.size(); ++i) {
            if(compareTerms(pis1[i], pis1[j]) != 4 && )
                2terms.terms.push_back
        }
    }
    return 0;
}
