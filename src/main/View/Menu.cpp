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
    char c[9000];
    cin.clear();
    cin.sync();
    cin.ignore(); 

    //getline(cin, temp); 
    scanf("%[^\n]" ,c);
    temp += c;
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
    cout << " *  " << title << endl;
    cout << " ************************************************************************************" << endl;
    cout << " |      1) AGREGAR                                                                  |" << endl;
    cout << " |      2) EDITAR                                                                   |" << endl;
    cout << " |      3) ELIMINAR                                                                 |" << endl;
    cout << " |      4) REGRESAR                                                                 |" << endl;
    cout << " ************************************************************************************" << endl;
    cout << " ************************************************************************************" << endl;
}

void Menu::print_menu_manual_options() 
{
    cout << " ************************************************************************************" << endl;
    cout << " *                                       MENU                                       *" << endl;
    cout << " ************************************************************************************" << endl;
    cout << " *  INGRESO MANUAL                                                                  *" << endl;
    cout << " ************************************************************************************" << endl;
    cout << " |      1) USUARIOS                                                                 |" << endl;
    cout << " |      2) TAREAS                                                                   |" << endl;
    cout << " |      3) REGRESAR                                                                 |" << endl;
    cout << " ************************************************************************************" << endl;
    cout << " ************************************************************************************" << endl;
}

void Menu::print_report_options() 
{
    cout << " ************************************************************************************" << endl;
    cout << " *                                       MENU                                       *" << endl;
    cout << " ************************************************************************************" << endl;
    cout << " *  REPORTES                                                                        *" << endl;
    cout << " ************************************************************************************" << endl;
    cout << " |      1) REPORTE SOBRE LA LISTA DE ESTUDIANTES                                    |" << endl;
    cout << " |      2) REPORTE SOBRE LA LISTA DE TAREAS LINEALIZADA                             |" << endl;
    cout << " |      3) BUSQUEDA EN ESTRUTURA LINEALIZADA                                        |" << endl;
    cout << " |      4) BUSQUEDA DE POSICION EN LISTA LINEALIZADA                                |" << endl;
    cout << " |      5) COLA DE ERRORES                                                          |" << endl;
    cout << " |      6) CODIGO GENERADO DE SALIDA                                                |" << endl;
    cout << " |      7) REGRESAR                                                                 |" << endl;
    cout << " ************************************************************************************" << endl;
    cout << " ************************************************************************************" << endl;
}


void Menu::print_menu_update() 
{
    cout << " ************************************************************************************" << endl;
    cout << " *                                       MENU                                       *" << endl;
    cout << " ************************************************************************************" << endl;
    cout << " *  ACTUALIZAR DATOS DEL USUARIO                                                    *" << endl;
    cout << " ************************************************************************************" << endl;
    cout << " |      1) CARNE                                                                    |" << endl;
    cout << " |      2) NOMBRE                                                                   |" << endl;
    cout << " |      3) CARRERA                                                                  |" << endl;
    cout << " |      4) PASSWORD                                                                 |" << endl;
    cout << " |      5) CREDITOS                                                                 |" << endl;
    cout << " |      6) EDAD                                                                     |" << endl;
    cout << " |      7) CORREO                                                                   |" << endl;
    cout << " |      8) REGRESAR                                                                 |" << endl;
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
                print_menu_manual();
                break;
            case '4':
                print_menu_report();
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

void Menu::print_menu_manual()
{
    bool flag = true;
    char option;
    do
    {
        clear();
        cout << endl;
        print_info();
        cout << endl;
        print_menu_manual_options();
        cout << "\n INGRESE EL NUMERO DE LA OPCION: ";
        cin >> option;
        cout << " ____________________________________________________________________________________" << endl;

        switch (option)
        {
            case '1':
                view_manual_users();
                this->stop();
                break;
            case '2':

                this->stop();
                break;
            case '3':
                flag = false;
                break;
            default:
                cout << " ERROR OPCION INGRESADA NO VALIDA." << endl;
                break;
        }

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
                menu_update();
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

void Menu::print_menu_report()
{
    bool flag = true;
    char option;
    do
    {
        clear();
        cout << endl;
        print_info();
        cout << endl;
        print_report_options();
        cout << "\n INGRESE EL NUMERO DE LA OPCION: ";
        cin >> option;
        cout << " ____________________________________________________________________________________" << endl;

        switch (option)
        {
            case '1':
                studentController->report_student();
                this->stop();
                break;
            case '2':

                this->stop();
                break;
            case '3':

                this->stop();
                break;
            case '4':

                this->stop();
                break;
            case '5':

                this->stop();
                break;
            case '6':

                this->stop();
                break;
            case '7':
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
    string carne;
    string dpi; 
    string name; 
    string career; 
    string password; 
    string credits; 
    string age; 
    string mail;

    cout << " CARNET: ";
    carne = scanner();
    cout << " DPI: ";
    dpi = scanner();
    cout << " NOMBRE: ";
    name = scanner();
    cout << " CARRERA: ";
    career = scanner();
    cout << " PASSWORD: ";
    password = scanner();
    cout << " CREDITOS: ";
    credits = scanner();
    cout << " EDAD: ";
    age = scanner();
    cout << " CORREO: ";
    mail = scanner();

    studentController->add_student(carne, dpi, name, career, password, credits, age, mail);
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
    string option = "";
    cout << " DECEA ELIMINAR AL USUARIO (s/n): ";
    option = scanner();
    if(option == "s") 
    {
        studentController->delete_student(dpi);
    }
     
} 

void Menu::menu_update()
{
    bool flag = true;
    char option;

    string carne;
    string dpi; 
    string name; 
    string career; 
    string password; 
    string credits; 
    string age; 
    string mail;

    cout << " INGRESE NUMERO DE DPI DEL USUARIO: ";
    dpi = scanner();

    if(studentController->find_student(dpi).getDpi() != "") 
    {
        do
        {
            clear();
            cout << endl;
            print_info();
            cout << endl;
            print_menu_update();
            cout << "\n INGRESE EL NUMERO DE LA OPCION: ";
            cin >> option;
            cout << " ____________________________________________________________________________________" << endl;

            switch (option)
            {
                case '1':
                    cout << " CARNET: ";
                    carne = scanner();
                    this->stop();
                    break;
                case '2':
                    cout << " NOMBRE: ";
                    name = scanner();
                    this->stop();
                    break;
                case '3':
                    cout << " CARRERA: ";
                    career = scanner();
                    this->stop();
                    break;
                case '4':
                    cout << " PASSWORD: ";
                    password = scanner();
                    this->stop();
                    break;
                case '5':
                    cout << " CREDITOS: ";
                    credits = scanner();
                    this->stop();
                    break;
                case '6':
                    cout << " EDAD: ";
                    age = scanner();
                    this->stop();
                    break;
                case '7':
                    cout << " CORREO: ";
                    mail = scanner();
                    this->stop();
                    break;
                case '8':
                    flag = false;
                    break;
                default:
                    cout << " ERROR OPCION INGRESADA NO VALIDA." << endl;
                    break;
            }
        } while (flag);
    } else {
        cout << " USUARIO NO ENCONTRADO.\n";
    }
    studentController->update_student(dpi, carne, name, career, password, credits, age, mail);
}