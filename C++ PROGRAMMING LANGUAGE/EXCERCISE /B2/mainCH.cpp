//có tham khảo một số hàm còn thiếu của bạn trong lớp
#include<iostream>
#include<vector>
#include<string>
using namespace std;

typedef enum{
    MANAGER = 1,
    STAFF
}FunctionInRestaurants;

typedef enum{
    RETURN1,
    ADDDISHFORTABLE,
    CHANGEDISHFORTABLE,
    DELETEDISHFORTABLE,
    LISTDISHFORTABLE,
    PAYFORMENU
}OptionStaff;

typedef enum{
    RETURN,
    SETUPTABLE,
    ADDDISH,
    CHANGEDISH,
    DELETEDISH,
    LISTDISH
}OptionManager;

typedef enum{
    EMPTY,
    PERSON
}TypeStatus;

class Table{
    protected:
        int TableId;
        TypeStatus TableStatus;
    public: 
        Table(int TableId, TypeStatus TableStatus);
        int GetTableID();
        TypeStatus GetTableStatus();
        void SetTableStatus(TypeStatus TableStatus);
};

class EachTable{
    private:
        int DishIdTable;
        string DishNameTable;
        int CostDishTable;
        int NumberDish;
    public:
        EachTable(int TableId, string Name, int CostDish, int NumberDish);
        void SetDishNameTable(string Name);
        void SetCostDishTable(int CostDish);
        void SetDishIdTable(int TableId);
        void SetNumberDish(int NumberDish);
        string GetDishNameTable();
        int GetDishIdTable();
        int GetCostDishTable();
        int GetNumberDish();
}; 

class Dishes{
    private:
        int DishId;
        string DishName;
        int CostDish;
    public:
        Dishes(int DishId, string Name, int CostDish);
        void SetDishName(string Name);
        void SetCostDish(int CostDish);
        string GetDishName();
        int GetDishId();
        int GetCostDish();
};

void FunctionManager(vector<Table> &ListTables, vector<Dishes> &ListDishes);
static void SetUpNumberTable(vector<Table> &ListTables);
static void PrintTables(vector<Table> &ListTables);
static void PrintDishes(vector<Dishes> &ListDishes);
static void ChangeInformatinDish(vector<Dishes> &ListDishes,int ID);
static void ChangeNameDish(vector<Dishes> &ListDishes, int DishId);
static void ChangeCostDish(vector<Dishes> &ListDishes, int DishId);
static void DeleteDishById(vector<Dishes> &ListDishes, int IDToChange);

static void ChangeInformatinDish(vector<EachTable> &ListStaff,int ID);
static void ChangeNameDish(vector<EachTable> &ListStaff, int DishId);
static void ChangeCostDish(vector<EachTable> &ListStaff, int DishId);
static void ChangeNumberDish(vector<EachTable> &ListStaff, int DishId);
static void DeleteDishById(vector<EachTable> &ListStaff, int IDToChange);
static void PrintDishes(vector<EachTable> &ListStaff);
static void InformationStaff(vector<EachTable> &ListStaff, vector<Table> &ListTables);

static int ChooseNumberForTable; 

Table::Table(int TableId, TypeStatus TableStatus){
    this->TableId = TableId;
    this->TableStatus = TableStatus;
}

int Table::GetTableID(){
    return TableId;
}

TypeStatus Table::GetTableStatus(){
    return TableStatus;
}

void Table::SetTableStatus(TypeStatus TableStatus){
    this->TableStatus = TableStatus;
}

Dishes::Dishes(int DishId, string Name, int CostDish){
    this->DishId = DishId;
    this->DishName = Name;
    this->CostDish = CostDish;
}

string Dishes::GetDishName(){
    return DishName;
}

int Dishes::GetDishId(){
    return DishId;
}

int Dishes::GetCostDish(){
    return CostDish;
}

void Dishes::SetDishName(string Name){
    this->DishName = Name;
}

void Dishes::SetCostDish(int CostDish){
    this->CostDish = CostDish;
}

