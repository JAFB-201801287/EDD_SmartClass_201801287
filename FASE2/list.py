# -*- coding: utf-8 -*-

from model import Node, AVLNode, BTreeNode

# CLASE DOUBLE LINKED LIST ----------------------------------------------------------------------------------------------
class DoubleLinkedList():

# CONSTRUCTOR VACIO
    def __init__(self):
        self.index = 1
        self.head = None
        self.size = 0

# GET LIST
    def getList(self):
        return self.head

# GET SIZE
    def getSize(self):
        return self.size

# SET HEAD
    def setHead(self,  head):
        self.head = head

        i = 0
        temp = head
        while(temp is not None):
            i = i+1
            temp = temp.getAfter()
        self.size = i

# FIND
    def find(self, key):
        temp = self.head
        while(temp is not None):
            if(temp.getId() == key):
                return temp.getElement()
            temp = temp.getAfter()
        return None

    def findPosition(self, position):
        temp = self.head
        count = 1
        while(temp is not None):
            if(count == position):
                return temp.getElement()
            count = count + 1
            temp = temp.getAfter()
        return None

# ADD
    def add(self, element):
        new_node = Node(self.index, element)
        temp = self.head
        last = Node()
        
        if(self.head == None):
            self.head = new_node
            self.head.setAfter(None) 
            self.head.setBefore(None)
            
        else:
            while(temp != None):
                last = temp;
                temp = temp.getAfter()
        
        last.setAfter(new_node)
        new_node.setBefore(last)
        new_node.setAfter(None)
        last = new_node;

        ++self.index
        self.size = 1 + self.size

    # DELETE
    def delete(self, element):
        current = self.head
        before = None
        found = False
        temp = self.head
        last = None

        while(temp != None):
            last = temp
            temp = temp.getAfter()

        if(self.head != None or found):
            while(current != None):
                if(current.getElement() == element):
                    if(current == self.head):
                        self.head = self.head.getAfter()
                        self.head.setBefore(None)
                    elif(current == last):
                        before.setAfter(None)
                        last = before
                    else:
                        if(before != None): before.setAfter(current.getAfter())
                        current.getAfter().setBefore(before)
                    found = True
                    --self.size
                before = current
                current = current.getAfter()

    def deletePosition(self, position = 0):
        current = self.head
        before = None
        found = False
        temp = self.head
        last = None
        count = 1

        while(temp != None):
            last = temp
            temp = temp.getAfter()

        if(self.head != None or found):
            while(current != None):
                if(count == position):
                    if(self.size == 1):
                        self.head = None
                    elif(current == self.head):
                        self.head = self.head.getAfter()
                        self.head.setBefore(None)
                    elif(current == last):
                        before.setAfter(None)
                        last = before
                    else:
                        if(before != None): before.setAfter(current.getAfter())
                        current.getAfter().setBefore(before)
                    self.size = self.size - 1
                    return True
                count = count - 1
                before = current
                current = current.getAfter()
        return False

# SORTED ADD 
    def sortedAdd(self, key, element):
        newNode = Node(key, element)
        current = self.head
        last = Node()
        
        if(self.head == None):
            self.head = newNode;
            self.head.setAfter(None) 
            self.head.setBefore(None);
        elif(self.head.getId() >= newNode.getId()):
            newNode.setAfter(self.head)
            newNode.getAfter().setBefore(newNode)
            self.head = newNode
        else:
            while((current.getAfter() is not None) and (current.getAfter().getId() < newNode.getId())):
                current = current.getAfter()
            newNode.setAfter(current.getAfter())

            if (current.getAfter() != None):
                newNode.getAfter().setBefore(newNode)
            current.setAfter(newNode)
            newNode.setBefore(current)
        
        self.size = 1 + self.size

