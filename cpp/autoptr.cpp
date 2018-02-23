#include <string>
#include <memory>
#include <iostream>

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
	TestAutoPtr3();

	return 0;
}