EachTable::EachTable(int TableId, string Name, int CostDish, int NumberDish){
    this->DishIdTable = TableId;
    this->DishNameTable = Name;
    this->CostDishTable = CostDish;
    this->NumberDish = NumberDish;
}

void EachTable::SetDishNameTable(string Name){
    this->DishNameTable = Name;
}

void EachTable::SetCostDishTable(int CostDish){
    this->CostDishTable = CostDish;
}

void EachTable::SetDishIdTable(int TableId){
    this->DishIdTable = TableId;
}

void EachTable::SetNumberDish(int NumberDish){
    this->NumberDish = NumberDish;
}

string EachTable::GetDishNameTable(){
    return DishNameTable;
}

int EachTable::GetDishIdTable(){
    return DishIdTable;
}
int EachTable::GetCostDishTable(){
    return CostDishTable;
}

int EachTable::GetNumberDish(){
    return NumberDish;
}

static void SetUpTable(vector<Table> &ListTables, vector<Dishes> &ListDishes){
    cout << "\nManager" << endl;
    cout << "\t--------------------------\t" << endl;
    cout << "\t 1: Choice the number  table \t" << endl;
    cout << "\t 0: Return\t" << endl;
    cout << "\t--------------------------\t" << endl;
    cout << "\tEnter the your choice : ";
    int key;
    cin >> key;
    switch (key){
        case 1:
            SetUpNumberTable(ListTables);
            break;
        case 0:
            FunctionManager(ListTables,ListDishes);
            break;        
        default:
            break;
    }

}

static void SetUpNumberTable(vector<Table> &ListTables){
    cout << "\nManager" << endl;
    cout << endl << "\tEnter the count  Table: ";
    int TableNumber;
    cin >> TableNumber;
    int TableID;
    TypeStatus TableStatus;
    cout << "\t--------------------------\t" << endl;
    cout << "\t 1: Have person (X): " << endl;
    cout << "\t 0: Empty (0): " << endl;
    cout << "\t--------------------------\t" << endl;
    int ChooseStatus;
    for(int i = 1; i <= TableNumber; i++){
        TableID = i;
        cout << "\tPlease enter status  table  "<< TableID<< ": ";
        cin >> ChooseStatus;
        switch (ChooseStatus){
            case 1:
                TableStatus = PERSON;
                break;
            case 0:
                TableStatus = EMPTY;
                break;
            default:
                break;
        }  
        Table table(TableID, TableStatus);
        ListTables.push_back(table);
    }
        cout <<endl << "\nManager" << endl;
        PrintTables(ListTables);
}

static string AssignStatusForTable(TypeStatus Table){
        if( Table == EMPTY )  return "0";
        else if( Table == PERSON ) return "X";
        return " ";
}

static void PrintTables(vector<Table> &ListTables){
    cout << endl << "\t\t\t___________________LIST  TABLE___________________\t\t\t" << endl;
    cout << endl << "\tTableNumber\t" << "\t|\t";
    for(int i = 0; i < ListTables.size(); i++){
        cout << ListTables[i].GetTableID() << "\t|\t"; 
    }
    cout << endl << "\t-----------------------------------------------------------------------------------------------------------\t";
    cout << endl << "\tStatus\t\t"<< "\t|\t";
    for(int i = 0; i < ListTables.size(); i++){  
        cout <<AssignStatusForTable(ListTables[i].GetTableStatus())<< "\t|\t";
    }
    cout << "\n\n" << endl;  
}

static void AddDishIntoMenu(vector<Dishes> &ListDishes){
    int key;
    do{
        cout << "\nManager" << endl;
        cout << "\t 1: Enter the Dish Name: ";
        string DishName;
        cin >> DishName;
        cout << endl << "\t 2: Enter the Dish Cost: ";
        double CostDish;
        cin >> CostDish;
        cout << endl << "\nManager" << endl;
        static int DishId = 100;
        Dishes Dish( DishId, DishName, CostDish);
        ListDishes.push_back(Dish);
        DishId++;
        PrintDishes(ListDishes);  
        cout << endl << "\tWould you like choose the futher  Dish ?" << endl;
        cout << "\t--------------------------\t" << endl;
        cout << "\t 1: Go on add Dish: " << endl;
        cout << "\t 2: Return: " << endl;
        cout << "\t--------------------------\t" << endl;
        cout << "\t Enter your choice: ";
        cin >> key;
    }while(key == 1);
}

