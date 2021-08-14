#include "HomeworkController.h"

// CONSTRUCTOR VACIO
HomeworkController::HomeworkController()
{
    this->index = 0;
    this->id_report = 0;
    this->id_code = 0;
    studentController = StudentController::getInstance();
    errorController = ErrorController::getInstance();
    this->init_matriz();
}

HomeworkController* HomeworkController::instance = 0;

HomeworkController* HomeworkController::getInstance()
{
    if (instance == 0)
    {
        instance = new HomeworkController();
    }

    return instance;
}

// DESTRUCTOR
HomeworkController::~HomeworkController() {}

string* HomeworkController::split(string line) 
{
    string *elements = new string[9];
    int cont = 0;
    string delimiter = ",";
    int start = 0;
    int end = line.find(delimiter);
    while (end != -1) {
        elements[cont] = line.substr(start, end - start);
        start = end + delimiter.size();
        end = line.find(delimiter, start);
        cont++;
    }
    string temp = (line.substr(start, end - start));
    temp = this->replace(temp);
    elements[cont] = temp;

    return elements;
}

void HomeworkController::init_matriz()
{
    int month = 5;
    int day = 30; // COLUMN
    int hour = 9; // ROW
    for (int z = 0; z < month; z++)
    {
        for (int x = 0; x < day; x++)
        {
            for (int y = 0; y < hour; y++)
            { 
                this->matriz[z][x][y] = NULL;
            }
        }
    }
}

string HomeworkController::replace(string line) 
{
    string elements = "";
    int start = 0;
    int end1 = 0;
    bool flag = true;
    for (int i = 0; i <= line.length(); i++)
    {
        if((line[i] == '\r') || (line[i] == ' ')) 
        {
            end1 = i;
            flag = false;
            i = line.length();
        }
    }

    if(flag) 
    {
        elements = line;
    } else {
        elements = line.substr(start, end1);
        
    } 
    return elements; 
}

void HomeworkController::add_matriz(Homework homework, int month, int day, int hour) 
{
    bool flag = true;
    bool error_state = false;
    bool error_date = false;

    if(this->matriz[month-7][day-1][hour-8] == NULL) 
    {
        cout << " ESPACIO VACIO." << endl;
    } else {
        flag = false;
        cout << " ERROR EL ESPACIO YA ESTA OCUPADO." << endl;
    }

    if(studentController->find_student(homework.getCarne())) 
    {
        cout << " CARNE VALIDO." << endl;
    } else {
        flag = false;
        cout << " ERROR CARNE NO PERTENECE A NINGUN ESTUDIANTE." << endl;
    }

    if((month-7) >=0 && (month-7) <=4 && (day-1) >= 0 && (day-1) <= 29 && (hour-8) >= 0 && (hour-8) <= 8) 
    {
        cout << " FORMATO DE MES, DIA O HORA ES ACEPTADO." << endl;
    } else {
        flag = false;
        cout << " ERROR FORMATO DE MES, DIA O HORA ES INCORRECTO." << endl;
    }

    if ((homework.getState() == "Incumplido") || (homework.getState() == "Pendiente") || (homework.getState() == "Cumplido"))
    {
        cout << " FORMATO DE ESTADO ACEPTADO." << endl;
    } else {
        error_state = true;
        cout << " ERROR FORMATO DE ESTADO INCORRECTO." << endl;
    }

    string date = homework.getDate(); 
    if(is_date_valid(date)) 
    {
        cout << " FORMATO DE FECHA ACEPTADO." << endl;
    } else {
        error_date = true;
        cout << " ERROR FORMATO DE FECHA INCORRECTO." << endl;
    }
    
    if (flag)
    {
        this->index++;
        homework.setId(this->index);
        this->matriz[month-7][day-1][hour-8] = &homework;
        add_homework(homework);
        cout << " SE INGRESO LA INFORMACION DEL ESTUDIANTE.";
        if(error_state) 
        {
            errorController->add_error("TAREA", "ESTADO", homework.getId(), "");
            cout << "  (ERROR EN ESTADO)";
        } 

        if(error_date) 
        {
            errorController->add_error("TAREA", "FECHA", homework.getId(), "");
            cout << "  (ERROR EN FECHA)";
        } 
        cout << endl;
    } else {
        cout << " ERROR NO SE LOGRO INGRESAR EL ESTUDIANTE." << endl;
    }
    cout << endl;
}

