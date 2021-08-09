#include "StudentController.h"

// CONSTRUCTOR VACIO
StudentController::StudentController()
{

}

StudentController* StudentController::instance = 0;

StudentController* StudentController::getInstance()
{
    if (instance == 0)
    {
        instance = new StudentController();
    }

    return instance;
}

// DESTRUCTOR
StudentController::~StudentController() {}

string* StudentController::split(string line) 
{
    string *elements = new string[8];
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


string StudentController::replace(string line) 
{
    string elements = "";
    int start = 0;
    int end1 = 0;
    bool flag = true;
    const regex pattern("\\w");
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

void StudentController::print_student() 
{
    Student student;
    DoubleLinkedNode<Student> *current = new DoubleLinkedNode<Student>();
    DoubleLinkedNode<Student> *temp = first;
	current = first;

	if(first != NULL){
		do{
            //cout << current->element.getCarne() << "," << current->element.getDpi() << "," << current->element.getName() << "," << current->element.getCareer() << "," << current->element.getPassword() << ","  << current->element.getCredits() << "," << current->element.getAge() << "," << current->element.getMail() << endl;
            cout << current->before->element.getDpi() << " <- " << current->element.getDpi() << " -> " << current->after->element.getDpi() << endl;
			current = current->after;
		} while(current!=first);
	}else{
		cout << "\nLISTA VACIA\n";
	}
}

Student StudentController::find_student(string dpi) 
{
    Student student;
    DoubleLinkedNode<Student> *current = new DoubleLinkedNode<Student>();
	current = first;

	if(first != NULL){
		do{
            if(current->element.getDpi() == dpi) 
            {
                return current->element;
            }
			current = current->after;
		} while(current!=first);
	}else{
		cout << "\nLISTA VACIA\n";
	}

    return student;
}

void StudentController::add_student(string carne, string dpi, string name, string career, string password, string credits, string age, string mail) 
{
    Student student;
    bool flag = true;

    if(carne.length() == 9) 
    {
        student.setCarne(stoi(carne));
    } else {
        flag = false;
    }

    if(dpi.length() == 13) 
    {
        student.setDpi(dpi);
    } else {
        flag = false;
    }

    if(this->is_email_valid(mail)) 
    {
        student.setMail(mail);
    } else {
        flag = false;
    }
   
    if(flag) 
    {
        student.setName(name);
        student.setCareer(career);
        student.setPassword(password);
        student.setCredits(stoi(credits));
        student.setAge(stoi(age));
        add(student);
        cout << "SE INGRESO LA INFORMACION DEL ESTUDIANTE." << endl;
    } else {
        cout << "ERROR NO SE LOGRO INGRESAR EL ESTUDIANTE." << endl;
    }
}

void StudentController::update_student(string dpi, string carne  = "", string name  = "", string career = "", string password = "", string credits = "", string age = "", string mail = "") 
{
    DoubleLinkedNode<Student> *current = new DoubleLinkedNode<Student>();
	current = first;
    bool flag = true;

    if(first != NULL){
		do{
            if(current->element.getDpi() == dpi) 
            {
                flag = false;
                if (carne != "")
                {
                    if(carne.length() == 9) 
                    {
                        current->element.setCarne(stoi(carne));
                    } else {
                        cout << "ERROR CARNE SOLO ACEPTA 9 DIGITOS" << endl;
                    }  
                }

                if (name != "") {
                    current->element.setName(name);
                }

                if (career != "") {
                    current->element.setCareer(career);
                }

                if (password != "") {
                    current->element.setPassword(password);
                }

                if (credits != "") {
                    current->element.setCredits(stoi(credits));
                }

                if (age != "") {
                    current->element.setAge(stoi(age));
                }

                if (mail != "") {
                    if(this->is_email_valid(mail)) 
                    {
                        current->element.setMail(mail);
                    } else {
                        cout << "ERROR FORMATO DE CORREO." << endl;
                    }
                }
            }
			current = current->after;
		} while(current!=first);
	}else{
		cout << "\nLISTA VACIA\n";
	}

    if(flag) 
    {
        cout << "NO SE ENCONTRO EL DPI DEL ESTUDIANTE." << endl;
    }
}

void StudentController::delete_student(string dpi) 
{
    DoubleLinkedNode<Student> *current = first;
    DoubleLinkedNode<Student> *next = first->after;
    DoubleLinkedNode<Student> *last = first->before;

    if(first->element.getDpi() == dpi) 
    {
        cout << endl;
        first = current->after;
        last->after = first;
        first->before = last;
    }
    else if(last->element.getDpi() == dpi) 
    {
        cout << "ELEMENTO ELIMINADO: " << last->element.getDpi() << ", ELEMENTO ANTERIOR: " << last->before->element.getDpi() << ", ELEMENTO SOGUIENTE: " << last->after->element.getDpi() << endl;
        cout << endl;
        last->before->after = first;
        first->before = last->before;
        delete last;
    }else {
        do
        {
            if(current->element.getDpi() == dpi) 
            {
                DoubleLinkedNode<Student> *aux_node1 = next;
                DoubleLinkedNode<Student> *aux_node2 = current;
                current->after->before = current->before;
                current->before->after = next;
                delete aux_node2;
                index--;
                current = first;
            }
            current = current->after;
            next = next->after;
        } while (current != first);
    }
}

void StudentController::massive_charge() 
{
    ifstream file("/home/jafb/Documents/PROYECTS/C++ PROYECTS/EDD_SmartClass_201801287/ARCHIVOS DE PRUEBA/Estudiantes.csv", ios::in);
    if (!file.is_open())
    {
        cout << "Error" << endl;
    } else {
        string line;
        getline(file, line);
        while (getline(file, line))
        {//Carnet,DPI,Nombre,Carrera,Password,Creditos,Edad,Correo
            string *elements = split(line);
            //cout << elements[0] << "," << elements[1] << "," << elements[2] << "," << elements[3] << "," << elements[4] << ","  << elements[5] << "," << elements[6] << "," << elements[7] << endl;
            this->add_student(elements[0], elements[1], elements[2], elements[3], elements[4], elements[5], elements[6], elements[7]);
        }
    }
}


bool StudentController::is_email_valid(string& email)
{
   // define a regular expression
   const regex pattern("(\\w+)(\\.|_)?(\\w*)@(\\w+)(\\.)(com|es|org)( )*(\\n)*");

   // try to match the string with the regular expression
   return regex_match(email, pattern);
}