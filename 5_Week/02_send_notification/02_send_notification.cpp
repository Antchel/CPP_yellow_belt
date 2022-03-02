#include <iostream>
#include <string>

using namespace std;

void SendSms(const string& phone_number, const string& message) {
	cout << "Send " << message << " to number " << phone_number << endl;
};

void SendEmail(const string& email, const string& message) {
	cout << "Send " << message << " to email " << email << endl;
};

class INotifier {
public:
	virtual void Notify(const string& message) = 0;
};

class SmsNotifier: public INotifier {
public:
	SmsNotifier(const string& phone_number) :mphone_number(phone_number) {};
	void Notify(const string& message) {
		SendSms(mphone_number, message);
	};
private:
	string mphone_number;
};

class EmailNotifier: public INotifier {
public:
	EmailNotifier(const string& Email) :mEmail(Email) {};
	void Notify(const string& message) {
		SendEmail(mEmail, message);
	};
private:
	string mEmail;
};

void Notify(INotifier& notifier, const string& message) {
	notifier.Notify(message);
};

int main()
{
	const string str = "89001234567";
	SmsNotifier sms(str);
	sms.Notify("Hello, Antoxa");
	EmailNotifier mail("gmail@mail.ru");
	mail.Notify("This is a spam");

	Notify(sms, "Hi bro!");
	Notify(mail, "Hi there");
}
