#include <iostream>
#include <vector>

int main() {
    std::vector<int> vec = { 2, -2, 14, -32, 10, 2, 0, -1, 6, 17, -40, 22, 15, 10 };
    int posI = 0;
    int posJ = 0;
    int curI = 0;
    int curJ = 0;
    int curSum = 0;
    int max = vec[0];
    bool newSum = false;
    bool haveNotI = true;

    for(int i = 0; i < vec.size() - 1; ++i){
        int tmp = vec[i];
        for(int j = i + 1; j < vec.size(); ++j){
            tmp += vec[j];
            if(max < tmp){
                max = vec[i] + vec[j];
                posI = i;
                posJ = j;
            }
        }
    }
    /*for (int i = 0; i < vec.size() - 1; ++i)
    {
        if (newSum || vec[i] >= 0)
        {
            newSum = true;
            if (curSum + vec[i] >= curSum)
            {
                if (haveNotI)
                {
                    curI = i;
                    haveNotI = false;
                }
                curJ = i;
                curSum += vec[i];
            }
            else{
                if (curSum + vec[i] < 0)
                {
                    haveNotI = true;
                    newSum = false;
                    curSum = 0;
                }
                else
                    curSum += vec[i];
            }
            if (curSum > max)
            {
                max = curSum;
                posI = curI;
                posJ = curJ;
            }
        }
        else{
            curSum = 0;
        }
    }*/
    std::cout << "max = " << max << std::endl;
    std::cout << "i = " << posI << std::endl;
    std::cout << "j = " << posJ << std::endl;
    return 0;
}
