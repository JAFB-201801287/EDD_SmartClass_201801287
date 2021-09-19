from os import name
import json
from flask import Flask, request, jsonify
from controller import StudentController
from model import Student

app = Flask(__name__)

@app.route('/', methods=['GET'])
def start():
    return "JOSE ANDRES FLORES BARCO\n201801287\nPROYECTO EDD FASE 2"

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



if __name__ == '__main__':
    app.run('127.0.0.1', port=3000)