#include <iostream>
#include <vector>

enum TaskType
{
    None = 0,
    A,
    B,
    C
};

class People
{
private:
    std::string m_name = "unknown";
public:
    std::string setName (std::string inName)
    {
        return m_name = inName;
    }

    std::string getName()
    {
        return m_name;
    }
};

class Worker : public People
{
private:
    TaskType m_task = None;
public:
    bool isBusy()
    {
        if(m_task == None){
            return false;
        }
        else return true;
    };

    TaskType setTask(TaskType inTask)
    {
        return m_task = inTask;
    };

    TaskType getTask()
    {
        return m_task;
    };

    void addTask (TaskType inTask)
    {
        if (!isBusy()) setTask(inTask);
    };
};


class Team : public People
{
private:
    int m_count = 0;
    std::vector <Worker> workers;
    int m_id = 0;
    std::string m_managerName;
public:
    Team (int inId, int inCount)
    {
        m_id=inId;
        m_count = inCount;
        std::cout << "Please enter manager name" << std::endl;
        std::cin >> m_managerName;
        for (int i = 0; i < m_count; i++)
        {
            std::cout << "Please enter a Worker name" << std::endl;
            std::string temp;
            std::cin >> temp;
            Worker myWorker;
            myWorker.setName(temp);
            workers.push_back(myWorker);
        }
    }

    bool allIsBusy()
    {
        for(int i = 0; i < m_count; i++)
        {
            if (!workers[i].isBusy()) return false;
        }
        return true;
    };

    void giveTask (int inTask)
    {
        if (!allIsBusy())
        {
            inTask = (inTask + m_id) % 3 + 1;
            int stick = 0;
            for (int i = 0 ; i < m_count; i++)
            {
                if (!workers[i].isBusy()) stick = i;
            }
            if (inTask == 1) workers[stick].setTask(A);
            else if (inTask == 2) workers[stick].setTask(B);
            else if (inTask == 3) workers[stick].setTask(C);
        }
        else std::cout << "All are busy in that team!";
    }
};

class Head : public People
{
private:
    std::vector <Team> teams;
    int m_amount = 0;
public:

    void addTeam()
    {
        int inId, inCount;
        std::cout << "Please enter number of group and amount of employees" << std::endl;
        std::cin >> inId >> inCount;
        Team myTeam = Team(inId, inCount);
        teams.push_back(myTeam);
        m_amount ++;
    }

    void addTask()
    {
        int control = 0;
        int inAnswer = 0;
        std::cout << "Please give a task number" << std::endl;
        std::cin >> inAnswer;
        for (int i = 0; i < m_amount; i ++)
        {
            if (!teams[i].allIsBusy())
            {
                teams[i].giveTask(inAnswer);
                break;
            }
            else control ++;
        }
        if(control == m_amount) std::cout << "All are busy!" << std::endl;
    }

    bool isEmpty()
    {
        for (int i = 0; i < m_amount; i ++)
        {
            if (!teams[i].allIsBusy()) return true;
        }
        return false;
    };

    int getAmount()
    {
        return m_amount;
    }

};

int main() {
    Head myHead;
    std::string chef;
    std::cout << "Please enter a name of Chef" << std::endl;
    std::cin >> chef;
    myHead.setName(chef);
    myHead.addTeam();
    while (myHead.isEmpty())
    {
        myHead.addTask();
    }
}