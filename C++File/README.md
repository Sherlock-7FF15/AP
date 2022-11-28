# README

Name: Jiahe Zhang

USCID: 4614932748

## What I have finished

I have implemented all functions in both regular and extra credit parts.

## Code File

There are totally 5 .cpp and 3 txt fils.

### cpp

client.cpp

* The client.cpp is client server. 
* Client client server should boot up after the main server.

serverM.cpp

* The serverM.cpp is the main server, which is the core server in the project. Without main server, client can not boot up.

serverC.cpp

* The serverC.cpp is the credential server, which can access cred.txt database and provide identity authentication service for client.

serverCS.cpp

* The serverCS is the server belongs to CS department. It can provide course information about CS department for main server.

serverEE.cpp

* The serverCS is the server belongs to CS department. It can provide course information about CS department for main server.

### txt

cred.txt

* It stores all the encrypted credentials of the registered users

ee.txt

* It stores all the course information in EE department

cs.txt

* It stores all the course information in CS department

## Format of message exchanged

### client.cpp

* The username and password are stored and sent in a single array, and they are splited by char ','.
* client can only access serverM using TCP connection. The port number is allocated dymaticlly by OS.
* If login information is authenticated, serverM will return an int status 0. If the username was not found, the serverM will return an int status -1. If the password was not found, the serverM will return an int status 1. 
* If the department server didn't find the course, it will return string "Didn't find the course: XX" instead a bool or an int sign.
* If user requested multi query (extra credit), the result will be stored in a 1 dimentional array and each result will be splited by char '\n'.

###serverM.cpp

* The serverM will encrypt message from server and store it in a 1 dimentional int array.
* Message exchanged between serverC and client through serverM are all in 1 dimentional int array with maximum space 1024.
* ServerM will distinguish query request from the client through the number of ",". If there is a ",", it is a normal query, else it is a multi query.
* ServerM will distinguish query request from the client through the first character of the message. If the first character is "E", then it will forward the request to serverEE. If the first character is "C", serverM will forward the message to serverCS.
* Information exchanged between serverM and serverCS, serverEE are all in 1 dimentional char array.
* ServerM communicate with client through TCP over port 24578. Other conmmunications using UDP over port number 24748.

### serverC.cpp

* ServerC only can access information after encryption.
* ServerC will distinguish username and password through char '\n'.
* If the information are in cred.txt, serverC will send 0 to serverM. If password doesn't match, it will send -1 if username doesn't match. If username is not found, it will send 1.
* ServerC connect with serverM by UDP over port 21748.

### serverCS.cpp and serverEE.cpp

* Given the simularity of the function of these two server, their codes are almost the same.
* The server distinguish normal query and multi query by the number of "," in query message. If there is a ",", it is a single query.
* If the server didn't find the course code, it will return a string "Didn't find the course: XXX" directly in normal query. It will return a null array if in multi query.

## Idiosyncracy

* Please do NOT include "," in either username and password! Else it will cause some problems.
* I assumed that all course codes consisted of 5 chars, which is "EEXXX" or "CSXXX". Please make sure the input course codes are exactly 5 chars. Else it will cause some problems.

## Reuse Code

No.