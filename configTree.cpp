#include <iostream>
#include <vector>
#include <ctime>
using namespace std;

struct Folder
{
    int id;
    string name;
    string path;
    vector<Folder> children;
};

int generateUniqueId()
{
    static int counter = 0;
    time_t currentTime = time(nullptr);
    int uniqueId = static_cast<int>(currentTime) + counter++;
    return uniqueId;
}

// Function to add a new folder at a particular path in the directory tree
void addFolder(Folder &parentFolder, const string &folderName)
{
    Folder newFolder;
    newFolder.id = generateUniqueId();
    newFolder.name = folderName;
    newFolder.path = parentFolder.path + "/" + folderName;

    parentFolder.children.push_back(newFolder);
}

// Function to remove a folder from a particular path in the directory tree
void removeFolder(Folder &parentFolder, const string &folderName)
{
    for (auto it = parentFolder.children.begin(); it != parentFolder.children.end(); ++it)
    {
        if (it->name == folderName)
        {
            parentFolder.children.erase(it);
            break;
        }
    }
}

// Function to fetch the path of a given folder
string fetchFolderPath(const Folder &currentFolder, const string &folderName)
{
    if (currentFolder.name == folderName)
    {
        return currentFolder.path;
    }

    for (const auto &childFolder : currentFolder.children)
    {
        string path = fetchFolderPath(childFolder, folderName);
        if (!path.empty())
        {
            return path;
        }
    }

    return ""; // Folder not found
}

// Function to update the name of a folder
void updateFolderName(Folder &currentFolder, const string &oldName, const string &newName)
{
    if (currentFolder.name == oldName)
    {
        currentFolder.name = newName;
    }

    for (auto &childFolder : currentFolder.children)
    {
        updateFolderName(childFolder, oldName, newName);
    }
}

int main()
{
    Folder rootFolder;
    rootFolder.id = 0;
    rootFolder.name = "Root";
    rootFolder.path = "/root";

    // Add folders
    addFolder(rootFolder, "Folder1");
    addFolder(rootFolder, "Folder2");
    addFolder(rootFolder.children[0], "Subfolder1");
    addFolder(rootFolder.children[0], "Subfolder2");
    addFolder(rootFolder.children[1], "Subfolder3");

    // Fetch folder paths
    string folderPath1 = fetchFolderPath(rootFolder, "Folder1");
    string folderPath2 = fetchFolderPath(rootFolder.children[0], "Subfolder2");
    cout << "Folder1 path: " << folderPath1 << endl;
    cout << "Subfolder2 path: " << folderPath2 << endl;

    // Update folder name
    updateFolderName(rootFolder, "Folder1", "NewFolderName");

    // Remove folder
    removeFolder(rootFolder, "Folder2");

    return 0;
}
