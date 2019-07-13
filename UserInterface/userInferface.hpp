#include <iostream>

class UserInterface
{
  public:
    char getUserCharacter()
    {
      std::string userInput= "";
      std::cout << "Please choose you character to be 'x' or 'o'" << std::endl;
      do
      {
	std::cin >> userInput;
	std::cout << std::endl;
      }while(userInput != "x" && userInput != "o");

      return userInput.c_str()[0];
    }
    Point getUserPoint()
    {
      Point userPoint;
      std::cout << "Give me coordinate x" << std::endl;
      std::cin >> userPoint.x;
      std::cout << "Give me coordinate y" << std::endl;
      std::cin >> userPoint.y;
      return userPoint;
    }
};

