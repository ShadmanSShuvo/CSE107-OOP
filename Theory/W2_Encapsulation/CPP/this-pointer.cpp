#include <iostream>
#include <string>
using namespace std;
class Message
{
    string msg;

public:
    Message(string msg)
    {
        this->msg = msg;
    }
    Message updateMessage(string msg);
    void displayMessage();
};

Message Message::updateMessage(string msg)
{
    this->msg = msg;
    return *this;
}
    void Message::displayMessage()
    {
        cout << "Message: " << this->msg << endl;
    }

int main()
{
    Message msg("Hello, World!");
    msg.displayMessage();
    msg = msg.updateMessage("New Message.");
    msg.displayMessage();
}