static void PrintDishes(vector<Dishes> &ListDishes){
    cout << endl << "\t\t\t____MENU____\t\t\t" << endl;
    cout << endl << "\t----------------------------------------------------------\t\n";
    cout << "\t|\tID\t|\tName\t|\tCost\t|\t\n";
    for(int i = 0; i < ListDishes.size(); i++){ 
        cout << "\t----------------------------------------------------------\t\n";
        cout << "\t|\t" << ListDishes[i].GetDishId()<< "\t|\t"<< ListDishes[i].GetDishName() << "\t|\t"<< ListDishes[i].GetCostDish() << "\t|\t\n";  
    }
        cout << "\t----------------------------------------------------------\t\n";
}

void PrintDishNeedDelete(Dishes Dish){
    cout << endl << "\t----------------------------------------------------------\t\n";
    cout << "\t|\tID\t|\tName\t|\tCost\t|\t\n";
    cout << "\t----------------------------------------------------------\t\n";
    cout << "\t|\t"<< Dish.GetDishId() << "\t|\t"<< Dish.GetDishName()<< "\t|\t" << Dish.GetCostDish() << "\t|\t\n";
    cout << "\t----------------------------------------------------------\t\n";
}

static void ChangeDishInMenu(vector<Dishes> &ListDishes){
    cout << "\nManager" << endl;
    PrintDishes(ListDishes);
    cout << endl << "\t Please enter the ID  Dishes which are needed Delete: ";
    int ID;
    cin >> ID;
    ChangeInformatinDish(ListDishes, ID);
}
    
static void ChangeInformatinDish(vector<Dishes> &ListDishes,int ID){
    cout << "\nManager" << endl;
    cout << "\t--------------------------\t" << endl;
    cout << "\t 1: Change the name  the Dish \t" << endl;
    cout << "\t 2: Change the cost  the Dish \t" << endl;
    cout << "\t 0: Return\t" << endl;
    cout << "\t--------------------------\t" << endl;
    cout << "\tEnter the your choice : ";
    int key;
    cin >> key;
    switch (key){
    case 1:
        ChangeNameDish(ListDishes, ID);
        break;
    case 2:
        ChangeCostDish(ListDishes, ID);
        break;
    default:
        break;
    }
}

static void ChangeNameDish(vector<Dishes> &ListDishes, int DishId){
    int key;
    do{
    cout << "\nManager" << endl;
    cout << endl << "\tEnter Name  ID need modify: ";
    string ChooseNameToChange;
    cin >> ChooseNameToChange;
    for(int i = 0; i < ListDishes.size(); i++){
        if(ListDishes[i].GetDishId() == DishId)  ListDishes[i].SetDishName(ChooseNameToChange);
    }
    cout << "\nManager" << endl;
    cout <<endl << "\t Changed successFully the dish !! \t" << endl;
    cout << "\t List  Dishes after are Changed: \t" << endl;
    PrintDishes(ListDishes);
    cout << "\t--------------------------\t" << endl;
    cout << "\t 1: Go on change the Name  dish\t" << endl;
    cout << "\t 0: Return\t" << endl;
    cout << "\t--------------------------\t" << endl;
    cout << "\tEnter the your choice : ";
    cin >> key;
    }while(key == 1);
}

static void ChangeCostDish(vector<Dishes> &ListDishes, int DishId){
    int key;
    do{
        cout << "\nManager" << endl;
        cout << endl << "\tEnter Cost  ID need modify: ";
        int ChooseCostToChange;
        cin >> ChooseCostToChange;
        for(int i = 0; i < ListDishes.size(); i++){
            if(ListDishes[i].GetDishId() == DishId)  ListDishes[i].SetCostDish(ChooseCostToChange);
        }
        cout << "\nManager" << endl;
        cout <<endl << "\t Changed successFully the dish !!  \t" << endl;
        cout << "\t List  Dishes after are Changed: \t" << endl;
        PrintDishes(ListDishes);
        cout << "\t--------------------------\t" << endl;
        cout << "\t 1: Go on change the Cost  dish\t" << endl;
        cout << "\t 0: Return\t" << endl;
        cout << "\t--------------------------\t" << endl;
        cout << "\tEnter the your choice : ";
        cin >> key;
    }while(key == 1);
}

