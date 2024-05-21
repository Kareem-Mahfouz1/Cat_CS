#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;
int Hash_string(string str,int n = 65407){
    int base = 26 + 26 + 10;
    long long ln = n;
    long long sum = 0;
    for(int i = 0; i < str.size(); i++){
        int val = 0;
        if(islower(str[i]))
            val = str[i] - 'a';
        else if(isupper(str[i]))
            val = 26 + str[i] - 'A';
        else
            val = 26 + 26 + str[i] - '0';
        sum = (sum * base + val) % ln;
    }
    return sum % ln;
}
int Hash_string2(string str,int n = 65407){
    long long sum = 0;
    long long ln = n;
    for(int i = 0; i < str.size(); i+=4){
        sum += Hash_string(str.substr(i,4));
    }
    return sum % ln;
}

struct obj{
    string str1, str2;
    int num;

    obj(string str1,string str2,int num):
        str1(str1), str2(str2), num(num){}
        
    int hash() {
        return Hash_string(str1 + str2 + to_string(num));
    }
};

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
    double Limit_Load_Factor;
    int elements = 0;
    vector<vector<PhoneEntry>> table;
public:
    PhoneHashTable(int table_sz,double Limit_Load_Factor):
        table_sz(table_sz),
        Limit_Load_Factor(Limit_Load_Factor){
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
        elements++;
        if(!Check_load())
            rehash();
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
            cout<< "Hash " <<i<<": ";
            for(int j = 0; j < table[i].size();j++){
                table[i][j].print();
            }
            cout<<"\n";
        }
    }
    void rehash(){
        PhoneHashTable alt(table_sz*2,Limit_Load_Factor);

        for(int i = 0; i < table_sz;i++){
            if(table[i].size() == 0)
                continue;
            for(int j = 0; j < table[i].size();j++){
                alt.add(table[i][j]);
            }
        }
        table = alt.table;
        table_sz*= 2;

        
    }
    bool Check_load(){
        if((double) (elements/table_sz) > Limit_Load_Factor)
            return false;
        else
            return true;
    }
};

int main()
{
    PhoneHashTable ph(2,1);
    ph.add(PhoneEntry("ahmed","01002042061"));
    ph.add(PhoneEntry("kareem","01273460737"));
    ph.print_all();
    ph.add(PhoneEntry("han","01285009695"));
    ph.print_all();
    
    return 0;
}