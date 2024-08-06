#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;
int Hash_string(string str,int n = 65407){
    long long ln = n;
    long long sum = 0;
    for(int i = 0; i < str.size(); i++){
        sum = (sum * 26 + str[i] - 'a') % ln;
    }
    return sum % ln;
}
struct PhoneEntry{
    string name;
    string phone;

    PhoneEntry(string name,string phone):
        name(name),phone(phone){}
        
    int hash() {
        return Hash_string(name);
    }
    void print(){
        cout<<"("<<name<<" , "<<phone<<") ";
    }
};

class PhoneHashTable {
private:
    int table_sz;
    vector<vector<PhoneEntry>> table;
public:
    PhoneHashTable(int table_sz):
        table_sz(table_sz){
            table.resize(table_sz);
        }
    void add(PhoneEntry phone){
        int id = phone.hash() % table_sz;

        for(int i = 0; i < table[id].size();i++){
            if(phone.name == table[id][i].name){
                table[id][i] = phone;
                return;
            }
        }
        table[id].push_back(phone);
    }
    bool remove(PhoneEntry phone){
        int id = phone.hash() % table_sz;

        for(int i = 0; i < table[id].size();i++){
            if(phone.name == table[id][i].name){
                swap(table[id][i] , table[id].back());
                table[id].pop_back();
                return true;
            }
        }
        return false;
    }
    bool get(PhoneEntry &phone){
        int id = phone.hash() % table_sz;

        for(int i = 0; i < table[id].size();i++){
            if(phone.name == table[id][i].name){
                phone = table[id][i];
                return true;
            }
        }
        return false;
    }
    void print_all(){
        for(int i = 0; i < table_sz;i++){
            if(table[i].size() == 0)
                continue;
            cout<< "Hash" <<i<<": ";
            for(int j = 0; j < table[i].size();j++){
                table[i][j].print();
            }
            cout<<"\n";
        }
    }
};

int main()
{
    PhoneHashTable ph(4);
    ph.add(PhoneEntry("ahmed","5685"));
    ph.add(PhoneEntry("kareem","94220"));
    ph.add(PhoneEntry("kareem","85963"));
    ph.add(PhoneEntry("ali","01125"));
    ph.print_all();


    return 0;
}