void HomeworkController::delete_homework(int month, int day, int hour)
{
    DoubleLinkedNode1<Homework>* current = new DoubleLinkedNode1<Homework>();
    current = first;
    DoubleLinkedNode1<Homework>* before = new DoubleLinkedNode1<Homework>();
    before = NULL;
    bool found = false;
    DoubleLinkedNode1<Homework> *temp = first;
    DoubleLinkedNode1<Homework> *last = NULL;

    while (temp != NULL)
    {
        last = temp;
        temp = temp->after;
    }

    if(first != NULL) 
    {
        while (current != NULL && !found)
        {
            if(current->element.getMonth() == month && current->element.getDay() == day && current->element.getHour() == hour) 
            {
                if(current == first) 
                {
                    first = first->after;
                    first->before = NULL;
                } else if (current == last)
                {
                    before->after = NULL;
                    last = before;
                } else {
                    before->after = current->after;
                    current->after->before = before;
                }
                found = true;
                index--;
                this->matriz[month-7][day-1][hour-8] = NULL;
            }
            before = current;
            current = current->after;
        }
        
        if (found)
        {
            cout << " ELEMENTO ELIMINADO DE LA LISTA." << endl;
        } else {
            cout << " ELEMENTO NO ENCONTRADO EN LA LISTA." << endl;
        }
        
    } else {
        cout << " LISTA VACIA" << endl;
    }
}

bool HomeworkController::find_homework(int id) 
{
    DoubleLinkedNode1<Homework> *current = new DoubleLinkedNode1<Homework>();

	current = first;
    if(first != NULL)
    {
		while(current != NULL) 
        {
            if (current->element.getId() == id)
            {
                return true;
            }
            
            current = current->after;
        }
    }

    return false;
} 

Homework HomeworkController::find_homework1(int id) 
{
    DoubleLinkedNode1<Homework> *current = new DoubleLinkedNode1<Homework>();
    Homework homework;
	current = first;
    if(first != NULL)
    {
		while(current != NULL) 
        {
            if (current->element.getId() == id)
            {
                return current->element;
            }
            
            current = current->after;
        }
    }

    return homework;
} 

Homework HomeworkController::find_homework(int month, int day, int hour) 
{
    DoubleLinkedNode1<Homework> *current = new DoubleLinkedNode1<Homework>();
    Homework homework;

	current = first;
    if(first != NULL)
    {
		while(current != NULL) 
        {
            if (current->element.getMonth() == month && current->element.getDay() == day && current->element.getHour() == hour)
            {
                return current->element;
            }
            
            current = current->after;
        }
    }

    return homework;
} 

bool HomeworkController::position_homework(int month, int day, int hour) 
{
    DoubleLinkedNode1<Homework> *current = new DoubleLinkedNode1<Homework>();
    int position = 1;

	current = first;
    if(first != NULL)
    {
		while(current != NULL) 
        {
            if (current->element.getMonth() == month && current->element.getDay() == day && current->element.getHour() == hour)
            {
                cout << " POSICION EN LISTA: " << position << endl;
                return true;
            }
            position++;
            current = current->after;
        }
    }

    return false;
} 

void HomeworkController::update_homework(int id, string name, string description, string matter, string date, string state) 
{
    DoubleLinkedNode1<Homework> *current = new DoubleLinkedNode1<Homework>();

	current = first;
    if(first != NULL)
    {
		while(current != NULL) 
        {
            if(current->element.getId() == id) 
            {
                if (name != "") 
                {
                    current->element.setName(name);
                }

                if (description != "") 
                {
                    current->element.setName(name);
                }

                if (matter != "") 
                {
                    current->element.setName(name);
                }

                if (date != "") 
                {
                    if(!is_date_valid(date)) 
                    {
                        current->element.setDate(date);
                    } else {
                        cout << " ERROR FORMATO DE FECHA INCORRECTO." << endl;
                    }
                }

                if (state != "") 
                {
                    if ((state== "Incumplido") || (state == "Pendiente") || (state == "Cumplido"))
                    {
                        current->element.setName(name);
                    } else {
                        cout << " ERROR FORMATO DE ESTADO INCORRECTO." << endl;
                    }
                }
                this->matriz[current->element.getMonth()-7][current->element.getDay()-1][current->element.getHour()-8] = &current->element;
            }
            
            current = current->after;
        }
    }

} 

bool HomeworkController::add_homework(Homework homework) 
{
    int month = 5;
    int day = 30; // COLUMN
    int hour = 9; // ROW

    for (int z = 0; z < month; z++)
    {
        for (int x = 0; x < day; x++)
        {
            for (int y = 0; y < hour; y++)
            {
                if (this->matriz[z][x][y] != NULL && this->matriz[z][x][y]->getId() == homework.getId())
                {
                    add(homework);
                    return true;
                }
                
            }
        }
    }
    return false;
} 

void HomeworkController::massive_charge(string path) 
{
    try
    {
        ifstream file(path, ios::in);
        if (!file.is_open())
        {
            cout << " ERROR ARCHIVO NO ENCONTRADO." << endl;
        } else {
            string line;
            getline(file, line);
            while (getline(file, line))
            {
                string *elements = split(line);
                cout << elements[0] << "," << elements[1] << "," << elements[2] << "," << elements[3] << "," << elements[4] << ","  << elements[5] << "," << elements[6] << "," << elements[7] <<"," << elements[8] << endl;
                Homework homework;
                int month = stoi(elements[0]);
                int day = stoi(elements[1]);
                int hour = stoi(elements[2]);
                homework.setMonth(month);
                homework.setDay(day);
                homework.setHour(hour);
                homework.setCarne(stoi(elements[3]));
                homework.setName(elements[4]);
                homework.setDescription(elements[5]);
                homework.setMatter(elements[6]);
                homework.setDate(elements[7]);
                homework.setState(elements[8]);
                add_matriz(homework, month, day, hour); 
            }
        }
    }
    catch(std::ifstream::failure e)
    {
        std::cerr << e.what() << '\n';
    }
}

