#include "Menu.h"

// CONSTRUCTOR VACIO
Menu::Menu()
{
    studentController = StudentController::getInstance();
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
    cin.clear();
    cin.ignore();
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
                cout << " OPCION 3" << endl;
                break;
            case '4':
                cout << " OPCION 4" << endl;
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

void Menu::user_load() 
{
    string path;
    cout << " INGRESE LA RUTA DEL ARCHIVO DE USUARIOS: ";
    path = scanner();
    cout << endl;
    studentController->massive_charge(path);
    cout << " ____________________________________________________________________________________" << endl;
}