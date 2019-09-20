import cv2
import numpy as np
import matplotlib.pyplot as plt

digital = cv2.imread('MicroHematuria.JPG')
digitalCinza = cv2.cvtColor(digital, cv2.COLOR_BGR2GRAY)
digitalGauss = cv2.GaussianBlur(digitalCinza, (3, 3), 0)

#canny
digitalCanny = cv2.Canny(digitalCinza, 40, 100)

#prewitt
kernelx = np.array([[1, 1, 1], [0, 0, 0], [-1, -1, -1]])
kernely = np.array([[-1, 0, 1], [-1, 0, 1], [-1, 0, 1]])
digitalPrewittX = cv2.filter2D(digitalGauss, -1, kernelx)
digitalPrewittY = cv2.filter2D(digitalGauss, -1, kernely)
digitalPrewitt = digitalPrewittX + digitalPrewittY

#sobel
digitalSobelV = cv2.Sobel(digitalGauss, cv2.CV_8U, 1, 0, ksize=3)
digitalSobelH = cv2.Sobel(digitalGauss, cv2.CV_8U, 0, 1, ksize=3)
digitalSobel = digitalSobelH + digitalSobelV

#treshold otsu
retC, Cbin = cv2.threshold(digitalCinza, 0, 255, cv2.THRESH_BINARY+cv2.THRESH_OTSU)

th3 = cv2.adaptiveThreshold(digitalGauss, 255, cv2.ADAPTIVE_THRESH_GAUSSIAN_C, cv2.THRESH_BINARY, 11, 2)
ret, thresh3 = cv2.threshold(digitalGauss, 127, 255, cv2.THRESH_TRUNC)

cv2.imshow('Original', digital)
cv2.imshow('Cinza', digitalCinza)
cv2.imwrite('Hema_Cinza.png', digitalCinza)
cv2.imshow('Canny', digitalCanny)
cv2.imwrite('Hema_Canny.png', digitalCanny)
cv2.imshow('Prewitt', digitalPrewitt)
cv2.imwrite('Hema_Prewitt.png', digitalPrewitt)
cv2.imshow('Sobel', digitalSobel)
cv2.imwrite('Hema_Sobel.png', digitalSobel)
cv2.imshow('otsu', Cbin)
cv2.imwrite('Hema_otsu.png', Cbin)
cv2.imshow('otsu gauss', th3)
cv2.imwrite('Hema_otsu_gauss.png', th3)
cv2.imshow('truncamento', thresh3)
cv2.imwrite('Hema_truncamento.png', thresh3)
cv2.waitKey(0)
cv2.destroyAllWindows()
