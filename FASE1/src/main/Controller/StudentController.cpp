#include "StudentController.h"

// CONSTRUCTOR VACIO
StudentController::StudentController()
{
    this->id_report = 0;
    this->id_code = 0;
    errorController = ErrorController::getInstance();
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

string StudentController::remove_line_breaks(string line) 
{
    string elements = "";
    int start = 0;
    int end1 = 0;
    bool flag = true;
    for (int i = 0; i <= line.length(); i++)
    {
        if((line[i] == '\r')) 
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
		cout << "\n LISTA VACIA\n";
	}

    return student;
}

bool StudentController::find_student(int carne) 
{
    Student student;
    DoubleLinkedNode<Student> *current = new DoubleLinkedNode<Student>();
	current = first;

	if(first != NULL){
		do{
            if(current->element.getCarne() == carne) 
            {
                return true;
            }
			current = current->after;
		} while(current!=first);
	}
    
    return false;
}

void StudentController::add_student(string carne, string dpi, string name, string career, string password, string credits, string age, string mail) 
{
    Student student;
    bool flag = true;
    bool error_mail = false;

    if(carne.length() == 9) 
    {
        student.setCarne(stoi(carne));
    } else {
        cout << " ERROR CARNE." << endl;
        flag = false;
    }

    if(dpi.length() == 13) 
    {
        student.setDpi(dpi);
    } else {
        cout << " ERROR DPI." <<endl;
        flag = false;
    }

    if(this->is_email_valid(mail)) 
    {
        student.setMail(mail);
    } else {
        error_mail = true;
    }
   
    if(flag) 
    {
        student.setName(name);
        student.setCareer(career);
        student.setPassword(password);
        student.setCredits(stoi(credits));
        student.setAge(stoi(age));
        add(student);

        if(error_mail) 
        {
            errorController->add_error("ESTUDIANTE", "CORREO", 0, student.getDpi());
            cout << " SE INGRESO LA INFORMACION DEL ESTUDIANTE. (ERROR EN CORREO)" << endl;
        } else {
            cout << " SE INGRESO LA INFORMACION DEL ESTUDIANTE." << endl;
        }
        
    } else {
        cout << " ERROR NO SE LOGRO INGRESAR EL ESTUDIANTE." << endl;
    }
    cout << endl;
}

void StudentController::add_student1(string line) 
{
    string *elements = split(line);
    cout << elements[0] << "," << elements[1] << "," << elements[2] << "," << elements[3] << "," << elements[4] << ","  << elements[5] << "," << elements[6] << "," << elements[7] << endl;
    this->add_student(elements[0], elements[1], elements[2], elements[3], elements[4], elements[5], elements[6], elements[7]);
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
                        cout << " ERROR CARNE SOLO ACEPTA 9 DIGITOS" << endl;
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
                        cout << " ERROR FORMATO DE CORREO." << endl;
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
    bool flag = false;

    if(first->element.getDpi() == dpi) 
    {
        cout << endl;
        first = current->after;
        last->after = first;
        first->before = last;

        flag = true;
    }
    else if(last->element.getDpi() == dpi) 
    {
        //cout << "ELEMENTO ELIMINADO: " << last->element.getDpi() << ", ELEMENTO ANTERIOR: " << last->before->element.getDpi() << ", ELEMENTO SOGUIENTE: " << last->after->element.getDpi() << endl;
        //cout << endl;
        last->before->after = first;
        first->before = last->before;
        delete last;

        flag = true;
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

                flag = true;
            }
            current = current->after;
            next = next->after;
        } while (current != first);
    }

    if(flag) 
    {
        cout << " SE ELIMINO EL ELEMENTO." << endl;
    } else {
        cout << " ERROR NO SE LOGRO ENCONTRAR EL ELEMENTO." << endl;
    }
}

void StudentController::massive_charge(string path) 
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
                cout << elements[0] << "," << elements[1] << "," << elements[2] << "," << elements[3] << "," << elements[4] << ","  << elements[5] << "," << elements[6] << "," << elements[7] << endl;
                this->add_student(elements[0], elements[1], elements[2], elements[3], elements[4], elements[5], elements[6], elements[7]);
            }
        }
    }
    catch(std::ifstream::failure e)
    {
        std::cerr << e.what() << '\n';
    }
}

