from datetime import date
from os import name, sep
import json
from flask import Flask, request, jsonify
from controller import StudentController, CourseController
from model import Reminder, Student

app = Flask(__name__)

@app.route('/', methods=['GET'])
def start():
    return "JOSE ANDRES FLORES BARCO\n201801287\nPROYECTO EDD FASE 2"

@app.route('/carga', methods=['POST'])
def bulkData():
    content = request.get_json(force=True)
    studentController = StudentController()
    courseController = CourseController()
    try:
        isStudent = False
        isReminder = False
        isCurse = False

        type = content["tipo"]
        path = content["path"]

        for data in type.split(sep="|"):
            if(data == "estudiante"):
                isStudent = True
            elif(data == "recordatorio"):
                isReminder = True
            elif(data == "curso"):
                isCurse = True

        if(isStudent or isReminder):
            studentController.bulkLoad(path, isStudent, isReminder, isCurse)
            return jsonify({
                "tipo": type,
                "path": path
            })
        elif(isCurse):
            if(not courseController.bulkLoad(path, isCurse)):
                studentController.bulkLoad(path, False, False, isCurse)
            return jsonify({
                "tipo": type,
                "path": path
            })
        else:
            return jsonify({
                "tipo": type,
                "path": path,
                "ERROR": "TIPO NO COMPATIBLE"
            })

    except KeyError:
        return jsonify({"ERROR":"LLAVE NO ENCONTRADA"})

# REPORTES --------------------------------------------------------------------------------------------------------------
@app.route('/reporte', methods=['GET'])
def report():
    content = request.get_json(force=True)
    studentController = StudentController()
    courseController = CourseController()
    try:
        tipo = int(content["tipo"])
        

        if(tipo == 0):
            studentController.reportStudent()
            return jsonify({
                "response": "REPORTE DE ESTUDIANTE CREADO" 
            })
        elif(tipo == 1):
            carne = int(content["carnet"])
            year = int(content["año"])
            month = int(content["mes"])
            studentController.reportCalendar(carne, year, month)
            return jsonify({
                "response": "REPORTE DE MATRIZ DISPERSA CREADO" 
            })
        elif(tipo == 2):
            carne = int(content["carnet"])
            year = int(content["año"])
            month = int(content["mes"])
            day = int(content["dia"])
            hour = int(content["hora"])
            studentController.reportReminder(carne, year, month, day, hour)
            return jsonify({
                "response": "REPORTE DE TAREAS CREADO" 
            })
        elif(tipo == 3):
            courseController.report()
            return jsonify({
                "response": "REPORTE DE CURSOS GENERAL CREADO" 
            })
        elif(tipo == 4):
            carnet = int(content["carnet"])
            year = int(content["año"])
            semester = int(content["semestre"])
            studentController.reportCourse(carnet, year, semester)
            return jsonify({
                "response": "REPORTE DE CURSOS DE ESTUDIANTE CREADO" 
            })
        else:
            return jsonify({
                "response": "REPORTE NO CREADO" 
            })
    except KeyError:
        return jsonify({"ERROR":"LLAVE NO ENCONTRADA"})

# CRUD STUDENT ----------------------------------------------------------------------------------------------------------
@app.route('/estudiante', methods=['GET'])
def findStudent():
    content = request.get_json(force=True)
    studentController = StudentController()
    try:
        carne = int(content["carnet"])
        student = studentController.find(carne)

        if(student is not None):
            return jsonify({
                "carnet": student.getCarne(),
                "DPI": student.getDpi(),
                "nombre": student.getName(),
                "carrera": student.getCareer(),
                "correo": student.getEmail(),
                "password": student.getPassword(),
                "creditos": student.getCredits(),
                "edad": student.getAge()
            })
        else:
            return jsonify({
                "carnet": carne,
                "estado": "NO ENCONTRADO"
            })
    except KeyError:
        return jsonify({"ERROR":"LLAVE NO ENCONTRADA"})

