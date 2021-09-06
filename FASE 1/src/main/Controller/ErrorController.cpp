#include "ErrorController.h"

// CONSTRUCTOR VACIO
ErrorController::ErrorController()
{
    this->id_report = 1;
    this->id_error = 0;
}

ErrorController* ErrorController::instance = 0;

ErrorController* ErrorController::getInstance()
{
    if (instance == 0)
    {
        instance = new ErrorController();
    }

    return instance;
}

// DESTRUCTOR
ErrorController::~ErrorController() {}

int ErrorController::getIndex() 
{
    return index;
}

Error* ErrorController::getFirst() 
{
    if(first != NULL) 
    {
        return &first->element;
    }
    return NULL;
}

void ErrorController::add_error(string type, string description, int id_homework, string dpi) 
{
    Error error;
    error.setId(id_error);
    error.setType(type);
    error.setDescription(description);
    error.setId_homework(id_homework);
    error.setDpi(dpi);
    add(error);
    id_error++;
}

void ErrorController::delete_error(int id) 
{
    Node<Error> *current = first;
    Node<Error> *before = NULL;

    if(first != NULL) 
    {
        if(first->element.getId() == id) 
        {
            Node<Error> *temp = first;
            first = first->after;
            delete temp;
        } else {
            while (current != NULL)
            {
                if(current->element.getId() == id) 
                {
                    Node<Error> *temp = current;
                    before->after = current->after;
                    delete temp;
                }
                before = current;
                current = current->after;
            }
            
        }
    } else {
        cout << " \nLISTA VACIA\n";
    }
}


void ErrorController::report_error() 
{
    int id = 0;
    ofstream file;
    string diagram = "\tgraph [\n\t\trankdir = \"LR\"\n\t];\n\n\tnode [\n\t\tfontsize = \"16\"\n\t\tshape = \"ellipse\"\n\t];\n\n\tedge [\n\t];\n\n";
    Error error;
    Node<Error> *current = new Node<Error>();
    Node<Error> *temp = first;
	current = first;

	if(first != NULL){
		while(current) {
            cout << current->element.getId() << "," << current->element.getType() << "," << current->element.getDescrition() << endl;
            
            diagram += "\t\"" + to_string(current->element.getId()) + "\" [\n";
            diagram += "\t\tlabel = \"<f0> ID: " + to_string(current->element.getId()) + "| ";
            diagram += "<f1> TIPO: " + current->element.getType() +"| ";
            diagram += "<f2> DESCRIPCION: " + current->element.getDescrition() + "\"\n";
            diagram += "\tshape = \"record\"\n\t];\n\n";

            if(current->after != NULL) 
            {
                diagram += "\t\"" + to_string(current->element.getId()) + "\":f1 -> \"" + to_string(current->after->element.getId()) + "\":f1 [\n";
                diagram += "\t\tid = " + to_string(id) + "\n\t];\n\n";
                id++;
            }
			current = current->after;
		} 
	}else{
		cout << "\nLISTA VACIA\n";
	}

    diagram = "digraph g {\n" + diagram + "}";
    string comando1 = "dot -Tpng -o ErrorReport/ErrorReport" + to_string(this->id_report) + ".png ErrorReport/ErrorReport" + to_string(this->id_report) + ".dot";
    string comando2 = "mimeopen -d ErrorReport/ErrorReport" + to_string(this->id_report) + ".png";
    char cmd1[comando1.size() + 1];
    strcpy(cmd1, comando1.c_str());
    char cmd2[comando2.size() + 1];
    strcpy(cmd2, comando2.c_str());

    file.open("ErrorReport/ErrorReport" + to_string(this->id_report) + ".dot", ios::out);

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