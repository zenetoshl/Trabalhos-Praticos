import cv2,argparse,glob
import numpy as np

# mouse callback function
def showPixelValue(event,x,y,flags,param):
    global img, combinedResult, placeholder
    if event == cv2.EVENT_LBUTTONDOWN:
        bgr = img[y,x]
        print("BGR",bgr)
        ycb = cv2.cvtColor(np.uint8([[bgr]]),cv2.COLOR_BGR2YCrCb)[0][0]
        lab = cv2.cvtColor(np.uint8([[bgr]]),cv2.COLOR_BGR2Lab)[0][0]
        hsv = cv2.cvtColor(np.uint8([[bgr]]),cv2.COLOR_BGR2HSV)[0][0]
        print("YCB",ycb)
        print("Lab",lab)
        print("HSV",hsv)
        
    if event == cv2.EVENT_MOUSEMOVE:
        # get the value of pixel from the location of mouse in (x,y)
        bgr = img[y,x]
     

        # Convert the BGR pixel into other colro formats
        ycb = cv2.cvtColor(np.uint8([[bgr]]),cv2.COLOR_BGR2YCrCb)[0][0]
        lab = cv2.cvtColor(np.uint8([[bgr]]),cv2.COLOR_BGR2Lab)[0][0]
        hsv = cv2.cvtColor(np.uint8([[bgr]]),cv2.COLOR_BGR2HSV)[0][0]
        
        # Create an empty placeholder for displaying the values
        placeholder = np.zeros((img.shape[0],400,3),dtype=np.uint8)

        # fill the placeholder with the values of color spaces
        cv2.putText(placeholder, "BGR {}".format(bgr), (20, 70), cv2.FONT_HERSHEY_COMPLEX, .9, (255,255,255), 1, cv2.LINE_AA)
        cv2.putText(placeholder, "HSV {}".format(hsv), (20, 140), cv2.FONT_HERSHEY_COMPLEX, .9, (255,255,255), 1, cv2.LINE_AA)
        cv2.putText(placeholder, "YCrCb {}".format(ycb), (20, 210), cv2.FONT_HERSHEY_COMPLEX, .9, (255,255,255), 1, cv2.LINE_AA)
        cv2.putText(placeholder, "LAB {}".format(lab), (20, 280), cv2.FONT_HERSHEY_COMPLEX, .9, (255,255,255), 1, cv2.LINE_AA)
        
        # Combine the two results to show side by side in a single image
        combinedResult = np.hstack([img,placeholder])
        
        cv2.imshow('Pressione  A para Anterior, P para proxima imagem',combinedResult)


if __name__ == '__main__' :
     
    # load the image and setup the mouse callback function
    global img
    files = glob.glob('im*.png')
    files.sort()
    cap = cv2.VideoCapture("videocanetas.mp4")
    ret, frame = cap.read()
    img = cv2.imread(files[0])
    img = cv2.resize(img,(400,600))
    cv2.imshow('Pressione  A para Anterior, P para proxima imagem',img)

    # Create an empty window
    cv2.namedWindow('Pressione  A para Anterior, P para proxima imagem')
    # Create a callback function for any event on the mouse
    cv2.setMouseCallback('Pressione  A para Anterior, P para proxima imagem',showPixelValue)
    i = 0
    while(1):
        k = cv2.waitKey(1) & 0xFF
        # check next image in the folder
        if k == ord('p'):
            i += 1
            img = cv2.imread(files[i%len(files)])
            img = cv2.resize(img,(400,400))
            cv2.imshow('Pressione  A para Anterior, P para proxima imagem',img)
 
        # check previous image in folder
        elif k == ord('a'):
            i -= 1
            img = cv2.imread(files[i%len(files)])
            img = cv2.resize(img,(400,400))
            cv2.imshow('Pressione  A para Anterior, P para proxima imagem',img)

        elif k == 27:
            cv2.destroyAllWindows()
            break
