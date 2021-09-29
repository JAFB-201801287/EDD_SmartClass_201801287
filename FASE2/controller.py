# -*- coding: utf-8 -*-
import json
from os import system
import re
import calendar
from sys import flags
import graphviz
from graphviz import nohtml

from model import Node, Semester, Student, Reminder, Year, Month, Course
from list import BTree, DoubleLinkedList, LinkedList, AVLTree, SparseMatrix

def fileReader(address = ""):
    data = ""
    with open(address, "r", encoding="utf-8") as f: 
        for line in f.readlines():
            data += line.replace("\n", " ")
    return data

def dicReader(dic, keyValue):
    for key, value in dic.items():
        if(key.lower() == keyValue.lower()):
            return value
    return None
        

# CLASE STUDENT CONTROLLER ----------------------------------------------------------------------------------------------
class StudentController(object):
    __instance = None
    avlTree = AVLTree()

    # SINGLETON
    @staticmethod
    def __new__(cls):
        if StudentController.__instance is None:
            StudentController.__instance = object.__new__(cls)
        return StudentController.__instance

    def bulkLoad(self, address, isStudent, isReminder, isCurse, value = None):
        if(value is None):
            data = fileReader(address)
        
        if(isStudent or isReminder):
            match = re.match("\¿Elements\?(?P<content>(.)*)\¿\$Elements\?", data)

            if(match != None):
                studentsMatch = re.findall("\¿element[\s|\n]*type[\s|\n]*=[\s|\n]*\"user\"[\s|\n]*\?(?P<content>(.|\n)*?)\¿\$element\?", match.group("content").strip())
                reminderMatch = re.findall("\¿element[\s|\n]*type[\s|\n]*=[\s|\n]*\"task\"[\s|\n]*\?(?P<content>(.|\n)*?)\¿\$element\?", match.group("content").strip())

                for student in studentsMatch:
                    carne = re.findall("\¿[\s|\n]*item[\s|\n]*Carnet[\s|\n]*=[\s|\n]*\"(?P<content>[0-9]+)\"[\s|\n]*\$\?", student[0])
                    dpi = re.findall("\¿[\s|\n]*item[\s|\n]*DPI[\s|\n]*=[\s|\n]*\"(?P<content>[0-9]+)\"[\s|\n]*\$\?", student[0])
                    name = re.findall("\¿[\s|\n]*item[\s|\n]*Nombre[\s|\n]*=[\s|\n]*\"(?P<content>[^\"]+)\"[\s|\n]*\$\?", student[0])
                    career = re.findall("\¿[\s|\n]*item[\s|\n]*Carrera[\s|\n]*=[\s|\n]*\"(?P<content>[^\"]+)\"[\s|\n]*\$\?", student[0])
                    email = re.findall("\¿[\s|\n]*item[\s|\n]*Correo[\s|\n]*=[\s|\n]*\"(?P<content>[^\"]+)\"[\s|\n]*\$\?", student[0]) 
                    password = re.findall("\¿[\s|\n]*item[\s|\n]*Password[\s|\n]*=[\s|\n]*\"(?P<content>[^\"]+)\"[\s|\n]*\$\?", student[0]) 
                    credits = re.findall("\¿[\s|\n]*item[\s|\n]*Creditos[\s|\n]*=[\s|\n]*(?P<content>[0-9]+)[\s|\n]*\$\?", student[0]) 
                    age = re.findall("\¿[\s|\n]*item[\s|\n]*Edad[\s|\n]*=[\s|\n]*(?P<content>[0-9]+)[\s|\n]*\$\?", student[0])

                    self.add(int(carne[0]), dpi[0], name[0], career[0], email[0], password[0], credits[0], age[0])

                for reminder in reminderMatch:
                    carne = re.findall("\¿[\s|\n]*item[\s|\n]*Carnet[\s|\n]*=[\s|\n]*\"(?P<content>[0-9]+)\"[\s|\n]*\$\?", reminder[0])
                    name = re.findall("\¿[\s|\n]*item[\s|\n]*Nombre[\s|\n]*=[\s|\n]*\"(?P<content>[^\"]+)\"[\s|\n]*\$\?", reminder[0])
                    description = re.findall("\¿[\s|\n]*item[\s|\n]*Descripcion[\s|\n]*=[\s|\n]*\"(?P<content>[^\"]+)\"[\s|\n]*\$\?", reminder[0])
                    subject = re.findall("\¿[\s|\n]*item[\s|\n]*Materia[\s|\n]*=[\s|\n]*\"(?P<content>[^\"]+)\"[\s|\n]*\$\?", reminder[0])
                    date = re.findall("\¿[\s|\n]*item[\s|\n]*Fecha[\s|\n]*=[\s|\n]*\"(?P<content>[^\"]+)\"[\s|\n]*\$\?", reminder[0])
                    hour = re.findall("\¿[\s|\n]*item[\s|\n]*Hora[\s|\n]*=[\s|\n]*\"(?P<content>[^\"]+)\"[\s|\n]*\$\?", reminder[0])
                    state = re.findall("\¿[\s|\n]*item[\s|\n]*Estado[\s|\n]*=[\s|\n]*\"(?P<content>[^\"]+)\"[\s|\n]*\$\?", reminder[0])

                    self.addReminder(int(carne[0]), name[0], description[0], subject[0], date[0], hour[0], state[0])
        if(isCurse):
            if(value is None):
                value = json.loads(data)

            students = dicReader(value, "Estudiantes")

            if(students is not None):
                for student in students:
                    carnet = dicReader(student, "Carnet")
                    years = dicReader(student, "Años")
                    if(years is not None):
                        for value1 in years:
                            year = dicReader(value1, "Año")
                            semesters = dicReader(value1, "Semestres")
                            if(semesters is not None):
                                for value2 in semesters:
                                    semester = dicReader(value2, "Semestre")
                                    courses = dicReader(value2, "Cursos")
                                    if(courses is not None):
                                        for value3 in courses:
                                            code = dicReader(value3, "Codigo")
                                            name = dicReader(value3, "Nombre")
                                            credits = dicReader(value3, "Creditos")
                                            prerequisits = dicReader(value3, "Prerequisitos")
                                            mandatory = dicReader(value3, "Obligatorio")
                                            #print("CARNET:", carnet, "AÑO:", year, "SEMESTRE:", semester, "CODIGO:", code, "NOMBRE:", name)
                                            self.addCourse(int(carnet), int(year), int(semester), int(code), name, int(credits), prerequisits, mandatory)

    def add(self, carne = 0, dpi = "", name = "", career = "", email = "", password = "", credits = 0, age = 0):
        if(self.avlTree is not None) and (self.find(carne) is None):
            student = Student(carne, dpi, name, career, email, password, credits, age, DoubleLinkedList())
            self.avlTree.add(carne, student)
            return True
        return False

    def find(self, carne = 0):
        if(self.avlTree is not None):
            #student = Student()
            student = self.avlTree.find(carne)
            if(student is not None):
                return student.getElement()
        return None

    def update(self, carne = 0, dpi = "", name = "", career = "", email = "", password = "", credits = 0, age = 0):
        student = self.find(carne)
        if(student is not None):
            student.setCarne(carne)
            student.setDpi(dpi)
            student.setName(name)
            student.setCareer(career)
            student.setEmail(email)
            student.setPassword(password)
            student.setCredits(credits)
            student.setAge(age)
            return True
        return False

    def delete(self, carne = 0):
        if(self.avlTree is not None) and (self.find(carne) is not None):
            return self.avlTree.delete(carne)
        return False

    def addYear(self, carne, year):
        student = self.find(carne)
        if(student is not None):
            temp = student.getYearList().find(year)
            if(temp is None):
                temp = Year(year, DoubleLinkedList(), LinkedList())
                student.getYearList().sortedAdd(year, temp)
            return temp
        return None  

    def addSemester(self, carne, year, semester):
        tempyear = self.addYear(carne, year)
        if(tempyear is not None) and (1 <= semester <= 2):
            temp = None
            node = tempyear.getSemesters().getList()
            while(node is not None):
                if(node.getElement().getSemester() == semester):
                    temp = node.getElement()
                node = node.getAfter()

            if(temp is None):
                temp = Semester(semester, BTree()) 
                tempyear.getSemesters().add(temp)
            return temp
        return None   

    def addMonth(self, carne, year, month):
        tempYear = self.addYear(carne, year)
        if(tempYear is not None):
            temp = tempYear.getMonths().find(month)
            if(temp is None) and (month <= 12):
                temp = Month(month, SparseMatrix(calendar.monthrange(year, month)[1], 24))
                tempYear.getMonths().sortedAdd(month, temp)
            return temp
        return None

    def reportCourse(self, carnet, year, semester):
        student = self.find(carnet)

        if(student is not None):
            year = student.getYearList().find(year)
            if(year is not None):
                temp = year.getSemesters().getList()
                aux =  None
                while(temp is not None and aux is None):
                    if(temp.getElement().getSemester() == semester):
                        aux = temp.getElement().getCourses()
                    temp = temp.getAfter()

                if(aux is not None):
                    courseController = CourseController()
                    courseController.report(aux)
    
    def addCourse(self, carne, year, semester, code, name, credits, prerequisits, mandatory):
        semester = self.addSemester(carne, year, semester)

        if(semester is not None) :
            course = Course(code, name, credits, prerequisits, mandatory)
            semester.getCourses().add(code, course)
            return True
        return False

    def addReminder(self, carne = 0, name = "", description = "", subject = "", date = "", hour = 0, state = ""):
        day, month, year = date.split("/")
        temp = self.addMonth(carne, int(year), int(month))
        if(temp is not None):
            reminder = Reminder(carne, name, description, subject, date, hour, state)
            hour = hour.split(":")
            #schedule = temp.getSchedule().findMatrix((int(day)-1), (int(hour[0])-1))
            schedule = temp.getSchedule()

            if(schedule is None):
                temp.setSchedule(Month(month, SparseMatrix(calendar.monthrange(int(year), int(month))[1], 24)))

            reminders = schedule.add((int(day)-1), (int(hour[0])-1), DoubleLinkedList())

            if(reminders is not None):
                reminders.add(reminder)
                schedule.addSparseMatrix()
                return True
            
        return False
        
    def updateReminder(self, carne = 0, name = "", description = "", subject = "", date = "", hour = "", state = "", position = 0):
        student = self.find(carne)
        day, month, year = date.split("/")

        if(student is not None):
            year = student.getYearList().find(int(year))
            if(year is not None):
                tempMonth = year.getMonths().find(int(month))
                tempHour = hour.split(":")

                if(tempMonth is not None):
                    schedule = tempMonth.getSchedule().findMatrix((int(day)-1), (int(tempHour[0])-1))
                    if(schedule is not None):
                        reminder = schedule.findPosition(position)
                        if(reminder is not None):
                            reminder.setCarne(carne)
                            reminder.setName(name)
                            reminder.setDescription(description)
                            reminder.setSubject(subject)
                            reminder.setDate(date)
                            reminder.setHour(hour)
                            reminder.setState(state)
                            tempMonth.getSchedule().addSparseMatrix()
                            return reminder
        return None

    def deleteReminder(self, carne, year, month, day, hour, position):
        student = self.find(carne)

        if(student is not None):
            year = student.getYearList().find(year)
            if(year is not None):
                month = year.getMonths().find(month)
                schedule = month.getSchedule().find((day-1), (hour-1))
                if(schedule is not None):
                    return schedule.deletePosition(position)
        return False

    def findReminder(self, carne, year, month, day, hour, position):
        student = self.find(carne)

        if(student is not None):
            year = student.getYearList().find(year)
            if(year is not None):
                month = year.getMonths().find(month)
                schedule = month.getSchedule().find((day-1), (hour-1))

                if(schedule is not None):
                    reminder = schedule.findPosition(position)
                    return reminder
        return None

    def reportStudent(self):
        avl = self.avlTree.getList()
        if(avl is not None):
            g = graphviz.Digraph('g', filename='/home/jafb/Reportes_F2/StudentReport/btree.gv', format='svg',
                        node_attr={'shape': 'record', 'height': '.1'})

            for element in avl:
                key = element['key']
                student = element['element']
                conect = element['conect']
                direction = element['direction']
                #print(key)
                g.node('node' + str(key), nohtml('<f0> |{<f3>' + str(key) + '|' + str(student.getName()) + '|<f1>' + str(student.getCareer()) +'} |<f2>'))

                if(conect != 0):
                    if(direction == "left"):
                        g.edge('node' + str(conect) + ':f0', 'node' + str(key) +':f3')
                    elif(direction == "right"):
                        g.edge('node' + str(conect) + ':f2', 'node' + str(key) +':f3')
                    else:
                        g.edge('node' + str(conect) + ':f1', 'node' + str(key) +':f3')

            g.attr(label=r'\n\nARBOL AVL DE ESTUDIANTES\nJOSE ANDRES FLORES BARCO\n201801287')
            g.attr(fontsize='40')
            g.render()
            g.view()

    def reportCalendar(self, carne, year, month):
        student = self.find(carne)

        if(student is not None):
            year = student.getYearList().find(year)
            if(year is not None):
                month = year.getMonths().find(month)
                schedule = month.getSchedule()

                if(schedule is not None):
                    row = schedule.getRowMax()
                    column = schedule.getColumnMax()
                    letters = ["A", "B", "C", "D", "E", "F", "G", "H", "I", "J", "K", "L", "M", "N", "Ñ", "O", "P", "Q", "R", "S", "T", "U", "V", "W", "X", "Y", "Z"]

                    nodes = "INICIO [label = \"#\" width = 1.5 style = filled, fillcolor = bisque1, group = 1 ];\n"
                    tableColumn = "rank=same {INICIO"
                    for x in range(column):
                        nodes += "COLUMN" + str(x) + " [label = \"DIA " + str(x+1) + "\" width = 1.5 style = filled, fillcolor = bisque1, group = 1 ];\n"
                        tableColumn += " -- COLUMN" + str(x)
                    tableColumn += "}\n"

                    tableRow = "INICIO"
                    for x in range(row):
                        nodes += "ROW" + str(x) + " [label = \"" + str(x+1) + ":00\" width = 1.5 style = filled, fillcolor = bisque1, group = 1 ];\n"
                        tableRow += " -- ROW" + str(x)
                    tableRow += "\n"

                    count = 1
                    for y in range(row):
                        aux = ""
                        firstColumn = False
                        columnBefore = 0
                        flag = False
                        for x in range(column):
                            reminders = schedule.find(x, y)
                            if(reminders is not None):
                                nodes += letters[y] + str(x) + " [label = \"" + str(reminders.getSize()) + "\" width = 1.5 style = filled, fillcolor = bisque1, group = 1 ];\n"
                                aux += " -- " + letters[y] + str(x)
                                columnBefore = x
                                flag = True
                                if(x == 0):
                                    firstColumn = True
                            elif(flag) and ((columnBefore != 0) and ((x - columnBefore) > 1)):
                                nodes += "INVIS" + str(count) + " [style = invis];\n"
                                aux += " -- INVIS" + str(count)
                                count += 1
                                flag = False
                        if(aux != ""):
                            if(firstColumn):
                                aux = "rank=same {ROW" + str(y) + aux + "}\n"
                            else:
                                nodes += "INVIS" + str(count) + " [style = invis];\n"
                                aux = "rank=same {ROW" + str(y) + " -- INVIS" + str(count) + aux + "}\n"
                                count += 1
                            tableColumn += aux

                    for x in range(column):
                        aux = ""
                        for y in range(row):
                            reminders = schedule.find(x, y)
                            if(reminders is not None):
                                aux += " -- " + letters[y] + str(x)
                        if(aux != ""):
                            aux = "COLUMN" + str(x) + aux + "\n"
                            tableRow += aux


                    file = "graph grid {\n"
                    file += "layout=dot\n"
                    file += "label=\"CALENDARIO DE RECORDATORIOS\"\n"
                    file += "labelloc = \"t\"\n"
                    file += "node [shape=plaintext]\n"
                    file += "edge [weight=1000 style=dashed color=red]\n"
                    file += nodes
                    file += tableRow
                    file += tableColumn
                    file += "}"

                    f=open("/home/jafb/Reportes_F2/MatrixReport/reporte.dot","w")
                    f.write(file)
                    f.close()
                    system("dot -Tsvg -o /home/jafb/Reportes_F2/MatrixReport/reporte1.svg /home/jafb/Reportes_F2/MatrixReport/reporte.dot")

    def reportReminder(self, carne, year, month, day, hour):
        student = self.find(carne)

        if(student is not None):
            year = student.getYearList().find(year)
            if(year is not None):
                month = year.getMonths().find(month)
                schedule = month.getSchedule()
                reminders = schedule.find((day-1), (hour-1))

                if(reminders is not None):
                    g = graphviz.Digraph('g', filename='/home/jafb/Reportes_F2/ReminderReport/reporte.gv', format='svg',
                        node_attr={'shape': 'record', 'height': '.1'})
                    value = reminders.getList()
                    while(value is not None):
                        reminder = value.getElement()
                        g.node('node' + str(value.getId()), nohtml('{<f0> CARNE: ' + str(reminder.getCarne()) + '|<f1> NOMBRE: ' + str(reminder.getName()) + '|<f2> DESCRIPCION: ' + str(reminder.getDescription()) + '|<f3> MATERIA: ' + str(reminder.getSubject()) + '|<f4> FECHA: ' + str(reminder.getDate()) + '|<f5> HORA: ' + str(reminder.getHour()) + '|<f6> ESTADO: ' + str(reminder.getState()) + '}'))
                        
                        if(value.getAfter() is not None):
                            g.edge('node' + str(value.getId()) + ':f6', 'node' + str(value.getAfter().getId()) +':f0')

                        if(value.getBefore() is not None) and (value.getBefore().getId() != 0):
                            g.edge('node' + str(value.getId()) + ':f0', 'node' + str(value.getBefore().getId()) +':f6')
                        
                        value = value.getAfter()

                    g.render()
                    g.view()  
        return None

