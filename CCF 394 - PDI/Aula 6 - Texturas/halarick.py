""" Modulo Haralick
    contém a classe Haralick e suas métricas
"""

import numpy as np
import numpy.ma as ma
import time

class Haralick:
    '''
        A classe Haralick cria a matriz de co-ocorrência
        e calcula as métricas Homogeneidade, Entropia, SMA e Contraste.
    '''
    def __init__(self, mat, janela):
        self.metricas = np.zeros(shape=(4, 13))
        ng = (np.max(mat) + 1).astype(np.int)
        #print(ng)
        self.tempo = 0;
        inicio = time.time()
        matcoocorrencia(self, mat, janela, ng)
        fim = time.time()
        self.tempo = fim - inicio


# global ng
# ng = 256


def normalize(mD):  #normaliza a matriz entre 0 e ng
    #tratar casos de novalue que são sempre menores que zero
    if np.where(mD < 0):
        masked_data = ma.masked_where(mD < 0, mD)
        maximo = np.max(masked_data)
        minimo = np.min(masked_data)
    else:
        maximo = np.max(mD)
        minimo = np.min(mD)
    r=maximo - minimo
    if r == 0:
        r = maximo
    if r != 0:
        mD = (mD-minimo)/r
        mD *= 255
    return np.trunc(mD)

def imprimeMatriz(C):
        print(C[:, :, 0])
        print(C[:, :, 1])
        print(C[:, :, 2])
        print(C[:, :, 3])

def matcoocorrencia(self, mD, janela, ng):  #recebe a matriz de dados e retorna a de coocorrencia
    t=mD.shape
    #mD = normalize(mD)
    C = np.zeros(shape=(ng,ng,4), dtype=float)
    lin = (t[0] - 1)
    col = (t[1] - 1)

    #calculando as ocorrências
    #Direções 0-180 e 90-270
    for (i, j), x in np.ndenumerate(mD):
        if x < 0:
            continue
        x = int(x)
        l = i + janela
        k = j+janela
        if k <= col:
            y=int(mD[i, k])
            if y < 0:
                continue
            if ((0 <= x <= ng) and (0 <= y <= ng)): #para remover valores nulos
                C[x,y,0] += 1
                C[y,x,0] += 1
        if 0 <= l <= lin:
            y = int(mD[l, j])
            if ((0 <= x <= ng) and (0 <= y <= ng)):  # para remover valores nulos
                C[x, y, 1] += 1
                C[y, x, 1] += 1
    # Direções 45-225 e 135-315
    for (i, j), x in np.ndenumerate(mD):
        x = int(x)
        l = i + janela
        k = j - janela
        if (l <= lin) and (k >= 0):
            y = int(mD[l, k])
            if ((0 <= x <= ng) and (0 <= y <= ng)):  # para remover valores nulos
                C[x, y, 2] += 1
                C[y, x, 2] += 1
        k = j + janela
        if (l <= lin) and (k <= col):
            y = int(mD[l, k])
            if ((0 <= x <= ng) and (0 <= y <= ng)):  # para remover valores nulos
                C[x, y, 3] += 1
                C[y, x, 3] += 1

    #normalizando a saída
    for i in np.arange(0,4):
        s = sum(sum(C[:,:,i]))
        C[:, :, i] /= s

    del mD
    #imprimeMatriz(C)

    #calculando as métricas
    metricas_haralick(self, C, self.metricas, ng)

#Funções Auxiliares
def sumFeature(M, xx, yy, k):
    return np.sum(M[xx+yy==k])

def differenceFeature(M, xx, yy, k):
    return np.sum(M[np.absolute(xx-yy)==k])

#Função Principal
def metricas_haralick(self, M, metricas, ng):
    i = np.arange(0, ng)
    j = np.arange(0, ng)
    ii, jj = np.meshgrid(i, j, indexing='ij')  # ii -> linhas; jj -> colunas
    for i in np.arange(0, 4):
        calcula_metricas(self, M[:, :, i], self.metricas, ii, jj, i, ng)

#Função executora
def calcula_metricas(self, M, metricas, ii, jj, i, ng):
    #1. SMA ou Energia
    s = pow(M, 2)
    s = sum(sum(s))
    metricas[i, 0] = s
    #2. CONTRASTE
    n = (ii - jj) ** 2
    metricas[i, 1] = np.sum(n * M)
    #3. ENTROPIA
    metricas[i, 2] = -np.sum(M * np.log(M + 0.000001))
    #4. VARIÂNCIA
    mx = np.sum(ii * M)
    t = (ii - mx) ** 2
    metricas[i, 3] = np.sum(t * M)
    #5. CORRELACAO
    my = np.sum(jj * M)
    ox = np.sqrt(np.sum(M*((ii-mx)**2)))
    oy = np.sqrt(np.sum(M * ((jj - my) ** 2)))
    corr = (ii-mx)*(jj-my)*M
    metricas[i, 4] = np.sum(corr/(ox*oy))
    #6. HOMOGENEIDADE
    zz = 1 + (ii-jj)**2
    metricas[i, 5] = np.sum((1/zz)*M)
    #7. SUM AVERAGE 8. SUM ENTROPY 9. SUM VARIANCE
    vetk = np.zeros(2 * (ng - 1) + 1)
    lk = np.arange(0, 2 * (ng - 1) + 1)
    for k in lk:
        vetk[k] = sumFeature(M, ii, jj, k)
    metricas[i, 6] = np.sum(lk * vetk)
    metricas[i, 7] = -np.sum(vetk*np.log(vetk+0.000001))
    metricas[i, 8] = np.sum(((lk-metricas[i, 6])**2)*vetk)
    #10. DIFFERENCE VARIANCE 11. DIFERENCE ENTROPY
    vetk = np.zeros(ng)
    lk = np.arange(0, ng)
    for k in lk:
        vetk[k] = differenceFeature(M, ii, jj, k)
    aux = np.sum(lk*vetk)
    aux2 = ((lk-aux)**2)
    metricas[i, 9] = np.sum(aux2*vetk)
    metricas[i, 10] = -np.sum(vetk * np.log(vetk + 0.000001))
    #INFORMATION MEASURES OF CORRELATION 12. FEATURE 1 13. FEATURE 2
    px = np.sum(M, axis=0)
    py = np.sum(M, axis=1)
    xx, yy = np.meshgrid(px,py)
    hx = -np.sum(px * np.log(px + 0.000001))
    hy = -np.sum(py * np.log(py + 0.000001))
    hxy1 = -np.sum(M*np.log((xx*yy)+ 0.000001))
    metricas[i, 11] = (metricas[i,2]-hxy1)/np.maximum(hx,hy)
    hxy2 = -np.sum((xx*yy)*np.log((xx*yy)+ 0.000001))
    metricas[i, 12] = np.sqrt(1 - np.exp(-2 * (hxy2 - metricas[i, 2])))

if __name__ == '__main__':
   pass
