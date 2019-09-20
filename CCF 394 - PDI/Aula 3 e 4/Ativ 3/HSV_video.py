
import cv2
import numpy as np

cap = cv2.VideoCapture("videocanetas.mp4")

while(True):

    # Take each frame
    ret , frame = cap.read()
    if not ret: #final do vídeo
        break
    if ret == True:
        # Convert BGR to HSV
        hsv = cv2.cvtColor(frame, cv2.COLOR_BGR2HSV)

        # define range of blue color in HSV
        lower_blue = np.array([110,50,50])
        upper_blue = np.array([130,255,255])

        # define range of green color in HSV
        lower_green = np.array([30, 50, 50])
        upper_green = np.array([50, 255, 255])

        # define range of red color in HSV
        lower_red = np.array([160, 50, 50])
        upper_red = np.array([180, 255, 255])

        # define range of black color in HSV
        lower_black = np.array([130, 50, 50])
        upper_black = np.array([160, 255, 255])


        # Threshold the HSV image to get only blue colors
        mask_blue= cv2.inRange(hsv, lower_blue, upper_blue)
        # Threshold the HSV image to get only red colors
        mask_red = cv2.inRange(hsv, lower_red, upper_red)
        # Threshold the HSV image to get only green colors
        mask_green = cv2.inRange(hsv, lower_green, upper_green)
        # Threshold the HSV image to get only black colors
        mask_black = cv2.inRange(hsv, lower_black, upper_black)


        # Bitwise-AND mask and original image
        res_blue = cv2.bitwise_and(frame,frame, mask= mask_blue)
        res_red = cv2.bitwise_and(frame,frame, mask= mask_red)
        res_green = cv2.bitwise_and(frame,frame, mask= mask_green)
        res_black = cv2.bitwise_and(frame,frame,mask= mask_black)

        res_2 = cv2.bitwise_and(res_green,res_blue)
        res_3 = cv2.bitwise_and(res_2,res_red)


        #Salve the last frame
        cv2.imwrite("im_blue.png",res_blue)
        cv2.imwrite("im_black.png",res_black)
        cv2.imwrite("im_green.png",res_green)
        cv2.imwrite("im_red.png",res_red)


        cv2.imshow('res_blue',res_blue)
        cv2.imshow('res_red',res_red)
        cv2.imshow('res_green',res_green)
        cv2.imshow('res_black',res_black)
        cv2.imshow('res_3',res_3)


        #Salvando o video
        frame_width = int(cap.get(3))
        frame_height = int(cap.get(4))

        out_green = cv2.VideoWriter('saida_green.avi',cv2.VideoWriter_fourcc('M','J','P','G'), 60, ( frame_width , frame_height))
        out_black = cv2.VideoWriter('saida_black.avi',cv2.VideoWriter_fourcc('M','J','P','G'), 10, ( frame_width , frame_height))
        out_red = cv2.VideoWriter('saida_red.avi',cv2.VideoWriter_fourcc('M','J','P','G'), 10, ( frame_width , frame_height))
        out_blue = cv2.VideoWriter('saida_blue.avi',cv2.VideoWriter_fourcc('M','J','P','G'), 10, ( frame_width , frame_height))

        out_green.write((res_green).astype(np.uint8))
        out_black.write((res_black).astype(np.uint8))
        out_red.write((res_red).astype(np.uint8))
        out_blue.write((res_blue).astype(np.uint8))

        k = cv2.waitKey(5) & 0xFF
        if k == 27:
            cap.release()
            break

out_blue.release()
out_red.release()
out_black.release()
out_green.release()
cv2.destroyAllWindows()