# SPLIT PARA CINCO ELEMENTOS
    def split(self):
        temp = []

        head1 = self.head
        head2 = head1.getAfter().getAfter()
        head3 = head2.getAfter()

        head1.getAfter().setAfter(None)
        head2.setBefore(None)
        head2.setAfter(None)
        head3.setBefore(None)

        temp.append(head1)
        temp.append(head2)
        temp.append(head3)

        self.head = head2
        self.size = self.size - 4

        return temp

# SPLIT EN SEIS ELEMENTOS
    def divide(self):
        temp = []

        head1 = self.head
        head2 = head1.getAfter().getAfter().getAfter()
        
        head1.getAfter().getAfter().setAfter(None)
        head2.setBefore(None)

        self.size = 0
        #self.head = None

        temp.append(head1)
        temp.append(head2)

        return temp

# CLASE AVL TREE --------------------------------------------------------------------------------------------------------
class AVLTree():

# CONSTRUCTOR
    def __init__(self):
        self.root = None
        self.size = 0

# GET
    def get(self):
        return self.root

# SIZE 
    def size(self):
        return self.size

# INSERT
    def add(self, key, element):
        if not self.root:
            self.root = AVLNode(key, element)
        else:
            self.root = self.insert(key, element, self.root)

    def insert(self, key, element, node):
        if node is None:
            node = AVLNode(key, element)
        
        if(key < node.getKey()):
            node.setLeft(self.insert(key, element, node.getLeft()))    
            if(abs(self.height(node.getLeft()) - self.height(node.getRight())) == 2):
                if (key < node.getLeft().getKey()):
                    node = self.doubleLeftRotate(node)
                else:
                    node = self.leftRightRotate(node)
        elif(key > node.getKey()):
            node.setRight(self.insert(key, element, node.getRight()))
            if(abs(self.height(node.getRight()) - self.height(node.getLeft())) == 2):
                if(key > node.getRight().getKey()):
                    node = self.doubleRightRotate(node)
                else:
                    node = self.rightLeftRotate(node)
                    
        node.setHeight(max(self.height(node.getRight()), self.height(node.getLeft())) + 1)

        return node

# DOBLE ROTACION DE NODO A LA IZQUIERDA
    def doubleLeftRotate(self, node):
        temp = node.getLeft()
        node.setLeft(temp.getRight())
        temp.setRight(node)
        node.setHeight(max(self.height(node.right), self.height(node.left)) + 1)
        temp.setHeight(max(self.height(temp.left), node.height) + 1) 
        return temp

# DOBLE ROTACION DE NODO A LA DERECHA
    def doubleRightRotate(self, node):
        temp = node.getRight()
        node.setRight(temp.getLeft()) 
        temp.setLeft(node)
        node.setHeight(max(self.height(node.right), self.height(node.left)) + 1) 
        temp.setHeight(max(self.height(temp.right), node.height) + 1)
        return temp

# ROTACION DE NODO A LA DERECHA Y IZQUIERDA
    def rightLeftRotate(self, node):
        node.setRight(self.doubleLeftRotate(node.getRight()))
        return self.doubleRightRotate(node)

# ROTACION DE NODO A LA IZQUIERDA Y DERECHA 
    def leftRightRotate(self, node):
        node.setLeft(self.doubleRightRotate(node.getLeft()))
        return self.doubleLeftRotate(node)

# BUSQUEDA EN ARBOL
    def find(self, key):
        if not self.root:
            return None
        else:
            return self.search(key, self.root)

    def search(self, key, node = AVLNode()):
        if not node:
            return None
        elif(key < node.getKey()):
            return self.search(key, node.getLeft())        
        elif(key > node.getKey()):
            return self.search(key, node.getRight())
        else:
            return node

# BUSQUEDA MINIMO (IZQUIERDA)
    def findMinimum(self, node = None):
        if(self.root is None):
            return None
        elif(node is not None):
            return self.searchMinimum(node)
        else:
            return self.searchMinimum(self.root)

    def searchMinimum(self, node):
        if(node.getLeft()):
            return self.searchMinimum(node.getLeft())
        else:
            return node

