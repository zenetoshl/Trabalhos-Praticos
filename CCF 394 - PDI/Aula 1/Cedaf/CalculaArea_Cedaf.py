import numpy as np
import cv2

if __name__ == '__main__':
    img = cv2.imread('imagemCedaf.png')
    Z = img
    Z = img.reshape((-1,3))

    # convert to np.float32
    Z = np.float32(Z)

    # define criteria, number of clusters(K) and apply kmeans()
    criteria = (cv2.TERM_CRITERIA_EPS + cv2.TERM_CRITERIA_MAX_ITER, 10, 1.0)
    K = 4
    ret,label,center=cv2.kmeans(Z,K,None,criteria,10,cv2.KMEANS_RANDOM_CENTERS)

    # Now convert back into uint8, and make original image
    center = np.uint8(center)
    res = center[label.flatten()]
    res2 = res.reshape((img.shape))

    def createMask(img, color, threshhold):
        lower = [x * (1.0 - threshhold) for x in color]
        upper = [x * (1.0 + threshhold) for x in color]
        return cv2.inRange(img, np.array(lower), np.array(upper))


    estrada = createMask(res2, center[2],0.2)
    florest = createMask(res2, center[1], 0.2)
    land = createMask(res2, center[0], 0.2)
    lake = createMask(res2, center[3], 0.2)


    cv2.imshow('Estrada', estrada)
    cv2.imshow('Florest', florest)
    cv2.imshow('Land', land)
    cv2.imshow('Lake', lake)

     # cv2.np.array(city)

    cv2.imshow('Output_Estrada', cv2.bitwise_and(cv2.cvtColor(estrada, cv2.COLOR_GRAY2RGB), img))
    cv2.imshow('Output_Florest', cv2.bitwise_and(cv2.cvtColor(florest, cv2.COLOR_GRAY2RGB), img))
    cv2.imshow('Output_Land', cv2.bitwise_and(cv2.cvtColor(land, cv2.COLOR_GRAY2RGB), img))
    cv2.imshow('Output_Lake', cv2.bitwise_and(cv2.cvtColor(lake, cv2.COLOR_GRAY2RGB), img))
    #Area
    print('Output_City', (cv2.sumElems(estrada)[0] / 255)*0.5,'m²')
    print('Output_Florest', (cv2.sumElems(florest)[0] / 255)*0.5,'m²')
    print('Output_Land', (cv2.sumElems(land)[0] / 255)*0.5, 'm²' )
    print('Output_Lake', (cv2.sumElems(lake)[0] / 255)*0.5, 'm²' )

    # cv2.imshow('ori')
    cv2.imshow('res2',res2)
    cv2.waitKey(0)
    cv2.destroyAllWindows()
    print(center)
    print(label)
