import cv2
import numpy as np
cap=cv2.VideoCapture(0)
c=0
while True:
    _,frame=cap.read()  
    gaussian=cv2.GaussianBlur(frame,(5,5),2)
    lower_led=np.array([230,230,230])
    upper_led=np.array([255,255,255])
    mask_led=cv2.inRange(gaussian,lower_led,upper_led)
    if mask_led.any():
        points = cv2.findNonZero(mask_led)
        for [[x,y]] in points:
            if c%4==0:
                np.average(points)
                st=str(x)+','+str(y)
            else:
                c+=0.0001
    res_led=cv2.bitwise_and(frame,frame,mask=mask_led)
    cv2.putText(res_led, st, (555,420),cv2.FONT_HERSHEY_TRIPLEX, 0.4, (255, 255, 0), 1)
    cv2.imshow("Not_Original_Its_Copied",res_led)
    k = cv2.waitKey(1)
    if k == 27:
        break
cv2.destroyAllWindows()
cap.release()