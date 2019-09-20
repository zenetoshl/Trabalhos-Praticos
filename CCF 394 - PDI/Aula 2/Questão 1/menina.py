import cv2
import matplotlib.pyplot as plt

#transformar em cinza e depois equalizar
menina = cv2.imread('menina.jpg')
meninaCinza = cv2.cvtColor(menina, cv2.COLOR_BGR2GRAY)

meninaEqualizada = cv2.equalizeHist(meninaCinza) #histogramas

#preparar histogramas
plt.hist(meninaCinza.ravel(), 256, [0, 256])
plt.hist(meninaEqualizada.ravel(), 256, [0, 256])
plt.show()

#mostrar imagens
cv2.imshow('resultado', meninaEqualizada)
cv2.imwrite('menina_equa.png', meninaEqualizada)
cv2.imshow('original', meninaCinza)
cv2.imwrite('menina_ori.png', meninaCinza)
cv2.waitKey(0)
cv2.destroyAllWindows()