# BUSQUEDA MAXIMO (DERECHA)
    def findMaximum(self, node = None):
        if self.root is None:
            return None
        elif(node is not None):
            return self.searchMaximum(node)
        else:
            return self.searchMaximum(self.root)

    def searchMaximum(self, node):
        if node.getRight():
            return self.searchMaximum(node.getRight())
        else:
            return node

    def getList(self):
        if self.root is None:
            return None
        else:
            return self.getAvl(self.root) 

    def getAvl(self, node, conectId = 0, direction = ""):
        temp = []
        if node is not None:
            temp.append({
                "key": node.getKey(),
                "element": node.getElement(),
                "conect": conectId,
                "direction": direction
            })

            if(node.getLeft() is not None):
                temp = temp + self.getAvl(node.getLeft(), node.getKey(), "left")

            if(node.getRight() is not None):
                temp = temp + self.getAvl(node.getRight(), node.getKey(), "right")

        return temp

# DELETE
    def delete(self, key):
        if not self.root:
            return False
        else:
            self.root = self.remove(key, self.root)
            return True

    def remove(self, key, node):
        if(node is None):
            return None

        if(key < node.getKey()):
            node.setLeft(self.remove(key, node.getLeft()))

            if(abs(self.height(node.getLeft()) - self.height(node.getRight())) == 2):
                temp = node.getRight()

                if(self.height(temp.getLeft()) > self.height(temp.getRight())):
                    node = self.rightLeftRotate(node)
                else:
                    node = self.doubleRightRotate(node)
                    
        elif(key > node.getKey()):
            node.setRight(self.remove(key, node.getRight()))

            if(abs(self.height(node.getLeft()) - self.height(node.getRight())) == 2):
                temp = node.getLeft()
                if(self.height(temp.getRight()) > self.height(temp.getLeft())):
                    node = self.leftRightRotate(node)
                else:
                    node = self.doubleLeftRotate(node)

        elif(node.getKey() == key):
            if((node.getLeft() is not None) and (node.getRight() is not None)):
                if(self.height(node.getLeft()) > self.height(node.getRight())):
                    nodeMin = self.findMinimum(node.getRight())
                    node.setKey(nodeMin.getKey())
                    node.setRight(self.remove(nodeMin.getKey(), node.getRight()))
                else:
                    nodeMax = self.findMaximum(node.getLeft())
                    node.setKey(nodeMax.getKey())
                    node.setLeft(self.remove(nodeMax.getKey(), node.getLeft()))

            else:
                temp = node
                
                if(temp.getLeft() is not None):
                    node = temp.getLeft()
                else:
                    node = temp.getRight()

        return node

# ALTURA
    def height(self, node):
        if node is None:
            return -1
        else:
            return node.getHeight()    

# CLASE B TREE ----------------------------------------------------------------------------------------------------------
class BTree():

# CONSTRUCTOR
    def __init__(self, M = 5):
        self.M = M
        self.root = None
        self.size = 0

# OBTENER ARBOL
    def getBTree(self):
        return self.root

# CONTEO DE ELEMENTOS EN EL ARBOL
    def getSize(self):
        return self.size

# SEARCH LEAF
    def findLeaf(self, key, element = ""):
        if not self.root:
            return None
        else:
            return self.searchLeaf(key, self.root)

    def searchLeaf(self, node, key):
        print("")

