#include "opt.h"
#include <string.h>


opt::opt(std::string pageData)
{

	

	int size = pageData.length()-2;
	int* data = new int[size];
	int* frame = new int[framesNo];
	int* data1 = new int[size];

	int pagefaults = 0;

	int f = opt::framesNo;

	int l0;
	int l1;
	int l2;

	std::string out1;
	std::string out2;
	std::string out3;

	parseData(pageData, size, data);


	//Ran out of time to avoid hard coding this
	frame[0] = data[0];
	out1.append(std::to_string(frame[0]) + "  ");
	out2.append("_  ");
	out3.append("_  ");

	frame[1] = data[1];
	out1.append(std::to_string(frame[0]) + "  ");
	out2.append(std::to_string(frame[1]) + "  ");
	out3.append("_  ");

	frame[2] = data[2];
	out1.append(std::to_string(frame[0]) + "  ");
	out2.append(std::to_string(frame[1]) + "  ");
	out3.append(std::to_string(frame[2]) + "  ");


	for (int i = framesNo; i < size; i++)
	{
		l0 = 0;
		l1 = 0;
		l2 = 0;
		for (int j = i; j < size; j++)
		{
			if (frame[0] = data[j])
			{
				l0 = j - i;
				std::cout << l0 << std::endl;
			}
		}

		if (data[i] == frame[0] || data[i] == frame[1] || data[i] == frame[2])
		{
			out1.append("_  ");
			out2.append("_  ");
			out3.append("_  ");
		}else
		{
			out1.append(std::to_string(frame[0]) + "  ");
			out2.append(std::to_string(frame[1]) + "  ");
			out3.append(std::to_string(frame[2]) + "  ");
			pagefaults++;
		}

	}

	opt::printbreak(size);

	std::cout << out1 << std::endl;
	std::cout << out2 << std::endl;
	std::cout << out3 << std::endl;

	opt::printbreak(size);

	std::cout << "Pagefaults: " << pagefaults << std::endl;

	delete[] data;
};


void opt::parseData(std::string pageData,int size, int* data)
{
	for (int i = 2; i < size+2; i++) //Size doesn't include the algorithm identifier
	{
		data[i-2] = pageData[i] - '0';
	}
}

void opt::printbreak(int size)
{
	for (int i = 0; i < size * 3 - 2; i++)
	{
		std::cout << "-";
	}
	std::cout << std::endl;
}