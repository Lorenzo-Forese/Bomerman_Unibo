#!/bin/bash

# Compila i file c++
g++ main.cpp finestre.cpp impostazioni.cpp lang.cpp selezioni.cpp mapparandom.cpp -lncurses -o main

# Controlla se la compilazione avviene in maniera corretta
if [ $? -eq 0 ]; then
    # Fa partire il programma in modalita fullscreen

    # Ingrandisce la finestra del terminale
    xdotool search --name "Terminal" windowactivate --sync key F11

    # Esegue il programma
    ./main
else
    echo "Compilation failed."
fi
