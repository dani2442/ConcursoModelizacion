import numpy as np
def numero_a_letras(n):
    """Dado un entero, devuelve un string con su nombre en castellano"""
    especiales = {0: 'cero', 10: 'diez', 11: 'once', 12: 'doce', 13: 'trece', 14: 'catorce', 15: 'quince', 20: 'veinte', 100: 'cien', 1000: 'mil'}
    if n in especiales:
        return especiales[n]
    if n < 100:
        cifras = ['', 'una', 'dos', 'tres', 'cuatro', 'cinco', 'seis', 'siete', 'ocho', 'nueve']
        decenas = ['', 'dieci', 'veinti', 'treinta', 'cuarenta', 'cincuenta', 'sesenta', 'setenta', 'ochenta', 'noventa']
        if n % 10 == 0:
            return decenas[n // 10]
        if n < 30:
            return f"{decenas[n // 10]}{cifras[n % 10]}"
        return f"{decenas[n // 10]} y {cifras[n % 10]}"
    elif n < 1000:
        centenas = ['', 'ciento', 'doscientas', 'trescientas', 'cuatrocientas', 'quinientas', 'seiscientas', 'setecientas', 'ochocientas', 'novecientas']
        if n % 100 == 0:
            return centenas[n // 100]
        return f"{centenas[n // 100]} {numero_a_letras(n % 100)}"
    elif n < 10**6:
        if n < 2000:
            return f"mil {numero_a_letras(n % 1000)}"
        if n % 1000 == 0:
            return f"{numero_a_letras(n // 1000)} mil"
        return f"{numero_a_letras(n // 1000)} mil {numero_a_letras(n % 1000)}"
    else:
        raise ValueError("Numero demasiado grande")

def estandarizar_mensaje(mensaje):
    """Elimina tildes, mayusculas"""
    mensaje = mensaje.lower()
    for x, y in {'á': 'a', 'é': 'e', 'í': 'i', 'ó': 'o', 'ú': 'u'}.items():
        mensaje = mensaje.replace(x, y)
    return mensaje

def conteos_mensaje(mensaje, letras="abcdefghijklmnñopqrstuvwxyz"):
    """Devuelve un diccionario diciendo cuantas veces aparece cada letra"""
    mensaje = estandarizar_mensaje(mensaje)
    return {x: mensaje.count(x) for x in letras}

def conteos_mensaje2(mensaje,letras="abcdefghijklmnñopqrstuvwxyz"):
    return np.array(list(conteos_mensaje(mensaje,letras).values()))

def conteo_numero(numero,letras="abcdefghijklmnñopqrstuvwxyz"):
    dicc=conteos_mensaje(numero_a_letras(numero),letras)
    if numero==1:
        if 'z' in letras:
            dicc['z']+=1
    else:
        if 'c' in letras:
            dicc['c']+=1
        if 'e' in letras:
            dicc['e']+=1
        if 's' in letras:
            dicc['s']+=1
    return dicc

def conteo_numero2(numero,letras="abcdefghijklmnñopqrstuvwxyz"):
    return np.array(list(conteo_numero(numero,letras).values()))

def firmar_mensaje_fija(mensaje,letras="abcdefghijklmnñopqrstuvwxyz"):
    postdata = []
    for x in range(len(letras)):
        vez = "ve"
        postdata.append(f"{vez} la letra {letras[x]}")
    if len(postdata) > 1:
        postdata[-1] = "y " + postdata[-1]
    return mensaje + " En este mensaje aparece " + ", ".join(postdata)

def firmar_mensaje(mensaje, conteo):
    """Dado un mensaje y un conteo, firma el mensaje"""
    postdata = []
    for x in sorted(conteo.keys()):
        vez = "veces" if conteo[x] != 1 else "vez"
        postdata.append(f"{numero_a_letras(conteo[x])} {vez} la letra {x}")
    if len(postdata) > 1:
        postdata[-1] = "y " + postdata[-1]
    return mensaje + " En este mensaje aparece " + ", ".join(postdata)

def es_conteo_valido(mensaje, conteo):
    """Dado un mensaje y un conteo, decide si el conteo coincide con el mensaje firmado"""
    firmado = firmar_mensaje(mensaje, conteo)
    conteo_firmado = conteos_mensaje(firmado, conteo.keys())
    return conteo == conteo_firmado

def calcular_error(mensaje,conteo):
    firmado=firmar_mensaje(mensaje,conteo)
    conteo_firmado=conteos_mensaje(firmado,conteo.keys())
    return dicc_to_array(conteo_firmado)-dicc_to_array(conteo)

def calcular_error2(mensaje,conteo,letras="abcdefghijklmnñopqrstuvwxyz"):
    return calcular_error(mensaje,array_to_dicc(conteo,letras))

def norm(x):
    return np.sqrt(norm2(x))

def norm2(x):
    return sum(np.square(x))

def dicc_to_array(conteo):
    return np.array(list(conteo.values()))

def vec_to_mat(vec,i=0):
    if i==0: return vec.reshape((-1,1))
    else: return vec.reshape((1,-1))


def array_to_dicc(conteo,letras="abcdefghijklmnñopqrstuvwxyz"):
    dicc={}
    for i,letter in enumerate(letras):
        dicc[letter]=conteo[i]
    return dicc

