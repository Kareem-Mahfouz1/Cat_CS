#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;
int Hash_string(string str, int n = 65407)
{
    long long ln = n;
    long long sum = 0;
    for (int i = 0; i < str.size(); i++)
    {
        sum = (sum * 26 + str[i] - 'a') % ln;
    }
    return sum % ln;
}
struct PhoneEntry
{
    string name;
    string number;

    PhoneEntry(string name, string number) : name(name), number(number) {}

    int hash()
    {
        return Hash_string(name);
    }
    void print()
    {
        cout << "(" << name << " , " << number << ") ";
    }
};

class PhoneHashTable
{
private:
    int table_sz;
    vector<PhoneEntry *> table;
    PhoneEntry *deleted = new PhoneEntry("", "");

public:
    PhoneHashTable(int table_sz) : table_sz(table_sz)
    {
        table.resize(table_sz);
    }
    bool add(PhoneEntry phone)
    {
        int id = phone.hash() % table_sz;
        int original_id = id;
        for (int i = 0; i < table_sz; i++)
        {
            if (table[id] == deleted || !table[id])
            {
                table[id] = new PhoneEntry(phone.name, phone.number);
                return true;
            }
            else if (table[id]->name == phone.name)
            {
                table[id]->number = phone.number;
                return true;
            }
            id = (id + i * i) % table_sz;
            if (id == original_id)
            {
                rehash();
                add(phone);
                break;
            }
        }
        return false;
    }
    void rehash()
    {
        PhoneHashTable alt(table_sz * 2);

        for (int i = 0; i < table_sz; i++)
        {
            if (!table[i] || table[i] == deleted)
                continue;
            else
            {
                alt.add(*table[i]);
            }
        }
        table = alt.table;
        table_sz *= 2;
    }
    bool remove(PhoneEntry phone)
    {
        int id = phone.hash() % table_sz;
        int original_id = id;
        for (int i = 0; i < table_sz; i++)
        {
            if (!table[id])
                break;
            else if (table[id]->name == phone.name && table[id] != deleted)
            {
                delete table[id];
                table[id] = deleted;
                return true;
            }
            id = (id + i * i) % table_sz;
            if (id == original_id)
                break;
        }
        return false;
    }
    bool get(PhoneEntry &phone)
    {
        int id = phone.hash() % table_sz;
        int original_id = id;
        for (int i = 0; i < table_sz; i++)
        {
            if (!table[id])
                break;
            else if (table[id]->name == phone.name && table[id] != deleted)
            {
                phone.number = table[id]->number;
                return true;
            }
            id = (id + i * i) % table_sz;
            if (id == original_id)
                break;
        }
        return false;
    }
    void print_all()
    {
        for (int i = 0; i < table_sz; i++)
        {
            cout << i << " : ";
            if (table[i] == deleted)
                cout << "X";
            else if (!table[i])
                cout << "E";
            else
                table[i]->print();
            cout << "\n";
        }
        cout << "-------------------";
    }
};

int main()
{

    return 0;
}