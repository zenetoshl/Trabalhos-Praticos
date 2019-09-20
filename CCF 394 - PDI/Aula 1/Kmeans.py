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
    for y in range(4, 9):
        K = y
        ret, label, center = cv2.kmeans(Z, K, None, criteria, 10, cv2.KMEANS_RANDOM_CENTERS)

        # Now convert back into uint8, and make original image
        center = np.uint8(center)
        res = center[label.flatten()]
        res2 = res.reshape((img.shape))

        cv2.imshow('res'+y.__str__(), res2)
        print(center)
        print(label)
    cv2.waitKey(0)
    cv2.destroyAllWindows()
