#include <stdio.h>
#include <string>
#include <iostream>
#include <vector>

// Add any necessary #include headers here

// This is a helper method to read the storage connection string from the environment that you can use.
// There is no need to modify this.
const std::string& GetConnectionString()
{
	const static std::string ConnectionString = "";

	if (!ConnectionString.empty())
	{
		return ConnectionString;
	}

	const char* envConnection = std::getenv("AZURE_STORAGE_CONNECTION_STRING");
	if (envConnection)
	{
		const static std::string envConnectionString = std::string(envConnection);

		if (!envConnectionString.empty())
		{
			return envConnectionString;
		}
	}

	puts("Cannot find connection string or it is empty.");
	throw std::runtime_error("Cannot find connection string or it is empty.");
}

// TASK:
// 1) Install the Azure Blob Storage SDK from vcpkg and add that library dependency to this application.
// 2) Use the C++ Azure Storage SDK to upload the file on disk with the name @fileName
// to the cloud leveraging the Azure Blob Storage cloud service.
// 3) Once you have uploaded the file to the blob storage, print to console the response status code 
// AND the last modified date of the blob.
// 
// Note: For the implementation of this method, return 0 for success, and non-zero for any error.
// Note: The connection string to connect to the blob storage service is already set in the environment variable 
// and can be retrieved by calling 'GetConnectionString()'. You do not need to go to the Azure portal
// or setup any cloud resources yourself for this scenario.
int UploadFile(std::string fileName)
{
	// Do NOT modify these provided container and blob names.
	std::string containerName = "testcontainer";
	std::string blobName = "sample-blob";

	return 1;
}

// Entry point of the application which calls UploadFile(). There is no need to modify this.
int main(int argc, char* argv[])
{
	std::string fileName = "myFileToUpload.txt";

	if (argc >= 2) {
		puts("Using provided argument for the file name.");
		fileName = argv[1];
	}

	if (UploadFile(fileName))
	{
		puts("Task 1 incomplete due to an error.");
	}
	else
	{
		puts("Task 1 complete.");
	}

	system("pause");
	return 0;
}
