#include "Menu.h"

// CONSTRUCTOR VACIO
Menu::Menu()
{
    studentController = StudentController::getInstance();
    cin_bool = true;
}

// DESTRUCTOR
Menu::~Menu() 
{
    
}

void Menu::clear()
{
    #ifdef _WIN32
        system("cls");
    #else
        system("clear");
    #endif
}

string Menu::scanner()
{
    string temp = "";
    char a[100];
    if(cin_bool) 
    {
        cin.clear();
        cin.sync();
        cin_bool = false;
        cin.ignore(); 
    } else {
        cin.getline(a, 100);
        cin_bool = true;
    }
    getline(cin, temp); 

    return temp;
}

void Menu::stop()
{
    cout << "\n PRESIONAR ENTER PARA CONTINUAR. ";
    scanner();
}

void Menu::print_info() 
{
    cout << "  ---------------------------------------------------------------------------------- " << endl;
    cout << "  |     JOSE ANDRES FLORES BARCO                                                   | " << endl;
    cout << "  |     201801287                                                                  | " << endl;
    cout << "  |     ESTRUCTURA DE DATOS SECCION C                                              | " << endl;
    cout << "  |     PROYECTO FASE 1 -> SMART CLASS                                             | " << endl;
    cout << "  ---------------------------------------------------------------------------------- " << endl;
}

void Menu::print_menu_options() 
{
    cout << " ************************************************************************************" << endl;
    cout << " ************************************************************************************" << endl;
    cout << " *                                       MENU                                       *" << endl;
    cout << " ************************************************************************************" << endl;
    cout << " |      1) CARGA DE USUARIOS                                                        |" << endl;
    cout << " |      2) CARGA DE TAREAS                                                          |" << endl;
    cout << " |      3) INGRESO MANUAL                                                           |" << endl;
    cout << " |      4) REPORTES                                                                 |" << endl;
    cout << " |      5) SALIR                                                                    |" << endl;
    cout << " ************************************************************************************" << endl;
    cout << " ************************************************************************************" << endl;
}

void Menu::print_manual_options(string title) 
{
    cout << " ************************************************************************************" << endl;
    cout << " *                                       MENU                                       *" << endl;
    cout << " ************************************************************************************" << endl;
    cout << "   " << title << endl;
    cout << " ************************************************************************************" << endl;
    cout << " |      1) AGREGAR                                                                  |" << endl;
    cout << " |      2) EDITAR                                                                   |" << endl;
    cout << " |      3) ELIMINAR                                                                 |" << endl;
    cout << " |      4) REGRESAR                                                                 |" << endl;
    cout << " ************************************************************************************" << endl;
    cout << " ************************************************************************************" << endl;
}

void Menu::view_menu()
{
    bool flag = true;
    char option;
    do
    {
        clear();
        cout << endl;
        print_info();
        cout << endl;
        print_menu_options();
        cout << "\n INGRESE EL NUMERO DE LA OPCION: ";
        cin >> option;
        cout << " ____________________________________________________________________________________" << endl;

        switch (option)
        {
            case '1':
                user_load();
                break;
            case '2':
                cout << " OPCION 2" << endl;
                break;
            case '3':
                view_manual_users();
                break;
            case '4':
                studentController->report_student();
                break;
            case '5':
                cout << " OPCION 5" << endl;
                flag = false;
                break;
            default:
                cout << " ERROR OPCION INGRESADA NO VALIDA." << endl;
                break;
        }
        this->stop();

    } while (flag);
}

void Menu::view_manual_users()
{
    string dpi = "";

    bool flag = true;
    char option;
    do
    {
        clear();
        cout << endl;
        print_info();
        cout << endl;
        print_manual_options("INGRESO MANUAL DE USUARIOS.");
        cout << "\n INGRESE EL NUMERO DE LA OPCION: ";
        cin >> option;
        cout << " ____________________________________________________________________________________" << endl;

        switch (option)
        {
            case '1':
                create_user();
                this->stop();
                break;
            case '2':
                cout << " OPCION 2" << endl;
                this->stop();
                break;
            case '3':
                cout << " INGRESE NUMERO DE DPI: ";
                this->remove_user(scanner());
                this->stop();
                break;
            case '4':
                flag = false;
                break;
            default:
                cout << " ERROR OPCION INGRESADA NO VALIDA." << endl;
                break;
        }

    } while (flag);
}

void Menu::create_user() 
{
    string line = "";

    cout << " (CARNET,DPI,NOMBRE,CARRERA,PASSWORD,CREDITOS,EDAD,CORREO)" << endl;
    cout << " ESCRIBA CON EL SIGUIENTE FORMATO PARA INGRESAR EL USUARIO: \n ";
    
    line = scanner();
    
    studentController->add_student1(line); 
} 

void Menu::user_load() 
{
    string path;
    cout << " INGRESE LA RUTA DEL ARCHIVO DE USUARIOS: ";
    path = scanner();
    cout << endl;
    studentController->massive_charge(path);
    cout << " ____________________________________________________________________________________" << endl;
}

void Menu::remove_user(string dpi) 
{
    studentController->delete_student(dpi); 
} 