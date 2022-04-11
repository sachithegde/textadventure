#ifndef HELPER_H
#define HELPER_H

#include <stdlib.h>
#include <time.h>




int randomGen(int range)
{
	srand((int)time(0));
	int temp = rand() % range;
	/*std::cout << "Random Int: " << temp << " Range: " << range << std::endl;*/
	return temp;
}


#endif // !HELPER_H