void DeleteDishInMenu(vector<Dishes> &ListDishes){
    cout << "\nManager" << endl;
    PrintDishes(ListDishes);
    cout << endl << "\t Please enter the ID  Dishes which are needed Delete: ";
    int ID;
    cin >> ID;
    cout << "\nManager" << endl;
    cout << "\tDo you really want to exit ? \t" << endl;
    cout << "\t--------------------------\t" << endl;
    cout << "\t 1: Sure \t" << endl;
    cout << "\t 2: Not yet \t" << endl;
    cout << "\t--------------------------\t" << endl;
    cout << "\tEnter the your choice : ";
    int key;
    cin >> key;
    switch (key){
    case 1:
        DeleteDishById(ListDishes, ID);
        break;
    case 2:
        break;
    default:
        cout << "ERROR !!";
        break;
    }
}

static void DeleteDishById(vector<Dishes> &ListDishes, int IDToChange){
    int key;
    do{
    for(int i = 0; i < ListDishes.size(); i++){
        if(ListDishes[i].GetDishId() == IDToChange)  ListDishes.erase(ListDishes.begin() + i );
    }
    cout << "\nManager" << endl;
    cout <<endl << "\t Deleted successFully the dish !! \t" << endl;
    cout << "\t List  Dishes after are Changed: \t" << endl;
    PrintDishes(ListDishes);
    cout << "\t--------------------------\t" << endl;
    cout << "\t 1: Go on delete \t" << endl;
    cout << "\t 0: Return\t" << endl;
    cout << "\t--------------------------\t" << endl;
    cout << "\tEnter the your choice : ";
    cin >> key;
    }while(key == 1);
}

void FunctionManager(vector<Table> &ListTables, vector<Dishes> &ListDishes){
    int retu;
    while(1){
        cout << "\nManager" << endl;
        cout << "\t--------------------------\t" << endl;
        cout << "\t1: Set the table number\t" << endl;
        cout << "\t2: Adding Dish into the menu\t" << endl;
        cout << "\t3: Modify the Dish\t" << endl;
        cout << "\t4: Delete the Dish\t" << endl;
        cout << "\t5: The List  the Dishes\t" << endl;
        cout << "\t0: Return\t" << endl;
        cout << "\t--------------------------\t" << endl;
        cout << "\tEnter the your choice : ";
        int key;
        cin >> key;
        switch(key){
            case RETURN:  
                retu = 0;                 
                break;
            case SETUPTABLE:
                SetUpTable(ListTables,ListDishes);
                break;
            case ADDDISH:
                AddDishIntoMenu(ListDishes);
                break;
            case CHANGEDISH:
                ChangeDishInMenu(ListDishes);
                break;
            case DELETEDISH:
                DeleteDishInMenu(ListDishes);
                break;
            case LISTDISH:
                cout << "\nManager" << endl;
                PrintDishes(ListDishes);
                break;
            default:
                break;
        }
        if(retu == 0){
            break; 
        }
    }
}

static void AddDishIntoMenu(vector<EachTable> &ListStaff, vector<Table> &ListTables){
    int key;
    do{
    cout << "\nStaff" << endl;
    cout << "\t 1: Enter the Dish Name: ";
    string DishName;
    cin >> DishName;
    cout << endl << "\t 2: Enter the Dish Cost: ";
    double CostDish;
    cin >> CostDish;
    cout << endl << "\t 3: Enter the number  Dish: ";
    int NumberDish;
    cin >> NumberDish;
    cout << endl << "\nStaff" << endl;
    static int DishId = 100;
    EachTable Table( DishId, DishName, CostDish, NumberDish);
    ListStaff.push_back(Table);
    DishId++;
    cout << endl << "\tAdded successfully the Dish !!" << endl;
    PrintDishes(ListStaff);
    cout << endl << "\tWould you like choose the futher  Dish ?" << endl;
    cout << "\t--------------------------\t" << endl;
    cout << "\t 1: Go on add Dish: " << endl;
    cout << "\t 2: Return: " << endl;
    cout << "\t--------------------------\t" << endl;
    cout << "\t Enter your choice: ";
    cin >> key;
    }while(key == 1);
      for(int i = 0; i < ListTables.size(); i++){
        if(ListTables[i].GetTableID() == ChooseNumberForTable && ListTables[i].GetTableStatus() == EMPTY)  ListTables[i].SetTableStatus(PERSON);    
    }
}

