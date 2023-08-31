import re

file = open("problemas.txt", "r")
problemas = []
ANSWER = 0
ERRORSITO = 'error'
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
def es_int(num):
    try:
        int(num)
        return True
    except ValueError:
        return False
def operacion(n1, operacion, n2):
    if operacion == '+':
        res = n1+n2
        return res
    elif operacion == '-':
        res = n1-n2
        return res
    elif operacion == '*':
        res = n1*n2
        return res
    elif operacion == '//':
        if n2 == 0:
            return ERRORSITO
        res = n1//n2
        return res
def CUPON(x, y):
    if y == 0:
        res = int(x * 0.2)
    elif y > 100:
        res = "error"
    else:
        res = int(x * (y / 100))
    return res

def evaluar_exp(EXP):
    prior = {'+': 1, '-': 1, '*': 2, '//': 2}
    numeros = []
    operaciones = []
    global ANSWER
    for linea in EXP:
        expresiones = re.findall(r'(\d+|ANS|[()+\-*/]+|CUPON\(\d+(?:,\s*\d+)?\s*\))', linea)  # Modificada para incluir CUPON()
        for objetos in expresiones:
            if objetos == 'ANS':
                numeros.append(ANSWER)
            elif es_int(objetos):
                numeros.append(int(objetos))
            elif re.match(r'CUPON\((\d+)(?:,(\d+))?\)', objetos):
                valores = re.findall(r'\d+', objetos)
                if len(valores) == 1:
                    res_cupon = CUPON(int(valores[0]), 0)  # Si no hay segundo valor, asumir 0 para Y
                else:
                    res_cupon = CUPON(int(valores[0]), int(valores[1]))
                numeros.append(res_cupon)
            elif objetos in prior:
                while (operaciones and operaciones[-1] in prior and prior[objetos] <= prior.get(operaciones[-1], 0)):
                    aritmeticas = operaciones.pop()
                    numero_2 = numeros.pop()
                    numero_1 = numeros.pop()
                    res = operacion(numero_1, aritmeticas, numero_2)
                    if res is not None and res < 0:
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
                    if res is not None and res < 0:
                        res = 0
                    numeros.append(res)
                if operaciones and operaciones[-1] == '(':
                    operaciones.pop()
            if operaciones.count('(') != operaciones.count(')'):
                numeros.append(ERRORSITO)
            return numeros  # Return early if there's an imbalance
        while operaciones:
            aritmeticas = operaciones.pop()
            numero_2 = numeros.pop()
            numero_1 = numeros.pop()
            res = operacion(numero_1, aritmeticas, numero_2)
            if res is not None and res < 0:
                res = 0
            numeros.append(res)
        if numeros:
            ANSWER = numeros[-1]
    return numeros


for lineas in file:
    separacion = re.split(r'\s', lineas)
    lineasSinBN = re.split(r'\n', lineas)
    whiteline = re.match(r'\n', lineas)
    
    if lineasSinBN[0] != '':
        problemas.append(lineasSinBN[0])

    if separacion[len(separacion) - 1] != '' and whiteline is None:
        resultados = evaluar_exp(problemas)
        if ERRORSITO in resultados:
            problemas.append(ERRORSITO)
        else:
            problemas.append(resultados[-1])  # Append the last calculated result

    if whiteline is not None:
        resultados = evaluar_exp(problemas)
        if ERRORSITO in resultados:
            problemas.append(ERRORSITO)
        else:
            problemas.append(resultados[-1])  # Append the last calculated result
        ANSWER = 0
        problemas.clear()

# Write the problemas list to the output file
file_output = open("desarrollos.txt", "a")
for item in problemas:
    if item == ERRORSITO:
        file_output.write("error\n")
    else:
        file_output.write(str(item) + "\n")
file_output.write("\n")
file_output.close()

file.close()







