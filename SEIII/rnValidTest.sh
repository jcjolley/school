#!/bin/bash

function sendInput(){
    echo generateRoman | ./a.out
    echo "What the heck"
    echo "quit" | ./a.out
}

function generateRoman() {
    return 1 
}

function echoAndSend(){
    echo generateRoman
    sendInput
}

#for i in 'seq 1 10';
#do
#echoAndSend
#done
sendInput