void PrintDishNeedDelete1(Dishes Dish){
    cout << endl << "\t----------------------------------------------------------\t\n";
    cout << "\t|\tID\t|\tName\t|\tCost\t|\t\n";
    cout << "\t----------------------------------------------------------\t\n";
    cout << "\t|\t"<< Dish.GetDishId()<< "\t|\t"<< Dish.GetDishName()<< "\t|\t"<< Dish.GetCostDish()<< "\t|\t\n";
    cout << "\t----------------------------------------------------------\t\n";
}

static void ChangeDishInMenu(vector<EachTable> &ListStaff){
    cout << "\nStaff" << endl;
    PrintDishes(ListStaff);
    cout << endl << "\t Please enter the ID  Dishes which are needed Delete: ";
    int ID;
    cin >> ID;
    ChangeInformatinDish(ListStaff, ID);
}
    
static void ChangeInformatinDish(vector<EachTable> &ListStaff,int ID){
    cout << "\nStaff" << endl;
    cout << "\t--------------------------\t" << endl;
    cout << "\t 1: Change the name  the Dish \t" << endl;
    cout << "\t 2: Change the cost  the Dish \t" << endl;
    cout << "\t 3: Change the quanity  the Dish \t" << endl;
    cout << "\t 0: Return\t" << endl;
    cout << "\t--------------------------\t" << endl;
    cout << "\tEnter the your choice : ";
    int key;
    cin >> key;
    switch(key){
        case 1:
            ChangeNameDish(ListStaff, ID);
            break;
        case 2:
            ChangeCostDish(ListStaff, ID);
            break;
        case 3:
            ChangeNumberDish(ListStaff, ID);
            break;
        default:
            break;
    }
}

static void ChangeNameDish(vector<EachTable> &ListStaff, int DishId){
    int key;
    do{
    cout << "\nStaff" << endl;
    cout << endl << "\tEnter Name  ID need modify: ";
    string ChooseNameToChange;
    cin >> ChooseNameToChange;
    for(int i = 0; i < ListStaff.size(); i++){
        if(ListStaff[i].GetDishIdTable() == DishId)  ListStaff[i].SetDishNameTable(ChooseNameToChange);
    }
    cout << "\nStaff" << endl;
    cout <<endl << "\t Changed successFully the dish !! \t" << endl;
    cout << "\t List  Dishes after are Changed: \t" << endl;
    PrintDishes(ListStaff);
    cout << "\t--------------------------\t" << endl;
    cout << "\t 1: Go on change the Name  dish\t" << endl;
    cout << "\t 0: Return\t" << endl;
    cout << "\t--------------------------\t" << endl;
    cout << "\tEnter the your choice : ";
    cin >> key;
    }while(key == 1);
}

static void ChangeCostDish(vector<EachTable> &ListStaff, int DishId){
    int key;
    do{
        cout << "\nStaff" << endl;
        cout << endl << "\tEnter Cost  ID need modify: ";
        int ChooseCostToChange;
        cin >> ChooseCostToChange;
        for(int i = 0; i < ListStaff.size(); i++){
            if(ListStaff[i].GetDishIdTable() == DishId)  ListStaff[i].SetCostDishTable(ChooseCostToChange);
        }
        cout << "\nStaff" << endl;
        cout <<endl << "\t Changed successFully the dish !!  \t" << endl;
        cout << "\t List  Dishes after are Changed: \t" << endl;
        PrintDishes(ListStaff);
        cout << "\t--------------------------\t" << endl;
        cout << "\t 1: Go on change the Cost  dish\t" << endl;
        cout << "\t 0: Return\t" << endl;
        cout << "\t--------------------------\t" << endl;
        cout << "\tEnter the your choice : ";
        cin >> key;
    }while (key == 1);
}

