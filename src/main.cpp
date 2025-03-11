#include "app.h"
#include <iostream>

int main() {
    ShippingSystem system;
    

    system.registerUser("usuario1", "password123");
    
    Package package{"PKG001", 2.5, "Electronics", "Laptop"};
    system.registerPackage(package);
    
    return 0;
}
