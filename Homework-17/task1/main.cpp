#include <iostream>
#include <vector>

class Bigstick
{
private:
    std::vector <std::string> names;

  public:

  void amountGeneration ()
  {
    names.resize(std::rand() % 2 + 2);
  };
  void placement()
  {
    for (int i = 0; i < names.size(); i++)
    {
      std::cout << "middlestick " << i + 1 << " settlement" <<std::endl;
      std::cout << " Please enter a name of Elf" << std::endl;
      std::cin >> names[i];
    }
  };
  void foundNeighborsStick (std::string foo)
  {
    for (int i = 0; i < names.size(); i++)
    {
      if (foo == names[i])
      {
        std::cout << "Neighbors of " << foo << " are:" << std::endl;
        for (int j = 0; j < names.size(); j++)
        {
          if (j != i) std::cout << names[j] << std::endl;
        }
      }
    }
  }
};


class Tree
{
private:
    std::vector <Bigstick> tree;

  public:

  void amountOfBigSticks ()
  {
    tree.resize(std::rand() % 3 + 3);
  }

  void treePlacement ()
  {
    for (int i=0; i < tree.size(); i ++)
    {
      std::cout << "Bigstick " << i + 1 << " settlement" << std::endl;
      tree[i].amountGeneration();
      tree[i].placement();
    }
  };
  void foundNeighborsTree (std::string foo)
  {
    for (int i = 0; i < tree.size(); i++)
    {
      tree[i].foundNeighborsStick(foo);
    }
  }
};

class Village
{
private:
    std::vector <class Tree> village;

  public:
    Village () : village(5){}

  void settlement()
  {
    std::cout << "Village Settlement" << std::endl;
    for (int i = 0; i < village.size(); i++)
    {
      std::cout << "Tree " << i + 1 << " settlement" << std::endl;
      village[i].amountOfBigSticks();
      village[i].treePlacement();
    }
  }
  void foundNeighborsVillage (std::string foo)
  {
    for (int i = 0; i < village.size(); i++)
    {
      village[i].foundNeighborsTree(foo);
    }
  }

};



int main() {
  Village myVillage;
  myVillage.settlement();
  std::cout << "Who are we looking for?" << std:: endl;
  std::string answer;
  std::cin >> answer;
  myVillage.foundNeighborsVillage(answer);
}