# INSERT
    def add(self, key, element = ""): 
        if not self.root:
            self.root = BTreeNode(DoubleLinkedList(), DoubleLinkedList(), leaf=True)
            self.root.getElements().sortedAdd(key, element)

        else:
            self.insert(key, element, self.root)

    def insert(self, key, element, node, container = None):
        if(not node):
            node = BTreeNode(DoubleLinkedList(), DoubleLinkedList(), leaf=True)
            node.getElements().sortedAdd(key, element)

        if(node.isLeaf()):
            if(container is not None) and (node.getParent() is not None) and (container.getAfter() is not None) and (node.getParent().getMinKey() < key):
                container = container.getAfter()
                node = container.getElement()

            if(node.getMaxKey() < key):
                node.setMaxKey(key)

            if(node.getMinKey() > key):
                node.setMinKey(key) 

            node.getElements().sortedAdd(key, element)           

            if(node.getElements().getSize() >= 5):
                split = node.getElements().split()
                temp1, temp2, temp3 = split
                if(node.getParent() is None) and (node.isLeaf()):
                    node.setElements(DoubleLinkedList())
                    node.getElements().setHead(temp2)
                    node.setMaxKey(node.getElements().getList().getId())
                    node.setMinKey(node.getElements().getList().getId())
                    node.setLeaf(False)

                    aux1 = BTreeNode(DoubleLinkedList(), DoubleLinkedList(), node, temp1.getAfter().getId(), temp1.getId(), True)
                    aux1.getElements().setHead(temp1)

                    aux2 = BTreeNode(DoubleLinkedList(), DoubleLinkedList(), node, temp3.getAfter().getId(), temp3.getId(), True)
                    aux2.getElements().setHead(temp3)

                    node.getNodes().sortedAdd(aux1.getMinKey(), aux1)
                    node.getNodes().sortedAdd(aux2.getMinKey(), aux2)
                else:
                    parent = node.getParent()
                    node.setElements(DoubleLinkedList())
                    node.getElements().setHead(temp1)

                    if(container is not None):
                        container.setId(temp1.getId())

                    if(temp2.getId() < parent.getMinKey()):
                        parent.setMinKey(temp2.getId())

                    if(temp2.getId() > parent.getMaxKey()):
                        parent.setMaxKey(temp2.getId())

                    aux2 = BTreeNode(DoubleLinkedList(), DoubleLinkedList(), parent, maxKey=temp3.getAfter().getId(),  minKey=temp3.getId(), leaf=True)
                    aux2.getElements().setHead(temp3)

                    parent.getNodes().sortedAdd(aux2.getMinKey(), aux2)
                    parent.getElements().sortedAdd(temp2.getId(), temp2.getElement())
                    self.climbTree(parent)

        else:
            nodes = node.getNodes().getList()
            while(nodes is not None):
                if(nodes.getElement().getMinKey() < key):
                    if(nodes.getAfter() is None):
                        return self.insert(key, element, nodes.getElement(), container=nodes)
                    elif(nodes.getAfter() is not None) and (nodes.getAfter().getId() > key):
                        return self.insert(key, element, nodes.getElement(), container=nodes)
                if(nodes.getElement().getMinKey() > key):
                    return self.insert(key, element, nodes.getElement(), container=nodes)
                nodes = nodes.getAfter()

        return node

    def climbTree(self, node):
        if(node.getNodes().getSize() > 5) and (node.getElements().getSize() >= 5):
            min, center, max = node.getElements().split()
            left, right = node.getNodes().divide()
            if(node.getParent() is None):
                node.setElements(DoubleLinkedList())
                node.setNodes(DoubleLinkedList())
                node.getElements().setHead(center)
                node.setMaxKey(node.getElements().getList().getId())
                node.setMinKey(node.getElements().getList().getId())
                node.setLeaf(False)

                aux1 = BTreeNode(DoubleLinkedList(), DoubleLinkedList(), node, min.getAfter().getId(), min.getId(), False)
                aux1.getElements().setHead(min)
                left.getElement().setParent(aux1)
                self.changeParent(left, aux1)
                aux1.getNodes().setHead(left)

                aux2 = BTreeNode(DoubleLinkedList(), DoubleLinkedList(), node, max.getAfter().getId(), max.getId(), False)
                aux2.getElements().setHead(max)
                self.changeParent(right, aux2)
                aux2.getNodes().setHead(right)

                node.getNodes().sortedAdd(aux1.getMinKey(), aux1)
                node.getNodes().sortedAdd(aux2.getMinKey(), aux2)
            else:
                parent = node.getParent()
                parent.getElements().sortedAdd(center.getId(), center.getElement())

                if(center.getId() < parent.getMinKey()):
                    parent.getNodes().getList().setId(center.getId())
                    parent.setMinKey(center.getId())

                if(center.getId() > parent.getMaxKey()):
                    parent.setMaxKey(center.getId())

                node.getElements().setHead(min)
                node.setMinKey(min.getId())
                left.getElement().setParent(node)
                self.changeParent(left, node)
                node.getNodes().setHead(left)

                aux2 = BTreeNode(DoubleLinkedList(), DoubleLinkedList(), parent, max.getAfter().getId(), max.getId(), False)
                aux2.getElements().setHead(max)
                self.changeParent(right, aux2)
                aux2.getNodes().setHead(right)

                parent.getNodes().sortedAdd(aux2.getMinKey(), aux2)
                self.climbTree(parent)


    def changeParent(self, node, parent):
        current = node
        while(current is not None):
            current.getElement().setParent(parent)
            current = current.getAfter()

