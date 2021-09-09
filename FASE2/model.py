# -*- coding: utf-8 -*-

# CLASE NODE ------------------------------------------------------------------------------------------------------------
class Node():

# CONSTRUCTOR VACIO
    def __init__(self):
        self.id = 0
        self.element = []
        self.after = Node()
        self.before = Node()

# CONSTRUCTOR
    def __init__(self, id, element, after, before):
        self.id = id
        self.element = id
        self.after = after
        self.before = after

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

# CLASE ESTUDIANTE ------------------------------------------------------------------------------------------------------
class Student():

# CONSTRUCTOR VACIO
    def __init__(self):
        self.carne = 0
        self.dpi = ""
        self.name = ""
        self.career = ""
        self.email = ""
        self.password = ""
        self.credits = ""
        self.age = 0
        self.yearList = []

# CONSTRUCTOR
    def __init__(self, carne, dpi, name, career, email, password, credits, age):
        self.carne = carne
        self.dpi = dpi
        self.name = name
        self.career = career
        self.email = email
        self.password = password
        self.credits = credits
        self.age = age
        self.yearList = []

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
class Year():

# CONSTRUCTOR VACIO
    def __init__(self):
        self.year = 0
        self.months = []
        self.semester = []

# CONSTRUCTOR
    def __init__(self, year, months, semesters):
        self.year = year
        self.months = months
        self.semester = semesters

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
class Month():
        
# CONSTRUCTOR VACIO
    def __init__(self):
        self.month = ""
        self.homeworks = ""

# CONSTRUCTOR
    def __init__(self, month, homeworks):
        self.month = month
        self.homeworks = homeworks

# SETTERS
    def setMonth(self, month):
        self.month = month

    def setHomeworks(self, homeworks):
        self.homeworks = homeworks

# GETTERS
    def getMonth(self):
        return self.month

    def getHomeworks(self):
        return self.homeworks

# CLASE SEMESTER --------------------------------------------------------------------------------------------------------
class Semester():
        
# CONSTRUCTOR VACIO
    def __init__(self):
        self.semester = ""
        self.courses = ""

# CONSTRUCTOR
    def __init__(self, semester, courses):
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
class Reminder():

# CONSTRUCTOR VACIO
    def __init__(self):
        self.carne = 0
        self.name = ""
        self.description = ""
        self.subject = ""
        self.date = ""
        self.hour = ""
        self.state = ""

# CONSTRUCTOR
    def __init__(self, carne, name, description, subject, date, hour, state):
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
class Course():

# CONSTRUCTOR VACIO
    def __init__(self):
        self.code = 0
        self.name = ""
        self.credits = 0
        self.prerequisits = []
        self.mandatory = False

# CONSTRUCTOR
    def __init__(self, code, name, credits, prerequisits, mandatory):
        self.code = code
        self.name = name
        self.credits = credits
        self.prerequisits = []
        self.require = False

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