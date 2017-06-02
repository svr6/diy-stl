#include <ext/hash_map>
#include <iostream>
#include <stdint.h>
namespace std{ using namespace __gnu_cxx;}

int main()
{
	std::hash_multimap<uint32_t, char * > m;

	m.insert(std::make_pair(1,(char*)0));
	m.insert(std::make_pair(1,(char*)1));
	m.insert(std::make_pair(1,(char*)2));

	std::cout << m.size() << std::endl;

	return 0;

}
