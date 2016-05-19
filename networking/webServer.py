#!/usr/bin/python
#######################################################################
# Program:
#    Lab PythonWebServer, Computer Communication and Networking
#    Brother Jones, CS 460
# Author:
#    Joshua Jolley
# Summary:
#    A simple web server implemented in python
#    Time Spent: 2.5 hrs
#    Resources used: 
#       https://docs.python.org/2/library/mimetypes.html
#       http://www.tutorialspoint.com/python/python_functions.htm
#       Lab 1's java code
#######################################################################

import sys
import mimetypes
from socket import *

DEFAULT_VALUE = 6789

##########################################################
# GetPort
# read port from command line
#########################################################
def getPort():
    serverPort = int(sys.argv[1]) if len(sys.argv) == 2 else DEFAULT_VALUE
    return serverPort

##########################################################
# SetupSocket
# setup listening socket
#########################################################
def setupSocket(serverPort):
    serverSocket = socket(AF_INET, SOCK_STREAM)
    serverSocket.bind(('', serverPort))
    serverSocket.listen(1)
    print 'The HTTP Server is ready to recieve requests'
    return serverSocket

##########################################################
# GetFilename
# get the filename requested
#########################################################
def getFilename(request):
    try:
        filename = request.split(' ', 3)[1]
        filename = '.' + filename
        return filename, False
    except IndexError as e:
        return "ERROR", True
        print "ERROR: Could not get the filename from the request\n" + e

##########################################################
# LoadFile
# load the file
#########################################################
def loadFile(filename):
    try: 
        with open(filename,"rb") as fin: 
            myfile = fin.read()
            return myfile, False
    except IOError as e:
        return "ERROR", True
        print "ERROR: Cannot read the file or file not found\n" + e

##########################################################
# CreateResponse
# form a response
#########################################################
def createResponse(filename, myfile, error):
    if error:
        statusLine = "HTTP/1.0 404 Not Found\r\n"
        contentTypeLine = "text/html; charset=utf-8\r\n\r\n"
        entityBody = "<HTML><HEAD></HEAD><BODY>404 NOT FOUND</BODY></HTML>"
    else:
        statusLine = "HTTP/1.0 200 OK\r\n"
        contentTypeLine = "Content-type: " + mimetypes.guess_type(filename)[0] + "\r\n\r\n"
        entityBody = myfile

    response = statusLine + contentTypeLine + entityBody
    return response

##########################################################
# ListenForRequests
# listen for requests and respond appropriately
#########################################################
def listenForRequests(serverSocket): 
    while 1:
        error = False
    
        #accept a connection
        connectionSocket, addr = serverSocket.accept()

        #recieve the response
        request = connectionSocket.recv(2048)
        print request
   
        #get the filename
        filename, filenameError = getFilename(request)
    
        #load the file
        myfile, loadFileError = loadFile(filename)
    
        #form a response
        response = createResponse(filename, myfile, (filenameError or loadFileError))
    
        #send the response
        connectionSocket.send(response)
        connectionSocket.close()
    
    return

##########################################################
# Main
#########################################################
port = getPort()

socket = setupSocket(port)

listenForRequests(socket)
