# -*- coding: utf-8 -*-
import re
import calendar
import graphviz
from graphviz import nohtml

from model import Node, Student, Reminder, Year, Month, Course
from list import BTree, DoubleLinkedList, AVLTree, SparseMatrix

def fileReader(address = ""):
    data = ""
    with open(address, "r", encoding="utf-8") as f: 
        for line in f.readlines():
            data += line.replace("\n", " ")
    return data

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

    def bulkLoad(self, address, isStudent, isReminder, isCurse):
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
                temp = Year(year, DoubleLinkedList(), DoubleLinkedList())
                student.getYearList().sortedAdd(year, temp)
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

    def addReminder(self, carne = 0, name = "", description = "", subject = "", date = "", hour = 0, state = ""):
        day, month, year = date.split("/")
        temp = self.addMonth(carne, int(year), int(month))
        if(temp is not None):
            reminder = Reminder(carne, name, description, subject, date, hour, state)
            hour = hour.split(":")
            schedule = temp.getSchedule().findMatrix((int(day)-1), (int(hour[0])-1))
            reminders = None
            if(schedule is None):
                reminders = temp.getSchedule().add((int(day)-1), (int(hour[0])-1), DoubleLinkedList())
            else:
                reminders = temp.getSchedule().findMatrix((int(day)-1), (int(hour[0])-1))

            if(reminders is not None):
                reminders.add(reminder)
                temp.getSchedule().addSparseMatrix()
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

                temp = schedule.getList()

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