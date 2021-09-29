# -*- coding: utf-8 -*-

# CLASE NODE ------------------------------------------------------------------------------------------------------------
class Node(object):

# CONSTRUCTOR
    def __init__(self, id = 0, element = None, after = None, before = None):
        self.id = id
        self.element = element
        self.after = after
        self.before = before

# SETTERS
    def setId(self, id):
        self.id = id

    def setElement(self, element):
        self.element = element

    def setAfter(self, after):
        self.after = after

    def setBefore(self, before):
        self.before = before

# GETTERS
    def getId(self):
        return self.id

    def getElement(self):
        return self.element

    def getAfter(self):
        return self.after

    def getBefore(self):
        return self.before

# CLASE NODO ARBOL AVL --------------------------------------------------------------------------------------------------
class AVLNode(object):

# CONSTRUCTOR
    def __init__(self, key = 0, element = None, left = None, right = None, height = 0):
        self.key = key
        self.element = element
        self.left = left
        self.right = right
        self.height = height

# SETTERS
    def setKey(self, key):
        self.key = key

    def setElement(self, element):
        self.element = element

    def setLeft(self, left):
        self.left = left

    def setRight(self, right):
        self.right = right

    def setHeight(self, height):
        self.height = height

# GETTERS
    def getKey(self):
        return self.key

    def getElement(self):
        return self.element

    def getLeft(self):
        return self.left

    def getRight(self):
        return self.right

    def getHeight(self):
        return self.height

# CLASE NODO ARBOL B ----------------------------------------------------------------------------------------------------
class BTreeNode(object):

# CONSTRUCTOR
    def __init__(self, elements = [], nodes = [], parent = None, maxKey = 0, minKey = 0, leaf = False):
        self.elements = elements
        self.nodes = nodes
        self.parent = parent
        self.maxKey = maxKey
        self.minKey = minKey
        self.leaf = leaf

# SETTERS
    def setElements(self, elements):
        self.elements = elements

    def setNodes(self, nodes):
        self.nodes = nodes

    def setParent(self, parent):
        self.parent = parent

    def setMaxKey(self, maxKey):
        self.maxKey = maxKey

    def setMinKey(self, minKey):
        self.minKey = minKey

    def setLeaf(self, leaf):
        self.leaf = leaf

# GETTERS
    def getElements(self):
        return self.elements

    def getNodes(self):
        return self.nodes

    def getParent(self):
        return self.parent

    def getMaxKey(self):
        return self.maxKey

    def getMinKey(self):
        return self.minKey

    def isLeaf(self):
        return self.leaf


# CLASE ESTUDIANTE ------------------------------------------------------------------------------------------------------
class Student():

# CONSTRUCTOR
    def __init__(self, carne = 0, dpi = "", name = "", career = "", email = "", password = "", credits = 0, age = 0, yearList = None):
        self.carne = carne
        self.dpi = dpi
        self.name = name
        self.career = career
        self.email = email
        self.password = password
        self.credits = credits
        self.age = age
        self.yearList = yearList

# SETTERS
    def setCarne(self, carne):
        self.carne = carne

    def setDpi(self, dpi):
        self.dpi = dpi

    def setName(self, name):
        self.name = name

    def setCareer(self, career):
        self.career = career

    def setEmail(self, email):
        self.email = email
    
    def setPassword(self, password):
        self.password = password

    def setCredits(self, credits):
        self.credits = credits

    def setAge(self, age):
        self.age = age
    
    def setYearList(self, yearList):
        self.yearList = yearList

# GETTERS
    def getCarne(self):
        return self.carne

    def getDpi(self):
        return self.dpi

    def getName(self):
        return self.name

    def getCareer(self):
        return self.career

    def getEmail(self):
        return self.email
    
    def getPassword(self):
        return self.password

    def getCredits(self):
        return self.credits

    def getAge(self):
        return self.age
    
    def getYearList(self):
        return self.yearList

# CLASE YEAR ------------------------------------------------------------------------------------------------------------
class Year(object):

# CONSTRUCTOR
    def __init__(self, year = 0, months = [], semesters = []):
        self.year = year
        self.months = months
        self.semesters = semesters

# SETTERS
    def setYear(self, year):
        self.year = year

    def setMonths(self, months):
        self.months = months

    def setSemesters(self, semesters):
        self.semesters = semesters

# GETTERS
    def getYear(self):
        return self.year

    def getMonths(self):
        return self.months

    def getSemesters(self):
        return self.semesters

# CLASE YEAR ------------------------------------------------------------------------------------------------------------
class Month(object):

# CONSTRUCTOR
    def __init__(self, month = 0, schedule = []):
        self.month = month
        self.schedule = schedule

# SETTERS
    def setMonth(self, month):
        self.month = month

    def setSchedule(self, schedule):
        self.schedule = schedule

# GETTERS
    def getMonth(self):
        return self.month

    def getSchedule(self):
        return self.schedule

# CLASE SEMESTER --------------------------------------------------------------------------------------------------------
class Semester(object):

# CONSTRUCTOR
    def __init__(self, semester = 0, courses = []):
        self.semester = semester
        self.courses = courses

# SETTERS
    def setSemester(self, semester):
        self.semester = semester

    def setCourses(self, courses):
        self.courses = courses

# GETTERS
    def getSemester(self):
        return self.semester

    def getCourses(self):
        return self.courses
        
# CLASE RECORDATORIO ----------------------------------------------------------------------------------------------------
class Reminder(object):

# CONSTRUCTOR
    def __init__(self, carne = 0, name = "", description = "", subject = "", date = "", hour = 0, state = ""):
        self.carne = carne
        self.name = name
        self.description = description
        self.subject = subject
        self.date = date
        self.hour = hour
        self.state = state

# SETTERS
    def setCarne(self, carne):
        self.carne = carne
    
    def setName(self, name):
        self.name = name

    def setDescription(self, description):
        self.description = description

    def setSubject(self, subject):
        self.subject = subject

    def setDate(self, date):
        self.date = date

    def setHour(self, hour):
        self.hour = hour

    def setState(self, state):
        self.state = state

# GETTERS
    def getCarne(self):
        return self.carne

    def getName(self):
        return self.name

    def getDescription(self):
        return self.description

    def getSubject(self):
        return self.subject

    def getDate(self):
        return self.date

    def getHour(self):
        return self.hour

    def getState(self):
        return self.state

# CLASE CURSO -----------------------------------------------------------------------------------------------------------
class Course(object):

# CONSTRUCTOR
    def __init__(self, code = 0, name = "", credits = 0, prerequisits = [], mandatory = False):
        self.code = code
        self.name = name
        self.credits = credits
        self.prerequisits = []
        self.require = mandatory

# SETTERS
    def setCode(self, code):
        self.code = code

    def setName(self, name):
        self.name = name

    def setCredits(self, credits):
        self.credits = credits

    def setPrerequisits(self, prerequisits):
        self.prerequisits = prerequisits

    def setRequire(self, require):
        self.require = require

# GETTERS
    def getCode(self):
        return self.code

    def getName(self):
        return self.name

    def getCredits(self):
        return self.credits

    def getPrerequisits(self):
        return self.prerequisits

    def getRequire(self):
        return self.require