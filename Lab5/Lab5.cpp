#include <math.h>
#include <iostream>

using namespace std;
class HashTable {
private:
    const int tableSize = 43;
    const double A = 0.6180339887;
public:
    int divisionMethod(const int& key) {
        return key % tableSize;
    }
    int multiplicationMethod(const int& key) {
        double scaledValue = key * A;
        double fractionalPart = scaledValue - floor(scaledValue);
        return tableSize * fractionalPart;
    }
    unsigned int stringKeysMethod(const string& key) {
        unsigned int hash = key[0];
        int degree = 1;
        for (int i = 1; i < key.size(); i++) {
            hash += key[i] * pow(A, degree);
            degree++;
        }
        return hash % tableSize;
    }
};
int main()
{
    while (true) {
        HashTable table;
        int option;
        int key;
        string stringKey;
        cout << "Choose a method:" << endl;
        cout << "1. Division method" << endl;
        cout << "2. Multiplication method" << endl;
        cout << "3. Method for string keys" << endl;
        cin >> option;
        switch (option) {
        case 1:
            cin >> key;
            cout << table.divisionMethod(key) << endl;
            break;
        case 2:
            cin >> key;
            cout << table.multiplicationMethod(key) << endl;
            break;
        case 3:
            cin >> stringKey;
            cout << table.stringKeysMethod(stringKey) << endl;
            break;
        }

    }
    
}


