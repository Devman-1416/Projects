import os
import shutil

#Gets the user input file path, where you want to organize
def get_path():
    #Get File Path From user, validates it

    while True:
        path = input(r"Enter Directory/Folder Path: ")
        try:
            #Checks File Path, return booloan
            os.path.isdir(path)
            return path

        except:
            print("Error: [",path,"] Not a Valid Path!\nTry Again\n")

#Get the folder contents to be latter used for comparing
def get_folder(path):
    #Get folder contents from using Path entered
    try:
        # Prints and stores all file names int folder
        return os.listdir(path)

    except FileNotFoundError:
        print("Error Finding Folder Contents!")
        return []

#Make folders (It not already made) and move files into apportiate ones
def move_and_make(folder,path,CATEGORIES):
    try:
        count = 0
        for item in folder:
            # Spilts Name and extention
            root, ext = os.path.splitext(item)
            found = 0


            #Start At Category ex. Images
            for name  in CATEGORIES:

                #Look and compare the ext from the file to the extentions store in current category ex. [".jpg", ".png", ".jpeg", ".gif"]
                for type in CATEGORIES[name]:

                    #When File Matches A cateforgy thats not Misc, make folder and move file
                    if ext == type:
                        #Combine the Current Path directory and make folder if not there
                        destination = os.path.join(path, name)
                        os.makedirs(destination, exist_ok=True)

                        #Move File       #Source is Path .etx    #Move to folder with folder Name
                        shutil.move(os.path.join(path, item), os.path.join(destination, item))
                        count+=1
                        found = 1

            #If Not a folders and Is a Misc
            if found == 0 and os.path.isfile(os.path.join(path, item)):
                #Combine the Current Path directory and make folder if not there
                destination = os.path.join(path, "Misc")
                os.makedirs(destination, exist_ok=True)

                #Move File       #Source is Path .etx    #Move to folder with folder Name
                shutil.move(os.path.join(path, item), os.path.join(destination, item))
                count+=1

        #Display Results
        if count != 0: print("\nFiles Moved:", count)
        else: print("\nNothing to sort!")

        print("Targeted Directory: ",path)
        print("Contents:",os.listdir(path))

    except:
        print("Error Making Directories")


#------------------------------Main--------------------------------

#Dictionary
CATEGORIES = {
    "Images": [".jpg", ".png", ".jpeg", ".gif"],
    "Documents": [".txt", ".pdf", ".docx"],
    "Code": [".py", ".js", ".html", ".css"],
    "Archives": [".zip", ".rar", ".7z"],
    "Misc": []
}

print("\n-----------File Sorter-------------\n")

while True:

    # Get The path to the folder and store contents
    path = get_path()
    folder = get_folder(path)

    # If folder not empty
    if folder != []:
        move_and_make(folder,path,CATEGORIES)


    #User choice to exit the program
    again = input("\n\nNew Directory To Organize? (1-Yes) or (0-No): ")

    while again != "1" and again != "0":
        print("Not a valid input! Try again.")
        again = input("New Directory To Organize? (1-Yes) or (0-No): ")

    if again == "0":
        break





print("\n\n-----------Thanks for Using Me Dude!!-------------\n\n")
