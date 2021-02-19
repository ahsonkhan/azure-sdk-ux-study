#include <stdio.h>
#include <string>
#include <iostream>
#include <vector>
#include <stdexcept>

// Add any necessary #include headers here

#include <azure/core.hpp>
#include <azure/core/http/curl/curl.hpp>
#include <azure/storage/blobs.hpp>

using namespace Azure::Storage::Blobs;

// This is a helper method to read the storage connection string from the environment that you can use.
// There is no need to modify this.
const std::string& GetConnectionString()
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

	puts("Cannot find connection string or it is empty.");
	throw std::runtime_error("Cannot find connection string or it is empty.");
}

// TASK:
// Run this application that is using the C++ Azure Storage SDK to <some task that results in a request failed exception>.
// You will notice something went wrong. Figure out what went wrong, and write some code to log error details to the console to catch such errors in the future.
//
// Note: The necessary azure-storage-blobs dependency has already been installed for you.
// Note: The connection string to connect to the blob storage service is already set in the environment variable 
// and can be retrieved by calling 'GetConnectionString()'. You do not need to go to the Azure portal
// or setup any cloud resources yourself for this scenario.
int FixMe()
{
	// Do NOT modify these provided container and blob names.
	std::string containerName = "testcontainer";
	std::string blobName = "sample-blob";

	std::vector<uint8_t> downloadedBlob(5);

	BlobClientOptions options;
	options.TransportPolicyOptions.Transport = std::make_shared<Azure::Core::Http::CurlTransport>();

	auto sourceClient = BlobClient::CreateFromConnectionString(GetConnectionString() + "bad url", containerName, blobName, options);
	auto sourceBlockBlobClient = sourceClient.AsBlockBlobClient();

	auto downloadResponse = sourceBlockBlobClient.DownloadTo(downloadedBlob.data(), downloadedBlob.size());
	auto& downloadResult = downloadResponse.ExtractValue();
	printf("The downloaded blob size is %lld\n", downloadResult.BlobSize);

	return 1;
}

int main()
{
	if (FixMe())
	{
		puts("Task 3 incomplete due to an error.");
	}
	else
	{
		puts("Task 3 complete.");
	}

	system("pause");
	return 0;
}
