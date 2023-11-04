#include<iostream>
#include<conio.h>
using namespace std;

void mainMenu();
void adminMenu();
void customerMenu();

// Class for the Admin
class Admin {
private:
    string train_plan[3];
    float train_cost[3];

public:
    // Function to insert training plans and their costs
    void insert_plan() {
        for (int i = 0; i < 3; i++) {
            cin.ignore();
            cout << "Please Enter Training Plan\n";
            getline(cin, train_plan[i]);
            cout << "Please Enter Training Cost\n";
            cin >> train_cost[i];
        }
    }

    // Function to view training plans and their costs
    void view_training_plan() {
        cout << "\tTraining Plan\t\tTraining Cost\n";
        for (int i = 0; i < 3; i++) {
            cout << i + 1 <<"\t"<< train_plan[i] << "\t\t" << train_cost[i] << endl;
        }
    }

    // Function to show weight categories
    void show_weight() {
        cout << "\n=========Competition Weight Categories========\n\n";
        cout << "Categories\t\t\tWeight Limit\n";
        cout << "1.Heavy Weight\t\t\tover 100\n";
        cout << "2.Light Heavy Weight\t\t100\n";
        cout << "3.Middle Weight\t\t\t90\n";
        cout << "4.Light MiddleWeight\t\t81\n";
        cout << "5.Light Weight\t\t\t73\n";
        cout << "6.Flyweight\t\t\t66\n";
        cout << endl;
    }

    // Function to update training plans and their costs
    void update_admin() {
        view_training_plan();
        string update_plan; // Plan to update
        cin.ignore();
        cout << "Enter a plan you want to update: ";
        getline(cin, update_plan);

        for (int i = 0; i < 3; i++) {
            if (update_plan == train_plan[i]) {
                cout << "Enter a training plan: ";
                getline(cin, train_plan[i]);
                cout << "Enter cost: ";
                cin >> train_cost[i];
                break; // Exit the loop once the update is done
            }
        }
        adminMenu();
    }
};

// Creating an Admin object
Admin obj_admin;

// Class for the Guest, inheriting from Admin
class Guest : public Admin {
public:
    // Function for the guest menu
    void guest() {
        int ch;
        cout << " 1. View Plan \n 2. Weight Categories \n 3. Main Menu" << endl;
        cin >> ch;
        if (ch == 1) {
            obj_admin.view_training_plan();
            guest();
        }
        else if (ch == 2) {
            show_weight();
            guest();
        }
        else if (ch == 3) {
            mainMenu();
        }
    }
};

// Creating a Guest object
Guest obj_guest;

// Class for the Customer, inheriting from Admin
class Customer : public Admin {
public:
    string customer_name;
    int t_plan;
    string cu_plan;
    string weight;
    char tution;
    int tution_hr;
    float beginner_fees = 20;
    float intermediate_fees = 30;
    float elite_fees = 40;
    float tution_fees = 23000.00;
    float total_cost = 0;
    float private_t;
    string cur_weight;
    char competition;
    int race;
    float comp_fees = 22.00;
    int comp = 0;

    // Function to calculate private tuition fees
    float private_tution(char c) {
        if (c == 'y') {
            cout << "Please Enter private tuition hours: \n";
            cin >> tution_hr;
            if (tution_hr < 5) {
                total_cost += (tution_fees * tution_hr);
                return total_cost;
            }
            else {
                cout << "You have exceeded the allotted private hours.\n";
                private_tution(c);
            }
        }
        else {
            return total_cost;
        }
    }