static void ChangeNumberDish(vector<EachTable> &ListStaff, int DishId){
    int key;
    do{
        cout << "\nStaff" << endl;
        cout << endl << "\tEnter Quanity need modify: ";
        int ChooseQuanityToChange;
        cin >> ChooseQuanityToChange;
        for(int i = 0; i < ListStaff.size(); i++){
            if(ListStaff[i].GetDishIdTable() == DishId)  ListStaff[i].SetNumberDish(ChooseQuanityToChange);
        }
        cout << "\nStaff" << endl;
        cout <<endl << "\t Changed successFully the dish !!  \t" << endl;
        cout << "\t List  Dishes after are Changed: \t" << endl;
        PrintDishes(ListStaff);
        cout << "\t--------------------------\t" << endl;
        cout << "\t 1: Go on change the Cost  dish\t" << endl;
        cout << "\t 0: Return\t" << endl;
        cout << "\t--------------------------\t" << endl;
        cout << "\tEnter the your choice : ";
        cin >> key;
    }while (key == 1);
}

static void DeleteDishInMenu(vector<EachTable> &ListStaff){
    cout << "\nStaff" << endl;
    PrintDishes(ListStaff);
    cout << endl << "\t Please enter the ID  Dishes which are needed Delete: ";
    int ID;
    cin >> ID;
    cout << "\nStaff" << endl;
    cout << "\tDo you really want to exit ? \t" << endl;
    cout << "\t--------------------------\t" << endl;
    cout << "\t 1: Sure \t" << endl;
    cout << "\t 2: Not yet \t" << endl;
    cout << "\t--------------------------\t" << endl;
    cout << "\tEnter the your choice : ";
    int key;
    cin >> key;
    switch (key){
        case 1:
            DeleteDishById(ListStaff, ID);
            break;
        case 2:
            break;
        default:
            cout << "ERROR !!";
            break;
    }
}

static void DeleteDishById(vector<EachTable> &ListStaff, int IDToChange){
    int key;
    do{
        for(int i = 0; i < ListStaff.size(); i++){
            if(ListStaff[i].GetDishIdTable() == IDToChange)  ListStaff.erase(ListStaff.begin() + i );
        }
        cout << "\nStaff" << endl;
        cout <<endl << "\t Deleted successFully the dish !! \t" << endl;
        cout << "\t List  Dishes after are Changed: \t" << endl;
        PrintDishes(ListStaff);
        cout << "\t--------------------------\t" << endl;
        cout << "\t 1: Go on delete \t" << endl;
        cout << "\t 0: Return\t" << endl;
        cout << "\t--------------------------\t" << endl;
        cout << "\tEnter the your choice : ";
        cin >> key;
    }while(key == 1);
}

static void PrintDishes(vector<EachTable> &ListStaff){
    int STT = 1;
    cout << endl << "\t\t\t\t____________MENU____________\t\t\t\t\t" << endl;
    cout << "\t---------------------------------------------------------------------------------\t\n";
    cout << "\t|\tStt\t|\tID\t|\tName\t|\tCost\t|\tQuanity\t|\t\n";
    for(int i = 0; i < ListStaff.size(); i++){
        cout << "\t---------------------------------------------------------------------------------\t\n";
        cout << "\t|\t"<<STT<< "\t|\t"<< ListStaff[i].GetDishIdTable()<< "\t|\t"<< ListStaff[i].GetDishNameTable()<< "\t|\t"<< ListStaff[i].GetCostDishTable()<< "\t|\t"<< ListStaff[i].GetNumberDish()<< "\t|\t\n";
        STT++;
    }
    cout << "\t---------------------------------------------------------------------------------\t\n";
}

