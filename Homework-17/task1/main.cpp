#include <iostream>
#include <string>
#include <vector>

class Branch
{
    Branch* parent = nullptr;
    std::vector<Branch*> children;

    std::string elfName = "None";

public:

    Branch(Branch* inParent): parent(inParent) {

    }

    Branch* addChild()
    {
        Branch* child = new Branch(this);
        children.push_back(child);
        return child;
    }

    int getChildrenCount()
    {
        return children.size();
    }

    bool canBeOccupied()
    {
        return parent != nullptr;
    }

    std::string getElfName()
    {
        return elfName;
    }

    void occupy(std::string inElfName)
    {
        if (elfName == inElfName) return;
        if (inElfName != "None")
        {
            if (elfName != "None")
            {
                std::cerr << "House already occupied!" << std::endl;
                return;
            }
            if (!canBeOccupied())
            {
                std::cerr << "This branch can't be occupied!" << std::endl;
                return;
            }
            elfName = inElfName;
        }
    }

    Branch* getTopBranch()
    {
        if (parent == nullptr) return nullptr;
        if (parent->parent == nullptr) return parent;
        return parent->getTopBranch();
    }

    Branch* getBigBranch()
    {
        if (parent == nullptr) return nullptr;
        return parent->parent == nullptr ? this : parent;
    }

    int countElves()
    {
        int count = elfName != "None";
        for (int i = 0; i < children.size(); ++i)
        {
            count += children[i]->countElves();
        }
        return count;
    }

    int countNeighbors()
    {
        Branch* bigBranch = getBigBranch();
        return bigBranch == nullptr ? 0 : bigBranch->countElves() - (elfName != "None");
    }

    void occupyChildren()
    {
        if (canBeOccupied())
        {
            std::string inElfName;
            std::cout << "Elf name:";
            std::cin >> inElfName;
            occupy(inElfName);
        }
        for (int i = 0; i < children.size(); ++i)
        {
            children[i]->occupyChildren();
        }
    }

    Branch* findElfBranch(const std::string& inElfName)
    {
        if (elfName == inElfName)
        {
            return this;
        }
        for (int i = 0; i < children.size(); ++i)
        {
            if (Branch* child = children[i]->findElfBranch(inElfName); child != nullptr)
            {
                return child;
            }
        }
        return nullptr;
    }
};

int main()
{
    std::vector<Branch*> trees;
    for (int i = 0; i < 1; ++i) // 1 для простоты
    {
        Branch* tree = new Branch(nullptr);
        trees.push_back(tree);
        int largeCount = (std::rand() % 3) + 3;
        for (int j = 0; j < largeCount; ++j)
        {
            Branch* large = tree->addChild();
            int smallCount = (std::rand() % 2) + 2;
            for (int k = 0; k < smallCount; ++k)
            {
                large->addChild();
            }
        }
    }

    for (int i = 0; i < trees.size(); ++i)
    {
        trees[i]->occupyChildren();
    }

    std::string elfName;
    std::cout << "Search for elf:";
    std::cin >> elfName;

    for (int i = 0; i < trees.size(); ++i)
    {
        if (Branch* branch = trees[i]->findElfBranch(elfName);branch != nullptr)
        {
            int count = branch->countNeighbors();
            std::cout << "Neighbors: " << count << std::endl;
        }
    }
}