#include <iostream>
#include <fstream>

int main()
{
    std::ifstream fin("river.txt");
    std::ofstream fout("basket.txt", std::ios::app);

    if(!fout.is_open()) {
        std::cout << "Basket is missing." << std::endl;
    } else if(!fin.is_open()){
        std::cout << "River is missing." << std::endl;
    } else{
        std::string fish;
        std::cout << "Fish type: ";
        std::cin >> fish;
        int counter = 0;
        while(!fin.eof()){
            std::string tmp;
            fin >> tmp;
            if(tmp == fish){
                fout << fish << std::endl;
                ++counter;
            }
        }
        std::cout << "amount of catch: " << counter << std::endl;
    }
    fin.close();
    fout.close();

    return 0;
}