@app.route('/estudiante', methods=['DELETE'])
def deleteStudent():
    content = request.get_json(force=True)
    studentController = StudentController()
    try:
        carne = int(content["carnet"])

        if(studentController.delete(carne)):
            return jsonify({
                "carnet": carne,
                "estado": "ELIMINADO"
            })
        else:
            return jsonify({
                "carnet": carne,
                "estado": "NO ENCONTRADO"
            })
    except KeyError:
        return jsonify({"ERROR":"LLAVE NO ENCONTRADA"})

@app.route('/estudiante', methods=['POST'])
def createStudent():
    content = request.get_json()
    studentController = StudentController()
    #for key, value in content.items():
    #    print (key, value)
    try:
        carne = int(content["carnet"])
        dpi = content["DPI"]
        name = content["nombre"]
        career = content["carrera"]
        email = content["correo"]
        password = content["password"]
        credits = content["creditos"]
        age = content["edad"]

        if(studentController.add(carne, dpi, name, career, email, password, credits, age)):

            return jsonify({
                    "estudiante": {
                    "carnet": carne,
                    "DPI": dpi,
                    "nombre": name,
                    "carrera": career,
                    "correo": email,
                    "password": password,
                    "creditos": credits,
                    "edad": age
                },
                "estado": "INGRESADO"
            })
        else:
            return jsonify({
                "estudiante": {
                    "carnet": carne,
                    "DPI": dpi,
                    "nombre": name,
                    "carrera": career,
                    "correo": email,
                    "password": password,
                    "creditos": credits,
                    "edad": age
                },
                "estado": "NO INGRESADO",
                "ERROR": "CARNE REPETIDO"
            })
    except KeyError:
        return jsonify({"ERROR":"LLAVE NO ENCONTRADA"})

@app.route('/estudiante', methods=['PUT'])
def updateStudent():
    content = request.get_json(force=True)
    studentController = StudentController()
    #for key, value in content.items():
    #    print (key, value)
    try:
        carne = int(content["carnet"])
        dpi = content["DPI"]
        name = content["nombre"]
        career = content["carrera"]
        email = content["correo"]
        password = content["password"]
        credits = content["creditos"]
        age = content["edad"]


        if(studentController.update(carne, dpi, name, career, email, password, credits, age)):

            return jsonify({
                    "estudiante": {
                    "carnet": carne,
                    "DPI": dpi,
                    "nombre": name,
                    "carrera": career,
                    "correo": email,
                    "password": password,
                    "creditos": credits,
                    "edad": age
                },
                "estado": "ACTUALIZADO"
            })
        else:
            return jsonify({
                "carnet": carne,
                "estado": "NO ENCONTRADO"
            })
    except KeyError:
        return jsonify({"ERROR":"LLAVE NO ENCONTRADA"})

# CRUD REMINDER ---------------------------------------------------------------------------------------------------------
@app.route('/recordatorios', methods=['POST'])
def createReminder():
    content = request.get_json(force=True)
    studentController = StudentController()
    try:
        carne = int(content["carnet"])
        name = content["nombre"]
        description = content["descripcion"]
        subject = content["materia"]
        date = content["fecha"]
        hour = content["hora"]
        state = content["estado"]

        if(studentController.addReminder(carne, name, description, subject, date, hour, state)):
            return jsonify({
                "recordatorio": {
                    "carnet": carne,
                    "nombre": name, 
                    "descripcion": description, 
                    "materia": subject, 
                    "fecha": date,
                    "hora": hour, 
                    "estado": state
                },
                "estado": "INGRESADO"
            })
        else:
            return jsonify({
                "recordatorio": {
                    "carnet": carne,
                    "nombre": name, 
                    "descripcion": description, 
                    "materia": subject, 
                    "fecha": date,
                    "hora": hour, 
                    "estado": state
                },
                "estado": "NO INGRESADO",
                "ERROR": "CARNE DE ESTUDIANTE NO ENCONTRADO"
            })
    except KeyError:
        return jsonify({"ERROR":"LLAVE NO ENCONTRADA"})