    // Function to determine weight categories
    int weight_categories() {
        int race = 1;
        int current_weight;
        show_weight();
        cout << "Enter your current weight: \n";
        cin >> current_weight;
        if (current_weight > 100) {
            cout << "Congratulations!!! You can join Heavy Weight Competition.\n";
            cur_weight = "Heavy Weight";
        }
        else if (current_weight == 100) {
            cout << "Congratulations!!! You can join Light Heavyweight Competition.\n";
            cur_weight = "Light Weight";
        }
        else if (current_weight < 100 && current_weight >= 90) {
            cout << "Congratulations!!! You can join Middleweight Competition.\n";
            cur_weight = "Middleweight";
        }
        else if (current_weight < 90 && current_weight >= 81) {
            cout << "Congratulations!!! You can join Light Middleweight Competition.\n";
            cur_weight = "Light Middleweight";
        }
        else if (current_weight < 81 && current_weight >= 73) {
            cout << "Congratulations!!! You can join Lightweight Competition.\n";
            cur_weight = "Lightweight";
        }
        else if (current_weight < 73 && current_weight >= 66) {
            cout << "Congratulations!!! You can join Flyweight Competition.\n";
            cur_weight = "Flyweight";
        }
        else {
            cout << "Sorry!!! You can't compete.\n";
            race = 0;
        }

        return race;
    }

    /* Function to get customer data */
    void getdata() {
        cin.ignore();
        cout << "Enter the customer name: ";
        getline(cin, customer_name);
        obj_admin.view_training_plan();
        cout<<"Enter the number of training plan: ";
        cin >> t_plan;
        if (t_plan == 1) {
            cu_plan = "beginner";
            total_cost += beginner_fees;
        }
        else if (t_plan == 2) {
            cu_plan = "intermediate";
            total_cost += intermediate_fees;
        }
        else if (t_plan == 3) {
            cu_plan = "Elite";
            total_cost += elite_fees;
        }
        cout << "Do you wanna take Private tuition (y/n): \n";
        cin >> tution;
        private_t = private_tution(tution); // Calculate private tuition fees
        if ((t_plan == 2) || (t_plan == 3)) {
            race = weight_categories();
            if (race == 1) {
                cout << "Congratulations!!! You can join a competition.\n";
                cout << "Enter the number of competitions: \n";
                cin >> comp;
                total_cost += (comp_fees * comp);
            }
            else if (race == 0) {
                cout << "Sorry!!! You can't join a competition.\n";
            }
        }
        else {
            cout << "Sorry!!! You are a beginner, so you can't compete.\n";
        }
    }

    // Function to display customer data
    void showdata() {
        cout << "Customer Name =" << customer_name << endl;
        cout << "Total Cost = " << total_cost << endl;
        cout << "Weight = " << cur_weight << endl;
        cout << "Training Plan = " << cu_plan << endl;
    }
};

// Creating an array of Customer objects
Customer obj_customer[3];
int s = 0;

/* Main function */
int main() {
    mainMenu();
}

// Function for the main menu
void mainMenu() {
    int user;
    cout << "1. Admin\n2. Customer\n3. Guest\n";
    cin >> user;
    if (user == 1) {
        adminMenu();
        getch();
    }
    else if (user == 2) {
        customerMenu();
    }
}

// Function for the admin menu
void adminMenu() {
    int admin_task;
    cout << "1. Insert Plan\n2. Update\n3. View Training Plan\n4. Main Menu\n";
    cin >> admin_task;
    if (admin_task == 1) {
        obj_admin.insert_plan();
        getch();
        adminMenu();
    }
    if (admin_task == 2) {
        obj_admin.update_admin();
        getch();
        adminMenu();
    }
    else if (admin_task == 3) {
        obj_admin.view_training_plan();
        getch();
        adminMenu();
    }
    else if (admin_task == 4) {
        mainMenu();
    }
    else {
        cout << "Please Try Again!!!";
        adminMenu();
    }
}

// Function for the customer menu
void customerMenu() {
    int customer_task;
    char ch;
    cout << "1. Register\n2. View Information\n0. Main Menu\n";
    cin >> customer_task;
    if (customer_task == 1) {
        obj_customer[s].getdata();
        s++;
        cout << "Success inserted.\n";
        customerMenu();
    }
    else if (customer_task == 2) {
        cout << "Customer Name\tTraining Plan\t\tWeight Categories\tTotal Cost\n";
        for (int i = 0; i < s; i++) {
            obj_customer[i].showdata();
        }
        customerMenu();
    }
    else if (customer_task == 3) {
        mainMenu();
    }
}

