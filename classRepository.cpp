#include <iostream>
#include <typeinfo>

using namespace std;

class AbstractEntity {
public:
    virtual void Print() { 
        cout << "AbstractEntity: call print" << endl; 
    }

    virtual ~AbstractEntity() = default;
};

class AccountEntity : public AbstractEntity {   
public:
    void Print() override { 
        cout << "AccountEntity: call print" << endl; 
    }
};

class RoleEntity : public AbstractEntity {  
public:
    void Print() override { 
        cout << "RoleEntity: call print" << endl; 
    }
};

class IRepository { 
public:
    virtual void Save(AbstractEntity* entity) = 0;
    virtual ~IRepository() = default;
};

class AccountRepository : public IRepository {
public:
    void Save(AbstractEntity* entity) override {
        if (typeid(*entity) != typeid(AccountEntity)) {
            cout << " Error: trying to save a non-AccountEntity in the AccountRepository" << endl;
            cout << "type entity = " << typeid( *entity ).name() << endl;
            return;
        }
        cout << "Saving AccountEntity..." << endl;
    }
};

class RoleRepository : public IRepository {
public:
    void Save(AbstractEntity* entity) override {
        if (typeid(*entity) != typeid(RoleEntity)) {
            cout << " Error: trying to save a non-RoleRepository in the RoleRepository" << endl;
            cout << "type entity = " << typeid( *entity ).name() << endl;
            return;
        }
        cout << "Saving RoleEntity..." << endl;
    }
};

int main() {
    AccountEntity account;
    RoleEntity role;
    AccountRepository accountRepo;
    RoleRepository roleRepo;

    account.Print();
    role.Print();

    cout << endl;

    accountRepo.Save(&account);
    roleRepo.Save(&role);

    cout << endl;

    accountRepo.Save(&role);
    roleRepo.Save(&account);
    
    return 0;
}