void PayForMenuEachTable(vector<EachTable> &ListStaff, vector<Table> &ListTables){
    int key;
    do{
        cout << "\nStaff" << endl;
        cout << endl << "\t\t\t_________Pay for the Dish at Table "<< " "<<ChooseNumberForTable<< "_________\t\t\t" << endl;
        cout << endl << "\tBILL\t" << endl;
        PrintDishes(ListStaff);
        int TotalCostToPayDishes = 0;
        for(int i = 0; i < ListStaff.size(); i++){
            TotalCostToPayDishes += ListStaff[i].GetNumberDish() * ListStaff[i].GetCostDishTable();
        }
        for(int i = 0; i < ListTables.size(); i++){
            if(ListTables[i].GetTableID() == ChooseNumberForTable && ListTables[i].GetTableStatus() == PERSON)  ListTables[i].SetTableStatus(EMPTY);
        }
        cout << endl << "\tTotal Cost to pay for Dishes at table "<<ChooseNumberForTable<< ": "<< TotalCostToPayDishes<<endl;
        cout << endl << "\tThe List  tables after pay the dish :" << endl;
        PrintTables(ListTables);
        cout << "\t X : Have person  " << endl;
        cout << "\t 0 : Empty  " << endl<<endl;
        cout << endl << "\t--------------------------\t" << endl;
        cout << "\t 1: Go on pay for the Dish\t" << endl;
        cout << "\t 0: Return\t" << endl;
        cout << "\t--------------------------\t" << endl;
        cout << "\tEnter the your choice : ";
        cin >> key;
    }while(key == 1);
}

void FunctionStaff(vector<Table> &ListTables,vector<EachTable> &ListStaff){
    if(ListTables.size() != 0){
        cout << endl << "\nStaff" << endl;
        PrintTables(ListTables);
        cout << endl << "Enter the number  Table: ";
        cin >> ChooseNumberForTable;
        for(int i = 0; i < ListTables.size(); i++){       
            if(ListTables[i].GetTableID() == ChooseNumberForTable)  InformationStaff(ListStaff,ListTables);   
        }
    }
    else cout << endl << " Please set up the table in the choice  Manager !!\n" << endl;

}

static void InformationStaff(vector<EachTable> &ListStaff,vector<Table> &ListTables){
    while(1){
        cout << "\nStaff" << endl;
        cout << "\t\tTABLE NUMBER: "<<ChooseNumberForTable<<endl;
        cout << "\t--------------------------\t" << endl;
        cout << "\t1: Adding Dish into the menu \t" << endl;
        cout << "\t2: Modify the Dish\t" << endl;
        cout << "\t3: Delete the Dish\t" << endl;
        cout << "\t4: The List  the Dishes\t" << endl;
        cout << "\t5: Pay for the menu\t" << endl;
        cout << "\t0: Return\t" << endl;
        cout << "\t--------------------------\t" << endl;
        cout << "\tEnter the your choice : ";
        int key;
        cin >> key;
        switch (key){
            case  ADDDISHFORTABLE:
                AddDishIntoMenu(ListStaff,ListTables);
                break;
            case CHANGEDISHFORTABLE:
                ChangeDishInMenu(ListStaff);
                break;
            case DELETEDISHFORTABLE:
                DeleteDishInMenu(ListStaff);
                break;
            case LISTDISHFORTABLE:
                cout << "\nStaff" << endl;
                PrintDishes(ListStaff);
                break;
            case  PAYFORMENU:
                PayForMenuEachTable(ListStaff, ListTables);
                break;
            case RETURN1:  
                FunctionStaff(ListTables,ListStaff);               
                break;
            default:
                break;    
        }
    }
}

int main(){
    vector<Table> ListTables;
    vector<Dishes> ListDishes;
    vector<EachTable> ListStaff;
    while(1){
        cout << "----------------";
        cout << "\n 1: Manager\n 2: Staff\n";
        cout << "----------------";
        cout << "\n Please enter your choice : ";
        int key;
        cin >> key;
        switch(key){
            case MANAGER:
                FunctionManager(ListTables,ListDishes);
                break;
            case STAFF:
                FunctionStaff(ListTables, ListStaff);
                break;
            default:
                cout << "\n ERROR SYNTAX!!" << endl;
                break;
        }
    }
    return 0;
}
