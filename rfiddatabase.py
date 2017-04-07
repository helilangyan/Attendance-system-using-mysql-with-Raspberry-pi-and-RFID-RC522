#!/usr/bin/python
import serial
import time
import MySQLdb
#establish connection to MYSQL.
dbConn=MySQLdb.connect("localhost","root","Deligence123","rfidesp") or die ("could not connect to data$
#open a cursor to the database
device="""/dev/ttyUSB0"""
try:
    print "Trying...",device
    arduino=serial.Serial(device,9600)
except:
    print"Failed to connect on",device
while True:
    time.sleep(1)
    try:
        data=arduino.readline() #read data from arduino
        print data
        pieces=data.split("  ") #split data by tab
        try:
            cursor=dbConn.cursor()
            cursor.execute("""INSERT INTO rfesp(ID,RFIDNUM,RFIDTAGSERIES) VALUES(NULL,%s,%s)""",(piece$
            dbConn.commit()
 #commit the insert
            cursor.close() #close the cursor
        except MYSQLdb.IntegrityError:
            print"failed to insert data"
        finally:
            cursor.close() # close incase it failed
    except:
        print"Processing!"

