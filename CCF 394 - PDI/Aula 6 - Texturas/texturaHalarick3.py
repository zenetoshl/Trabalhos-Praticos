from skimage.feature import greycomatrix,greycoprops
import cv2
import numpy as np
import csv

#funcaodopacoteskimageparacalcularamatrizGLCMeosatributosdamatriz

#image_path="/home/user/image.png"#enderecodaimagem
image=cv2.imread("grama2.jpg")#leituradaimagem
image_gray= cv2.cvtColor(image, cv2.COLOR_RGB2GRAY)#transformardeRGBparaniveldecinza
d=1#distanciaentrepixelsparaGLCM
print(image.shape)
matrix=greycomatrix(image_gray,[d],[0],normed=True)
#calculodamatrizem0graus

props=np.zeros((6))#vetorparaarmazenaratributos
props[0]=greycoprops(matrix,"contrast")#calculacontrast
props[1]=greycoprops(matrix,"dissimilarity")#calculadissimilaridade
props[2]=greycoprops(matrix,"homogeneity")#calculahomogeneidade
props[3]=greycoprops(matrix,"energy")#calculaenergia
props[4]=greycoprops(matrix,"correlation")#calculacorrelacao
props[5]=greycoprops(matrix,"ASM")#calculasegundomomentoangula
print(props)
