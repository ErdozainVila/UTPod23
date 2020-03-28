# UTPod23

############################################
########## Compiling from windows ##########
############################################
g++ -std=c++11 file_1.cpp file_2.cpp -o your_program_name

###########################################
########## Set up the Git Bash ############
###########################################
git config --global user.name “your username”
git config --global user.email “your_email_address@example.com”

cd into the project to be tracked and initialize
git init
git status

########## Add files to the staging area ############
git add -A                        -> adds all the untracked files
git add filename                  -> add an specific file
git status                        -> shows status

########## Removing files from the staging area ############
git reset filename               -> removes specific file from the staging area
git reset                        -> removes all files from the staging area

########## Commit changes from the staging area to the repository ############
git commit -m “Initial commit”  -> the message must be clear
git status                      -> shows status
git log                         -> to check the commits made

########## To clone a remote repository ############
git clone <url> <destination_path>

########## In order to push changes to a remote repository ############
git pull origin master
git push origin master

###########################################
########## Useful commands ################
###########################################    
mkdir project             -> Create a project directory
cp ~/add.c                -> Create a file
touch filename.extension  -> Creates a filename
ls -l                     -> Shows files plus dates
ls –a                     -> shows the unseen files
rm filename.extension     -> removes files
mv old_fn.ext new_fn.ext  -> changes name
