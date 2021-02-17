#include <stdio.h>
#include <string>

// Add the necessary #include headers here


// Use the C++ Azure Storage SDK to upload the file on disk with the name @fileName
// to the cloud leveraging the Azure Storage cloud service.
// Note: The necessary azure-storage-blobs dependency has already been installed for you.
// Note: Here are the Azure Storage account details. The connection string to connect to the service is set in the environment variable.
void UploadFile(std::string fileName)
{

}

int main()
{
    std::string fileName = "myFile.txt";
    UploadFile(fileName);
    puts ("Task 1 complete");
    return 0;
}