# CLASE CURSE CONTROLLER ------------------------------------------------------------------------------------------------
class CourseController(object):
    __instance = None
    bTree = BTree()

    # SINGLETON
    @staticmethod
    def __new__(cls):
        if CourseController.__instance is None:
            CourseController.__instance = object.__new__(cls)
        return CourseController.__instance

    def add(self, code, name, credits, prerequisits, mandatory):
        course = Course(code, name, credits, prerequisits, mandatory)
        self.bTree.add(code, course)

    def bulkLoad(self, address, isCurse, value = None):

        if(isCurse):
            flag = False
            if(value is None):
                data = fileReader(address)
                value = json.loads(data)

            for key, value in value.items():
                if(key.lower() == "cursos"):
                    flag = True
                    for curso in value:
                        code = ""
                        name = ""
                        credits = ""
                        prerequisits = ""
                        require = ""
                        for key1, value1 in curso.items():
                            if(key1.lower() == "codigo"):
                                code = int(value1)
                            elif(key1.lower() == "nombre"):
                                name = value1
                            elif(key1.lower() == "creditos"):
                                credits = int(value1)
                            elif(key1.lower() == "prerequisitos"):
                                prerequisits = value1
                            elif(key1.lower() == "obligatorio"):
                                require = value1
                        self.add(code, name, credits, prerequisits, require)
        return flag
    
    def report(self, node = None):
        if(node is None):
            btree = self.bTree
        else:
            btree = node

        if(btree is not None):
            g = graphviz.Digraph('g', filename='/home/jafb/Reportes_F2/GeneralCourseReport/btree.gv', format='svg',
                        node_attr={'shape': 'record', 'height': '.1'})

            nodes = btree.getNodes()
            
            for node in nodes:
                key = node['key']
                elements = node['elements']
                parent = node['parent']
                size = node['size']

                #print(key, elements, parent)

                temp = elements
                count = 0
                aux = ""
                if(temp is not None) and (temp.getElement() is not None):
                    element = temp.getElement()
                    aux = "{ CODIGO: " + str(element.getCode()) + "| NOMBRE: " + str(element.getName()) + "}"

                    count += 1
                    temp = temp.getAfter()

                while(temp is not None):
                    element = temp.getElement()
                    aux += " | { CODIGO: " + str(element.getCode()) + "| NOMBRE: " + str(element.getName()) + "}"
                    count += 1
                    temp = temp.getAfter()
                g.node('node' + str(key), nohtml("{ {" + aux + "} }"))
                if(parent is not None):
                    g.edge('node' + str(parent), 'node' + str(key))
            g.view()
