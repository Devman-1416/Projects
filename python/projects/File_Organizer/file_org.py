import os
import shutil

#Path to my test folder
# r treats \ as real
path = r"C:\Users\Devin\Code\projects\python\projects\File_Organizer\test"


try:
    #Checks File Path, return booloan
    os.path.isfile(path)

    # Prints and stores all file names int folder
    print(os.listdir(path))
    folder = os.listdir(path)
    print("\n\n",folder)

except:
    print("Error Finding File Path!")


#Dictionary
CATEGORIES = {
    "Images": [".jpg", ".png", ".jpeg", ".gif"],
    "Documents": [".txt", ".pdf", ".docx"],
    "Code": [".py", ".js", ".html", ".css"],
    "Archives": [".zip", ".rar", ".7z"],
    "Misc": []
}

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
                found = 1

    #If Not a folders and Is a Misc
    if found == 0 and os.path.isfile(os.path.join(path, item)):
        #Combine the Current Path directory and make folder if not there
        destination = os.path.join(path, name)
        os.makedirs(destination, exist_ok=True)

        #Move File       #Source is Path .etx    #Move to folder with folder Name
        shutil.move(os.path.join(path, item), os.path.join(destination, item))




