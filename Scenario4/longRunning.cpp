#include <stdio.h>
#include <string>
#include <iostream>
#include <vector>
#include <stdexcept>

// Add the necessary #include headers here

// This is a helper method to read the storage connection string from the environment that you can use.
// There is no need to modify this.
const std::string& GetConnectionStringOne()
{
	const static std::string ConnectionString = "";

	if (!ConnectionString.empty())
	{
		return ConnectionString;
	}

	const char* envConnection = std::getenv("AZ_STORAGE_CONNECTION_STRING_1");
	if (envConnection)
	{
		const static std::string envConnectionString = std::string(envConnection);

		if (!envConnectionString.empty())
		{
			return envConnectionString;
		}
	}

	puts("Cannot find connection string 1 or it is empty.");
	throw std::runtime_error("Cannot find connection string 1 or it is empty.");
}

// This is a helper method to read the storage connection string from the environment that you can use.
// There is no need to modify this.
const std::string& GetConnectionStringTwo()
{
	const static std::string ConnectionString = "";

	if (!ConnectionString.empty())
	{
		return ConnectionString;
	}

	const char* envConnection = std::getenv("AZ_STORAGE_CONNECTION_STRING_2");
	if (envConnection)
	{
		const static std::string envConnectionString = std::string(envConnection);

		if (!envConnectionString.empty())
		{
			return envConnectionString;
		}
	}

	puts("Cannot find connection string 2 or it is empty.");
	throw std::runtime_error("Cannot find connection string 2 or it is empty.");
}

// TASK:
// Run this application that is using the C++ Azure Storage SDK to copy a large blob from the source container to the destination container
// and track progress by printing a timer, i.e. "not done <number of seconds since the operation started>" message to the console 
// every second the copy operation is in progress. Also output the progress of how many bytes have been copied so far.
// If the operation doesn't finish within 30 seconds, cancel it.
// 
// Note: The necessary azure-storage-blobs dependency has already been installed for you.
// Note: The connection strings to connect to both the source and destination blob storage service are 
// already set in the environment variables and can be retrieved by calling 'GetConnectionStringOne()' 
// and 'GetConnectionStringTwo()'. You do not need to go to the Azure portal or setup any cloud 
// resources yourself for this scenario.
int CopyWithProgress()
{
	// Do NOT modify these provided container and blob names.
	std::string containerName = "testcontainer";
	std::string blobName = "sample-large-blob";

	std::string destinationContainer = "containername";
	std::string destBlob = "copy-blob";

	return 1;
}

int main()
{
	if (CopyWithProgress())
	{
		puts("Task 4 incomplete due to an error.");
	}
	else
	{
		puts("Task 4 complete.");
	}

	system("pause");
	return 0;
}
