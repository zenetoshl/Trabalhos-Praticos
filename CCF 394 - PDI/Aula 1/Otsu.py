import cv2
import numpy as np
from matplotlib import pyplot as plt


if __name__ == '__main__':

    orig = cv2.imread("imagemCedaf.png")



    (B, G, R) = cv2.split(orig)
    cv2.imshow("Original", orig)
    cv2.imshow("Azul", B)
    cv2.imshow("Verde", G)
    cv2.imshow("Vermelho", R)

    img_grey = cv2.cvtColor(orig, cv2.COLOR_BGR2GRAY)
    ret,otsu = cv2.threshold(img_grey, 0, 255, cv2.THRESH_BINARY + cv2.THRESH_OTSU)
    ret,otsuB = cv2.threshold(B, 0, 255, cv2.THRESH_BINARY + cv2.THRESH_OTSU)
    ret,otsuG = cv2.threshold(G, 0, 255, cv2.THRESH_BINARY + cv2.THRESH_OTSU)
    ret,otsuR = cv2.threshold(R, 0, 255, cv2.THRESH_BINARY + cv2.THRESH_OTSU)

    cv2.imshow('otsu',otsu)
    cv2.imshow('otsuG',otsuG)
    cv2.imshow('otsuB',otsuB)
    cv2.imshow('otsuR',otsuR)
    cv2.waitKey(0)