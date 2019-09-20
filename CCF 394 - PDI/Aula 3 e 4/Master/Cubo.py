import numpy as np
import cv2


if __name__ == '__main__':
    orig = cv2.imread("images/rub00.jpg")
    lab = cv2.cvtColor(orig, cv2.COLOR_BGR2LAB)

    cv2.imshow("lab", lab)
    l,a,b=cv2.split(lab)
    cv2.imshow("l", l)
    cv2.imshow("a", a)
    cv2.imshow("b", b)

    (B, G, R) = cv2.split(orig)
    cv2.imshow("Original", orig)
    cv2.imshow("Azul", B)
    cv2.imshow("Verde", G)
    cv2.imshow("Vermelho", R)


    cv2.waitKey(0)
