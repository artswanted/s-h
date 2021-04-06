#include <iostream>
#include <vector>

int main() {
    std::vector<int> vec = {2, 5, 8, 4, 0, 11, 7, 5, 13, 1};
    int iResultValue = 14;
    int iPos1 = 0, iPos2 = 0;
    bool bFound = false;

    for (int j = 0; j < vec.size(); j++){
        if (bFound) {break;}
        for (int i = j+1; i < vec.size(); i++){
            if (i == -1 || j == -1) {break;}
            //std::cout << vec[j] << std::endl;
            //std::cout << vec[i] << std::endl;
            //std::cout << "----------\n";
            if ((vec[j] + vec[i]) == iResultValue){
                iPos1 = vec[j];
                iPos2 = vec[i];
                bFound = true;
                break;
            } else if (vec[j] == vec[i]){
                vec[i] = -1;
            }
        }
    }
    std::cout << iPos1 << " + " << iPos2 << " = " << (iPos1+iPos2) << "| == " << iResultValue;
    return 0;
}
