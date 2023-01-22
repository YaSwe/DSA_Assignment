#pragma once
#include <iostream>
using namespace std;

class User
{
private:
	string username;
	string password;
	
public:
	User(string name, string pass);
	User() = default;
	
	void setName(string newName);

	string getName();

	void setPassword(string newPassword);

	string getPassword();
};
