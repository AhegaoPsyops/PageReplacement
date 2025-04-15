#include "opt.h"
#include <string.h>


opt::opt(std::string pageData, int framesNo)
{
	opt::framesNo = framesNo;

	int size = pageData.length();
	int* data = new int[size];

	parseData(pageData, data);

	delete[] data;
};


void opt::parseData(std::string pageData, int* data)
{
	for (int i = 1; i < pageData.length(); i++)
	{
		data[i-1] = pageData[i];
	}
}