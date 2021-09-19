# -*- coding: utf-8 -*-

from model import Node, Student, Reminder, Year, Course
from list import BTree, DoubleLinkedList, AVLTree, SparseMatrix

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

    def add(self, carne = 0, dpi = "", name = "", career = "", email = "", password = "", credits = 0, age = 0):
        if(self.avlTree is not None) and (self.find(carne) is None):
            student = Student(carne, dpi, name, career, email, password, credits, age)
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
        if(self.avlTree is not None):
            return self.avlTree.delete(carne)
        return False