@app.route('/recordatorios', methods=['PUT'])
def updateReminder():
    content = request.get_json(force=True)
    studentController = StudentController()
    try:
        carne = int(content["carnet"])
        name = content["nombre"]
        description = content["descripcion"]
        subject = content["materia"]
        date = content["fecha"]
        hour = content["hora"]
        state = content["estado"]
        position = int(content["posicion"])

        if(studentController.updateReminder(carne, name, description, subject, date, hour, state, position)):
            return jsonify({
                "recordatorio": {
                    "carnet": carne,
                    "nombre": name, 
                    "descripcion": description, 
                    "materia": subject, 
                    "fecha": date,
                    "hora": hour, 
                    "estado": state
                },
                "estado": "ACTUALIZADO"
            })
        else:
            return jsonify({
                "recordatorio": {
                    "carnet": carne,
                    "nombre": name, 
                    "descripcion": description, 
                    "materia": subject, 
                    "fecha": date,
                    "hora": hour, 
                    "estado": state
                },
                "ERROR": "RECORDATORIO NO ENCONTRADO"
            })
    except KeyError:
        return jsonify({"ERROR":"LLAVE NO ENCONTRADA"})

@app.route('/recordatorios', methods=['DELETE'])
def deleteReminder():
    content = request.get_json(force=True)
    studentController = StudentController()
    try:
        carne = int(content["carnet"])
        date = content["fecha"]
        hour = content["hora"]
        day, month, year = date.split("/")
        hour = hour.split(":")
        position = int(content["posicion"])
        reminder = studentController.deleteReminder(carne, int(year), int(month), int(day), int(hour[0]), position)

        if(reminder):
            return jsonify({
                "carnet": carne,
                "estado": "ELIMINADO"
            })
        else:
            return jsonify({
                "carnet": carne,
                "estado": "NO ENCONTRADO"
            })
    except KeyError:
        return jsonify({"ERROR":"LLAVE NO ENCONTRADA"})

@app.route('/recordatorios', methods=['GET'])
def findReminder():
    content = request.get_json(force=True)
    studentController = StudentController()
    try:
        carne = int(content["carnet"])
        date = content["fecha"]
        hour = content["hora"]
        day, month, year = date.split("/")
        hour = hour.split(":")
        position = int(content["posicion"])
        reminder = studentController.findReminder(carne, int(year), int(month), int(day), int(hour[0]), position)

        if(reminder is not None):
            return jsonify({
                "carnet": reminder.getCarne(),
                "nombre": reminder.getName(), 
                "descripcion": reminder.getDescription(), 
                "materia": reminder.getSubject(), 
                "fecha": reminder.getDate(),
                "hora": reminder.getHour(), 
                "estado": reminder.getState()
            })
        else:
            return jsonify({
                "carnet": carne,
                "estado": "NO ENCONTRADO"
            })
    except KeyError:
        return jsonify({"ERROR":"LLAVE NO ENCONTRADA"})

# CRUD COURSE -----------------------------------------------------------------------------------------------------------
@app.route('/cursosPensum', methods=['POST'])
def createPensumCourse():
    content = request.get_json(force=True)
    courseController = CourseController()
    try:
        courseController.bulkLoad("", True, content)
        return jsonify({
            "estado" : "INGRESADO"
        })
    except KeyError:
        return jsonify({"ERROR":"LLAVE NO ENCONTRADA"})

@app.route('/cursosEstudiante', methods=['POST'])
def createStudentCourse():
    content = request.get_json(force=True)
    studentController = StudentController()
    try:
        studentController.bulkLoad("", False, False, True, content)
        return jsonify({
            "estado" : "INGRESADO"
        })
    except KeyError:
        return jsonify({"ERROR":"LLAVE NO ENCONTRADA"})

if __name__ == '__main__':
    app.run('127.0.0.1', port=3000)