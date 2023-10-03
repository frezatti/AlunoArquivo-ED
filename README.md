# AlunoArquivo-ED
this project uses a the QFile lib to open the ArquivoAlunoDisciplina2023.csv file to get the student information.
the file does need to be in the correct format to avoid any weird behavior, like crashes and misplaced text.
When opening the project you will see that there is no file path to the ArquivoAlunoDisciplina2023.csv i use the QFileDialog library to find the file path and display.
i used the QT Creator ide to create this project.
the main logic of the program is in the controler class that is where all the information is gathered from the file, and put in its correct place.
The interface of the program interface is dependent on the file that it opens, for example if the classes are diferent the options to sort them by will change so its kind of dinamic the options that you get to order the data, because its based 
on the file that was opened, also the screen hides and shows relevant part of the screen based on what the search needs so if you need to type a search bar will appear if you need to pick an option a combobox will appear.

this project was made last semester for my data structuer class.
