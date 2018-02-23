#include <string>
#include <memory>
#include <iostream>
#include<boost/smart_ptr.hpp>

class Simple
{
	public:
		Simple(int param=0)
		{
			number = param;
			std::cout << "Simple: " << number << std::endl;			
		}

		~Simple()
		{
			std::cout << "~Simple: " << number << std::endl;			
		}

		void PrintInfo()
		{
			std::cout << "PrintInfo: " << info.c_str() << std::endl;			
		}

		std::string info;
	private:
		int number;
};


void TestSharedPtr2(boost::shared_ptr<Simple> memory)
{
	memory->PrintInfo();
	std::cout << "Shared Ptr use count: " << memory.use_count() << std::endl;
}

void TestSharedPtr()
{
	boost::shared_ptr<Simple> memory(new Simple(123));
	if(memory.get())
	{
		memory->PrintInfo();
		memory.get()->info = "Add";
		memory->PrintInfo();
		(*memory).info += " Test Scoped";
		memory->PrintInfo();
	}
 
	std::cout << "Shared Ptr use count: " << memory.use_count() << std::endl;
	TestSharedPtr2(memory);
	std::cout << "Shared Ptr use count: " << memory.use_count() << std::endl;
}



void TestScopedPtr()
{
	boost::scoped_ptr<Simple> memory(new Simple(234));
	if(memory.get())
	{
		memory->PrintInfo();
		memory.get()->info = "Add";
		memory->PrintInfo();
		(*memory).info += " Test Scoped";
		memory->PrintInfo();

		//unavailable
		{
			//memory.release();
			boost::scoped_ptr<Simple> memory2;
			//memory2 = memory;
		}

	}
}

void TestAutoPtr3()
{
	std::auto_ptr<Simple> memory(new Simple(347));
	if(memory.get())
	{
		/*
		{
			Simple * tmp_ptr = memory.release();
			delete tmp_ptr;
		}
		*/

		{
			memory.reset();
		}
	}
}


void TestAutoPtr2()
{
	std::auto_ptr<Simple> memory(new Simple(346));
	if(memory.get())
	{
		memory->PrintInfo();
		std::auto_ptr<Simple> memory2;
		memory2 = memory;
		memory2->PrintInfo();
		memory->PrintInfo();
	}
}

void TestAutoPtr()
{
	std::auto_ptr<Simple> memory(new Simple(345));
	if(memory.get())
	{
		memory->PrintInfo();
		memory.get()->info = "Add";
		memory->PrintInfo();
		(*memory).info += "Test";
		memory->PrintInfo();
	}
}

int main()
{
	//TestAutoPtr();
	//TestAutoPtr2();
	//TestAutoPtr3();
	//TestScopedPtr();
	TestSharedPtr();

	return 0;
}
