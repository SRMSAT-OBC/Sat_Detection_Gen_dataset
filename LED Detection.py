import cv2
import numpy as np
cap=cv2.VideoCapture(0)
c=0
while True:
    _,frame=cap.read()  
    hsv=cv2.cvtColor(frame,cv2.COLOR_BGR2HSV)
    lower_ledg=np.array([25,52,72])
    upper_ledg=np.array([102,255,255])
    lower_ledb=np.array([94,80,2])
    upper_ledb=np.array([126,255,255])
    lower_ledr=np.array([161,155,84])
    upper_ledr=np.array([179,255,255])
    lower_ledp=np.array([50,0,500])
    upper_ledp=np.array([150,50,150])
    lower_ledq=np.array([0,50,50])
    upper_ledq=np.array([0,255,255])
    mask_ledg=cv2.inRange(hsv,lower_ledg,upper_ledg)
    mask_ledb=cv2.inRange(hsv,lower_ledb,upper_ledb)
    mask_ledr=cv2.inRange(hsv,lower_ledr,upper_ledr)
    mask_ledp=cv2.inRange(hsv,lower_ledp,upper_ledp)
    mask_ledq=cv2.inRange(hsv,lower_ledq,upper_ledq)
    mask1=mask_ledg+mask_ledb+mask_ledr+mask_ledp+mask_ledq
    if mask_ledg.any():
        points = cv2.findNonZero(mask_ledg)
        for [[x,y]] in points:
            if c%4==0:
                np.average(points)
                st1="GREEN="+str(x)+','+str(y)
            else:
                c+=0.0001
    else:
        st1="GREEN="+"0,0" 
    if mask_ledb.any():
        points2 = cv2.findNonZero(mask_ledb)
        for [[x,y]] in points2:
            if c%4==0:
                np.average(points2)
                st2="BLUE="+str(x)+','+str(y)
            else:
                c+=0.0001
    else:
        st2="BLUE="+"0,0" 
    if mask_ledr.any():
        points3 = cv2.findNonZero(mask_ledr)
        for [[x,y]] in points3:
            if c%4==0:
                np.average(points3)
                st3="RED="+str(x)+','+str(y)
            else:
                c+=0.0001
    else:
        st3="RED="+"0,0"
    if mask_ledp.any():
        points4 = cv2.findNonZero(mask_ledp)
        for [[x,y]] in points4:
            if c%4==0:
                np.average(points4)
                st4="PURPLE="+str(x)+','+str(y)
            else:
                c+=0.0001
    else:
        st4="PURPLE="+"0,0"
    if mask_ledq.any():
        points5 = cv2.findNonZero(mask_ledq)
        for [[x,y]] in points5:
            if c%4==0:
                np.average(points5)
                st5="YELLOW="+str(x)+','+str(y)
            else:
                c+=0.0001
    else:
        st5="YELLOW="+"0,0"
    res_ledg=cv2.bitwise_and(frame,frame,mask=mask1)
    gray=cv2.cvtColor(res_ledg,cv2.COLOR_BGR2GRAY)
    if res_ledg.any():
        points6 = cv2.findNonZero(gray)
        for [[x,y]] in points6:
            np.average(points6)
            cv2.circle(res_ledg,(x,y),10,(225,255,0),1)
    kernel=np.ones((15,15),np.float32)/225
    smoothedg=cv2.filter2D(res_ledg,-1,kernel)
    cv2.putText(res_ledg, st1, (530,380),cv2.FONT_HERSHEY_TRIPLEX, 0.4, (255, 255, 0), 1)
    cv2.putText(res_ledg, st2, (530,390),cv2.FONT_HERSHEY_TRIPLEX, 0.4, (255, 255, 0), 1)
    cv2.putText(res_ledg, st3, (530,400),cv2.FONT_HERSHEY_TRIPLEX, 0.4, (255, 255, 0), 1)
    cv2.putText(res_ledg, st4, (530,410),cv2.FONT_HERSHEY_TRIPLEX, 0.4, (255, 255, 0), 1)
    cv2.putText(res_ledg, st5, (530,420),cv2.FONT_HERSHEY_TRIPLEX, 0.4, (255, 255, 0), 1)
    cv2.imshow("Not_Original_Its_Copied",res_ledg)
    k = cv2.waitKey(1)
    if k == 27:
        break
cv2.destroyAllWindows()
cap.release()









