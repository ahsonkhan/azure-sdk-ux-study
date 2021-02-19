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
// Use the C++ Azure Storage SDK to download the file from an existing blob container into another new one under
// a different storage account, leveraging the Azure Storage cloud service.
// You need to create a destination container first to move the file from the source blob container into.
// 
// Note: For the implementation of this method, return 0 for success, and non-zero for any error.
// Note: Here are the Azure Storage account details. The connection string to connect to the service is 
// set in the environment variable.
// Note: The connection strings to connect to both the source and detination blob storage service are 
// already set in the environment variables and can be retrieved by calling 'GetConnectionStringOne()' 
// and 'GetConnectionStringTwo()'. You do not need to go to the Azure portal.
// Note: You don't need to install the package dependency from scenario 1 as the CMakeLists.txt already 
// links the required package.
int TransferFile()
{
	// Do NOT modify these provided container and blob names.
	std::string sourceContainerName = "testcontainer";
	std::string sourceBlobName = "sample-blob";

	return 1;
}

int main()
{
	if (TransferFile())
	{
		puts("Task 2 incomplete due to an error.");
	}
	else
	{
		puts("Task 2 complete.");
	}

	system("pause");
	return 0;
}