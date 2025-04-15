#include "opt.h"

opt::opt(std::string pageData)
{
	std::cout << "Optimal algorithm written by Corban Turner" << std::endl;


	int size = pageData.length() - 2;
	opt::framesNo = pageData[1] - '0';	//Gets the frame size from the page Data
	//Dynamically allocated arrays that will hold the input stream and frames respectively
	int* data = new int[size];
	int* frame = new int[framesNo];

	int pagefaults = 0;

	parseData(pageData, size, data); //Translates the pageData string into an array of ints, minus the first two characters

	std::string* array = new std::string[framesNo]; //Array of strings that stores the output


	for (int i = 0; i < size; i++) //Operates once on each input character
	{
		int l = 0; //Stores the largest length between the current location and the next time the variable is referenced
		int n = 0; //References the frame with the page that will be swapped

		for (int f = 0; f < framesNo; f++)
		{
			//Find the frame that will not be used for the longest period of time
			int length = opt::findlength(frame, f, data, i, size);
			if (length > l)
			{
				l = length;
				n = f;
			}
		}

		//Checks if the page is already in a frame
		if (checkdupe(frame, data, i))
		{
			//If page exists, show an empty column. 
			for (int f = 0; f < framesNo; f++)
			{
				array[f].append("_ ");
			}
		}
		else
		{
			frame[n] = data[i];

			//Ammends the array of output strings
			for (int f = 0; f < framesNo; f++)
			{
				if (frame[f] < 0)
				{
					array[f].append("_ ");
				}
				else
				{
					array[f].append(std::to_string(frame[f]) + " ");
				}
			}
			pagefaults++;
		}
	}


	//Print Function

	opt::printbreak(size);

	for (int i = 0; i < size; i++)
	{
		std::cout << data[i] << " ";
	}
	std::cout << std::endl;

	opt::printbreak(size);

	for (int i = 0; i < framesNo; i++)
	{
		std::cout << array[i] << std::endl;
	}

	opt::printbreak(size);

	std::cout << "Pagefaults: " << pagefaults << std::endl;

	//Deletes the dynamically allocated arrays
	delete[] data;
	delete[] frame;
};


void opt::parseData(std::string pageData, int size, int* data)
{
	for (int i = 2; i < size + 2; i++) //Size doesn't include the algorithm identifier
	{
		data[i - 2] = pageData[i] - '0';
	}
}

void opt::printbreak(int size)
{
	for (int i = 0; i < size * 2 - 1; i++)
	{
		std::cout << "-";
	}
	std::cout << std::endl;
}

int opt::findlength(int frame[], int n, int* data, int location, int size)
{
	int length = size;
	for (int i = location; i < size; i++)
	{
		if (data[i] == frame[n])
		{
			length = i - location;
		}
	}
	if (frame[n] < 0) //Biases the length to fill in empty pages
	{
		return 99;
	}
	return length;
}

bool opt::checkdupe(int frame[], int* data, int i)
{
	for (int f = 0; f < framesNo; f++)
	{
		if (data[i] == frame[f])
		{
			return true;
		}
		else
		{
			return false;
		}
	}
}
