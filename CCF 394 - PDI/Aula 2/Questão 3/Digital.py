import cv2
import numpy as np
import matplotlib.pyplot as plt
from skimage.filters import roberts,sobel


digital = cv2.imread('impressaodigital.png')
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

#roberts
digitalRoberts = roberts(digitalCinza)
fig, ax = plt.subplots(ncols=1, sharex=True, sharey=True, figsize=(8, 4))
ax.imshow(digitalRoberts, cmap=plt.cm.gray)
ax.set_title('Roberts')
ax.axis('off')

plt.tight_layout()
plt.show()

#mostrar imagens
cv2.imshow('Original', digital)
cv2.imshow('Cinza', digitalCinza)
cv2.imwrite('Digital_Cinza.png', digitalCinza)
cv2.imshow('Canny', digitalCanny)
cv2.imwrite('Digital_Canny.png', digitalCanny)
cv2.imshow('Prewitt', digitalPrewitt)
cv2.imwrite('Digital_Prewitt.png', digitalPrewitt)
cv2.imshow('Sobel', digitalSobel)
cv2.imwrite('Digital_Sobel.png', digitalSobel)
cv2.waitKey(0)
cv2.destroyAllWindows()
