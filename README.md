# PATH TO TXT AND CSV NEED TO BE CHANGED TO THE ABSOLUTE PATH OF THE LOCAL COMPUTER

mainwindow.cpp -> line 193
QString absolutePath = "C:/PATH/" + user + ".csv";

engine.cpp -> line 17
dictionary = readFromFile("C:/PATH/words.txt", wordLength);
