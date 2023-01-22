#include "User.h"

User::User(string name, string pass) 
{
	username = name;
	password = pass;
}

void User::setName(string newName) 
{
	username = newName;
}

string User::getName() 
{
	return username;
}

void User::setPassword(string newPassword) 
{
	password = newPassword;
}

string User::getPassword() 
{
	return password;
}

void valid(string username) {

}