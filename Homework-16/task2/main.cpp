#include <iostream>
#include <vector>
#include <string>




class Phone
{
private:
    class AddressBook
    {
    public:
        std::string name;
        std::string number;
    };
    AddressBook newContact;
    std::vector <class AddressBook> list;
public:
    void add ()
    {
        std::string buffer;
        std::cout << "Please Enter a name of Person" << std::endl;
        std::cin >> newContact.name;
        std::cout << "Please enter a number of person with +7 (10 additional digits)" << std::endl;
        std::cin >> buffer;
        while (buffer.size() != 12 && buffer[0] != '+' && buffer[1] != '7')
        {
            std::cout << "Incorrect input" << std::endl;
            std::cout << "Please enter again" << std::endl;
            std::cin >> buffer;
        }
        newContact.number = buffer;
        list.push_back(newContact);

        std::cout << "Contact is added." << std::endl;
    };

    void call()
    {
        std::string buffer;
        std::cout << "Whom you want to call?" << std::endl;
        std::cin >> buffer;
        for (int i=0; i < list.size(); i++)
        {
            if(buffer == list[i].name)
            {
                std::cout << "We're calling to " << list[i].name << " by number" << list[i].number << std::endl;
            } else if (buffer == list[i].number)
            {
                std::cout << "We're calling to " << list[i].name << " by number" << list[i].number << std::endl;
            } else std::cout << "There is no such kind of person" << std::endl;
        }
    };
    void sms()
    {
        std::string buffer;
        std::string message;
        std::cout << "Please enter a message" << std::endl;
        std::cin >> std::ws;
        std::getline (std::cin, message);
        std::cout << "Whom you want to send it?" << std::endl;
        std::cin >> buffer;
        for (int i=0; i < list.size(); i++)
        {
            if(buffer == list[i].name)
            {
                std::cout << "SMS " << message <<" were sent to " << list[i].name << " by number" << list[i].number << std::endl;
            } else if (buffer == list[i].number)
            {
                std::cout << "SMS " << message <<" were sent to " << list[i].name << " by number" << list[i].number << std::endl;
            } else std::cout << "There is no such kind of person" << std::endl;
        }
    };
};

int main() {
    Phone myPhone;
    std::cout << "Input command:";
    std::string choice;
    do {
        std::cin >> choice;
        if (choice == "add"){
            myPhone.add ();
        } else if (choice == "call"){
            myPhone.call ();
        } else if (choice == "sms") {
            myPhone.sms ();
        } else if (choice == "exit"){
            break;
        } else {
            std::cout << "Wrong command!" << std::endl;
        }
    } while (true);
}
