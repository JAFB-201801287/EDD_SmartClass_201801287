#include "Menu.h"

// CONSTRUCTOR VACIO
Menu::Menu()
{
    studentController = StudentController::getInstance();
    homeworkController = HomeworkController::getInstance();
    errorController = ErrorController::getInstance();
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
    if(errorController->getFirst() != NULL) 
    {
        cout << " |                                                                                  |" << endl;
        cout << " |      0) RESOLVER ERRORES                                                         |" << endl;
    }
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


void Menu::print_menu_update_student() 
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

void Menu::print_menu_update_homework() 
{
    cout << " ************************************************************************************" << endl;
    cout << " *                                       MENU                                       *" << endl;
    cout << " ************************************************************************************" << endl;
    cout << " *  ACTUALIZAR DATOS DE LA TAREA                                                    *" << endl;
    cout << " ************************************************************************************" << endl;
    cout << " |      1) CARNE                                                                    |" << endl;
    cout << " |      2) NOMBRE                                                                   |" << endl;
    cout << " |      3) DESCRIPCION                                                              |" << endl;
    cout << " |      4) MATERIA                                                                  |" << endl;
    cout << " |      5) FECHA                                                                    |" << endl;
    cout << " |      6) ESTADO                                                                   |" << endl;
    cout << " |      7) REGRESAR                                                                 |" << endl;
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
            case '0':
                solve_problemens();
                break;
            case '1':
                user_load();
                break;
            case '2':
                homework_load();
                break;
            case '3':
                print_menu_manual();
                break;
            case '4':
                print_menu_report();
                break;
            case '5':
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
                view_manual_homeworks();
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

void Menu::view_manual_homeworks()
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
        print_manual_options("INGRESO MANUAL DE TAREAS.");
        cout << "\n INGRESE EL NUMERO DE LA OPCION: ";
        cin >> option;
        cout << " ____________________________________________________________________________________" << endl;

        switch (option)
        {
            case '1':
                create_homework();
                this->stop();
                break;
            case '2':
                view_update_homework();
                this->stop();
                break;
            case '3':
                remove_homework();
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
                homeworkController->report_homework();
                this->stop();
                break;
            case '3':
                search_struct_homework();
                this->stop();
                break;
            case '4':
                search_position_homework();
                this->stop();
                break;
            case '5':
                errorController->report_error();
                this->stop();
                break;
            case '6':
                studentController->generated_code();
                homeworkController->generated_code();
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

void Menu::create_homework() 
{
    int month = 0;
    int day = 0;
    int hour = 0;

    Homework homework;

    cout << " MES: ";
    month = stoi(scanner());
    homework.setMonth(month);

    cout << " DIA: ";
    day = stoi(scanner());
    homework.setDay(day);

    cout << " HORA: ";
    hour = stoi(scanner());
    homework.setHour(hour);

    cout << " CARNE: ";
    homework.setCarne(stoi(scanner()));

    cout << " NOMBRE: ";
    homework.setName(scanner());

    cout << " DESCRIPCION: ";
    homework.setDescription(scanner());

    cout << " MATERIA: ";
    homework.setMatter(scanner());

    cout << " FECHA: ";
    homework.setDate(scanner());

    cout << " ESTADO (Pendiente, Realizado, Incumplido): ";
    homework.setState(scanner());

    homeworkController->add_matriz(homework, month, day, hour); 
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

void Menu::remove_homework() 
{
    int month = 0;
    int day = 0;
    int hour = 0;

    cout << " MES: ";
    month = stoi(scanner());

    cout << " DIA: ";
    day = stoi(scanner());

    cout << " HORA: ";
    hour = stoi(scanner());

    homeworkController->delete_homework(month, day, hour);
}

void Menu::homework_load() 
{
    string path;
    cout << " INGRESE LA RUTA DEL ARCHIVO DE TAREAS: ";
    path = scanner();
    cout << endl;
    homeworkController->massive_charge(path);
    cout << " ____________________________________________________________________________________" << endl;
}

void Menu::search_struct_homework() 
{
    int month = 0;
    int day = 0;
    int hour = 0;

    cout << " MES: ";
    month = stoi(scanner());

    cout << " DIA: ";
    day = stoi(scanner());

    cout << " HORA: ";
    hour = stoi(scanner());
    cout << endl;
    cout << " ____________________________________________________________________________________" << endl;
    Homework homework = homeworkController->find_homework(month, day, hour);
    cout << endl;
    cout << " ID: " << homework.getId() << endl;
    cout << " CARNE: " << homework.getCarne() << endl;
    cout << " NOMBRE: " << homework.getName() << endl;
    cout << " DESCRIPCION: " << homework.getDescription() << endl;
    cout << " MATERIA: " << homework.getMatter() << endl;
    cout << " FECHA: " << homework.getDate() << endl;
    cout << " ESTADO: " << homework.getState() << endl;
}

void Menu::search_position_homework() 
{
    int month = 0;
    int day = 0;
    int hour = 0;

    cout << " MES: ";
    month = stoi(scanner());

    cout << " DIA: ";
    day = stoi(scanner());

    cout << " HORA: ";
    hour = stoi(scanner());
    cout << endl;
    cout << " ____________________________________________________________________________________" << endl;
    cout << endl;
    if(!homeworkController->position_homework(month, day, hour)) 
    {
        cout << " TAREA NO ENCONTRADA.";
    }

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
            print_menu_update_student();
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

void Menu::view_update_homework()
{
    bool flag = true;
    char option;

    int id = 0;
    string carne;
    string name; 
    string description; 
    string matter; 
    string date; 
    string state; 

    cout << " INGRESE NUMERO DE ID DE LA TAREA: ";
    id = stoi(scanner());

    if(homeworkController->find_homework(id)) 
    {
        do
        {
            clear();
            cout << endl;
            print_info();
            cout << endl;
            print_menu_update_homework();
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
                    cout << " DESCRIPCION: ";
                    description = scanner();
                    this->stop();
                    break;
                case '4':
                    cout << " MATERIA: ";
                    matter = scanner();
                    this->stop();
                    break;
                case '5':
                    cout << " FECHA: ";
                    date = scanner();
                    this->stop();
                    break;
                case '6':
                    cout << " ESTADO (Pendiente, Realizado, Incumplido): ";
                    state = scanner();
                    this->stop();
                    break;
                case '7':
                    flag = false;
                    homeworkController->update_homework(id, name, description, matter, date, state);
                    break;
                default:
                    cout << " ERROR OPCION INGRESADA NO VALIDA." << endl;
                    break;
            }
        } while (flag);
    } else {
        cout << " ID DE TAREA NO ENCONTRADO.\n";
    }

}

void Menu::solve_problemens() 
{
    if(errorController->getFirst() != NULL) 
    {
        string option = "s";
        bool flag = true;
        Error* error;
        string mail = "";
        string date = "";
        string state = "";
        do
        { 
            error = errorController->getFirst();
            if(error != NULL) 
            {
                if(error->getType() == "ESTUDIANTE" && error->getDescrition() == "CORREO") 
                {
                    Student student = studentController->find_student(error->getDpi());
                    cout << " ESTUDIANTE" << endl;
                    cout << " ____________________________________________________________________________________" << endl;
                    cout << " CARNET: " << student.getCarne() << endl;
                    cout << " NOMBRE: " << student.getName() << endl;
                    cout << " CARRERA: " << student.getCareer() << endl;
                    cout << " PASSWORD: " << student.getPassword() << endl;
                    cout << " CREDITOS: " << student.getCredits() << endl;
                    cout << " EDAD: " << student.getAge() << endl;
                    cout << " CORREO: ";
                    mail = scanner();

                    if(studentController->is_email_valid(mail)) 
                    {
                        studentController->update_student(error->getDpi(), "", "", "", "", "", "", mail);
                        errorController->delete_error(error->getId());
                    }
                } else if(error->getType() == "TAREA") 
                {
                    Homework homework = homeworkController->find_homework1(error->getId_homework());
                    cout << " TAREA" << endl;
                    cout << " ____________________________________________________________________________________" << endl;
                    cout << " CARNET: " << homework.getCarne() << endl;
                    cout << " NOMBRE: " << homework.getName() << endl;
                    cout << " DESCRIPCION: " << homework.getDescription() << endl;
                    cout << " MATERIA: " << homework.getMatter() << endl;
                    if(error->getDescrition() == "ESTADO") 
                    {
                        cout << " ESTADO (Pendiente, Realizado, Incumplido): ";
                        state = scanner();
                        if ((state== "Incumplido") || (state == "Pendiente") || (state == "Cumplido"))
                        {
                            homeworkController->update_homework(error->getId_homework(), "", "", "", "", state);
                            errorController->delete_error(error->getId());
                        } 
                    } else if(error->getDescrition() == "FECHA") 
                    {
                        cout << " FECHA: ";
                        date = scanner();

                        if(homeworkController->is_date_valid(date)) 
                        {
                            homeworkController->update_homework(error->getId_homework(), "", "", "", date, "");
                            errorController->delete_error(error->getId());
                        } 
                    }
                }
                this->stop();
                clear();
                cout << endl;
                print_info();
                cout << endl;
                print_menu_options();

                cout << " DECEA SEGUIR ARREGLANDO ERRORES (s/n): ";
                option = scanner();
                cout << " ____________________________________________________________________________________" << endl;
            } else {
                cout << " NO HAY MAS ERRORES PARA ARREGLAR." << endl;
                flag = false;
            }

        } while (flag && option == "s");
        

    } else {
        cout << " ERROR OPCION INGRESADA NO VALIDA." << endl;
    }

}