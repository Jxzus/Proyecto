#pragma once
#include <string>
#include <vector>
#include <map>
using namespace std;

enum class ShipmentStatus {
    REGISTERED,
    IN_TRANSIT,
    DELIVERED
};

struct Package {
    string id;
    double weight;
    string category;
    string description;
};

struct Shipment {
    string id;
    vector<Package> packages;
    ShipmentStatus status;
    string userId;
};

struct User {
    string username;
    string passwordHash;
};

class ShippingSystem {
public:
    bool registerUser(const string& username, const string& password);
    bool authenticateUser(const string& username, const string& password);
    bool registerPackage(const Package& package);
    bool createShipment(const string& userId, const vector<string>& packageIds, string& shipmentId);
    bool updateShipmentStatus(const string& shipmentId, ShipmentStatus newStatus);
    vector<Shipment> getShipments() const;
    
private:
    map<string, User> users_;
    map<string, Package> packages_;
    map<string, Shipment> shipments_;
    string currentUser_;
    
    string hashPassword(const string& password);
};
