import re

file = open("problemas.txt","r")
problemas=[]
ANSWER=0
ERRORSITO='error'
def es_int(num):
    try:
        int(num)
        return True
    except ValueError:
        return False

def operacion(n1, operacion, n2):
    if operacion == '+':
        return n1 + n2
    elif operacion == '-':
        return n1 - n2
    elif operacion == '*':
        return n1 * n2
    elif operacion == '//':
        if n2 == 0:
            return ERRORSITO
        return n1 // n2
    
def CUPON(x,y):
    if y == 0:
        res = int(x*0.2)
    elif y > 100:
        res = "error"
    else:
        res = int(x*(y/100))
    return res
    
def evaluar_exp(EXP):
    prior = {'+': 1, '-': 1, '*': 2, '//': 2}
    numeros = []
    operaciones = []
    global ANSWER
    for linea in EXP:
        lineas = linea.split('\n')
        for linea_actual in lineas:
            expresiones = re.findall(r'(\d+|ANS|[()+\-*/]+)', linea_actual)
            for objetos in expresiones:
                if objetos == 'ANS':
                    numeros.append(ANSWER)
                elif es_int(objetos):
                    numeros.append(int(objetos))
                elif objetos in prior:
                    while (operaciones and operaciones[-1] in prior and prior[objetos] <= prior.get(operaciones[-1], 0)):
                        aritmeticas = operaciones.pop()
                        numero_2 = numeros.pop()
                        numero_1 = numeros.pop()
                        res = operacion(numero_1, aritmeticas, numero_2)
                        if res < 0:
                            res = 0
                        numeros.append(res)
                    operaciones.append(objetos)
                elif objetos == '(':
                    operaciones.append(objetos)
                elif objetos == ')':
                    while operaciones and operaciones[-1] != '(':
                        aritmeticas = operaciones.pop()
                        numero_2 = numeros.pop()
                        numero_1 = numeros.pop()
                        res = operacion(numero_1, aritmeticas, numero_2)
                        if res < 0:
                            res = 0
                        numeros.append(res)
                    if operaciones and operaciones[-1] == '(':
                        operaciones.pop()

        while operaciones:
            aritmeticas = operaciones.pop()
            numero_2 = numeros.pop()
            numero_1 = numeros.pop()
            res = operacion(numero_1, aritmeticas, numero_2)
            if res < 0:
                res = 0
            numeros.append(res)

        if numeros:
            ANSWER = numeros[-1]
    return numeros

def escribir(expresiones,resultados):
    file = open("desarrollos.txt","a")
    i = len(expresiones)
    count=0
    while count < i:
        file.write(expresiones[count])
        file.write(" = ")
        file.write(str(resultados[count]))
        file.write("\n")
        count += 1
    file.write("\n")
    file.close()

#MAIN
for lineas in file: 
    separacion= re.split(r'\s',lineas)
    lineasSinBN= re.split(r'\n',lineas)
    whiteline= re.match(r'\n',lineas)
    
    if lineasSinBN[0]!='': #Añade las lineas a una lista
        problemas.append(lineasSinBN[0])

    if separacion[len(separacion)-1]!='' and whiteline == None:
        escribir(problemas,evaluar_exp(problemas))
       

    if whiteline!= None:
        escribir(problemas,evaluar_exp(problemas))
        ANSWER = 0
        problemas.clear()
file.close()
