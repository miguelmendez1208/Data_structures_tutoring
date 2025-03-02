#include <iostream>
#include <string>

using namespace std;

class Address {
private:
    string streetNum;
    string city;
    string zip;

public:
    Address(string street, string city, string zipCode) {
        streetNum = street;
        this->city = city;
        zip = zipCode;
    }

    string getStreet() const { return streetNum; }
    string getCity() const { return city; }
    string getZip() const { return zip; }

    void setStreet(const string& street) { streetNum = street; }
    void setCity(const string& city) { this->city = city; }
    void setZip(const string& zipCode) { zip = zipCode; }

    void displayAddress() const {
        cout << getStreet() << ", " << getCity() << ", " << getZip();
    }
};

class Contact {
private:
    string name;
    string phone;
    string relationship;
    Address* address;

public:
    Contact(string name, string phone, string relationship, Address* address) {
        this->name = name;
        this->phone = phone;
        this->relationship = relationship;
        this->address = address;
    }

    string getName() const { return name; }
    string getPhone() const { return phone; }
    string getRelationship() const { return relationship; }
    Address* getAddress() const { return address; }

    void setName(const string& newName) { name = newName; }
    void setPhone(const string& newPhone) { phone = newPhone; }
    void setRelationship(const string& newRelationship) {
        relationship = newRelationship;
    }

    void setAddress(Address* newAddress) {
        address = newAddress;
    }

    void displayContact() const {
        cout << "Name: " << getName() << endl;
        cout << "Phone: " << getPhone() << endl;
        cout << "Relationship: " << getRelationship() << endl;
        cout << "Address: ";
        getAddress()->displayAddress();
        cout << endl << endl;
    }
};

int main() {
    // Create a shared address
    Address* sharedAddress = new Address("123 Main St", "Springfield", "12345");

    // Create Contact objects using the shared address
    Contact ann("Ann", "555-123-4567", "Friend", sharedAddress);
    Contact preeti("Preeti", "555-987-6543", "Colleague", sharedAddress);
    cout << "Shared address: " <<endl;
    cout << sharedAddress << endl;

    // Display initial contact information
    cout << "Initial Contacts:" << endl;
    ann.displayContact();
    preeti.displayContact();

    // Create a new address for Preeti
    Address* preetiNewAddress = new Address("456 Oak Ave", "Springfield", "67890");
    cout << "New Address for Preeti!: " << endl;
    cout << preetiNewAddress << endl;

    // Update Preeti's address
    preeti.setAddress(preetiNewAddress);

    // Display updated contact information
    cout << "\nUpdated Contacts:" << endl;
    ann.displayContact();
    preeti.displayContact();
    
    cout << ann.getAddress() << endl;
    cout << preeti.getAddress() <<endl;

    // Clean up dynamically allocated memory
    delete sharedAddress;
    delete preetiNewAddress;

    return 0;
}