void StudentController::report_student() 
{
    int id = 0;
    ofstream file;
    string diagram = "\tgraph [\n\t\trankdir = \"LR\"\n\t];\n\n\tnode [\n\t\tfontsize = \"16\"\n\t\tshape = \"ellipse\"\n\t];\n\n\tedge [\n\t];\n\n";
    Student student;
    DoubleLinkedNode<Student> *current = new DoubleLinkedNode<Student>();
    DoubleLinkedNode<Student> *temp = first;
	current = first;

	if(first != NULL){
		do{
            cout << current->element.getCarne() << "," << current->element.getDpi() << "," << current->element.getName() << "," << current->element.getCareer() << "," << current->element.getPassword() << ","  << current->element.getCredits() << "," << current->element.getAge() << "," << current->element.getMail() << endl;
            
            diagram += "\t\"" + current->element.getDpi() + "\" [\n";
            diagram += "\t\tlabel = \"<f0> CARNE: " + to_string(current->element.getCarne()) + "| ";
            diagram += "<f1> DPI: " + current->element.getDpi() +"| ";
            diagram += "<f2> NOMBRE: " + current->element.getName() + "| ";
            diagram += "<f3> CARRERA: " + current->element.getCareer() + "| ";
            diagram += "<f4> PASSWORD: " + current->element.getPassword() + "| ";
            diagram += "<f5> CREDITOS: " + to_string(current->element.getCredits()) + "| ";
            diagram += "<f6> EDAD: " + to_string(current->element.getAge()) + "| ";
            diagram += "<f7> CORREO ELECTRONICO: " + current->element.getMail() + "\"\n";
            diagram += "\tshape = \"record\"\n\t];\n\n";

            diagram += "\t\"" + current->element.getDpi() + "\":f3 -> \"" + current->after->element.getDpi() + "\":f3 [\n";
            diagram += "\t\tid = " + to_string(id) + "\n\t];\n\n";
            id++;

            diagram += "\t\"" + current->element.getDpi() + "\":f4 -> \"" + current->before->element.getDpi() + "\":f4 [\n";
            diagram += "\t\tid = " + to_string(id) + "\n\t];\n\n";
            id++;

			current = current->after;
		} while(current!=first);
	}else{
		cout << "\nLISTA VACIA\n";
	}

    diagram = "digraph g {\n" + diagram + "}";
    string comando1 = "dot -Tpng -o StudentReport/StudentReport" + to_string(this->id_report) + ".png StudentReport/StudentReport" + to_string(this->id_report) + ".dot";
    string comando2 = "mimeopen -d StudentReport/StudentReport" + to_string(this->id_report) + ".png";
    char cmd1[comando1.size() + 1];
    strcpy(cmd1, comando1.c_str());
    char cmd2[comando2.size() + 1];
    strcpy(cmd2, comando2.c_str());

    file.open("StudentReport/StudentReport" + to_string(this->id_report) + ".dot", ios::out);

    if(file.fail()) 
    {
        cout << "NO SE ENCONTRO EL ARCHIVO" << endl;
        file.close();
    } else {
        file << diagram;
        file.close();
        system(cmd1);
        system(cmd2);
        this->id_report++;
    }
} 

void StudentController::generated_code() 
{
    ofstream file;
    string diagram = "";
    DoubleLinkedNode<Student> *current = new DoubleLinkedNode<Student>();
	current = first;

	if(first != NULL){
		do{        
            diagram += "\t¿element type=\"user\"?\n";
            diagram += "\t\t¿item Carnet = \"" + to_string(current->element.getCarne()) + "\" $?\n";
            diagram += "\t\t¿item DPI = \"" + current->element.getDpi() + "\" $?\n";
            diagram += "\t\t¿item Nombre = \"" + current->element.getName() + "\" $?\n";
            diagram += "\t\t¿item Carrera = \"" + current->element.getCareer() + "\" $?\n";
            diagram += "\t\t¿item Password = \"" + current->element.getPassword() + "\" $?\n";
            diagram += "\t\t¿item Creditos = " + to_string(current->element.getCredits()) + " $?\n";
            diagram += "\t\t¿item Edad = " + to_string(current->element.getAge()) + " $?\n";
            diagram += "\t\t¿item Correo = \"" + current->element.getMail() + "\" $?\n";
            diagram += "\t¿$element?\n\n";

			current = current->after;
		} while(current!=first);
	}else{
		cout << "\nLISTA VACIA\n";
	}

    diagram = "¿Elements?\n\n" + diagram + "¿$Elements?";

    file.open("Generated Code/Student" + to_string(this->id_code) + ".txt", ios::out);

    if(file.fail()) 
    {
        cout << "NO SE ENCONTRO EL ARCHIVO" << endl;
        file.close();
    } else {
        file << diagram;
        file.close();
        this->id_code++;
    }
} 

bool StudentController::is_email_valid(string& email)
{
   const regex pattern("(\\w+)(\\.|_)?(\\w*)@(\\w+)(\\.)(com|es|org)( )*(\\n)*");

   return regex_match(email, pattern);
}