# PRINT
    def printNode(self, node = None, c = 0):
        if(node is None):
            elements = self.root.getElements().getList()
            nodes = self.root.getNodes().getList()
        else:
            elements = node.getElements().getList()
            nodes = node.getNodes().getList()

        while(elements is not None):
            print(str(elements.getElement()) + " NIVEL: " + str(c))
            elements = elements.getAfter()

        print("-------------------------------------")
        while(nodes is not None):
            print("INICIO >> " + str(nodes) + " - " + str(nodes.getElement().getParent().getMinKey()) + " - MIN: " + str(nodes.getElement().getMinKey()) + " ID: " + str(nodes.getId()))
            self.printNode(nodes.getElement(), c+1)
            nodes = nodes.getAfter()

# CLASE SPARCE MATRIZ ---------------------------------------------------------------------------------------------------
class SparseMatrix():

# CONSTRUCTOR
    def __init__(self, columnMax = 0, rowMax = 0):
        self.columnMax = columnMax
        self.rowMax = rowMax
        self.matrix = [[None for column in range(columnMax)] for row in range(rowMax)]
        self.sparseMatrix = None
        self.size = 0   

# GET 
    def get(self):
        return self.sparseMatrix

    def getMatriz(self):
        return self.matrix

# ADD
    def add(self, column, row, element):
        if(self.sparseMatrix == None) and (column <= self.columnMax) and (row <= self.rowMax) and (column >=0) and (row >= 0):
            self.matrix[row][column] = element
            self.size = self.size + 1
            return self.matrix[row][column]
        return None

# FIND 
    def find(self, column, row):
        if(self.sparseMatrix is not None):
            for element in self.sparseMatrix:
                if(element[0] == row) and (element[1] == column):
                    return element[2]
        return None

    def findMatrix(self, column, row):
        if(self.matrix is not None):
            return self.matrix[row][column]
        return None

# ADD SPARSE MATRIX
    def addSparseMatrix(self):
        if(self.matrix is not None):
            self.sparseMatrix = [[None for column in range(3)] for row in range(self.size+1)]

            self.sparseMatrix[0][0] = self.rowMax
            self.sparseMatrix[0][1] = self.columnMax
            self.sparseMatrix[0][2] = self.size

            count = 1
            for row in range(self.rowMax):
                for column in range(self.columnMax):
                    if(self.matrix[row][column] is not None):
                        self.sparseMatrix[count][0] = row
                        self.sparseMatrix[count][1] = column
                        self.sparseMatrix[count][2] = self.matrix[row][column]

                        count = count + 1






                
                