bool HomeworkController::is_date_valid(string& date)
{
   // define a regular expression
   const regex pattern("\\d{4}\\/(0?[1-9]|1[012])\\/(0[1-9]|[12][0-9]|3[01])");

   // try to match the string with the regular expression
   return regex_match(date, pattern);
}


void HomeworkController::report_homework() 
{
    int id = 0;
    ofstream file;
    string diagram = "\tgraph [\n\t\trankdir = \"LR\"\n\t];\n\n\tnode [\n\t\tfontsize = \"16\"\n\t\tshape = \"ellipse\"\n\t];\n\n\tedge [\n\t];\n\n";
    Homework homework;
    DoubleLinkedNode1<Homework> *current = new DoubleLinkedNode1<Homework>();
    DoubleLinkedNode1<Homework> *temp = first;
	current = first;

	if(first != NULL){
		while(current != NULL){
            diagram += "\t\"" + to_string(current->element.getId()) + "\" [\n";
            diagram += "\t\tlabel = \"<f0> ID: " + to_string(current->element.getId()) + "| ";
            diagram += "<f1> CARNE: " + to_string(current->element.getCarne()) + "| ";
            diagram += "<f2> NOMBRE: " + current->element.getName() + "| ";
            diagram += "<f3> DESCRIPCION: " + current->element.getDescription() + "| ";
            diagram += "<f4> MATERIA: " + current->element.getMatter() + "| ";
            diagram += "<f5> FECHA: " + current->element.getDate() + "\"\n";
            diagram += "\tshape = \"record\"\n\t];\n\n";

            if(current->before != NULL && current != first) 
            {
                diagram += "\t\"" + to_string(current->element.getId())  + "\":f3 -> \"" + to_string(current->before->element.getId()) + "\":f3 [\n";
                diagram += "\t\tid = " + to_string(id) + "\n\t];\n\n";
                id++;
            }

            if(current->after != NULL) 
            {
                diagram += "\t\"" + to_string(current->element.getId())  + "\":f2 -> \"" + to_string(current->after->element.getId()) + "\":f2 [\n";
                diagram += "\t\tid = " + to_string(id) + "\n\t];\n\n";
                id++;
            }
            

			current = current->after;
		}
	}else{
		cout << "\nLISTA VACIA\n";
	}

    diagram = "digraph g {\n" + diagram + "}";
    string comando1 = "dot -Tpng -o HomeworkReport/HomeworkReport" + to_string(this->id_report) + ".png HomeworkReport/HomeworkReport" + to_string(this->id_report) + ".dot";
    string comando2 = "mimeopen -d HomeworkReport/HomeworkReport" + to_string(this->id_report) + ".png";
    char cmd1[comando1.size() + 1];
    strcpy(cmd1, comando1.c_str());
    char cmd2[comando2.size() + 1];
    strcpy(cmd2, comando2.c_str());

    file.open("HomeworkReport/HomeworkReport" + to_string(id_report) + ".dot", ios::out);

    if(file.fail()) 
    {
        cout << "NO SE ENCONTRO EL ARCHIVO" << endl;
        file.close();
    } else {
        file << diagram;
        file.close();
        system(cmd1);
        system(cmd2);
        id_report++;
    }
} 


void HomeworkController::generated_code() 
{
    ofstream file;
    string diagram = "";
    Homework homework;
    DoubleLinkedNode1<Homework> *current = new DoubleLinkedNode1<Homework>();
	current = first;

	if(first != NULL){
		while(current != NULL){
            diagram += "\t¿element type=\"task\"?\n";
            diagram += "\t\t¿item Carnet = \"" + to_string(current->element.getCarne()) + "\" $?\n";
            diagram += "\t\t¿item Nombre = \"" + current->element.getName() + "\" $?\n";
            diagram += "\t\t¿item Descripcion = \"" + current->element.getDescription() + "\" $?\n";
            diagram += "\t\t¿item Materia = \"" + current->element.getMatter() + "\" $?\n";
            diagram += "\t\t¿item Fecha = \"" + current->element.getDate() + "\" $?\n";
            diagram += "\t\t¿item Hora = \"" + to_string(current->element.getHour()) + ":00\" $?\n";
            diagram += "\t\t¿item Estado = \"" + current->element.getState() + "\" $?\n";
            diagram += "\t¿$element?\n\n";

			current = current->after;
		}
	}else{
		cout << "\nLISTA VACIA\n";
	}

    diagram = "¿Elements?\n\n" + diagram + "¿$Elements?";

    file.open("Generated Code/Homework" + to_string(id_code) + ".txt", ios::out);

    if(file.fail()) 
    {
        cout << "NO SE ENCONTRO EL ARCHIVO" << endl;
        file.close();
    } else {
        file << diagram;
        file.close();
        id_code++;
    }
} 