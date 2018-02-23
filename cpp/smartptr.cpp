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


void TestWeakPtr()
{
	boost::weak_ptr<Simple> memory_weak;
	boost::shared_ptr<Simple> memory(new Simple(134));
	
	{
		std::cout << "TestWeakPtr UseCount: " << memory.use_count() << std::endl;
		memory_weak = memory;
		std::cout << "TestWeakPtr UseCount: " << memory.use_count() << std::endl;
	}
}

void TestSharedArray2(boost::shared_array<Simple> memory) 
{ 
	std::cout << "TestSharedArray2 UseCount: " << memory.use_count() << std::endl;
}

void TestSharedArray() 
{
	boost::shared_array<Simple> memory(new Simple[2]);
	if (memory.get()) 
	{
		memory[0].PrintInfo();
		memory.get()[0].info = "Addition 00";
		memory[0].PrintInfo();
		memory[1].PrintInfo();
		memory.get()[1].info = "Addition 11";
		memory[1].PrintInfo();
		//(*memory)[0].info += " other"; 
	}
	std::cout << "TestSharedArray UseCount: " << memory.use_count() << std::endl;
	TestSharedArray2(memory);
	std::cout << "TestSharedArray UseCount: " << memory.use_count() << std::endl;
}


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


void TestScopedArray()
{
	boost::scoped_array<Simple> memory(new Simple(2345));
	if(memory.get())
	{
		memory[0].PrintInfo();
		memory.get()[0].info = "Add";
		memory[0].PrintInfo();
		//(*memory)[0].info += " Test Scoped"; //not support
		memory.get()[0].info = "Test Scoped Array";
		memory[0].PrintInfo();

		//unavailable
		{
			//memory[0].release();
			//boost::scoped_array<Simple> memory2;
			//memory2 = memory;
		}
	}
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
	//TestSharedPtr();
	//TestScopedArray();
	//TestSharedArray();
	TestWeakPtr();

	return 0;
}
