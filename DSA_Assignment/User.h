/*
P02
Chua Jie Ren - S10222145D
THU YA SWE - S10222373G
*/

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
