#include <ext/hash_map>
#include <iostream>
#include <stdint.h>
namespace std{ using namespace __gnu_cxx;}

int main()
{
	std::hash_multimap<uint32_t, char * > m(1000);
#define MAX 20
	int n=0,j=0;
	for(n=0; n<MAX; n++)
	{
		for(j=0; j<MAX; j++)
		{
			m.insert(std::make_pair(1,(char*)0));
			m.insert(std::make_pair(1,(char*)1));
			m.insert(std::make_pair(1,(char*)2));
		}
		std::cout << m.bucket_count() << std::endl;
	}
	std::cout << m.size() << std::endl;
	std::cout << m.bucket_count() << std::endl;

	return 0;

}
