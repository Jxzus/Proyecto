#include "app.h"
#include <algorithm>
#include <random>
#include <functional>

using namespace std;

string ShippingSystem::hashPassword(const string& password) {

    return to_string(hash<string>{}(password));
}

bool ShippingSystem::registerUser(const string& username, const string& password) {
    if (users_.find(username) != users_.end()) {
        return false;
    }
    
    User newUser{username, hashPassword(password)};
    users_[username] = newUser;
    return true;
}

bool ShippingSystem::authenticateUser(const string& username, const string& password) {
    auto it = users_.find(username);
    if (it == users_.end()) {
        return false;
    }
    
    if (it->second.passwordHash == hashPassword(password)) {
        currentUser_ = username;
        return true;
    }
    return false;
}

bool ShippingSystem::registerPackage(const Package& package) {
    if (packages_.find(package.id) != packages_.end()) {
        return false;
    }
    
    packages_[package.id] = package;
    return true;
}
