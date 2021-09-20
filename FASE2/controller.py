# -*- coding: utf-8 -*-
import re

from model import Node, Student, Reminder, Year, Course
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
        if(self.avlTree is not None) and(self.find(carne)):
            return self.avlTree.delete(carne)
        return False
